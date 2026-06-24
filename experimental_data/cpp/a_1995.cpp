#include <bits/stdc++.h>
#define int long long 
#define endl '\n' 
using namespace std;
void solve() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	while (k > 0) {
		ans++;
		k -= n;
		if (ans & 1)
			n -= 1;
	}
	cout << ans << endl;
}
signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}