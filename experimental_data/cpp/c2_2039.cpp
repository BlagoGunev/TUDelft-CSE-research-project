#include <bits/stdc++.h>
#define cerr cout << "in " << __LINE__ << "\t: "
using namespace std;
#define int long long
int x, m;
void Solve(int test) {
	cin >> x >> m;
	int ans = 0;
	int k = max(1ll, m / x - 1);
	ans += k - 2 + 1;
	for (int j = k + 1; j <= k + 3; j++)
		if ((j * x ^ x) <= m) ans++;
	for (int y = 1; y <= min(m, x - 1); y++)
		if ((x ^ y) % y == 0 && (x ^ y) % x)
			ans++;
	cout << ans + (x <= m) << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) Solve(i);
	return 0;
}