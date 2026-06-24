#include <bits/stdc++.h>
using namespace std;

int a[300005];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		if (n % 2) {
			cout << "YES\n";
			continue;
		}
		long long t = 0;
		for (int i = 1; i <= n; ++i) {
			if (i % 2) t += a[i];
			else t -= a[i];
		}
		if (t > 0) cout << "NO\n";
		else cout << "YES\n";

	}

	return 0;
}