// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <array>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

constexpr cat MOD = 1000000007;

#ifndef _TREAP_H
#define _TREAP_H

#include <algorithm> // std::sort
#include <vector> // std::vector
#include <utility> // std::pair
#include <random> // std::mt19937_64
#include <chrono>

template <typename T> T zero();

namespace treap {

namespace has_traits {
    template<typename L, typename R = L>
    struct has_operator_plus {
        template<typename T = L, typename U = R> // template parameters here to enable SFINAE
        static auto test(T &&t, U &&u) -> decltype(t + u, void(), std::true_type{});
        static auto test(...) -> std::false_type;
        using type = decltype(test(std::declval<L>(), std::declval<R>()));
    };

    template<typename T, typename ...Args>
    struct has_member_zero {
        template<typename T_ = T>
        static auto test(T_ &&t, Args &&...args) -> decltype(t.zero(std::forward<Args>(args)...), void(), std::true_type{});
        static auto test(...) -> std::false_type;
        using type = decltype(test(std::declval<T>(), std::declval<Args>()...));
    };
} // namespace has_traits

template <class Key, bool Multi, class Allocator = std::allocator<Key> >
class treap {
 private:
  struct node;
  using pnode = struct node *;
  using node_allocator_t = typename std::allocator_traits<Allocator>::template rebind_alloc<node>;
  using index_t = int;  // also used for sizes and distances/shifts between indices

  constexpr static bool has_add_keys = has_traits::has_operator_plus<Key>::type::value;
  constexpr static bool has_zero_key_member = has_traits::has_member_zero<Key>::type::value;

  std::mt19937_64 * rng_;
  node_allocator_t node_allocator_;
  bool rng_owner_;
  bool is_sorted_;
  bool stop_; // for priority regeneration
  pnode root_;

  using priority_t = std::mt19937_64::result_type;

  priority_t next_priority () {
    priority_t priority = (*rng_)();
    return priority;
  }

  void regenerate_priorities_recursive (std::vector <priority_t> & new_priors, pnode & t, index_t l, index_t r) {
    if (!t)
      return;
    t->priority = new_priors[r - 1];
    regenerate_priorities_recursive(new_priors, t->l, l, l + cnt(t->l));
    regenerate_priorities_recursive(new_priors, t->r, l + cnt(t->l), r - 1);
  }

  void regenerate_priorities () {
    index_t sz = size();
    std::vector <priority_t> new_priors(sz);
    for (index_t i = 0; i < sz; i++)
      new_priors[i] = next_priority();
    std::sort(new_priors.begin(), new_priors.end());
    for (index_t i = 0; i < sz; i++)
      new_priors[i] += i;
    regenerate_priorities_recursive(new_priors, root_, 0, sz);
  }

  struct node {
    priority_t priority;
    index_t cnt;
    pnode l, r;

    int reverse_order;

    // keys are used for sorted arrays - no need if regular array, just use values
    // sorted array supports find(key), lower_bound(key), insert(key), erase(key), shift keys by constant
    // what common operations can we have on keys?
    // lower_bound() is effectively get_max()/get_min() with special treatment for multitreap, insert/erase is effectively put()
    // we can shift the keys (add value to range of keys) so it's worth supporting get_sum()
    // set_max()/set_min() doesn't make much sense for keys - if the array is sorted, just go for erase() and vector<value>, it's efficient when amortised
    // user can skip key and have an indexed dynamic array
    // user can also skip value and have a sorted (or unsorted) array of keys
    // arbitrary number of segment-tree-like operations should be supported on values, to be implemented by user

    Key key, add_to_keys, sum_of_keys, min_of_keys, min_key, max_key;

    template <typename T = Key>
    node (const typename std::enable_if<std::is_arithmetic<T>::value, T>::type & key_, priority_t priority_) : priority{priority_}, cnt{1}, l{nullptr}, r{nullptr}, key{key_} {
      key = sum_of_keys = min_of_keys = min_key = max_key = key_;
      add_to_keys = 0;
      reverse_order = 0;
    }

    template <typename T = Key>
    node (const typename std::enable_if<has_traits::has_member_zero<T>::type::value, T>::type & key_, priority_t priority_) : priority{priority_}, cnt{1}, l{nullptr}, r{nullptr}, key{key_} {
      key = sum_of_keys = min_of_keys = min_key = max_key = key_;
      add_to_keys = T::zero();
      reverse_order = 0;
    }

    template <typename T = Key>
    node (const typename std::enable_if<!(std::is_arithmetic<T>::value | has_traits::has_member_zero<T>::type::value), T>::type & key_, priority_t priority_) : priority{priority_}, cnt{1}, l{nullptr}, r{nullptr}, key{key_} {
      key = sum_of_keys = min_of_keys = min_key = max_key = key_;
      add_to_keys = zero<T>();
      reverse_order = 0;
    }
  };

  pnode create_node(const Key & x) {
    auto place = node_allocator_.allocate(1);
    std::allocator_traits<node_allocator_t>::construct(node_allocator_, place, x, next_priority());
    return place;
  }

  void destroy_node(pnode t) {
    if (!t) return;
    std::allocator_traits<node_allocator_t>::destroy(node_allocator_, t);
    node_allocator_.deallocate(t, 1);
  }

/*  static inline bool compare_nodes() (const node & a, const node & b) {
    if (a.Key < b.Key)
      return true;
    if (b.Key < a.Key)
      return false;
    if (!Multi) return false;
    return a.priority < b.priority;
  }
*/
  index_t cnt (pnode t) {
    return t ? t->cnt : 0;
  }

  template <typename T = Key>
  static inline typename std::enable_if<std::is_arithmetic<T>::value, T>::type
  zero_key () {
    return 0;
  }

  template <typename T = Key>
  static inline typename std::enable_if<has_zero_key_member, T>::type
  zero_key () {
    return T::zero();
  }

  template <typename T = Key>
  static inline typename std::enable_if<!(std::is_arithmetic<T>::value | has_zero_key_member), T>::type
  zero_key () {
    return zero<T>();
  }

  template <typename T = Key>
  static inline typename std::enable_if<std::is_arithmetic<T>::value, T>::type
  inf_key () {
    return std::numeric_limits<T>::max();
  }

  template <typename T = Key>
  static inline typename std::enable_if<has_add_keys, T>::type
  add_keys (const Key & a, const Key & b) {
    return a + b;
  }

  template <typename T = Key>
  static inline typename std::enable_if<has_add_keys, T>::type
  mul_key_count (const Key & a, const index_t & cnt) {
    return a * cnt;
  }

  static inline bool check_key_sortedness(const Key & a, const Key & b) {
    if (!Multi)
      return b < a;
    return !(a < b);
  }

  inline void pull_sum_of_keys (pnode t) {
    if (t) {
      t->sum_of_keys = t->key;
      if (t->l)
        t->sum_of_keys = add_keys(t->sum_of_keys, t->l->sum_of_keys);
      if (t->r)
        t->sum_of_keys = add_keys(t->sum_of_keys, t->r->sum_of_keys);
    }
  }

  inline void pull_min_of_keys (pnode t) {
    if (t) {
      t->min_of_keys = t->key;
      if (t->l)
        t->min_of_keys = std::min(t->min_of_keys, t->l->min_of_keys);
      if (t->r)
        t->min_of_keys = std::min(t->min_of_keys, t->r->min_of_keys);
    }
  }

  inline void pull_min_max_key (pnode t) {
    if (!is_sorted_) return;
    if (t) {
      t->min_key = t->max_key = t->key;
      if (t->l)
        t->min_key = t->l->min_key;
      if (t->r)
        t->max_key = t->r->max_key;
    }
  }

  inline void pull_cnt (pnode t) {
    if (t)
      t->cnt = cnt(t->l) + cnt(t->r) + 1;
  }

  void pull (pnode t) {
    pull_cnt(t);
    pull_sum_of_keys(t);
    pull_min_of_keys(t);
    pull_min_max_key(t);
    // pull values
  }

  template <typename T = Key>
  inline typename std::enable_if<has_add_keys, void>::type
  update_sum_of_keys (pnode t, Key add) {
    if (!t)
      return;
    t->key = add_keys(t->key, add);
    t->add_to_keys = add_keys(t->add_to_keys, add);
    t->min_key = add_keys(t->min_key, add);
    t->max_key = add_keys(t->max_key, add);
  }

  inline void update_reverse_order (pnode t, int rev) {
    if (!t)
      return;
    t->reverse_order ^= rev;
  }

  void update (pnode t, Key add, int rev) {
    if (!t)
      return;
    update_sum_of_keys(t, add);
    update_reverse_order(t, rev);
    // update values
  }

  void push_reverse_order (pnode t) {
    if (!t || t->reverse_order == 0)
      return;
    update_reverse_order(t->l, t->reverse_order);
    update_reverse_order(t->r, t->reverse_order);
    std::swap(t->l, t->r);
    t->reverse_order = 0;
  }

  void push_sum_of_keys (pnode t) {
    if (!t || t->add_to_keys == zero_key())
      return;
    update_sum_of_keys(t->l, t->add_to_keys);
    update_sum_of_keys(t->r, t->add_to_keys);
    t->sum_of_keys = add_keys(t->sum_of_keys, mul_key_count(t->add_to_keys, cnt(t)));
    t->add_to_keys = zero_key();
  }

  void push (pnode t) {
    if (!t)
      return;
    push_sum_of_keys(t);
    push_reverse_order(t);
    // push values
  }

  // update = only mark down a change to be lazy-applied later
  // push = lazy-apply change and update children, must be called before node is evaluated

  void merge (pnode & t, pnode l, pnode r) {
    push(l);
    push(r);
    if (!l || !r)
      t = l ? l : r;
    else if (l->priority > r->priority) {
      merge(l->r, l->r, r);
      t = l;
    }
    else {
      merge(r->l, l, r->l);
      t = r;
    }
    pull(t);
  }

  void split_at (pnode t, pnode & l, pnode & r, index_t index) { // split at position
    if (!t) {
      l = r = 0;
      return;
    }
    push(t);
    if (index <= cnt(t->l)) {
      split_at(t->l, l, t->l, index);
      r = t;
    }
    else {
      split_at(t->r, t->r, r, index - 1 - cnt(t->l));
      l = t;
    }
    pull(t);
  }

  void split_by_key (pnode t, pnode & l, pnode & r, const Key & key, bool & eq) {
    /*
    Helper method for `insert`. Attempts to split treap rooted at `t` into two treaps.

    If `Multi`, the treaps are `<= key` and `> key` respectively.
    After return, `l`, `r` will contain roots of these treaps and `eq` will be undefined.

    If not `Multi`:
    - If an equal `key` exists in the treap rooted at `t`, split does not happen. After return, `l`, `r` will be undefined and `eq` will be `true`.
    - Otherwise, after return, `l`, `r` will contain roots of the treaps `< key` and `> key` respectively and `eq` will be `false`.
    */
    if (!t) {
      l = r = 0;
      return;
    }
    push(t);
    if (!Multi && !(key < t->key) && !(t->key < key)) {
      eq = true;
      return;
    }
    if (key < t->key) {
      split_by_key(t->l, l, t->l, key, eq);
      if (Multi || !eq)
        r = t;
    }
    else {
      split_by_key(t->r, t->r, r, key, eq);
      if (Multi || !eq)
        l = t;
    }
    if (Multi || !eq)
      pull_cnt(t);
    pull_sum_of_keys(t);
    // pull values
  }

  void insert_at (pnode & t, pnode it, index_t index) { // insert at position
    push(t);
    if (!t)
      t = it;
    else if (it->priority == t->priority) {
      stop_ = true;
      regenerate_priorities();
    }
    else if (it->priority > t->priority) {
      split_at(t, it->l, it->r, index);
      t = it;
    }
    else if (index <= cnt(t->l))
      insert_at(t->l, it, index);
    else
      insert_at(t->r, it, index - cnt(t->l) - 1);
    if (stop_)
      return;
    pull(t);
  }

  void insert (pnode & t, pnode it, bool & eq) { // insert by key
    push(t);
    if (!t)
      t = it;
    else if (!Multi && !(it->key < t->key) && !(t->key < it->key)) {
      eq = true;
      return;
    }
    else if (it->priority == t->priority) {
      stop_ = true;
      regenerate_priorities();
    }
    else if (it->priority > t->priority) {
      split_by_key(t, it->l, it->r, it->key, eq);
      if (!eq)
        t = it;
    }
    else if (it->key < t->key)
      insert(t->l, it, eq);
    else
      insert(t->r, it, eq);
    if (stop_)
      return;
    if (!eq)
      pull_cnt(t);
    pull_sum_of_keys(t);
    // pull values
  }

  void erase_at (pnode & t, index_t index) {
    push(t);
    if (cnt(t->l) == index) {
      pnode l = t->l, r = t->r;
      destroy_node(t);
      t = nullptr;
      merge(t, l, r);
    }
    else if (index < cnt(t->l))
      erase_at(t->l, index);
    else
      erase_at(t->r, index - cnt(t->l) - 1);
    pull(t);
  }

  void erase (pnode & t, const Key & key, bool & found) {
    push(t);
    if (!(key < t->key && !(t->key < key))) {
      pnode l = t->l, r = t->r;
      destroy_node(t);
      t = nullptr;
      merge(t, l, r);
      found = true;
    }
    else if (key < t->key)
      erase(t->l, key, found);
    else
      erase(t->r, key, found);
    pull(t);
  }

  // pair<Key, Values>
  Key get (pnode t, index_t index) {
    push(t);
    if (index < cnt(t->l))
      return get(t->l, index);
    else if (index > cnt(t->l))
      return get(t->r, index - cnt(t->l) - 1);
    return t->key;
  }

  index_t find (pnode t, const Key & key) {
    push(t);
    if (!t)
      return size();
    if (!(key < t->key) && !(t->key < key))
      return cnt(t->l);
    if (key < t->key)
      return get(t->l, key);
    else
      return get(t->r, key) + 1 + cnt(t->l);
  }

  index_t last_min (pnode t) {
    /*
    Finds last index where key is minimum of treap rooted at `t`.
    Since infinite key is not guaranteed to exist, `t` must not be `nullptr`.
    */
    push(t);
    if (t->r) {
      push(t->r);
      if (!(t->min_key < t->r->min_key))
        return last_min(t->r) + 1 + cnt(t->l);
    }
    if (!(t->min_key < t->key))
      return cnt(t->l);
    return last_min(t->l);
  }

  index_t first_max (pnode t) {
    /*
    Finds first index where key is maximum of treap rooted at `t`.
    Since infinite key is not guaranteed to exist, `t` must not be `nullptr`.
    */
    push(t);
    if (t->l) {
      push(t->l);
      if (!(t->l->max_key < t->max_key))
        return first_max(t->l);
    }
    if (!(t->key < t->max_key))
      return cnt(t->l);
    return first_max(t->r) + 1 + cnt(t->l);
  }

  // pair< pair<Key, Values>, int>
  std::pair <Key, index_t> lower_bound (pnode t, const Key & key, index_t index) {
    push(t);
    if (!t)
      return {Key(), size()};
    if (!(key < t->key) && !(t->key < key)) {
      if (t->l) {
        push(t->l);
        if (!(t->l->max_key < key))
          return {key, index + first_max(t->l)};
      }
      return {key, index + cnt(t->l)};
    }
    if (key < t->key) {
      std::pair <Key, index_t> ret = lower_bound(t->l, key, index);
      if (ret.second == size())
        ret = {t->key, index + cnt(t->l)};
      return ret;
    }
    return lower_bound(t->r, key, index + 1 + cnt(t->l));
  }

  // pair< pair<Key, Values>, int>
  std::pair <Key, index_t> upper_bound (pnode t, const Key & key, index_t index) {
    push(t);
    if (!t)
      return {Key(), size()};
    if (!(key < t->key) && !(t->key < key)) {
      if (t->r) {
        push(t->r);
        if (!(key < t->r->min_key))
          return {key, index + cnt(t->l) + 1 + last_min(t->r) + 1};
      }
      return {key, index + cnt(t->l) + 1};
    }
    if (key < t->key) {
      std::pair <Key, index_t> ret = upper_bound(t->l, key, index);
      if (ret.second == size())
        ret = {t->key, index + cnt(t->l)};
      return ret;
    }
    return upper_bound(t->r, key, index + 1 + cnt(t->l));
  }

  void shift_keys (pnode & t, index_t l, index_t r, const Key & add) {
    // add to every key with index [l, r)
    pnode l1, r1;
    split_at(t, l1, r1, r);
    pnode l2, r2;
    split_at(l1, l2, r2, l);
    update(r2, add, 0);
    pnode t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
  }

  void reverse (pnode & t, index_t l, index_t r) {
    pnode l1, r1;
    split_at(t, l1, r1, r);
    pnode l2, r2;
    split_at(l1, l2, r2, l);
    update(r2, zero_key(), 1);
    pnode t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
  }

  void move (pnode & t, index_t left, index_t right, index_t shift) {
    // shift indices: [l, r) becomes [l+shift, r+shift)
    if (shift == 0)
      return;
    index_t l = left + std::min(0, shift);
    index_t r = right + std::max(0, shift);
    index_t m = (shift > 0) ? right : left;
    pnode prefix, tmp;
    split_at(root_, prefix, tmp, l);
    pnode suffix, middle;
    split_at(tmp, middle, suffix, r - l);
    pnode mid_prefix, mid_suffix;
    split_at(middle, mid_prefix, mid_suffix, m - l);
    merge(middle, mid_suffix, mid_prefix);
    merge(tmp, middle, suffix);
    merge(root_, prefix, tmp);
  }

  Key get_sum_of_keys (pnode & t, index_t l, index_t r) {
    pnode l1, r1;
    split_at(t, l1, r1, r);
    pnode l2, r2;
    split_at(l1, l2, r2, l);
    Key ret = r2->sum_of_keys;
    pnode t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
    return ret;
  }

  Key get_min_of_keys (pnode & t, index_t l, index_t r) {
    pnode l1, r1;
    split_at(t, l1, r1, r);
    pnode l2, r2;
    split_at(l1, l2, r2, l);
    Key ret = r2->min_of_keys;
    pnode t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
    return ret;
  }

  void clear (pnode & t) {
    if (!t)
      return;
    clear(t->l);
    clear(t->r);
    destroy_node(t);
    t = nullptr;
  }

 public:
  treap (std::mt19937_64 * rng = nullptr) {
    is_sorted_ = true;
    stop_ = false;
    root_ = nullptr;
    if (rng) {
      rng_owner_ = false;
      rng_ = rng;
    }
    else {
      rng_owner_ = true;
      rng_ = new std::mt19937_64;
      rng_->seed(std::chrono::steady_clock::now().time_since_epoch().count());
    }
  }

  ~treap () {
    if (rng_owner_)
      delete rng_;
    clear(root_);
  }

  index_t size () { return cnt(root_); }

  bool empty () { return (cnt(root_) == 0); }

  bool is_sorted () { return is_sorted_; }

  void srand (std::mt19937_64::result_type seed) {
    // optional
    rng_->seed(seed);
  }

  bool insert (Key x) {
    bool eq = false;
    pnode t = create_node(x);
    stop_ = false;
    insert(root_, t, eq);
    while (stop_) {
      stop_ = false;
      eq = false;
      insert(root_, t, eq);
    }
    if (eq)
      destroy_node(t);
    return !eq;
  }

  void insert_at (index_t pos, const Key & x) {
    if (pos > size())
      return;
    pnode t = create_node(x);
    stop_ = false;
    insert_at(root_, t, pos);
    while (stop_) {
      stop_ = false;
      insert_at(root_, t, pos);
    }
    if (pos > 0 && is_sorted_) {
      is_sorted_ = check_key_sortedness(get(root_, pos), get(root_, pos - 1));
    }
    if (pos < size() - 1 && is_sorted_) {
      is_sorted_ = check_key_sortedness(get(root_, pos + 1), get(root_, pos));
    }
  }

  bool erase (Key x) {
    bool found = false;
    erase(root_, x, found);
    return found;
  }

  void erase_at (index_t pos) {
    if (pos >= size())
      return;
    erase_at(root_, pos);
  }

  void clear () {
    clear(root_);
  }

  index_t find (Key key) {
    if (!is_sorted_)
      return size();
    index_t index = find(root_, key);
    if (index > size()) // not found
      index = size();
    return index;
  }

  // pair<Key, Values>
  Key operator[] (index_t index) {
    return get(root_, index);
  }

  // pair< pair<Key, Values>, int>
  std::pair <Key, index_t> lower_bound (Key x) {
    if (!is_sorted_)
      return {Key(), size()};
    return lower_bound(root_, x, 0);
  }

  // pair< pair<Key, Values>, int>
  std::pair <Key, index_t> upper_bound (Key x) {
    if (!is_sorted_)
      return {Key(), size()};
    return upper_bound(root_, x, 0);
  }

  void shift_keys (index_t left, index_t right, Key x) {
    if (left >= right)
      return;
    left = std::max(left, 0);
    right = std::min(right, size());
    shift_keys(root_, left, right, x);
    if (left > 0 && is_sorted_) {
      is_sorted_ = check_key_sortedness(get(root_, left), get(root_, left - 1));
    }
    if (right < size() - 1 && is_sorted_) {
      is_sorted_ = check_key_sortedness(get(root_, right + 1), get(root_, right));
    }
  }

  void reverse (index_t left, index_t right) {
    if (left >= right)
      return;
    left = std::max(left, 0);
    right = std::min(right, size() - 1);
    reverse(root_, left, right);
    is_sorted_ = false;
  }

  void move (index_t left, index_t right, index_t shift) {
    if (left >= right || shift == 0)
      return;
    shift = std::max(shift, -left);
    shift = std::min(shift, size()-right);
    if (left > 0 && right < size() && is_sorted_) {
      is_sorted_ = check_key_sortedness(get(root_, right), get(root_, left - 1));
    }
    move(root_, left, right, shift);
    if (left + shift > 0 && is_sorted_) {
      is_sorted_ = check_key_sortedness(get(root_, left + shift), get(root_, left + shift - 1));
    }
    if (right + shift < size() && is_sorted_) {
      is_sorted_ = check_key_sortedness(get(root_, right + shift), get(root_, right + shift - 1));
    }
  }

  Key get_sum_of_keys (index_t left, index_t right) {
    if (left >= right)
      return zero_key();
    return get_sum_of_keys(root_, left, right);
  }

  Key get_min_of_keys (index_t left, index_t right) {
    if (left >= right)
      return inf_key();
    return get_min_of_keys(root_, left, right);
  }
};  // class treap

}  // namespace treap

#endif  // _TREAP_H

bool solve(auto & X, auto & D, const auto & non_unique) {
	int N = X.size();
	if(N == 1) return true;
	if(non_unique.empty()) return false;
	auto thr = *rbegin(non_unique);
	while(thr < X[N-2]) {
		auto s = X.get_sum_of_keys(0, X.upper_bound(thr).ss);
		int idx = X.upper_bound(s).ss;
		if(idx == N) return true;
		idx--;
		if(X[idx] > thr) {
			thr = X[idx];
			continue;
		}
		if(idx == N-2) return false;
		auto d_mi = D.get_min_of_keys(idx+1, N-1);
		if(d_mi > s) return false;
		thr = X[idx+1];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	cin >> N >> Q;
	treap::treap<cat, true> X;
	treap::treap<cat, true> D;
	set<int> non_unique;
	for(int i = 0; i < N; i++) {
		cat a;
		cin >> a;
		int idx = X.lower_bound(a).ss;
		if(idx != X.size() && X[idx] == a) non_unique.insert(a);
		if(idx < X.size()) D.insert_at(idx, X[idx] - a);
		if(idx > 0) D.insert_at(idx-1, a - X[idx-1]);
		X.insert_at(idx, a);
	}
	cout << (solve(X, D, non_unique) ? "Yes\n" : "No\n");
	for(int q = 0; q < Q; q++) {
		string op;
		cat a;
		cin >> op >> a;
		if(op == "-") {
			int idx = X.lower_bound(a).ss;
			if(X.upper_bound(a).ss - idx == 2) non_unique.erase(a);
			if(idx < X.size()-1) D.erase_at(idx);
			if(idx > 0) D.erase_at(idx-1);
			X.erase_at(idx);
			if(idx > 0 && idx < X.size()) D.insert_at(idx-1, X[idx] - X[idx-1]);
		}
		else {
			int idx = X.lower_bound(a).ss;
			if(idx != X.size() && X[idx] == a) non_unique.insert(a);
			if(idx < X.size()) D.insert_at(idx, X[idx] - a);
			if(idx > 0) {
				D.erase_at(idx-1);
				D.insert_at(idx-1, a - X[idx-1]);
			}
			X.insert_at(idx, a);
		}
		cout << (solve(X, D, non_unique) ? "Yes\n" : "No\n");
	}
}

// look at my code
// my code is amazing