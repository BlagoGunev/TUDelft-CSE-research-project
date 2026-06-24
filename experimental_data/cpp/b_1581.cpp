#include<bits/stdc++.h>

typedef long long ll;

typedef unsigned long long ull;

typedef double dd;

typedef long double ld;

#define endl '\n'

#define pi acos(-1)

#define all(v) v.begin(),v.end()

#define r_all(v) v.rbegin(),v.rend()

#define fix(n) fixed<<setprecision(n)

#define rrt(x)    return cout<<x,0<<endl

#define watch(x) cout << (#x)<<" = "<<x<<endl

#define forn(n) for(int i=0;i<n;i++)

#define forn1(n) for(int i=1;i<=n;i++)

#define dl cout<<endl;

#define sz(x) (int)x.size()

#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define pb push_back

#define F first

#define S second

#define formap(mp) for(auto it : mp)cout<<it.F<<" "<<it.S<<endl;

//#define ceil(x,y) (((x) / (y)) + ((x) % (y) ? 1 : 0))

using namespace std;



ll fpow(ll a,ll p){ll res = 1,x = a;while(p){if(p&1)res = (res*x); x = (x*x);p >>= 1;} return res;}





/*

vector<int>adj[100];

int vis[100],vid;



void DFS(int node)

{

    vis[node] = vid;

    for(auto child : adj[node])

    {

        if(vis[child] != vid){

            DFS(child);

        }

    }

}*/



int main()

{



    Fast;





    int t;cin>>t;

    while(t--){

        ll n,e,k,mn,mx;cin>>n>>e>>k;



        mx = ((n*(n-1))/2);

        if(e > mx || e < n-1){

            cout<<"NO"<<endl;

            continue;

        }

        if(e==0)mn = 0;

        else if(e==1 || e == mx)mn = 1;

        else mn = 2;



        if(mn >= k-1)cout<<"NO"<<endl;

        else cout<<"YES"<<endl;

    }



return 0;

}