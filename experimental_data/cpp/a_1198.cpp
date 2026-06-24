#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
using namespace std;
namespace mine
{
	typedef long long ll;
	#define pr pair<int,int>
	#define FR first
	#define SE second
	#define MP make_pair
	#define PB push_back
	#define vc vector
	void chmax(int &x,const ll y) {x=(x>y?x:y);}
	void chmin(int &x,const ll y) {x=(x<y?x:y);}
	ll qread()
	{
		ll ans=0,f=1;char c=getchar();
		while(c<'0' or c>'9') {if(c=='-')f=-1;c=getchar();}
		while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
		return ans*f;
	}
	void write(ll num)
	{
		if(num<0) putchar('-'),num=-num;
		if(num>=10) write(num/10);
		putchar('0'+num%10);
	}
	void write1(ll num){write(num);putchar(' ');}
	void write2(ll num){write(num);putchar('\n');}
	const int INF=0x3f3f3f3f;
	const int MOD=19930726;
	void add(ll &a,ll b){a+=b;if(a>=MOD)a-=MOD;if(a<=-MOD)a+=MOD;}
	ll qpower(ll x,int e)
	{
		ll ans=1;
		while(e)
		{
			if(e&1) ans=ans*x%MOD;
			x=x*x%MOD;e>>=1;
		}
		return ans;
	}
	ll invm(ll x){return qpower(x,MOD-2);}
	const int N=1e6+10;

	int a[N];
	void main()
	{
		int n=qread(),I=qread();for(int i=1;i<=n;i++) a[i]=qread();sort(a+1,a+n+1);
		int l=1,r=n,mx=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if( ceil(log2(mid*1.0))*n<=I*8 ) mx=mid,l=mid+1;
			else r=mid-1;
		}
		int ans=n;
		for(int l=1,now=1,r=1;l<=n;l++)
		{
			while(r+1<=n and now+(a[r]!=a[r+1])<=mx) now+=(a[r]!=a[r+1]),r++;
			ans=min(ans,n-(r-l+1));
			// printf("l=%d r=%d now=%d mx=%d\n",l,r,now,mx);
			if(a[l]!=a[l+1]) now--;
		}
		write(ans);
	}
};
int main()
{
	srand(time(0));
	mine::main();
}