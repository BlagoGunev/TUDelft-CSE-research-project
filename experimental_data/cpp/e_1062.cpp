#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pr pair<int,int>
#define ll long long
using namespace std;
int n,m;
int tot;
int head[100010];
int to[200010];
int nex[200010];
int f[100010];
int son[100010];
int top[100010];
int d[100010];
int size[100010];
int s[100010];
int mn[100010][20];
int mx[100010][20];
int b[100010];
int num;
int l,r;
void add(int x,int y)
{
    tot++;
    nex[tot]=head[x];
    head[x]=tot;
    to[tot]=y;
}
int cmp1(int x,int y)
{
    if(!x||!y)
    {
        return x+y;
    }
    return s[x]<s[y]?x:y;
}
int cmp2(int x,int y)
{
    if(!x||!y)
    {
        return x+y;
    }
    return s[x]>s[y]?x:y;
}
void dfs(int x)
{
    size[x]=1;
    s[x]=++num;
    for(int i=head[x];i;i=nex[i])
    {
        d[to[i]]=d[x]+1;
        dfs(to[i]);
        size[x]+=size[to[i]];
        if(size[to[i]]>size[son[x]])
        {
            son[x]=to[i];
        }
    }
}
void dfs2(int x,int tp)
{
    top[x]=tp;
    if(son[x])
    {
        dfs2(son[x],tp);
    }
    for(int i=head[x];i;i=nex[i])
    {
        if(to[i]!=son[x])
        {
            dfs2(to[i],to[i]);
        }
    }
}
int lca(int x,int y)
{
    if(!x||!y)
    {
        return x+y;
    }
    while(top[x]!=top[y])
    {
        if(d[top[x]]<d[top[y]])
        {
            swap(x,y);
        }
        x=f[top[x]];
    }
    return d[x]<d[y]?x:y;
}
int fmin(int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    int len=b[r-l+1];
    return cmp1(mn[l][len],mn[r-(1<<len)+1][len]);
}
int fmax(int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    int len=b[r-l+1];
    return cmp2(mx[l][len],mx[r-(1<<len)+1][len]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&f[i]);
        add(f[i],i);
    }
    dfs(1);
    dfs2(1,1);
    for(int i=2;i<=n;i++)
    {
        b[i]=b[i>>1]+1;
    }
    for(int i=1;i<=n;i++)
    {
        mn[i][0]=mx[i][0]=i;
    }
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i<=n-(1<<j)+1;i++)
        {
            mn[i][j]=cmp1(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
            mx[i][j]=cmp2(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        }
    }
    while(m--)
    {
        scanf("%d%d",&l,&r);
        int x=fmin(l,r);
        int y=fmax(l,r);
        int lx=fmin(l,x-1);
        int rx=fmin(x+1,r);
        int ans=0;
        int res=0;
        ans=lca(cmp1(lx,rx),y);
        int ly=fmax(l,y-1);
        int ry=fmax(y+1,r);
        res=lca(cmp2(ly,ry),x);
        if(d[ans]>d[res])
        {
            printf("%d %d\n",x,d[ans]);
        }
        else
        {
            printf("%d %d\n",y,d[res]);
        }
    }
}