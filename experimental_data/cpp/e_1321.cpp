#pragma GCC target("avx2")

#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;



using ll = long long;

const int INF = 1e9;

const ll inf = 1LL<<60;





// Range add Range max

using S = ll;

using F = ll;

S op(S a, S b){ return max(a, b); }

S e(){ return -inf; }

S mapping(F f, S x){ return x+f; }

F composition(F f, F g){ return f+g; }

F id(){ return 0LL; }



/*

// Range add Range sum

// init {0LL, 1LL}

struct S {

  ll value;

  ll size;

};

using F = ll;

S op(S a, S b) { return {a.value+b.value, a.size+b.size}; }

S e(){ return {0LL, 0LL}; }

S mapping(F f, S x){ return {x.value + x.size*f, x.size}; }

F composition(F f, F g) { return f+g; }

F id() { return 0LL; }

*/



/*

// Range change Range min

using S = ll;

using F = ll;

S op(S a, S b){ return min(a, b); }

S e(){ return inf; }

S mapping(F f, S x) {

  if (f == -1) return x;

  return f;

}

F composition(F f, F g){

  if (f == -1) return g;

  return f;

}

F id(){ return -1; }

*/



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

  ll n, m, p; cin >> n >> m >> p;

  vector<ll> A(1000010, inf);

  for (int i=0; i<n; i++) {

    ll a, c; cin >> a >> c;

    A[a] = min(A[a], c);

  }

  for (int i=1000000; i>=0; i--) A[i] = min(A[i], A[i+1]);

  vector<ll> B(1000010, inf);

  for (int i=0; i<m; i++) {

    ll a, c; cin >> a >> c;

    B[a] = min(B[a], c);

  }

  for (int i=1000000; i>=0; i--) B[i] = min(B[i], B[i+1]);

  for (auto &c : B) c *= -1;

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(B);

  vector<tuple<ll, ll, ll>> x(p);

  for (int i=0; i<p; i++) {

    ll s, t, u; cin >> s >> t >> u;

    x[i] = {s, t, u};

  }

  sort(x.begin(), x.end());

  ll ans = -(A[0] - B[0]);

  for (int i=0; i<p; i++) {

    ll s = get<0>(x[i]), t = get<1>(x[i]), u = get<2>(x[i]);

    seg.apply(t+1, 1000010, u);

    ans = max(ans, seg.all_prod() - A[s+1]);

    // cout << ans << endl;

  }

  cout << ans << '\n';

}



int main() {

  ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  // int t; cin >> t;

  /*while (t--)*/ solve();

}