#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	for (cin >> T; T; T--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int ans = b + c - d;
		if (ans > a || d < b) cout << "-1\n";
		else cout << a - ans + d - b << '\n';
	}
	return 0;
}