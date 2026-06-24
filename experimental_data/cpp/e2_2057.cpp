#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair
#define debug(x) cout << #x << " = " << x << "\n";

int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!('0' <= ch && ch <= '9')) {
		if (ch == '-') f = -1; ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();
	}
	return x * f;
}

void wr(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) wr(x / 10); putchar(x % 10 + '0');
}
bool MemoryST;

const int N = 410;
const int M = N * N;
const int inf = 1e9 + 1;

struct Union_set {
	int n, f[N];
	void init(int nn) {
		n = nn;
		for (int i = 1; i <= n; ++i)
			f[i] = i;
	}
	int find (int x) {
		if (f[x] == x) return x;
		return f[x] = find(f[x]);
	}
	int merge (int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return 0;
		f[x] = y;
		return 1;
	}
} uf;

vector<pii> e[N];

int cnt, x[N];
int u[M], v[M], w[M], id[M], vis[M];
int n, m, q, f[N][N][N][2]; 

void bfs(int p, int s) {
	deque<pii> q;
	q.push_front(mkp(s, 1)); f[p][s][s][1] = 0;
	while (!q.empty()) {
		int u = q.front().fi, p1 = q.front().se; q.pop_front();
//		cout << p << " is " << s<< " " << u << " " << p1 << " " << f[p][s][u][p1] << "\n";
		for (auto pi : e[u]) {
			int v = pi.fi, w = pi.se + f[p][s][u][p1], p2 = (p1 & pi.se);
			if (f[p][s][v][p2] > w) {
				f[p][s][v][p2] = w;
				if (pi.se) q.push_back(mkp(v, p2));
				else q.push_front(mkp(v, p2));
			} 
		}
	} 
}

void Mainsolve() {
	cin >> n >> m >> q;
	for (int i = 1; i <= m; ++i)
		cin >> u[i] >> v[i] >> w[i], id[i] = i, vis[i] = 0;
	sort (id + 1, id + m + 1, [&](int x, int y) {
		return w[x] < w[y];
	});
	cnt = 0;
	uf.init(n);
	for (int i = 1; i <= m; ++i) {
		if (uf.merge(u[id[i]], v[id[i]])) x[++cnt] = w[id[i]], vis[id[i]] = 1;
	}
	cnt = unique(x + 1, x + cnt + 1) - x - 1;
	for (int p = 0; p <= cnt; ++p)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				f[p][i][j][0] = f[p][i][j][1] = inf;
	for (int i = 1; i <= n; ++i)
		e[i].clear();
	for (int i = 1; i <= m; ++i)
		e[u[i]].pb(mkp(v[i], 1)), e[v[i]].pb(mkp(u[i], 1));
	for (int i = 1; i <= n; ++i)
		bfs(0, i);
	uf.init(n);
	for (int p = 1; p <= cnt; ++p) {
		for (int a = 1; a <= n; ++a)
			for (int b = 1; b <= n; ++b)
				f[p][a][b][0] = f[p - 1][a][b][0], f[p][a][b][1] = f[p - 1][a][b][1]; 
		for (int i = 1; i <= m; ++i) { 
			if (w[i] == x[p] && vis[i]) {
				for (int a = 1; a <= n; ++a)
					for (int b = 1; b <= n; ++b)
						f[p][a][b][0] = min(f[p][a][b][0], min(f[p][a][u[i]][1], f[p][a][u[i]][0]) + min(f[p][v[i]][b][0], f[p][v[i]][b][1]));
				for (int a = 1; a <= n; ++a)
					for (int b = 1; b <= n; ++b)
						f[p][a][b][0] = min(f[p][a][b][0], min(f[p][a][v[i]][1], f[p][a][v[i]][0]) + min(f[p][u[i]][b][0], f[p][u[i]][b][1]));
			}
		}
	}
	while (q--) {
		int a, b, k; cin >> a >> b >> k;
		int l = 1, r = cnt;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (f[mid][a][b][0] < k) r = mid;
			else l = mid + 1;
		}
		cout << x[l] << " "; 
	}
	cout << "\n";
}

bool MemoryED;
int main() {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cerr << fixed << setprecision(6) << (&MemoryST - &MemoryED) / 1024.0 << "KB\n";

	int T; cin >> T;
	while (T--) Mainsolve();

	cerr << endl << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";

//	system("fc .out .out");
	return 0;
}