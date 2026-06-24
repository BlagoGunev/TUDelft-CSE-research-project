#include <iostream>
#include <set>
#include <vector>

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::multiset<int> a, b;

	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		a.insert(x);
	}

	for (int j = 0; j < m; ++j) {
		int x;
		std::cin >> x;
		b.insert(x);
	}

	for (int i = 1; i <= std::min(k, 1000); ++i) {
		if (i & 1) {
			int x = *a.begin();
			int y = *prev(b.end());
			if (x < y) {
				a.erase(a.begin());
				b.erase(prev(b.end()));
				a.insert(y);
				b.insert(x);
			}
		}
		else {
			int x = *prev(a.end());
			int y = *b.begin();
			if (x > y) {
				a.erase(prev(a.end()));
				b.erase(b.begin());
				a.insert(y);
				b.insert(x);
			}
		}
	}

	k -= 1000;

	if (k > 0 && (k & 1)) {
		int x = *a.begin();
		int y = *prev(b.end());
		if (x < y) {
			a.erase(a.begin());
			b.erase(prev(b.end()));
			a.insert(y);
			b.insert(x);
		}
	}

	long long ans = 0;

	for (int x : a) {
		ans += x;
	}

	std::cout << ans << '\n';
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}