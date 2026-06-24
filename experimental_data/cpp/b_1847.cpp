#include <bits/stdc++.h>

using namespace std;


void solve(void)
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int c = (2 << 31) - 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		c &= v[i];
		if (c == 0) {
			ans++;
			c = (2 << 31) - 1;
		}
	}

	if (ans == 0) cout << "1\n";
	else cout << ans << "\n";
}


int main(void)
{
	int t;
	cin >> t;

	while (t--) solve();
}