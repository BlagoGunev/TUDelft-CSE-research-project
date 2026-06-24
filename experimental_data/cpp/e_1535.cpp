#include<bits/stdc++.h>

using namespace std;



void __print(int x) {cerr << x;}

void __print(long x) {cerr << x;}

void __print(long long x) {cerr << x;}

void __print(unsigned x) {cerr << x;}

void __print(unsigned long x) {cerr << x;}

void __print(unsigned long long x) {cerr << x;}

void __print(float x) {cerr << x;}

void __print(double x) {cerr << x;}

void __print(long double x) {cerr << x;}

void __print(char x) {cerr << '\'' << x << '\'';}

void __print(const char *x) {cerr << '\"' << x << '\"';}

void __print(const string &x) {cerr << '\"' << x << '\"';}

void __print(bool x) {cerr << (x ? "true" : "false");}



template<typename T, typename V>

void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>

void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>

void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

#else

#define debug(x...)

#endif



#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ll long long

#define pb push_back

#define ff first

#define ss second

#define all(x) x.begin(),x.end()

const int mod=1e9+7;

const int inf = 1e9;

const int N=3e5+9;

int par[N][20];

int c[N];

int a[N];



void solve()

{

    int q;

    cin >> q;

    cin >> a[0] >> c[0];

    for(int i = 0; i < 20; i++) par[0][i] = 0;

    for(int i = 1; i <= q; i++)

    {

        int t;

        cin >> t;

        if(t == 1)

        {

            int p;

            cin >> p >> a[i] >> c[i];

            par[i][0] = p;

            for(int j = 1; j < 20; j++) par[i][j] = par[par[i][j-1]][j-1];

        }

        else 

        {

            int node, w;

            cin >> node >> w;

            ll taken = 0, cost = 0;

            while(w)

            {

                int now = node;

                for(int i = 19; i >= 0; i--)

                {

                    if(a[par[now][i]]) now = par[now][i];

                }

                int mn = min(w,a[now]);

                w -= mn;

                a[now] -= mn;

                taken += mn * 1LL;

                cost +=1LL * mn * c[now];

                if(now == node) break; 

            }

            cout << taken << " " << cost << endl;

        }

    }

}



int32_t main()

{

    IOS;

    int t = 1;

    int ct = 1;

    //cin >> t;

    while(t--) 

    {

       // cout << "Case #" << ct++ <<": " ;     

        solve();

    }



    return 0;

}