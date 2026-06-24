#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1 << 30;



int main() {

	cin.tie(nullptr)->sync_with_stdio(false);

	int n; cin >> n;

	vector<pair<int, int>> a(n);

	for (auto &[x, y] : a) cin >> x >> y;



	sort(a.begin(), a.end(), [](auto lhs, auto rhs){

		return min(lhs.first, lhs.second) < min(rhs.first, rhs.second);

	});



	vector<int> sf(n);

	for (int i = 0; i < n; ++i)

		sf[i] = max(a[i].first, a[i].second);

	for (int i = n - 2; i >= 0; --i)

		sf[i] = max(sf[i], sf[i + 1]);





	int ans = 0;

	int la[2] = {INF, INF}, c[2][2] = {};

	int pr = INF;

	for (int i = 0; i < n; ++i) {

		auto [x, y] = a[i];

		auto w = [n](int p){ return 1 <= p and p <= n ? 1 : 2; };

		if (int s = w(x) | w(y); s != 3) {

			cout << "-1\n";

			return 0;

		}

		if (la[0] > max(x, y)) {

			la[0] = max(x, y);

			c[0][x > y]++;

		} else if (la[1] > max(x, y)) {

			la[1] = max(x, y);

			c[1][x > y]++;

		} else {

			cout << "-1\n";

			return 0;

		}

		pr = min(pr, max(x, y));

		if (i + 1 == n or pr > sf[i + 1]) {

			ans += min(c[0][1] + c[1][0], c[0][0] + c[1][1]);

			c[0][0] = c[0][1] = c[1][0] = c[1][1] = 0;

			la[0] = la[1] = INF;

		}

	}

	cout << ans << '\n';

	return 0;

}