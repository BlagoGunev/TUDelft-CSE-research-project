#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#define ll long long
#define maxn 200010
#define rep(x,a,b) for(x=a;x<=b;x++)
#define drep(x,a,b) for(x=a;x>=b;x--)
using namespace std;
ll read(ll x=0)
{
	char c, f=1;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-48;
	return x*f;
}
ll s1[maxn], s2[maxn], n, d[maxn];
void init()
{
	ll i;
	n=read();
	rep(i,1,n)d[i]=read();
	rep(i,1,n)s1[i]=s1[i-1]+d[i];
	drep(i,n,1)s2[i]=s2[i+1]+d[i];
}
bool check(ll l, ll r, ll x)
{
	ll mid;
	do
	{
		mid=l+r>>1;
		if(s2[mid]>x)l=mid+1;
		else r=mid;
//		printf("x=%I64d (%I64d,%I64d) %I64d\n",x,l,r,n);
	}
	while(l^r);
	return s2[l]==x;
}
int main()
{
//	freopen("in.txt","r",stdin);
	ll i;
	init();
//	rep(i,1,n)printf("%I64d ",s2[i]);printf("\n");
	drep(i,n,0)
	{
		if(check(i+1,n+1,s1[i]))
		{
			printf("%I64d",s1[i]);
			return 0;
		}
	}
}