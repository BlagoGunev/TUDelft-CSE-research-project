#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<functional>
#include<deque>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<numeric>
#include<memory>
#include<utility>
#include<bitset>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
#define lowBit(x) ((x)&(-x))
#define rep(i,a,n) for (ll i=a;i<=n;i++)
#define per(i,a,n) for (ll i=n;i>=a;i--)
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define D(x1, y1, x2, y2) sqrt(pow(x2-x1, 2)+pow(y2-y1, 2))
#define endl "\n"
typedef vector<ll> VI;
typedef pair<ll, ll> PII;
ll mod = 1e9 + 7;
const ll N = 1e6 + 6;
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
ll powmod(ll a, ll b)
{
	ll ans = 1;
	while (b > 0)
	{
		if (b & 1)ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
ll readn()
{
	ll sum = 0, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		sum = sum * 10 + (ch - '0');
		ch = getchar();
	}
	return sum * f;
}

int main()
{
	int t = readn();
	while (t--)
	{
		int a[109];
		ll n = readn(), l = readn(), r = readn(), k = readn();
		for(int i=1;i<=n;i++) a[i]=readn();
		sort(a+1,a+1+n);
		int num = 0 , sum = 0;
		if(a[n]<l) 
		{
			puts("0");
			continue;
		} 
		for(int i=1;i<=n;i++)
		{
			if(sum<=k&&a[i]>=l&&a[i]<=r) sum+=a[i],num++;
			if(sum>k) 
			{
				num--;
				break;
			}
			if(a[i]>r) break;
		}
		printf("%d\n",num);
	}

	return 0;
}