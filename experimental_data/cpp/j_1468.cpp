#include <bits/stdc++.h>

using namespace std;



#define int long long



void solve() {

	int n, m, k;

	cin >> n >> m >> k;

	vector<tuple<int, int, int>> edges(m + 2), edges_large, edges_small;

	vector<int> values;

	for (int i = 1; i <= m; i++) {

		int a, b, c;

		cin >> a >> b >> c;

		edges[i] = {a, b, c};

		if (c > k)

			edges_large.push_back(edges[i]);

		else

			edges_small.push_back(edges[i]);

		values.push_back(c);

	}

	sort(values.begin(), values.end());

	vector<int> fa(n + 2);

	for (int i = 1; i <= n; i++)

		fa[i] = i;

	function<int(int)> find = [&](int x) -> int {

		return x == fa[x] ? x : fa[x] = find(fa[x]);

	};

	int tot = 1;

	function<void(int, int)> merge = [&](int x, int y) -> void {

		x = find(x);

		y = find(y);

		if (x != y)

			fa[x] = y, tot++;

	};

	for (auto [u, v, w] : edges_small)

		merge(u, v);

	int flag = tot == n;

	if (flag) {

		int i = lower_bound(values.begin(), values.end(), k) - values.begin();

		int j = i - 1;

		int ans = 1e18;

		if (i >= 0 && i < m)

			ans = min(ans, abs(k - values[i]));

		if (j >= 0 && j < m)

			ans = min(ans, abs(k - values[j]));

		cout << ans << endl;

	} else {

		int ans = 0;

		vector<pair<int, pair<int, int>>> ve;

		for (auto [x, y, z] : edges_large)

			ve.push_back({z, {x, y}});

		sort(ve.begin(), ve.end());

		for (int i = 0; i < ve.size(); i++) {

			auto [w, pr] = ve[i];

			auto [u, v] = pr;

			if (find(u) != find(v))

				merge(u, v), ans += w - k;

			if (tot == n)

				break;

		}

		cout << ans << endl;

	}

}



signed main() {

	ios::sync_with_stdio(false);



	int t;

	cin >> t;

	while (t--) {

		solve();

	}

}