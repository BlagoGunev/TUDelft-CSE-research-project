#include <bits/stdc++.h>
typedef long long ll;
#define pi acos(-1)
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;

ll n, s;
//ll a[maxn], sum[maxn];
int main()
{
	cin>>n;
	ll ans = 0;
	while(n)
	{
		ans++;
		n = n>>1;
	}
	cout<<ans<<endl;
	
	return 0;
}