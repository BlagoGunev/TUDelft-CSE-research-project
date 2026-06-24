#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mo 1000000007
using namespace std;
int c[300005],f[300005],a[300005],t,ans,u,v,head[300005],to[600005],nxt[600005],head2[500005],to2[1000006],nxt2[1000006],num,num2,vis[300005],nownum,p;
void un(int u,int v)
{
    nxt[++num]=head[u];
    head[u]=num;
    to[num]=v;
}
void add(int x,int y)
{
    nxt2[++num2]=head2[x];
    head2[x]=num2;
    to2[num2]=y;
}
void dfs(int now)
{
    vis[now]=1;
    nownum=0; 
	p=1;
    for(int i=head2[now];i;i=nxt2[i])
    {
        a[++nownum]=to2[i];
        if(c[to2[i]]) f[c[to2[i]]]=1;
    }
    for(int i=head2[now];i;i=nxt2[i])
    if(!c[to2[i]])
    {
        while(f[p]) p++;
        c[to2[i]]=p;
        f[p]=1;
        ans=max(ans,p);
    }

    for(int i=head2[now];i;i=nxt2[i])
    {
        f[c[to2[i]]]=0;
    }
    for(int i=head[now];i;i=nxt[i])
        if(!vis[to[i]])
        dfs(to[i]);

}
int main(){
	ans=1;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&t);
        for(int j=1;j<=t;++j)
        {
            int tt;
            scanf("%d",&tt);
            add(i,tt);
        }
    }
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&u,&v);
        un(u,v); un(v,u);
    }
    dfs(1);
    cout<<ans<<endl;
    for(int i=1;i<=m;++i) printf("%d ",c[i]==0?1:c[i]);

    return 0;
}