#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
const int maxn=1e5+10;
int fa[maxn];
double sump[maxn],p[maxn],dp[maxn];
int n;

struct Edge
{
    int to,nxt;
} ed[maxn*2];
int last[maxn];
int tot=0;
void adde(int u,int v)
{
    ed[++tot].to=v;
    ed[tot].nxt=last[u];
    last[u]=tot;
}
void dfs(int x,int f)
{
    sump[x]=0;
    dp[x]=0;
    for(int i=last[x];i>0;i=ed[i].nxt) if(ed[i].to!=f)
    {
        fa[ed[i].to]=x;
        dfs(ed[i].to,x);
        dp[x]+=dp[ed[i].to];
        sump[x]+=p[ed[i].to];
    }
    dp[x]+=p[x]*(1-sump[x]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {scanf("%lf",&p[i]);p[i]=1-p[i];}
    for(int i=1;i<n;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ++u;++v;
        adde(u,v);adde(v,u);
    }
    dfs(1,0);
    double ans=dp[1];
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;++i)
    {
        int u;
        double newp;
        scanf("%d%lf",&u,&newp);
        newp=1-newp;
        ++u;
        if(fa[u]==0) ans+=(1-sump[u])*(newp-p[u]);
        else ans+=(1-sump[u])*(newp-p[u])-p[fa[u]]*(newp-p[u]);
        if(fa[u]>0) sump[fa[u]]+=newp-p[u];
        p[u]=newp;
        printf("%f\n",ans);
    }
    return 0;
}