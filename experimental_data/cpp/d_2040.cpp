//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> ii;
typedef vector<bool> vb;

#define INF (int)1e9+1
#define INFLL (ll)1e18+1
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORS(i, n) for(int i = 1; i <= n; i++)
#define FORB(i, s, n) for(int i = s; i < n; i++)
#define FORE(x, v) for (auto &x : v)
#define FORR(i, n) for (int i = n-1; i >= 0; i--)
#define REP(n) for (int _ = 0; _ < n; _++)
#define PB push_back
#define F first
#define S second
#define SORT(v) sort(v.begin(), v.end())
#define FILL(v, x) fill(v.begin(), v.end(), x)

bool is[400005];

void solve() {
	int n; cin >> n;
	vector<vector<int>> adj(n);
	REP(n-1) {
		int v, u; cin >> v >> u; v--; u--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	vector<int> v(n, -1);
	v[0] = 1;
	vector<int> cnt(n, 0);
	vector<vector<int>> ch(n);
	auto dfs = [&](auto &&self, int i, int p) -> void {
		for (auto u : adj[i]) if (u != p) {
			ch[i].push_back(u);
			self(self, u, i);
		}
	};
	dfs(dfs, 0, -1);
	set<int> z;
	z.insert(0);
	int chk = n - 1;
	for (int x = 2; x <= n * 2; x++) {
		for (auto i : z) if (!is[x - v[i]]) {
			int u = ch[i][cnt[i]++];
			if (cnt[i] == (int)ch[i].size()) z.erase(i);
			v[u] = x;
			chk--;
			if (ch[u].size()) z.insert(u);
			break;
		}
	}
	if (chk) {
		cout << -1 << '\n';
		return;
	}
	for (auto x : v) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(is, 1, sizeof is);
	is[0] = is[1] = 0;
	for (int i = 2; i < 400005; i++) {
		if (!is[i]) continue;
		for (ll j = 1LL * i * i; j < 400005; j += i) is[j] = 0;
	}
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}