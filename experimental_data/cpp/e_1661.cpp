#include <bits/stdc++.h>

#include <cstdlib>

using namespace std;

#define sz(x) int(size(x))

#define rep(a,b,c) for (int a = (b); a < (c); a++)

#define all(x) begin(x),end(x)

using ll = long long;

using vi = vector<int>;

using pii = pair<int, int>;



// template <class T>

// struct BIT {

//     vector<T> s;

//     int n;

//     BIT(int n): s(n + 1), n(n) {}

//     void update(int i, T v) {

//         for (i++; i <= n; i += i & -i) s[i] += v;

//     }

//     T query(int i) {

//         T ans = 0;

//         for (; i; i -= i & -i) ans += s[i];

//         return ans;

//     }

// };



struct ST {

    int n;

    int* t;

    ST(int n): n(n), t((int*)calloc(4*n, sizeof(int))) {}

    void update(int i, int x, int v = 1, int lo = 0, int hi = 0) {

        __builtin_prefetch(t + v * 16);

        hi = hi ?: n;

        t[v] += x;

        if (lo + 1 == hi) return;

        int mid = (lo + hi) / 2;

        if (i < mid) update(i, x, 2*v, lo, mid);

        else update(i, x, 2*v+1, mid, hi);

    }

    int query(int i, int v = 1, int lo = 0, int hi = 0) {

        __builtin_prefetch(t + v * 16);

        hi = hi ?: n;

        if (hi <= i) return t[v];

        if (i <= lo) return 0;

        int mid = (lo + hi) / 2;

        return query(i, 2*v, lo, mid) + query(i, 2*v+1, mid, hi);

    }

};



void solve() {

    int n;

    cin >> n;

    vi a(n);

    for (int j = 0; j < 3; j++) {

        string s;

        cin >> s;

        for (int i = 0; i < n; i++) a[i] = (a[i] << 1) | (s[i] - '0');

    }

    int q;

    cin >> q;

    vi ans(q);

    vector<vector<pii>> qs(n);

    for (int i = 0; i < q; i++) {

        int l, r;

        cin >> l >> r;

        qs[l-1].emplace_back(r, i);

    }



    vi stk;

    ST bit(n);

    for (int i = n-1; i >= 0; i--) {

        if (a[i] == 0b101) {

            if (!stk.empty() && (a[i] & a[stk.back()]) == 0b101) {

                bit.update(stk.back(), -2);

                if (a[stk.back()] == 0b101)

                stk.pop_back();

            }

            else if (!stk.empty() && (a[i] & a[stk.back()])) {

                bit.update(stk.back(), -1);

                stk.clear();

            }

            bit.update(i, 2);

            stk.push_back(i);

        }

        else if (a[i] == 0b111) {

            if (!stk.empty() && a[stk.back()] == 0b101) {

                bit.update(stk.back(), -2);

                stk.pop_back();

                if (!stk.empty() && a[stk.back()] == 0b111) {

                    bit.update(stk.back(), 1);

                    stk.pop_back();

                }

            }

            else if (!stk.empty() && (a[i] & a[stk.back()])) {

                bit.update(stk.back(), -1);

                stk.clear();

            }

            bit.update(i, 1);

            stk.push_back(i);

        }

        else if (a[i]) {

            if (!stk.empty() && (a[i] & a[stk.back()]))

                bit.update(stk.back(), -1);

            bit.update(i, 1);

            stk = {i};

        }

        else stk.clear();



        for (auto [r, qi] : qs[i])

            ans[qi] = bit.query(r);

    }



    for (int i : ans) cout << i << "\n";

}



int main() {

    cin.tie(0)->sync_with_stdio(0);

    cin.exceptions(cin.failbit);



    // int t; cin >> t; while (t--)

    solve();



    return 0;

}