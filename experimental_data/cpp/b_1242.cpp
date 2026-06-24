#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<queue>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pa pair<int,int>
#define ll long long
#define inf 1000000000
#define mod 1000000007
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,ans,cnt;
struct edge{int to,nxt;}e[200005];
int q[100005];
int pre[100005],nxt[100005],last[100005];
int belong[100005];
bool vis[100005],t[100005];
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].nxt=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].nxt=last[v];last[v]=cnt;
}
void del(int x)
{
	int t=pre[x];
	nxt[t]=nxt[x];
	pre[nxt[x]]=t;
}
void bfs(int x)
{
	int head=0,tail=1;
	q[0]=x;
	while(head!=tail)
    {
        int now=q[head];head++;
        for(int i=last[now];i;i=e[i].nxt)t[e[i].to]=1;
        for(int i=nxt[0];i<=n;i=nxt[i])
            if(!t[i])
                del(i),q[tail++]=i;
        for(int i=last[now];i;i=e[i].nxt)t[e[i].to]=0;
    }
}
int main()
{
	n=read();m=read();
	for(int i=0;i<=n;i++)nxt[i]=i+1;
	for(int i=1;i<=n+1;i++)pre[i]=i-1;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		insert(u,v);
	}
	for(int i=nxt[0];i<=n;i=nxt[0])
		del(i),ans++,bfs(i);
	printf("%d\n",ans - 1);
	return 0;
}