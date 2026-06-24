#include<bits/stdc++.h>
using namespace std;
#define maxn 405
#define int long long
const int mod=998244353;
vector<int> edge[maxn];
int dist[maxn][maxn],ans[maxn][maxn],n,m;
int deg[maxn],len[maxn];
bool check[maxn];
int solve(int i,int j){
    for(int u=1;u<=n;u++) deg[u]=len[u]=-1;
    int num=0;
    for(int u=1;u<=n;u++){
        int d=(dist[u][j]+dist[u][i]-dist[i][j]);
        if(d%2==1) return 0;
        if(d==0) num++;
        d/=2;
        deg[u]=d;
        len[u]=dist[i][u]-d;
    }
    if(num>(dist[i][j]+1)) return 0;
    int res=1;
    for(int u=1;u<=n;u++){
        if(deg[u]==0) continue;
        int cnt=0;
        for(int v:edge[u]){
            if(deg[v]==deg[u]-1 && len[v]==len[u]) cnt++;
        }
        res=(res*cnt)%mod;
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v;cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        queue<int> q;q.push(i);
        for(int j=1;j<=n;j++) dist[i][j]=-1;
        dist[i][i]=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:edge[u]){
                if(dist[i][v]==-1){
                    q.push(v);
                    dist[i][v]=dist[i][u]+1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) ans[i][j]=ans[j][i]=solve(i,j);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
}