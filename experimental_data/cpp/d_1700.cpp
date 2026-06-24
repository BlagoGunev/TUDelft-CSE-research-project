#define popcnt(x) __builtin_popcountll(x)

#define pb push_back

#define be(a) a.begin(), a.end()

#define rbe(a) a.rbegin(), a.rend()

#define L(x, n) for (int x = 0; x < n; ++x)

#define cin(a) for (auto &i : a) cin >> i

#define cout(a, x) for (auto &i : a) cout << i << x; cout << '\n'

#define F first

#define S second

//#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef pair <int, int> pii;

typedef unsigned int ui;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

template <class T> bool ifLess(T &a, T b) {return a < b ? a = b, 1 : 0;};

template <class T> bool ifGreater(T &a, T b) {return a > b ? a = b, 1 : 0;};

template <class T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using pqueue = priority_queue <T, vector <T>, greater <T>>;

//I love my wife - Elizaveta Minchakova



int main() {

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    int n;

    cin >> n;

    int a[n];

    cin(a);

    ll dp[n], s = a[0];

    dp[0] = s;

    for (int i = 1; i < n; ++i) {

        dp[i] = max(dp[i - 1], ((s += a[i]) + i)/(i + 1));

    }

    for (int i = 0; i < n; ++i) {

        ifLess(dp[i], (s + i)/(i + 1));

    }

    reverse(dp, dp + n);

    int q;

    cin >> q;

    while (q--) {

        int t;

        cin >> t;

        int x = n + 1 - (upper_bound(dp, dp + n, t) - dp);

        cout << (x > n ? -1 : x) << '\n';

    }



    return 0;

}