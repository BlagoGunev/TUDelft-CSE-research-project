#pragma GCC target("avx2")

#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;



using ll = long long;

const int INF = 1e9 + 10;

const ll inf = 1LL<<60;



using S = pair<int, int>;

using F = pair<int, int>;

S op(S a, S b) {

  return max(a, b);

}

S e() {

  return {0, -1};

}

S mapping(F f, S x) {

  return max(f, x);

}

F composition(F f, F g) {

  return max(f, g);

}

F id() {

  return {0, -1};

}



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

int bsf(unsigned int n) {

#ifdef _MSC_VER

    unsigned long index;

    _BitScanForward(&index, n);

    return index;

#else

    return __builtin_ctz(n);

#endif

}



}



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

    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}

    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {

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

            if (((r >> i) << i) != r) push(r >> i);

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



void solve() {

  int n, m; cin >> n >> m;

  vector<int> v;

  vector<vector<int>> r(m, vector<int>(3));

  for (int i=0; i<m; i++) {

    cin >> r[i][0] >> r[i][1] >> r[i][2];

    v.emplace_back(r[i][1]);

    v.emplace_back(r[i][2]);

    r[i][0]--;

  }

  sort(v.begin(), v.end());

  v.erase(unique(v.begin(), v.end()), v.end());

  auto f = [&](int x) -> int {

    return lower_bound(v.begin(), v.end(), x) - v.begin();

  };

  vector<vector<pair<int, int>>> s(n);

  for (int i=0; i<m; i++) s[r[i][0]].emplace_back(f(r[i][1]), f(r[i][2]));

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v.size());

  vector<pair<int, int>> dp(n);

  for (int i=0; i<n; i++) {

    pair<int, int> ma = {-1, -1};

    for (auto t : s[i]) ma = max(ma, seg.prod(t.first, t.second + 1));

    dp[i] = {ma.first + 1, ma.second};

    for (auto t : s[i]) seg.apply(t.first, t.second+1, {ma.first + 1, i});

  }

  cout << n-seg.all_prod().first << '\n';

  int cur = n-1;

  for (int i=0; i<n; i++) if (dp[i].first == seg.all_prod().first) {

    cur = i;

    break;

  }

  vector<int> w(n);

  while (cur >= 0) {

    w[cur] = 1;

    cur = dp[cur].second;

  }

  for (int i=0; i<n; i++) if (!w[i]) cout << i+1 << " ";

  cout << '\n';

}



int main() {

  ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  // int t; cin >> t;

  /*while (t--)*/ solve();

}