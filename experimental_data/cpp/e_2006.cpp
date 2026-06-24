#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<int> adj[505050];
int deg[505050];
int P[505050];
vector<int> K[505050];
vector<int> cdep[505050];
priority_queue<pii, vector<pii>, greater<pii>> pq[505050];
int dep[505050];
int st[20][505050];
int sz[505050];
bool chk[505050];

void init(int v, int p) {
	dep[v] = dep[p] + 1;
	st[0][v] = p;
	for (int i : adj[v]) {
		if (i == p) continue;
		init(i, v);
	}
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	int d = dep[a] - dep[b];
	for (int i = 19; i >= 0; i--) {
		if (d >> i & 1) a = st[i][a];
	}
	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if (st[i][a] == st[i][b]) continue;
		a = st[i][a]; b = st[i][b];
	}
	return st[0][a];
}

int dist(int a, int b) {
	int l = lca(a, b);
	return dep[a] + dep[b] - 2 * dep[l];
}

int go(int u, int v, int k) {
	int l = lca(u, v);
	int x;
	if (dep[u] - dep[l] <= k) {
		x = v;
		k = dep[u] + dep[v] - 2 * dep[l] - k;
	} else {
		x = u;
	}
	for (int i = 19; i >= 0; i--) {
		if (k >> i & 1) x = st[i][x];
	}
	return x;
}

void dfs1(int v, int p) {
	sz[v] = 1;
	for (int i : adj[v]) {
		if (chk[i] || i == p) continue;
		dfs1(i, v);
		sz[v] += sz[i];
	}
}

void dfs2(int v, int p, int cen, int d) {
	K[v].push_back(cen);
	cdep[v].push_back(d);
	for (int i : adj[v]) {
		if (chk[i] || i == p) continue;
		dfs2(i, v, cen, d + 1);
	}
}

void dnc(int v) {
	dfs1(v, 0);
	int n = sz[v];
	int bef = v, cen = v;
	while (1) {
		bool ok = false;
		for (int i : adj[cen]) {
			if (chk[i] || i == bef) continue;
			if (sz[i] * 2 >= n) {
				bef = cen; cen = i;
				ok = true; break;
			}
		}
		if (!ok) break;
	}
	dfs2(cen, 0, cen, 0);
	chk[cen] = true;
	for (int i : adj[cen]) {
		if (chk[i]) continue;
		dnc(i);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			K[i].clear();
			cdep[i].clear();
			deg[i] = 0;
			chk[i] = false;
			while (pq[i].size()) pq[i].pop();
		}
		for (int i = 2; i <= N; i++) {
			scanf("%d", &P[i]);
			adj[i].push_back(P[i]);
			adj[P[i]].push_back(i);
		}
		init(1, 0);
		for (int i = 1; i <= 19; i++) {
			for (int j = 1; j <= N; j++) st[i][j] = st[i - 1][st[i - 1][j]];
		}
		dnc(1);

		int u = 1, v = 1, d = 0;
		bool ok = true;

		auto add = [&](int x) {
			for (int j = 0; j < K[x].size(); j++) {
				int c = K[x][j];
				pq[c].emplace(cdep[x][j], x);
			}
		};

		printf("1 "); add(1);
		for (int i = 2; i <= N; i++) {
			int du = dist(u, i), dv = dist(v, i);
			if (max({du, dv, d}) == du) { d = du; v = i; }
			else if (max({du, dv, d}) == dv) { d = dv; u = i; }
			deg[P[i]]++; deg[i] = 1;
			if (deg[P[i]] > 3) ok = false;
			if (!ok) { printf("-1 "); continue; }

			add(i);

			int ans = N;
			for (int k = d / 2; k <= (d + 1) / 2; k++) {
				int m = go(u, v, k);
				for (int j = 0; j < K[m].size(); j++) {
					int c = K[m][j];
					if (c > i) continue;
					while (pq[c].size()) {
						auto [t, x] = pq[c].top();
						if (deg[x] >= 3) { pq[c].pop(); continue; }
						ans = min(ans, (d + 1) / 2 + t + cdep[m][j]);
						break;
					}
				}
			}
			printf("%d ", ans + 1);
		}
		puts("");
	}
	return 0;
}