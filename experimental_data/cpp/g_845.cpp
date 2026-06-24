#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> G[N];
bool v[N];
int d[N];
vector<pair<int, int>> mat;
void add(int x) {
	for (auto y : mat) {
		if (x >> y.first & 1) {
			x ^= y.second;
		}
	}
	if (!x) return;
	int y;
	for (y = 30; (~x >> y & 1); -- y);
	mat.push_back({y, x});
}
void dfs(int x, int p = 0, int pw = 0) {
	v[x] = 1;
	for (auto e : G[x]) {
		if (e.first == p && e.second == pw) {
			p = -1;
			continue;
		}
		int u = e.first, w = e.second;
		if (v[u]) {
			add(w ^ d[u] ^ d[x]);
			continue;
		}
		d[u] = d[x] ^ w;
		dfs(u, x, w);
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w});
		if (u != v) G[v].push_back({u, w});
	}
	dfs(1);
	int ans = d[n];
	vector<int> all;
	for (auto y : mat) {
		all.push_back(y.second);
	}
	sort(all.begin(), all.end(), greater<int>());
	mat.clear();
	for (int y : all) add(y);
	for (auto y : mat) {
		if (ans >> y.first & 1) ans ^= y.second;
	}
	printf("%d\n", ans);
}