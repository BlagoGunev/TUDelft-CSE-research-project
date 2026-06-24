#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fi first
#define se second
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 5e5 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 998244353;
int n, k;
ll fac[N], inv[N];
ll powmod(ll a, ll b)
{
	a %= mod;
	ll ans = 1;
	while(b)
	{
		if(b&1) ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}
void init(int n)
{
	fac[0] = 1;
	for(int i=1; i<=n; i++) fac[i] = fac[i-1]*i%mod;
	inv[n] = powmod(fac[n], mod-2);
	for(int i=n-1; i>=0; i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll comb(int a, int b)
{
	if(a<b||b<0||a<0) return 0;
	return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	init(n);
	ll ans = 0;
	for(int i=1; i<=n; i++)
	{
		int j = n/i - 1;
		(ans += comb(j, k-1)) %= mod;
	}
	cout << ans;
	return 0;
}