#include <bits/stdc++.h>



using namespace std;

#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#define pb push_back

#define int long long

#define ll long long

#define ld long double



#define rep(i, n) for (ll i=0; i<n; i++)

#define repi(i, n) for (ll i=1; i<=n; i++)



#define repi1(i, n) for (ll i = n; i >=0; i--)

#define mem(v, ha) memset(v, ha, sizeof(v))

#define all(a)  a.begin(), a.end()

#define allr(a)  a.rbegin(), a.rend()

#define CLOCK cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";

typedef vector<ll> vi;

typedef vector<vector<int>> vvi;

typedef vector<pair<ll, ll>> vpi;

typedef vector<char> vc;

#define no cout << "NO\n"

#define yes cout << "YES\n"

#define mp make_pair

#define ff first

#define ss second

const ll MOD = 1e9 + 7;

const ll mod = 998244353 ;



const long double PI = 3.141592653589793238460;

const int inf = (int)(1e18);



template<typename T> istream& operator>>(istream& in, vector<T>& a) {for (auto &x : a) in >> x; return in;};

template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for (auto &x : a) out << x << ' '; return out;};



// auto sum=[&](int use, int y){return use+y;};

// function <void(int)>dfs=[&](int u)  //void is the return type, int is the argument





void solve() {

    int n;

    cin >> n;

    vi a(n);

    vvi ind(n);

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];

        a[i]--;

        ind[a[i]].pb(i);

    }

    vi ans(n + 2, 2 * n);

    for (int i = 0; i < n; i++)

    {

        int beg = -1, mx = 0;

        for (auto l : ind[i])

        {

            mx = max(mx, l - beg);

            beg = l;

        }

        mx = max(mx, n - beg);

        ans[mx] = min(ans[mx], i);

    }

    int mini = 2 * n;

    for (int i = 1; i <= n; i++)

    {

        mini = min(mini, ans[i]);

        if (mini > n)

            cout << -1 << ' ';

        else

            cout << mini + 1 << ' ';

    }

    cout << '\n';

}

int32_t main()

{

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif





    fast_io;

    int T = 1;

    cin >> T;



    while (T--)

    {

        solve();





    }



}