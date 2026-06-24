#include<iostream>
#include<cmath>
#include<algorithm>
#define maxn 200010
using namespace std;
typedef long long ll;
ll a[maxn];
ll st[maxn][20];
ll lg[maxn];
int t;
inline char gc()
{
	static char buf[1 << 12], * p1 = buf, * p2 = buf;
	return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 12, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll read()
{
	ll x = 0, f = 1;
	char ch(gc());
	while (ch<'0' || ch>'9')
	{
		if (ch == '-')
			f = -1;
		ch = gc();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = gc();
	}
	return x * f;
}
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
void init(int n)
{
	for(int j=1;j<20;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
ll query(int l,int r)
{
	int k=lg[r-l+1];
	return gcd(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
//	freopen("G.in","r",stdin);
	lg[0]=-1;
	for(int i=1;i<=maxn-1;i++)
		lg[i]=lg[i>>1]+1;
	t=read();
	while(t--)
	{
		int n=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		for(int i=n+1;i<=(n<<1)&&i<=maxn-1;i++)
			st[i][0]=0;
		for(int i=1;i<=n;i++)
			st[i][0]=abs(a[i]-a[i-1]);
		init(n);
		int  ans=1;
		for(int i=1,j=2;i<=n;i++)
		{
			if(i==j)
				j=i+1;
			while(i<j&&j<=n)
			{
				if(query(i+1,j)>=2)
				{
					ans=max(ans,j-i+1);
					j++;
				}
				else
					break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}