#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
typedef long long ll;

using namespace std;
const int N = 1e5 + 10;
const ll mod = 998244353;
const ll INF = 1e18 + 1e7;
string s[N];
int n, m, k;
int v[110][110];
int dp[110][110];
int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}
void solve()
{
	int a[4];
	ll ans = 0;
	for (int i = 0; i < 4; ++i)
	{
		cin >> a[i];
		ans += a[i] / 2;
	}
	if (a[0] % 2 && a[1] % 2 && a[2] % 2)
		ans++;
	cout << ans << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}