#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif


void solve() {
	int a, b; cin >> a >> b;
	if (a < b) swap(a, b);
	int ans = 0;
	while (a > b) {
		b *= 2;
		ans++;
	}
	int max8 = ans / 3;
	ans = ans % 3;
	int max4 = ans / 2;
	ans = ans % 2;
	int max2 = ans;
	ans = max2 + max4 + max8;
	if (a != b) ans = -1;
	cout << ans << '\n';
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int  t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}