#include <bits/stdc++.h>

using namespace std;

template <typename T>

using pair2 = pair <T, T>;

#define fi first

#define se second

#define pb push_back

#define eb emplace_back

int n, m, a[200005], dep[200005], siz[200005];

int hson[200005], top[200005], father[200005];

vector <int> g[200005];

void dfs1(int u, int fa) {

	dep[u] = dep[fa] + 1, father[u] = fa;

	siz[u] = 1, hson[u] = 0;

	for (auto v : g[u]) {

		if (v == fa) continue;

		dfs1(v, u);

		siz[u] += siz[v];

		if (siz[ hson[u] ] < siz[v]) {

			hson[u] = v;

		}

	}

}

void dfs2(int u) {

	if (hson[u]) {

		top[ hson[u] ] = top[u];

		dfs2(hson[u]);

	}

	for (auto v : g[u]) {

		if (v == father[u] or v == hson[u]) continue;

		top[v] = v;

		dfs2(v);

	}

}

int lca(int x, int y) {

	while (top[x] != top[y]) {

		if (dep[ top[x] ] < dep[ top[y] ]) {

			swap(x, y);

		}

		x = father[ top[x] ];

	}

	if (dep[x] > dep[y]) {

		swap(x, y);

	}

	return x;

}

int dist(int x, int y) {

	return dep[x] + dep[y] - 2 * dep[ lca(x, y) ];

}

struct node {

	int l, r;

	pair2 <int> org;

	vector < pair2 <int> > vec;

} tr[800005];

int x, y;

#define ls (p * 2)

#define rs (p * 2 + 1)

void build(int p, int l, int r) {

	tr[p].l = l, tr[p].r = r;

	tr[p].vec.clear(), tr[p].org = {0, 0};

	if (l == r) return ;

	int mid = (l + r) / 2;

	build(ls, l, mid), build(rs, mid + 1, r);

}

void update(int p, int x, int y, int id, int val) {

	if (x > y) return ;

	if (tr[p].l >= x && tr[p].r <= y) {

		return tr[p].vec.eb(id, val), void();

	}

	int mid = (tr[p].l + tr[p].r) / 2;

	if (x <= mid) update(ls, x, y, id, val);

	if (mid < y) update(rs, x, y, id, val);

}

void dfs(int p, int l, int r) {

	tr[p].org = {x, y};

	for (auto i : tr[p].vec) {

		int z = i.fi;

		a[z] = i.se;

		int nowx = x, nowy = y;

		if (dist(x, y) + a[x] + a[y] < dist(nowx, z) + a[nowx] + a[z]) {

			x = nowx, y = z;

		}

		if (dist(x, y) + a[x] + a[y] < dist(nowy, z) + a[nowy] + a[z]) {

			x = z, y = nowy;

		}

		if (dist(x, y) + a[x] + a[y] < 2 * a[z]) {

			x = y = z;

		}

	}

	if (l == r) {

		cout << (dist(x, y) + a[x] + a[y] - 1) / 2 + 1 << '\n';

		for (auto i : tr[p].vec) {

			int z = i.fi;

			a[z] = 0;

		}

		tie(x, y) = tr[p].org;

		return ;

	}

	int mid = (l + r) / 2;

	dfs(ls, l, mid), dfs(rs, mid + 1, r);

	for (auto i : tr[p].vec) {

		int z = i.fi;

		a[z] = 0;

	}

	tie(x, y) = tr[p].org;

}

#undef ls

#undef rs

int lst[200005], dis[200005], far;

void find(int u, int fa) {

	if (dis[u] > dis[far] or !far) {

		far = u;

	}

	for (auto v : g[u]) {

		if (v == fa) continue;

		dis[v] = dis[u] + 1;

		find(v, u);

	}

}

int main() {

	// freopen("code.in", "r", stdin);

	// freopen("code.out", "w", stdout);

	ios :: sync_with_stdio(0), cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {

		cin >> a[i];

	}

	for (int i = 1; i < n; ++i) {

		int u, v; cin >> u >> v;

		g[u].pb(v), g[v].pb(u);

	}

	dfs1(1, 0), top[1] = 1, dfs2(1);

	cin >> m;

	build(1, 1, m);

	for (int i = 1; i <= n; ++i) {

		lst[i] = 1;

	}

	for (int i = 1; i <= m; ++i) {

		int x, v;

		cin >> x >> v;

		update(1, lst[x], i - 1, x, a[x]);

		lst[x] = i, a[x] = v;

	}

	for (int i = 1; i <= n; ++i) {

		update(1, lst[i], m, i, a[i]);

	}

	memset(a, 0, sizeof(a));

	dis[1] = 0, far = 0, find(1, 0), x = far;

	dis[x] = 0, far = 0, find(x, 0), y = far;

	dfs(1, 1, m);

	return 0;

}