//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 2500005;
ll jc[maxn], bjc[maxn];
vi cal(vi a) {
	// return d th and (d - 1) th
	int d = a.size() - 1;
	ll sum = 1ll * d * (d + 1) / 2 % mod;
	ll r[2] = {0, 0};
	for (int i = 0; i <= d; i++) {
		ll cf = bjc[d - i] * bjc[i] % mod;
		if ((d - i) % 2) cf = -cf;
		cf = cf * a[i] % mod;
		r[0] = (r[0] + cf) % mod;
		r[1] = (r[1] - cf * (sum - i)) % mod;
	}
	return {r[0], r[1]};
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	jc[0] = 1;
	for (int i = 1; i < maxn; i++) jc[i] = jc[i - 1] * i % mod;
	bjc[maxn - 1] = ksm(jc[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; i--) bjc[i] = bjc[i + 1] * (i + 1) % mod;
	int d;
	cin >> d;
	vi a(d + 1), b(d + 1);
	for (int i = 0; i <= d; i++)	
		cin >> a[i];
	for (int i = 0; i <= d; i++)
		cin >> b[i];
	vi h = cal(a), g = cal(b);
	// h[0] * d * s + h[1] = g[1]
	ll s = (g[1] - h[1]) * ksm(h[0], mod - 2) % mod * ksm(d, mod - 2) % mod;
	s %= mod;
	if (s < 0) s += mod;
	cout << s << endl;
    return 0;
}