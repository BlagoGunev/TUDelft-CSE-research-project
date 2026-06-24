#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200005
int num,num1,head[N],head1[N],vet[N+N],vet1[N+N],nex[N+N],nex1[N+N];
int s,rt,a[N],size[N],vis[N];
inline int read()
{
	char ch=getchar(),last='!'; int ans=0;
	while (ch<'0'||ch>'9') last=ch,ch=getchar();
	while (ch<='9'&&ch>='0') ans=ans*10+ch-48,ch=getchar();
	if (last=='-') ans=-ans;
	return ans;
}
inline void add(int u,int v)
{
	num++;
	vet[num]=v; nex[num]=head[u]; head[u]=num;
}
inline void add1(int u,int v)
{
	num1++;
	vet1[num1]=v; nex1[num1]=head1[u]; head1[u]=num1;
}
void dfs(int u,int fa)
{
	size[u]=1;
	for (int i=head[u]; i; i=nex[i])
	{
		int v=vet[i];
		if (v!=fa) 
		{
			dfs(v,u);
			size[u]+=size[v];
		}
	}
}
void dfs1(int u,int fa)
{
	for (int i=head[u]; i; i=nex[i])
	{
		int v=vet[i];
		if (v==fa) continue;
		if (size[v]&1) add1(u,v);
		else add1(v,u);
		dfs1(v,u);
	}
}
void dfst(int u)
{
	vis[u]=1;
	for (int i=head1[u]; i; i=nex1[i])
	{
		int v=vet1[i];
		if (!vis[v]) dfst(v);
	}
	a[++s]=u;
}
int main()
{
	int n=read();
	for (int i=1; i<=n; i++)
	{
		int x=read();
		if (x==0) rt=i;
		add(x,i); add(i,x);
	}
	if (!(n&1))
	{
		puts("NO");
		return 0;
	}
	dfs(rt,0);
	dfs1(rt,0);
	for (int i=1; i<=n; i++) 
		if (!vis[i]) dfst(i);
	puts("YES");
	for (int i=s; i>=1; i--) printf("%d\n",a[i]);
	return 0;
}