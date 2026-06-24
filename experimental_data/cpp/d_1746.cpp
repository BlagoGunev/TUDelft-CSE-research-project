#include <bits/stdc++.h>



#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



#define x0 abc

#define y0 ABC

#define x1 abcd

#define y1 ABCD

#define xn abcde

#define yn ABCDE



#define lb lower_bound

#define ub upper_bound



#define in insert

#define er erase



#define fi first

#define se second

#define mp make_pair



#define pb push_back

#define pob pop_back



#define uns unsigned



#define ld long double

#define ll long long



#define cont continue

#define re return



#define endl '\n'



#define fbo find_by_order

#define ook order_of_key



#define MAXLL 9000000000000000000LL

#define MAXINT 2000000000



#define MINLL -9000000000000000000LL

#define MININT -2000000000



#define OUT cout << "-------" << endl;



#define bpc __builtin_popcount

#define bpcll __builtin_popcountll



#define tm qwerty



using namespace std;



using namespace __gnu_pbds;



mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());



typedef tree < pair <ll, ll>, null_type, less < pair <ll, ll> >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;







ld pi = acos(-1.), E = exp(1.);



ll N, M = 1e9 + 7, D = 5000, T, Q;



vector < pair <ll, ll> > adj[250001];



ll a[250001], b[250001], p[250001], dp[250001], n, i, k, ans;



    void dfs(ll v, ll k)

    {

        if (adj[v].empty()) {

            b[v] = 0;



            re;

        }



        b[v] = k % (ll) adj[v].size();



        for (auto to : adj[v]) {

            ans += k / (ll) adj[v].size() * to.se;



            dfs(to.fi, k / (ll) adj[v].size());

        }

    }



    bool comp(pair <ll, ll> a, pair <ll, ll> b)

    {

        if (dp[a.fi] + a.se > dp[b.fi] + b.se)

        re 1;



        re 0;

    }



    void dfs1(ll v)

    {

        dp[v] = 0;



        for (auto to : adj[v]) dfs1(to.fi);



        sort(adj[v].begin(), adj[v].end(), comp);



        ll i;



        for (i = 0; i < b[v]; i++) ans += dp[adj[v][i].fi] + adj[v][i].se;



        for (i = b[v]; i < adj[v].size(); i++) dp[v] = max(dp[v], dp[adj[v][i].fi] + adj[v][i].se);

    }



    void solve()

    {

        cin >> n >> k;



        for (i = 2; i <= n; i++) cin >> p[i];



        for (i = 1; i <= n; i++) cin >> a[i];



        for (i = 1; i <= n; i++) adj[i].clear();



        for (i = 2; i <= n; i++) adj[p[i]].pb({i, a[i]});



        ans = a[1] * k;



        dfs(1, k);



        dfs1(1);



        cout << ans << endl;

    }



int main()

{

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);



    ios::sync_with_stdio(0);

    cin.tie(0);



    cin >> T;



    while (T--) solve();



    re 0;

}