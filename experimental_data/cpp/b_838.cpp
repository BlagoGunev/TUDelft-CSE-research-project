#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=2e5+10;
int dfn[maxn],seq[maxn],leave[maxn],vl[maxn];
LL dep[maxn];
vector<pair<int,int> > edl[maxn];
int top=0,n,q;
struct Segment
{
    LL mark,minvl;
} seg[maxn*4];
struct Edge
{
    int u,v,w;
} ed[maxn*2];
void dfs(int x)
{
    seq[++top]=x;
    dfn[x]=top;
    for(int i=0;i<edl[x].size();i++)
    {
        dep[edl[x][i].first]=dep[x]+edl[x][i].second;
        dfs(edl[x][i].first);
    }
    leave[x]=top;
}
inline void update(int x)
{
    seg[x].minvl=min(seg[x<<1].minvl,seg[(x<<1)|1].minvl)+seg[x].mark;
}
inline void pushdown(int x)
{
    seg[x<<1].mark+=seg[x].mark;
    seg[x<<1].minvl+=seg[x].mark;
    seg[(x<<1)|1].mark+=seg[x].mark;
    seg[(x<<1)|1].minvl+=seg[x].mark;
    seg[x].mark=0;
}
void build(int x,int l,int r)
{
    seg[x].mark=0;
    if(l==r)
    {
        seg[x].minvl=dep[seq[l]]+vl[seq[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build((x<<1)|1,mid+1,r);
    update(x);
}
void editdelta(int x,int l,int r,int nowl,int nowr,int d)
{
    if(nowl<=l&&r<=nowr)
    {
        seg[x].mark+=d;
        seg[x].minvl+=d;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(x);
    if(nowl<=mid) editdelta(x<<1,l,mid,nowl,nowr,d);
    if(nowr>mid) editdelta((x<<1)|1,mid+1,r,nowl,nowr,d);
    update(x);
}
void editpoint(int u,int d)
{
    int x=1,l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(u<=mid)
        {
            x<<=1;
            r=mid;
        } else
        {
            x=(x<<1)|1;
            l=mid+1;
        }
    }
    seg[x].minvl+=d;
    while(x>1)
    {
        x>>=1;
        update(x);
    }
}
LL askdep(int u)
{
    LL ret=dep[u];
    u=dfn[u];
    int x=1,l=1,r=n;
    while(l<r)
    {
        ret+=seg[x].mark;
        int mid=(l+r)>>1;
        if(u<=mid)
        {
            x<<=1;
            r=mid;
        } else
        {
            x=(x<<1)|1;
            l=mid+1;
        }
    }
    return ret+seg[x].mark;
}
void editedge(int id,int w)
{
    if(id<=n-1)
    {
        editdelta(1,1,n,dfn[ed[id].v],leave[ed[id].v],w-ed[id].w);
    } else
    {
        editpoint(dfn[ed[id].u],w-vl[ed[id].u]);
        vl[ed[id].u]=w;
    }
    ed[id].w=w;
}
LL askmin(int x,int l,int r,int nowl,int nowr)
{
    if(nowl<=l&&r<=nowr) return seg[x].minvl;
    int mid=(l+r)>>1;
    pushdown(x);
    if(nowr<=mid) return askmin(x+x,l,mid,nowl,nowr);
    if(nowl>mid) return askmin(x+x+1,mid+1,r,nowl,nowr);
    return min(askmin(x+x,l,mid,nowl,nowr),askmin(x+x+1,mid+1,r,nowl,nowr));
}
LL askans(int s,int t)
{
    if(dfn[s]<=dfn[t]&&leave[t]<=leave[s]) return askdep(t)-askdep(s);
    return askmin(1,1,n,dfn[s],leave[s])-askdep(s)+askdep(t);
}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f<0?-x:x;
}
int main()
{
    n=read();q=read();
    for(int i=1;i<=n-1;i++)
    {
        ed[i].u=read();ed[i].v=read();ed[i].w=read();
        edl[ed[i].u].push_back(make_pair(ed[i].v,ed[i].w));
    }
    for(int i=n;i<=2*n-2;i++)
    {
        ed[i].u=read();ed[i].v=read();ed[i].w=read();
        vl[ed[i].u]=ed[i].w;
    }
    dep[1]=0;
    dfs(1);
    build(1,1,n);
    for(int i=1;i<=q;i++)
    {
        int op=read();
        if(op==1)
        {
            int id,w;
            id=read();w=read();
            editedge(id,w);
        } else
        {
            int s,t;
            s=read();t=read();
            cout<<askans(s,t)<<'\n';
        }
    }
    return 0;
}