#include<iostream>

#include<iomanip>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

#include<string>

#include<map>

#include<set>

#include<queue>

#include<bitset>

#include<assert.h>

using namespace std;

#define de(x) cout<<#x<<": "<<(x)<<endl;

#define ded(x,y) {cout<<#x<<":"<<endl;for(int o=0;o<=y;++o)cout<<x[o]<<" ";cout<<endl;}

#define dede(x,y,z) {cout<<#x<<":"<<endl;for(int o=0;o<=y;++o){for(int oo=0;oo<=z;++oo)cout<<x[o][oo]<<" ";cout<<endl;}}

#define de2(x) {string o;int oo=x;while(oo)o+=(oo&1)+'0',oo>>=1;reverse(o.begin(),o.end());cout<<#x<<" "<<o<<endl;}

#define OK cout<<"OKOK"<<endl;

#define mem(x,y) memset(x,y,sizeof(x));

#define cpy(x,y) memcpy(x,y,sizeof(x));

#define int long long

#define double long double

const int inf=0x3f3f3f3f3f3f3f3f;

const double eps=1e-9;

const double PI=acos(-1.0);

const int N=110;



int n,m,k;

int a[N];

vector<int> adj[N];

int dis[N][2];



void bfs(int s)

{

    mem(dis,0x3f);

    dis[s][0]=0;

    queue<pair<int,int>> q;

    q.push({s,0});

    while(!q.empty())

    {

        auto [u,id]=q.front();

        q.pop();

        for(int v:adj[u])

        {

            if(dis[v][id^(a[u]!=a[v])]==inf)

            {

                dis[v][id^(a[u]!=a[v])]=dis[u][id]+1;

                q.push({v,id^(a[u]!=a[v])});

            }

        }

    }

}



void work()

{

    cin>>n>>m>>k;

    for(int i=1;i<=n;++i)

        cin>>a[i];

    int u,v;

    for(int i=1;i<=m;++i)

    {

        cin>>u>>v;

        adj[u].push_back(v);

        adj[v].push_back(u);

    }

    int ans=0;

    for(int u=1;u<=n;++u)

    {

        bfs(u);

        for(int v=1;v<=n;++v)

        {

            for(int i=0;i<=k;++i)

                ans=max(ans,min(dis[v][0]+i,dis[v][1]+k-i));

        }

        // if(u==1)de(dis[3][0]);

    }

    cout<<ans<<"\n";

}



signed main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);cout.tie(0);

    // cout<<fixed<<setprecision(9);

    int _=1;

    // cin>>_;

    while(_--)

        work();

    return 0;

}



/*



*/