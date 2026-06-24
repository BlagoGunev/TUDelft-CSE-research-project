#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f<0?-x:x;
}
const int maxnode=15000000,maxn=1e5+10;
typedef long long LL;
struct segment
{
    int ls,rs;
    LL sum;
} seg[maxnode];
int tot=0;
int root[maxn],last[maxn],a[maxn];
int n,m;
set<int> ls[maxn];
void edit(int& x,int l,int r,int p,int v)
{
    if(x==0) x=++tot;
    seg[x].sum+=v;
    if(l<r)
    {
        int mid=(l+r)>>1;
        if(p<=mid) edit(seg[x].ls,l,mid,p,v);
        else edit(seg[x].rs,mid+1,r,p,v);
    }
}
LL ask(int x,int l,int r,int nowl,int nowr)
{
    if((nowl<=l&&r<=nowr)||x==0) return seg[x].sum;
    int mid=(l+r)>>1;
    LL ret=0;
    if(nowl<=mid) ret+=ask(seg[x].ls,l,mid,nowl,nowr);
    if(nowr>mid) ret+=ask(seg[x].rs,mid+1,r,nowl,nowr);
    return ret;
}

LL query(int k1,int nowl,int nowr)
{
    LL ret=0;
    while(k1>0)
    {
        ret+=ask(root[k1],1,n,nowl,nowr);
        k1-=k1&(-k1);
    }
    return ret;
}
void modify(int k1,int p,int v)
{
    while(k1<=n)
    {
        edit(root[k1],1,n,p,v);
        k1+=k1&(-k1);
    }
}
void rem(int p,int x)
{
    set<int>::iterator it=ls[x].find(p);
    int pre=0,nxt=0;
    if(it!=ls[x].begin())
    {
        pre=*(--it);
        modify(pre,p,pre-p);
        ++it;
    }
    //cout<<":::"<<*(ls[x].rend())<<endl;
    if(it!=--ls[x].end())
    {
        nxt=*(++it);
        modify(p,nxt,p-nxt);
        --it;
    }
    if(pre>0&&nxt>0) modify(pre,nxt,nxt-pre);
    ls[x].erase(p);
}
void ins(int p,int x)
{
    a[p]=x;
    ls[x].insert(p);
    set<int>::iterator it=ls[x].find(p);
    int pre=0,nxt=0;
    if(it!=ls[x].begin())
    {
        pre=*(--it);
        modify(pre,p,p-pre);
        ++it;
    }
    if(it!=--ls[x].end())
    {
        nxt=*(++it);
        modify(p,nxt,nxt-p);
        --it;
    }
    if(pre>0&&nxt>0) modify(pre,nxt,pre-nxt);
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(last[a[i]]>0) modify(last[a[i]],i,i-last[a[i]]);
        last[a[i]]=i;
        ls[a[i]].insert(i);
    }
    for(int i=1;i<=m;i++)
    {
        int op=read();
        if(op==1)
        {
            int p=read(),x=read();
            rem(p,a[p]);
            ins(p,x);
            a[p]=x;
        } else
        {
            int l=read(),r=read();
            cout<<query(n,1,r)-query(l-1,1,r)<<'\n';
        }
    }
    return 0;
}