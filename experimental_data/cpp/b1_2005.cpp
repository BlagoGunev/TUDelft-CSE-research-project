#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		int l, r, x;
		cin >> l >> r >> x;
		
		if (l > r) swap(l, r);
		
		if (x < l) cout << l - 1 << "\n";
		else if (x > r) cout << n - r << "\n";
		else cout << (r - l) / 2 << "\n";
	}

	return 0;
}