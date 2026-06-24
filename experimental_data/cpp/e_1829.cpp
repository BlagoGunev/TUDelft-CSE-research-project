#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pdd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef vector<vector<pl> > vvpl;
typedef vector<pl> vpl;
typedef vector<pair<pl,ll>> vppl;
typedef vector<pi> vpi;
typedef map<int,int> mi;
typedef map<ll,ll> ml;
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define forrn(i,s) for(int i = s; i >= 0; i--)
#define forrns(i,s,e) for(int i = s; i >= e; i--)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size()) 



ll dfs(vvl &a, vvl &visited, ll i, ll j, ll n, ll m){
    if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || a[i][j] == 0)
        return 0;
    
    visited[i][j] = 1;
    ll ans = a[i][j];
    ans += dfs(a, visited, i+1, j, n, m);
    ans += dfs(a, visited, i-1, j, n, m);
    ans += dfs(a, visited, i, j+1, n, m);
    ans += dfs(a, visited, i, j-1, n, m);

    return ans;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vvl a(n, vl(m));
    forn(i, n){
        forn(j, m){
            cin >> a[i][j];
        }
    }

    vvl visited(n, vl(m, 0));
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && a[i][j] != 0){
                ans = max(ans, dfs(a, visited, i, j, n, m));
            }
        }
    }

    cout<<ans<<endl;
}

int main()
{
    fast_cin();
    ll t;
    // t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}