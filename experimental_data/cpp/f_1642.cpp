#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define fr first

#define sc second

#define endl '\n'

#define pb push_back

#define sz(x) (int)((x).size())

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define bpw(x) (1ll << (x))

#define bcnt(x) __builtin_popcount((x))



#pragma GCC optimize ("-O3")

#pragma GCC optimize ("unroll-loops")

#pragma GCC target ("avx,avx2,sse,sse2,sse3,sse4,tune=native,popcnt")



using namespace std;

using namespace __gnu_pbds;



typedef long long ll;

typedef unsigned long long ull;

typedef pair <int, int> pii;

typedef long double ld;



template <typename T> inline bool umax (T &a, const T &b) { return (a < b ? a = b, 1 : 0); }

template <typename T> inline bool umin (T &a, const T &b) { return (a > b ? a = b, 1 : 0); }



template <typename T>

using oset = tree<T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;



const int N = 1e5 + 5;

const int M = 6;

const int buben = 1000;



bitset <N> fat[N / buben + 5];



signed main()

{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    vector <pair <int, vector <int>>> a (n);

    vector <int> cmp;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            int x; cin >> x;

            a[i].sc.pb(x);

            cmp.pb(x);

        }

        cin >> a[i].fr;

    }

    sort(all(a)); sort(all(cmp)); cmp.erase(unique(all(cmp)), cmp.end());

    for (auto &[w, vec] : a) {

        for (auto &j : vec) j = lower_bound(all(cmp), j) - cmp.begin();

    }

    vector <vector <int>> pos (sz(cmp));

    for (int i = 0; i < n; i++) { /// sorted order

        for (auto j : a[i].sc) pos[j].pb(i);

    }

    vector <int> uk (sz(cmp), -1);

    int UK = 0;

    for (int i = 0; i < sz(cmp); i++) {

        if (sz(pos[i]) >= buben) {

            uk[i] = UK++;

            for (auto j : pos[i]) fat[uk[i]][j] = 1;

        }

    }

    int ans = INT_MAX;

    bitset <N> br;

    for (int i = 0; i < n; i++) {

        br.reset();

        for (auto j : a[i].sc) {

            if (sz(pos[j]) >= buben) {

                br |= fat[uk[j]];

            }

            else {

                for (auto j : pos[j]) br[j] = 1;

            }

        }

        br.flip(); int bst = br._Find_first();

        if (bst < n) umin(ans, a[i].fr + a[bst].fr);

    }

    if (ans == INT_MAX) ans = -1;

    cout << ans;

    return 0;

}