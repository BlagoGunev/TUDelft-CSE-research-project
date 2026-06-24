#include <bits/stdc++.h>
using namespace std;

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

const long long INF = 1e18;
using state = array<long long, 8>;
int n, m;

// b0 ... b2
// b1 ... X

bool get_bit(int mask, int i) {
  return (mask>>i)&1;
}

state all_inf() {
  state ans;
  for (int i = 0; i < 8; i++) {
    ans[i] = INF;
  }
  return ans;
}

state e() {
  state ans = all_inf();
  for (int i = 0; i < 8; i++) {
    if (get_bit(i, 0) == get_bit(i, 2)) ans[i] = 0;
  }
  return ans;
}

state from_unit(int mask) {
  state ans = all_inf();
  for (int i = 0; i < 8; i++) {
    if (get_bit(i, 0) != get_bit(i, 2)) continue;
    ans[i] = 0;
    for (int j: {0, 1}) {
      ans[i] += get_bit(i, j) != get_bit(mask, j);
    }
  }
  return ans;
}

state combine(state a, state b, int c) {
  state ans = all_inf();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      int v = (i^j)&3;
      if (v != 0 && v != 3) continue;
      int k = (i&3)|(j&4);
      ans[k] = min(ans[k], a[i]+b[j]+(get_bit(i, 2) != get_bit(j, 0) ? c : 0));
    }
  }
  return ans;
};

state row_op(state a, state b) {
  return combine(a, b, m);
}

state col_op(state a, state b) {
  return combine(a, b, n);
}

state mapping(int x, state s) {
  state ans;
  if (get_bit(x, 0)) x |= 4;
  for (int i = 0; i < 8; i++) ans[i] = s[i^x];
  return ans;
}

int composition(int x, int y) {
  return x^y;
}

int id() {
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> n >> m >> q;
  string L, R, U, D;
  cin >> L >> R >> U >> D;
  vector<state> initrow(n), initcol(m);
  for (int i = 0; i < n; i++) {
    initrow[i] = from_unit(2*(R[i]=='R')+(L[i]=='R'));
  }
  for (int i = 0; i < m; i++) {
    initcol[i] = from_unit(2*(D[i]=='R')+(U[i]=='R'));
  }

  atcoder::lazy_segtree<state, row_op, e, int, mapping, composition, id> rowtree(initrow);
  atcoder::lazy_segtree<state, col_op, e, int, mapping, composition, id> coltree(initcol);

  auto answer = [&] () {
    long long ans = INF;
    for (int i = 0; i < 8; i++) {
      // flip bits 1 and 2
      int j = 4*get_bit(i, 1)+2*get_bit(i, 2)+get_bit(i, 0);
      ans = min(ans, rowtree.all_prod()[i]+coltree.all_prod()[j]);
    }
    cout << ans << '\n';
  };

  answer();
  while (q--) {
    char side;
    int l, r;
    cin >> side >> l >> r;
    l--;
    if (side == 'L') rowtree.apply(l, r, 1);
    else if (side == 'R') rowtree.apply(l, r, 2);
    else if (side == 'U') coltree.apply(l, r, 1);
    else if (side == 'D') coltree.apply(l, r, 2);
    else assert(0);
    answer();
  }
}