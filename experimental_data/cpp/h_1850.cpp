#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds; 
using namespace std;
 
#define pb        push_back
#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
//#define f(i,a,b)  for(long long int i=a;i<b;i++)
#define YES       {cout<<"YES"<<endl; return;}
#define NO        {cout<<"NO"<<endl; return;}
typedef long long int ll;
 
void init(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
}
 
const long long N = 3e5+1;
const long long M= 1e9 + 7;
const long long mod = 998244353;
long long gcd(long long a, long long b)
{
  if(a==0)
  return b;
  return gcd(b%a, a);
}
void dfs(int node, vector<pair<ll, ll>> g[], map<ll, set<ll>> &mp, vector<ll> &vis)
{
  vis[node] = 1;
  for(auto it : g[node])
  {
    ll dist = *mp[node].begin() + it.second;
    mp[it.first].insert(dist);
    if(vis[it.first]==-1)
      dfs(it.first, g, mp, vis);
  }
}
void solve()
{
  long long n, m; cin>>n>>m;
  vector<pair<ll, ll>> g[n+1];
  vector<ll> vis(n+1, -1);
  ll a1,b1,c1;
  for(ll i = 1; i<=m; i++)
  {
    ll a,b,c; cin>>a>>b>>c;
    g[a].push_back({b,c});
    g[b].push_back({a,-c});
    if(i==1)
    {
      a1=a; b1=b; c1=c;
    }
  }
  map<ll, set<ll>> mp;
  mp[a1].insert(0);
  mp[b1].insert(*mp[a1].begin() + c1);
  dfs(a1, g, mp, vis);
  for(int i = 1; i<=n; i++)
  {
    if(vis[i]==-1)
      dfs(i, g, mp, vis);
  }
  int f = 0;
  for(auto it : mp)
  {
    //cout<<it.first<<" ";
    // for(auto i : it.second)
    // {
    //   cout<<i<<" ";
    // }
    // cout<<"\n";
    if(it.second.size()>1)
    {
      f=1; break;
    }
  }
  if(f==0) cout<<"YES\n";
  else cout<<"NO\n";

}
 


int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  init();
  int t; cin>>t;
  for(int i = 1; i<=t; i++){
    solve();
  }

  return 0;
}