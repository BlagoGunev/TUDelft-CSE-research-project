#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll; 
ll t,n,x,m,l,r; 
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&x,&m);
		ll l1=x,r1=x;
		for(ll i=1;i<=m;i++)
		{
			scanf("%lld%lld",&l,&r);
			if((l<=r1&&r>=r1)||(l<=l1&&r>=l1))
			{
				l1=min(l,l1);
				r1=max(r,r1);
			}
		}
		printf("%lld\n",r1-l1+1);
	}
	return 0;
}