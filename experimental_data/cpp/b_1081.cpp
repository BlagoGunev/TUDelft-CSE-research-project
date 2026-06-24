#include<iostream> 
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,ans[N],cnt;
struct data
{
	int x,y;
	bool operator <(const data&a) const
	{
		return x<a.x;
	}
}a[N];
int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif*/
	n=read();
	for (int i=1;i<=n;i++) a[i].x=n-read(),a[i].y=i;
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		int t=i;
		while (t<n&&a[t+1].x==a[i].x&&t+1-i+1<=a[i].x) t++;
		if (t-i+1!=a[i].x) {cout<<"Impossible";return 0;}
		cnt++;
		for (int j=i;j<=t;j++) ans[a[j].y]=cnt;
		i=t;
	}
	printf("Possible\n");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}