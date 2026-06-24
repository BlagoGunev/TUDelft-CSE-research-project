#include <bits/stdc++.h>

using namespace std;

int n, a[3005], b[3005], f[3005], cir[2][3005];

vector <int> g[3005];

int match[3005];

bool vis[3005];

vector <int> vec1[3005], vec2[3005];

int find(int x) {

	if (f[x] == x) return x;

	return f[x] = find(f[x]);

}

int main() {

	ios :: sync_with_stdio(0), cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {

		cin >> a[i];

	}

	for (int i = 1; i <= n; ++i) {

		cin >> b[i];

	}

	iota(f + 1, f + n + 1, 1);

	for (int i = 1; i <= n; ++i) {

		int fx = find(i), fy = find(a[i]);

		if (fx != fy) f[fx] = fy; 

	}

	for (int i = 1; i <= n; ++i) {

		cir[0][i] = find(i), vec1[ cir[0][i] ].push_back(i); 

	}

	iota(f + 1, f + n + 1, 1);

	for (int i = 1; i <= n; ++i) {

		int fx = find(i), fy = find(b[i]);

		if (fx != fy) f[fx] = fy;

	}

	for (int i = 1; i <= n; ++i) {

		cir[1][i] = find(i), vec2[ cir[1][i] ].push_back(i);

	}

	for (int i = 1; i <= n; ++i) {

		g[ cir[0][i] ].push_back(cir[1][i]);

	}

	auto dfs = [&] (auto &self, int u) {

		if (vis[u]) return false;

		vis[u] = true;

		for (auto v : g[u]) {

			if (!match[v] or self(self, match[v])) {

				match[v] = u;

				return true;

			}

		}

		return false;

	};

	int ans = 0;

	for (int i = 1; i <= n; ++i) {

		memset(vis, false, sizeof(vis));

		if (dfs(dfs, i)) ++ans;

	}

	cout << n - ans << '\n';

	set <int> s;

	for (int i = 1; i <= n; ++i) {

		s.insert(i);

	}

	for (int i = 1; i <= n; ++i) {

		if (match[i]) {

			bool del = false;

			for (auto j : vec1[ match[i] ]) {

				for (auto k : vec2[i]) {

					if (j == k) {

						s.erase(s.find(j));

						del = true;

						break;

					}

				}

				if (del) break;

			}

		}

	}

	for (auto i : s) {

		cout << i << ' ';

	}

	cout << '\n';

	return 0;

}