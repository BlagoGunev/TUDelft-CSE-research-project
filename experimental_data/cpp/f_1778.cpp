// LUOGU_RID: 101262776
#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1e9;
int n, k, a[100005], f[100005][1005];
vector <int> Div[1005], g[100005];
int Gcd[1005][1005], Lcm[1005][1005], sum[100005];
void dfs(int u, int fa) {
	sum[u] = a[u];
	for (auto v : g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		sum[u] = Gcd[ sum[u] ][ sum[v] ];
	}
}
int dp(int u, int d, int fa) {
	if (sum[u] % d == 0) return 0;
	if ((a[u] * a[u]) % d) return inf;
	if (f[u][d] != -1) return f[u][d];
	int &ans = f[u][d] = inf;
	for (auto i : Div[d]) {
		if (a[u] % i == 0 && (a[u] * i) % d == 0) {
			int res = 0;
			if (i > 1) res = 1;
			for (auto j : g[u]) {
				if (j == fa) continue;
				res += dp(j, Lcm[ d / i ][i], u);
				res = min(res, inf);
			}
			ans = min(ans, res);
		}
	}
	return ans;
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i], g[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		for (auto j : Div[ a[1] ]) {
			f[i][j] = -1;
		}
	}
	int ans = a[1];
	for (auto i : Div[ a[1] ]) {
		int sum = 0;
		for (auto j : g[1]) {
			sum += dp(j, i, 1);
			sum = min(sum, inf);
		}
		if (sum + 1 <= k) {
			ans = a[1] * i;
		}
	}
	cout << ans << '\n';
}
int main() {
	ios :: sync_with_stdio(0), cin.tie(0);
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			Gcd[i][j] = __gcd(i, j);
		}
	}
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			Lcm[i][j] = i / Gcd[i][j] * j;
		}
	}
	for (int i = 1; i <= 1000; ++i) {
		for (int j = i; j <= 1000; j += i) {
			Div[j].push_back(i);
		}
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}