#include <bits/stdc++.h>



    using namespace std;

    #define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

    #define pb push_back

    #define int long long

    #define ll long long

    #define ld long double



    #define rep(i, n) for (ll i=0; i<n; i++)

    #define rep1(i, n) for (ll i = n - 1; i >= 0; i--)

    #define repi(i, n) for (ll i = 1; i <= n; i++)

    #define repi1(i, n) for (ll i = n; i >=0; i--)

    #define mem(v, ha) memset(v, ha, sizeof(v))

    #define all(a)  a.begin(), a.end()

    #define allr(a)  a.rbegin(), a.rend()

    #define CLOCK cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

    typedef vector<ll> vi;

    typedef vector<vector<int>> vvi;

    typedef vector<pair<ll, ll>> vpi;

    typedef vector<char> vc;

    #define no cout << "No\n"

    #define yes cout << "Yes\n"

    #define mp make_pair

    #define ss second

    const ll M = 1e9 + 7;

    const ll mod = 998244353 ;



    const long double PI = 3.141592653589793238460;

    const int inf = (int)(1e9);



    // auto sum=[&](int use, int y){return use+y;};

    // function <void(int)>dfs=[&](int u)  //void is the return type, int is the argument

  int b[200005];

    void solve()

    {

       int n, k, m;

        cin >> n >> k >> m;

        for(int i=1;i<=m;i++)

            cin >> b[i];

        if((n - m) % (k - 1)) {

            cout << "NO" << '\n';

            return;

        }

        bool ok = false;

        for(int i=1;i<=m;i++)

            if(b[i] - 1 - (i - 1) >= (k - 1) / 2 && (n - b[i]) - (m - i) >= (k - 1) / 2)

                ok = true;

        if(ok)

            cout << "YES" << '\n';

        else

            cout << "NO" << '\n';

       



    }





    int32_t main()

    {





        fast_io;

        int T = 1;

         cin >> T;

        while (T--)

        {

            solve();





        }



    }