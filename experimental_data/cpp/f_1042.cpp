#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const int inf=1e9;
int gi() {
    int x=0,o=1;char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*o;
}
struct edge { int to,nxt; } e[N<<1];
int tot=0,h[N];
void adde(int u,int v) {
    e[++tot]=(edge){v,h[u]};h[u]=tot;
    e[++tot]=(edge){u,h[v]};h[v]=tot;
}
int n,k,ans=0,f[N],g[N],du[N];
void dfs(int u,int fa) {
    f[u]=-inf;g[u]=du[u]==1?0:-inf;
    for(int i=h[u];i;i=e[i].nxt) {
        int v=e[i].to; if(v==fa) continue;
        dfs(v,u);
        f[u]=max(f[u],f[v]-1);g[u]=max(g[u],g[v]+1);
    }
    if(f[u]>=g[u]) g[u]=-inf;
    else if(g[u]==k) f[u]=k,g[u]=-inf,ans++;
}
int main() {
    cin>>n>>k;int tot=n;
    for(int i=1,u,v;i<n;i++) u=gi(),v=gi(),adde(u,++tot),adde(v,tot),du[u]++,du[v]++;
    dfs(1,0);
    if(g[1]>=0) ans++;
    printf("%d\n",ans);
    return 0;
}