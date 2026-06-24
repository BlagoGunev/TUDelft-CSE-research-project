#include <bits/stdc++.h>



//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

//using namespace __gnu_pbds;



using ll = long long;

using ld = long double;



//#define int ll

#define pii pair <int, int>

#define pll pair <ll, ll>

#define pcc pair <char, char>

#define all(v) v.begin(), v.end()

#define rall(v) v.rbegin(), v.rend()

#define pb push_back

#define in insert

#define MP make_pair

#define sz(s) (int)s.size()

#define inf 1e9

#define infll 4e18



//typedef tree<int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;



void solve()

{

    int n, q;

    cin >> n >> q;

    vector <int> a(n, ~(1 << 30));

    vector <vector <pii>> g(n);

    for(int i = 0; i < q; i++)

    {

        int u, v, x;

        cin >> u >> v >> x;

        u--, v--;

        a[u] &= x;

        a[v] &= x;

        g[v].pb(pii(u, x));

        g[u].pb(pii(v, x));

    }

    for(int i = 0; i < n; i++)

    {

        int w = 0;

        for(auto now : g[i])

        {

            if(now.first == i)

            {

                w = now.second;

                continue;

            }

            w |= now.second & ~a[now.first];

        }

        a[i] = w;

        cout << a[i] << " ";

    }

    return;

}



signed main()

{

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int t = 1;

    //cin >> t;

    while(t--)

        solve();

    return 0;

}