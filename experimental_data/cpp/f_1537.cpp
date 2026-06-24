/*

The 100 2200 rated problem challenge

Date: 7/7/2022

Problem: 1537F (16/100)

Editorial: No

*/

#include <bits/stdc++.h>

#define ll long long

#define rep(i,m,n) for (auto i=m;i<=n;i++)

#define reb(i,m,n) for (auto i=m;i>=n;i--)

#define rv(i,vt) for (auto i:vt)

#define ii pair<ll,ll>

#define vi vector<ll>

#define F first

#define S second

#define pb push_back

using namespace std;

const ll N=1e6+5,mod=1e9+7;

vector<ll> ke[N];

bool biparite;

ll col[N],a[N],b[N],n,m;

void dfs (ll u){

    rv(v,ke[u]) if (col[u]==col[v]) biparite=0;

    else if (!col[v]) col[v]=3-col[u],dfs(v);

}

void solo()

{

    cin>>n>>m;

    ll sum=0;

    rep(i,1,n) cin>>a[i],sum+=a[i];

    rep(i,1,n) cin>>b[i],sum+=b[i],a[i]-=b[i];

    rep(i,1,n) ke[i].clear(),col[i]=0;

    rep(i,1,m){

        ll u,v;

        cin>>u>>v;

        ke[u].pb(v);

        ke[v].pb(u);

    }

    if (sum%2!=0){

        cout<<"NO";

        return;

    }

    biparite=1;

    col[1]=1;

    dfs(1);

    if (!biparite){

        cout<<"YES";

        return;

    }

    ll s1=0,s2=0;

    rep(i,1,n) if (col[i]==1) s1+=a[i];

    else s2+=a[i];

    if (s1==s2) cout<<"YES";

    else cout<<"NO";

}

int main()

{

   ios_base::sync_with_stdio(0);

   cin.tie(0);

   cout.tie(0);

   ll t=1;

   cin>>t;

   while (t--){

       solo();

       cout<<endl;

   }

}