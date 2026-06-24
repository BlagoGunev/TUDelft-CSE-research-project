#include <bits/stdc++.h>

#include <ext/rope>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")

//#pragma GCC optimize("unroll-loops")

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//#define int long long

#define pb push_back

#define x first

#define fi first

#define y second

#define se second

#define mk(a,b) make_pair(a,b)

#define mp(a,b) make_pair(a,b)

#define rr return 0

#define sqr(a) ((a)*(a))

#define all(a) (a).begin(), (a).end()

#define sz(a) (int)(a).size()

#undef M_PI

#define M_PI 3.14159265358979323846264338327950288419



using namespace std;

using namespace __gnu_cxx;

using namespace __gnu_pbds;



using ll = long long;

using ull = unsigned long long;

using ld = long double;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

using big = __int128;



template<class value, class cmp = less<value> >

using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

template<class value, class cmp = less_equal<value> >

using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

template<class key, class value, class cmp = less<key> >

using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;



/// find_by_order()

/// order_of_key()

mt19937 rng(228);

template<typename T = int>

inline T randll(T l = INT_MIN, T r = INT_MAX) {

    return uniform_int_distribution<T>(l, r)(rng);

}



inline ld randld(ld l = INT_MIN, ld r = INT_MAX) {

    return uniform_real_distribution<ld>(l, r)(rng);

}



const int INF = 2e9 + 11;

const int MOD = 998244353; /// think

const ll LINF = ll(2e18) + 11;



const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};



template<class T> bool umin (T &a, T b) {return a > b ? (a = b, true) : false; }

template<class T> bool umax (T &a, T b) {return a < b ? (a = b, true) : false; }







#ifdef LOCAL

#include "debug.h"

#else

#define debug(...) 42

#endif







inline void test_case () {

    int n, k;

    cin >> n >> k;

    vector <string> a(n);

    for (auto &i : a) {

        cin >> i;

//        i = string(n, '1');

    }

    vector <int> cnt(n + n);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            ++cnt[i - j + n];

        }

    }

    vector <vector <int> > b(n, vector <int> (n));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (cnt[i - j + n] >= k - 1) {

                b[i][j] = !(a[i][j] - '0');

            }

            if (cnt[i - j + n] <= k - 1) {

                b[i][j] = 1;

            }

//            cout << b[i][j];

        }

//        cout << '\n';

    }

    int f = INF;

    vector <pii> st;

    for (int i = n - 1; i >= 0; i--) {

        for (int j = 0; j < n; j++) {

            if (cnt[i - j + n] == k - 1) {

                if (f == INF) {

                    f = i - j;

                }

                if (f == i - j) {

                    st.pb({i, j});

                }

            }

        }

    }

    vector <vector <int> > have(n);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (b[i][j] && cnt[i - j + n] >= k - 1) {

                have[i].pb(j);

            }

        }

    }

//    debug(st);

    for (auto &i : st) {

        int x, y;

        tie(x, y) = i;

//        debug(x, y);

        while (true) {

            if (x < 0) {

                cout << "NO\n";

//                debug(1);

                return;

            }

            b[x][y] = 1;

            int to = y;

            if (!have[x].empty() && have[x].back() > y) {

                to = have[x].back();

            }

            while (!have[x].empty() && have[x].back() >= y) {

                have[x].pop_back();

            }

            while (to > y) {

                b[x][y] = 1;

                ++y;

            }

            if (cnt[x - y + n] == k - 1 && x - y != f) {

                break;

            }

            --x;

        }

//        debug(x, y);

    }

    for (int i = 0; i < n; i++) {

//        debug(have[i]);

        if (!have[i].empty()) {

            cout << "NO\n";

            return;

        }

    }

    cout << "YES\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << b[i][j];

        }

        cout << '\n';

    }

}





main()

{

    ios::sync_with_stdio(0);

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int t = 1;

    cin >> t;

    for (int test = 1; test <= t; test++) {

        test_case();

    }

}