#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());

	n = (int) a.size();

	int ans = a[n - 1];
	int l = 0;
	int r = ans - 1;

	while (l <= r) {
		int mid = l + (r - l) / 2;
		int need = 0;
		int last = -1000000005;
		for (int i = 0; i < n; ++i) {
			if (a[i] - last <= mid) continue;
			++need;
			last = a[i] + mid;
		}
		if (need <= 3) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
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