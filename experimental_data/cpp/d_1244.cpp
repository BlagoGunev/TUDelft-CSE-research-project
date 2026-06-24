#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100010
#define inf 9999999999999999
using namespace std;
typedef long long ll;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
ll c[4][maxn];
int a[4];
int head[maxn],nxt[maxn*2],to[maxn*2],tot;
void add(int u,int v)
{
    tot++;
    nxt[tot]=head[u];
    head[u]=tot;
    to[tot]=v;
}
int deg[maxn];
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(deg[i]>2)  return true;
    }
    return false;
}
int book[maxn];
int p[maxn],top;
int s[maxn];
void dfs(int x)
{
    p[++top]=x;
    s[x]=top;
    book[x]=1;
    for(int i=head[x];i;i=nxt[i])
    {
        if(book[to[i]])  continue;
        dfs(to[i]);
    }
}
int find(int x,int y)
{
    if(x>y) swap(x,y);
    if(x==2)  return 1;
    if(x==1&&y==3)  return 2;
    if(x==1&&y==2)  return 3;
}
ll ans=inf;
int ansx[maxn];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)  c[1][i]=read();
    for(int i=1;i<=n;i++)  c[2][i]=read();
	for(int i=1;i<=n;i++)  c[3][i]=read();
    for(int i=1;i<n;i++)
    {
        int q=read(),w=read();
        add(q,w);
        add(w,q);
        deg[w]++;deg[q]++;
    }
    if(check())
    {
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==1)
        {
            dfs(i);
            break;
        }
    }
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i==j)  continue;
            a[1]=i;a[2]=j;a[0]=find(i,j);
            ll tmp=0;
            for(int k=1;k<=n;k++)
            {
                tmp+=c[a[k%3]][p[k]];
            }
            if(tmp<ans)
            {
                ans=tmp;
                for(int k=1;k<=n;k++)  ansx[k]=a[k%3];
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)  printf("%d ",ansx[s[i]]);
    puts("");
    return 0;
}