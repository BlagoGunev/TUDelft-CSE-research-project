#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<math.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+10;
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}
ll lowbit(ll x)//最小1的权值 
{
	return x & -x;
}
int main()
{
	ll n,x,i,l;
	scanf("%lld %lld",&n,&x);
	{
		if(x>pow(2,n)-1)
		{
			l=pow(2,n)-1;
			printf("%lld\n",l);
			for(i=1;i<=l;i++)
			printf("%lld ",lowbit(i));
			putchar(10);
		}
		else
		{
			l=pow(2,n-1)-1;
			printf("%lld\n",l);
			for(i=1;i<=l;i++)
			{
				if(lowbit(i)>=lowbit(x))
				printf("%lld ",2*lowbit(i));
				else
				printf("%lld ",lowbit(i));
			}
			putchar(10);
		}
	}
}