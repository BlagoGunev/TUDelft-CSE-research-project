#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 2000010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,m,a[N],p[N],sum[N],nxt[N],b[N],t,cnt,ans;
int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif*/
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read()-m+1000000;
		if (a[i]==1000000) cnt++;
	}
	for (int i=1;i<=n;i++) nxt[i]=p[a[i]],p[a[i]]=i;
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]==1000000);
	ans=cnt;
	for (int i=0;i<=2000000;i++)
	if (i!=1000000&&p[i])
	{
		int x=p[i];t=0;b[++t]=1;
		while (nxt[x])
		{
			b[++t]=sum[nxt[x]]-sum[x];
			b[++t]=1;
			x=nxt[x];
		}
		int s=0;
		for (int j=1;j<=t;j++)
		{
			s+=b[j];
			if (s<0) s=0;
			ans=max(ans,cnt+s);
		}
	}
	cout<<ans<<endl;
	return 0;
}