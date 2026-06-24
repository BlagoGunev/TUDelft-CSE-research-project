#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define Max 10000001
#define endl '\n'
#define PL pair<int,int>
const int mod = 998244353;
ll a[Max];
void solve() {
	ll n, maxs, ans = 0;
	cin >> n;
	vector<int>s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	maxs = s[n - 1];
	for (int i = 1; i <= maxs; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		a[s[i]] = 1;
	}
	for (int i = 1; i <= maxs; i++) {
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= maxs; i++) {
		ll x = maxs / i, y = maxs / i;
		if (maxs % i) y++;
		ll sum = 0;
		for (int i = 1;; i++) {
			if (i * x > maxs) break;
			if (i * y >= maxs) {
				sum += a[maxs] - a[i * x-1];
				break;
			}
			if (i * x - 1 <= (i - 1)*y) {
				sum += a[maxs] - a[(i - 1) * y];
				break;
			}
			sum += a[y * i] - a[i * x - 1];
		}
		ans = (ans + sum * i) % mod;
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}