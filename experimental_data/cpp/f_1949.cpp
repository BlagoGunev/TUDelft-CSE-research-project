#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Source: ecnerwala
// Templates for Policy Based Data Structures
struct splitmix64_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
      std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

using namespace __gnu_pbds;
template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, null_type, Hash>;

template <class T, class Compare = less<>>
using ordered_set =
tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;


// Source: tourist
// Tested on: ARC 81 D
// Fast string hashing using Mersenne prime 2^61-1
struct Hash {
  static const uint64_t md = (1LL << 61) - 1;
  static uint64_t step;
  static vector<uint64_t> pw;

  uint64_t addmod(uint64_t a, uint64_t b) const {
    a += b;
    if (a >= md) a -= md;
    return a;
  }

  uint64_t submod(uint64_t a, uint64_t b) const {
    a += md - b;
    if (a >= md) a -= md;
    return a;
  }

  uint64_t mulmod(uint64_t a, uint64_t b) const {
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret =
      (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & md) + (ret >> 61);
    ret = (ret & md) + (ret >> 61);
    return ret - 1;
  }

  void ensure_pw(int sz) {
    int cur = (int)pw.size();
    if (cur < sz) {
      pw.resize(sz);
      for (int i = cur; i < sz; i++) {
        pw[i] = mulmod(pw[i - 1], step);
      }
    }
  }

  vector<uint64_t> pref;
  int n;

  template <typename T>
    Hash(const T& s) {
      n = (int)s.size();
      ensure_pw(n + 1);
      pref.resize(n + 1);
      pref[0] = 1;
      for (int i = 0; i < n; i++) {
        pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
      }
    }

  inline uint64_t operator()(const int from, const int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
  }
};
mt19937 rng(
  (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
uint64_t Hash::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> Hash::pw = vector<uint64_t>(1, 1);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int B = 512;
  using bs = bitset<1000007>;
  int n, m;
  cin >> n >> m;
  vector<uint64_t> hashes(n);
  vector<hash_set<int>> h(n);
  vector<int> len(n);
  vi heavy_idx(n, -1), is_heavy_inv;
  vector<bool> is_heavy(n);
  int heavy_ptr = 0;
  vector<bs> sets;
  vector<vi> g(m+1);
  rep(i, 0, n) {
    cin >> len[i];
    if (len[i] == 0) continue;
    if (len[i] > B) {
      is_heavy[i] = 1;
      heavy_idx[i] = heavy_ptr++;
      is_heavy_inv.push_back(i);
    }
    vi a(len[i]);
    for (auto& x : a) {
      cin >> x;
      h[i].insert(x);
      g[x].push_back(i);
    }
    hashes[i] = Hash(a)(0, sz(a) - 1);
    if (is_heavy[i]) {
      bs b;
      for (auto& x : a)
        b.set(x, 1);
      sets.push_back(b);
    }
  }

  // is i a subset of j?
  vector<vi> is_subset(heavy_ptr, vi(heavy_ptr));
  rep(i, 0, heavy_ptr) {
    rep(j, i+1, heavy_ptr) {
      if (i != j) {
        int ilen = len[is_heavy_inv[i]], jlen = len[is_heavy_inv[j]];
        if (hashes[i] == hashes[j]) {
          is_subset[i][j] = is_subset[j][i] = 1;
        } else if (ilen > jlen) {
          is_subset[j][i] = ((sets[i]&sets[j]) == sets[j]);
        } else if (ilen < jlen) {
          is_subset[i][j] = ((sets[i]&sets[j]) == sets[i]);
        }
      }
    }
  }

  auto check = [&](int i, int j) ->bool {
    if (len[i] == len[j]) {
      return hashes[i] == hashes[j];
    }
    if (len[i] > len[j]) swap(i, j);
    if (!is_heavy[i]) {
      for (auto& x : h[i]) {
        if (h[j].find(x) == h[j].end()) return false;
      }
      return true;
    } else {
      return is_subset[heavy_idx[i]][heavy_idx[j]];
    }
  };

  rep(i, 0, m) {
    if (sz(g[i]) == 0) continue;
    sort(all(g[i]), [&](int x, int y)->bool {
      return len[x] < len[y];
    });
    rep(j, 0, sz(g[i]) - 1) {
      int x = g[i][j], y = g[i][j+1];
      if (!check(x, y)) {
        cout << "YES\n";
        cout << x+1 << " " << y+1 << '\n';
        return 0;
      }
    }
  }
  cout << "NO\n";
}