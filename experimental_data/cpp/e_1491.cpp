#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()

#define sc(x) scanf("%d",&x)

#define scl(x) scanf("%lld",&x)

#define LL long long

#define LD long double

#define pb push_back

#define F first

#define S second

const double PI=3.1415926535897932384626433;

const int KL=1e6+10;

const LL MOD=1e9+7;

using namespace std;



int n,m,ans,q,k,a[KL],x,y,fib[KL],Sz[KL],tot;

bool leaf[KL],isfib[KL];

vector <int> adj[KL];

vector <pair<pair<int,int>,int>> cap;



void dfs(int node,int pr){

    Sz[node]=1;

    for(auto v:adj[node]){

        if(v==pr)continue;

        if(leaf[v])continue;



        dfs(v,node);

        if(isfib[Sz[v]] && isfib[tot-Sz[v]])cap.pb({{v,node},Sz[v]});

        Sz[node]+=Sz[v];



    }

}



bool solve(int root,int pr,int sz){

    if(sz<=3)return 1;

    if(!isfib[sz])return 0;

    tot=sz;

    cap.clear();

    dfs(root,pr);

    vector <pair<pair<int,int>,int>> cut=cap;

    ///cout<<root<<" "<<pr<<" "<<sz<<endl;

    /// for(auto v:cut)cout<<v.F.F<<" "<<v.F.S<<" "<<v.S<<" A "<<endl;



    if((int)cut.size()==0)return 0;

    bool ok=false;

    for(auto v:cut){

        leaf[v.F.F]=1;

        if(solve(root,pr,sz-v.S) && solve(v.F.F,v.F.S,v.S)){ok=1;break;}

        leaf[v.F.F]=0;

        break;

    }

    return ok;



}





int main(){

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    fib[0]=fib[1]=1;

    for(int i=2;i<=27;i++)fib[i]=fib[i-1]+fib[i-2];

    for(int i=1;i<=27;i++)isfib[fib[i]]=1;



    cin>>n; m=n-1;

    while(m--){

        cin>>x>>y;

        adj[x].pb(y);

        adj[y].pb(x);

    }

    if(solve(1,0,n))cout<<"YES\n";

    else cout<<"NO\n";



    return 0;

}