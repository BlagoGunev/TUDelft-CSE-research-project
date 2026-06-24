#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000010
#define N 200010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,m,a[N];
bool check(int k)
{
	for (int i=1;i<=k;i++) if (a[n-(k-i)]-a[i]<m) return 0;
	return 1;
}
signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int l=0,r=n/2,ans=0;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
	//NOTICE LONG LONG!!!!!
}