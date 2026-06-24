#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define pb push_back

#define all(a) a.begin(),a.end()

#define rall(a) a.rbegin(),a.rend()

#define mod (int)(1e8)

#define log(x) (31^__builtin_clz(x)) // Easily calculate log2 on GNU G++ compilers

int d[200001],df[200001];bool vis[200001],blocked[200001];int ans=0;vector<int> adj[200001];

int dfs(int node)

{vis[node]=1;

if(df[node]==0){blocked[node]=1;return d[node];}

int mn=1e9;

for(int i=0;i<adj[node].size();i++)

{if(!vis[adj[node][i]]){mn=min(mn,dfs(adj[node][i]));}}

if(mn-d[node]<=d[node]){blocked[node]=1;}

return mn;

}

void dfs2(int node)

{vis[node]=1;if(blocked[node]&&node!=1){ans++;return;}

for(int i=0;i<adj[node].size();i++)if(!vis[adj[node][i]])dfs2(adj[node][i]);

return;

}

int main()

{ios_base::sync_with_stdio(0),cin.tie(0);

int t;cin>>t;

while(t--)

{int k,n;cin>>n>>k;for(int i=1;i<=n;i++){d[i]=-1;df[i]=-1;}for(int i=0;i<=n;i++){vis[i]=0;blocked[i]=0;adj[i].resize(0);}

ans=0;

queue<int> q;d[1]=0;

for(int i=0;i<k;i++){int c;cin>>c;df[c]=0;q.push(c);}

for(int i=0;i<n-1;i++){int u,v;cin>>u>>v;adj[u].pb(v);adj[v].pb(u);}

while(!q.empty())

{int u=q.front();q.pop();

for(int i=0;i<adj[u].size();i++)if(df[adj[u][i]]==-1){df[adj[u][i]]=df[u]+1;q.push(adj[u][i]);}}

q.push(1);

while(!q.empty())

{int u=q.front();q.pop();

for(int i=0;i<adj[u].size();i++)if(d[adj[u][i]]==-1){d[adj[u][i]]=d[u]+1;q.push(adj[u][i]);}}

bool can=0;for(int i=2;i<=n;i++){if(adj[i].size()==1&&d[i]<df[i]){can=1;break;}}

if(can){cout<<-1<<'\n';

continue;

}

dfs(1);

for(int i=1;i<=n;i++){vis[i]=0;}

dfs2(1);

cout<<ans<<'\n';

}





 return 0;

}

/*





*/