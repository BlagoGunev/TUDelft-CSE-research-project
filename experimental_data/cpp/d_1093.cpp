#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 300010
#define P 998244353
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
ll read()
{
	ll x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int T,n,m,t,p[N],color[N],white,black;
bool flag;
struct data{int to,nxt;
}edge[N<<1];
void addedge(int x,int y){t++;edge[t].to=y,edge[t].nxt=p[x],p[x]=t;}
void dfs(int k,int c)
{
	if (flag==0) return;
	color[k]=c;if (c==0) white++;else black++;
	for (int i=p[k];i;i=edge[i].nxt)
	{
		if (flag==0) return;
		if (color[edge[i].to]==-1) dfs(edge[i].to,c^1);
		else if (color[edge[i].to]==c) {flag=0;return;}
	}
}
int ksm(int a,int k)
{
	int s=1;
	for (;k;k>>=1,a=1ll*a*a%P)if (k&1) s=1ll*s*a%P;
	return s;
}
int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif*/
	T=read();
	while (T--)
	{
		n=read(),m=read();flag=1;t=0;
		for (int i=1;i<=n;i++) p[i]=0,color[i]=-1;
		for (int i=1;i<=m;i++)
		{
			int x=read(),y=read();
			addedge(x,y),addedge(y,x);
		}
		int cnt=0,ans=1;
		for (int i=1;i<=n;i++)
		if (color[i]==-1)
		{
			white=black=0,cnt++,dfs(i,0);
			ans=1ll*ans*(ksm(2,white)+ksm(2,black))%P;
		}
		if (flag==0) ans=0;
		printf("%d\n",ans);
	}
	return 0;
}