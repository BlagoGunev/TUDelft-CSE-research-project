#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define X		first
#define Y		second
#define all(x)		(x).begin(),(x).end()
#define sep		' '
#define endl		'\n'
#define debug(x)	cerr << #x << ": " << x << endl;

const int MAXN = 200 + 10;

typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
const DOUBLE EPS = 1e-9;
struct LPSolver {
	int m, n;
	VI B, N;
	VVD D;
	LPSolver(const VVD &A, const VD &b, const VD &c) :
		m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, VD(n + 2)) {
			for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = A[i][j];
			for (int i = 0; i < m; i++) { B[i] = n + i; D[i][n] = -1; D[i][n + 1] = b[i]; }
			for (int j = 0; j < n; j++) { N[j] = j; D[m][j] = -c[j]; }
			N[n] = -1; D[m + 1][n] = 1;
		}
	void Pivot(int r, int s) {
		double inv = 1.0 / D[r][s];
		for (int i = 0; i < m + 2; i++) if (i != r)
			for (int j = 0; j < n + 2; j++) if (j != s)
				D[i][j] -= D[r][j] * D[i][s] * inv;
		for (int j = 0; j < n + 2; j++) if (j != s) D[r][j] *= inv;
		for (int i = 0; i < m + 2; i++) if (i != r) D[i][s] *= -inv;
		D[r][s] = inv;
		swap(B[r], N[s]);
	}
	bool Simplex(int phase) {
		int x = phase == 1 ? m + 1 : m;
		while (true) {
			int s = -1;
			for (int j = 0; j <= n; j++) {
				if (phase == 2 && N[j] == -1) continue;
				if (s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s]) s = j;
			}
			if (D[x][s] > -EPS) return true;
			int r = -1;
			for (int i = 0; i < m; i++) {
				if (D[i][s] < EPS) continue;
				if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||
						(D[i][n + 1] / D[i][s]) == (D[r][n + 1] / D[r][s]) && B[i] < B[r]) r = i;
			}
			if (r == -1) return false;
			Pivot(r, s);
		}
	}
	
	DOUBLE Solve(VD &x) {
		int r = 0;
		for (int i = 1; i < m; i++) if (D[i][n + 1] < D[r][n + 1]) r = i;
		if (D[r][n + 1] < -EPS) {
			Pivot(r, n);
			if (!Simplex(1) || D[m + 1][n + 1] < -EPS) return -numeric_limits<DOUBLE>::infinity();
			for (int i = 0; i < m; i++) if (B[i] == -1) {
				int s = -1;
				for (int j = 0; j <= n; j++)
					if (s == -1 || D[i][j] < D[i][s] || D[i][j] == D[i][s] && N[j] < N[s]) s = j;
				Pivot(i, s);
			}
		}
		if (!Simplex(2)) return numeric_limits<DOUBLE>::infinity();
		x = VD(n);
		for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n + 1];
		return D[m][n + 1];
	}
};

vector<int> adj[MAXN], r_adj[MAXN], ord;
int cmp, G[MAXN][MAXN], par[MAXN], F[MAXN], A[MAXN], n, m;
bool vis[MAXN];

void dfs(int v) {
	vis[v] = true;
	for (int u : adj[v])
		if (!vis[u])
			dfs(u);

	ord.push_back(v);
}

void sfd(int v) {
	par[v] = cmp;
	F[cmp] += A[v];
	for (int u : r_adj[v])
		if (!par[u])
			sfd(u);
}

int solve() {
	cmp = 0;
	ord.clear();
	for (int i = 0; i < n + 5; i++) {
		adj[i].clear();
		r_adj[i].clear();
		par[i] = 0;
		memset(G[i], false, sizeof G[i]);
		vis[i] = false;
		F[i] = A[i] = 0;
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> A[i];

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		r_adj[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);

	reverse(all(ord));
	int ind = 0;
	for (int v : ord) {
		if (!par[v]) {
			cmp++;
			sfd(v);
		}
	}

	for (int v = 1; v <= n; v++)
		for (int u : adj[v])
			if (par[v] != par[u] && !G[par[v]][par[u]])
				G[par[v]][par[u]] = ++ind;

	int tn = cmp + ind;
	VVD A;
	VD b, c(tn, 0);
	for (int i = 1; i <= cmp; i++) {	
		VD t(tn, 0), r(tn, 0);
		
		r[i - 1] = -1;

		bool source = true;
		for (int v = 1; v <= cmp; v++) {
			if (G[v][i]) source = false, t[G[v][i] + cmp - 1] += -1, r[G[v][i] + cmp - 1] += -1;
			if (G[i][v]) t[G[i][v] + cmp - 1] += 1;
		}

		A.push_back(t);
		b.push_back(F[i]);
		A.push_back(r);
		b.push_back(-1);
		VD f(tn, 0);
		f[i - 1] = 1;
		A.push_back(f);
		b.push_back(F[i]);
	}

	for (int i = 0; i < cmp; i++)
		c[i] = -1;

	VD x(cmp + ind);
	LPSolver solver(A, b, c);
	DOUBLE res = solver.Solve(x);
	if (isnan(res) || isinf(res)) cout << -1 << endl;
	else {
		int f = -res + EPS;
		cout << f << endl;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}