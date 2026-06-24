#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
#define all(m) m.begin(), m.end()
using ll = long long;

template<typename T> struct static_sum_query {vector<T> m; static_sum_query() = default; template<typename I>static_sum_query(I f, I l) {m.resize(l - f + 1); for (auto it = m.begin() + 1; f != l; ++f, ++it) {*it = *(it - 1) + *f;}} template<typename T_arr> static_sum_query(T_arr& m) {(*this) = static_sum_query(all(m));} inline T query(const int l, const int r) const {return m[r + 1] - m[l];}};

template<typename T>
class fenwick {
    int n;
    vector<T> fen;

public:
    fenwick() = default;
    fenwick(int n): n(n + 1), fen(n + 1) {}
    template<typename I>
    fenwick(I first, I last): n(last - first + 1), fen(n) {
        auto it = first;
        for (int i = 1; i < n; ++i, ++it) {
            fen[i] += *it;
            const int nw = i + (i & -i);
            if (nw < n) fen[nw] += fen[i];
        }
    }
    template<typename T_arr>
    fenwick(const T_arr& m, typename enable_if<!is_integral_v<T_arr>>::type* = 0) {
        (*this) = fenwick(m.begin(), m.end());
    }

    void clear() {
        fill(fen.begin(), fen.end(), 0);
    }

    void point_add(int p, T x) {
        assert(0 <= p && p < n - 1);
        for (++p; p < n; p += p & -p) fen[p] += x;
    }

    T pref_sum(int p) const {
        assert(-1 <= p && p < n - 1);
        T ans = 0;
        for (++p; p; p -= p & -p) ans += fen[p];
        return ans;
    }

    T suf_sum(int p) const {
        return pref_sum(n - 2) - pref_sum(p - 1);
    }

    T seg_sum(int l, int r) const {
        return pref_sum(r) - pref_sum(l - 1);
    }

    //[1, 2, 3] -> f(0) = -1, f(1) = 0, f(4) = 1, f(6) = 2
    int max_pref_with_sum_leq_k(T k) const {
        int p = 0, step = 1 << __lg(n);
        T s = 0;
        for (; step; step >>= 1) {
            int nw = p + step;
            if (nw < n && s + fen[nw] <= k) p = nw, s += fen[nw];
        }
        return p - 1;
    }

    int max_seg_with_sum_leq_k(int l, T k) {
        assert(0 <= l && l < n - 1);
        T ps = pref_sum(l - 1);
        return max_pref_with_sum_leq_k(k + ps);
    }

    int max_left_seg_with_sum_leq_k(int r, T k) {
        assert(0 <= r && r < n - 1);
        T ps = pref_sum(r);
        if (ps <= k) return 0;
        int u = max_pref_with_sum_leq_k(ps - k);
        // assert(u >= 0);
        T us = pref_sum(u);
        assert(us <= ps - k);
        T rem = ps - us;
        assert(rem >= k);
        if (rem == k) return u + 1;
        return u + 2;
    }
};

int main() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
    int z; cin>>z;
    for (; z--;) {
        ll a, x; cin>>a>>x;
        vector<ll> m(a);
        for (int q = 0; q < a; ++q) {
            cin >> m[q];
        }
        auto kek = static_sum_query<ll>(m.begin(), m.end());
        fenwick<ll> lol(m.begin(), m.end());
        ll o = 0;
        for (int q = 0; q < a; ++q) {
            ll l = q, r = q;
            while (r - l + 1 != a) {
                ll d = r - l + 1;
                if (r + 1 < a) {
                    r = lol.max_seg_with_sum_leq_k(r + 1, kek.query(l, r));
                }
                if (l) {
                    l = lol.max_left_seg_with_sum_leq_k(l - 1, kek.query(l, r));
                }
                if (r - l + 1 == d) break;
            }
            o += r - l + 1 == a;
        }
        cout << o << '\n';
    }
}