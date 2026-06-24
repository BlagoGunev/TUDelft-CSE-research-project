#include<bits/stdc++.h>

#define endl "\n"

#define int long long

#define ll long long

#define INF 0x3f3f3f3f3f3f3f3f

#define IOS std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int N = 2e5;

const int mod = 1e9 + 7;

int dep[N + 5], p[N + 5];

vector<int>mp[N + 5];

void init() {

	p[0] = 1;

	for (int i = 1; i <= N; i++) {

		p[i] = p[i - 1] * 2 % mod;

	}

}

void dfs(int u, int fa) {

	dep[u] = 1;

	for (auto v : mp[u]) {

		if (v != fa) {

			dfs(v, u);

			dep[u] = max(dep[u], dep[v] + 1);

		}

	}

}

void solve() {

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)mp[i].clear();

	for (int i = 1; i < n; i++) {

		int u, v;

		cin >> u >> v;

		mp[u].push_back(v), mp[v].push_back(u);

	}

	dfs(1, 0);

	int sum = 0;

	for (int i = 1; i <= n; i++) {

		sum = (sum + dep[i]) % mod;

	}

	cout << p[n - 1]*sum % mod << endl;

}

signed main() {

	init();

	IOS;

	int t;

	cin >> t;

	while (t--)

		solve();

}