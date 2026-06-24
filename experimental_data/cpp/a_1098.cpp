#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200010
#define inf 1000000010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,p[N],fa[N],a[N],s[N],t,ans;
bool flag=1;
struct data{int to,nxt;
}edge[N];
void addedge(int x,int y){t++;edge[t].to=y,edge[t].nxt=p[x],p[x]=t;}
void dfs(int k)
{
	if (!flag) return;
	for (int i=p[k];i;i=edge[i].nxt)
	{
		int x=edge[i].to,son=0;
		for (int j=p[x];j;j=edge[j].nxt) son++;
		if (son==0) a[x]=0;
		else
		{
			int y=inf;
			for (int j=p[x];j;j=edge[j].nxt)
			y=min(y,s[edge[j].to]);
			if (y<s[k]) {flag=0;break;}
			a[x]=y-s[k];s[x]=s[k]+a[x];
			for (int j=p[x];j;j=edge[j].nxt)
			a[edge[j].to]=s[edge[j].to]-s[x],dfs(edge[j].to);
		}
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	const char LL[]="%I64d\n";
#endif
	n=read();
	for (int i=2;i<=n;i++)
	{
		int x=read();fa[i]=x;addedge(x,i);
	}
	for (int i=1;i<=n;i++) s[i]=read();
	a[1]=s[1];dfs(1);
	if (flag)
	{
		ll ans=0;
		for (int i=1;i<=n;i++) ans+=a[i];
		cout<<ans;
	}
	else cout<<-1;
	return 0;
	//NOTICE LONG LONG!!!!!
}