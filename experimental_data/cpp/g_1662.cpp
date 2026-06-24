#include <bits/stdc++.h>



using namespace std;



typedef long long ll;



const int N = (int)1e6;



bitset<N> f;



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	

	int n;

	cin >> n;

	auto g = vector(n, vector<int>());

	

	for(int i = 1; i < n; i++) {

		int p;

		cin >> p;

		p -= 1;

		g[p].push_back(i);

		g[i].push_back(p);

	}

	

	vector<int> sz(n, 0);

	function<void(int, int)> dfs = [&](int u, int fa) {

		sz[u] = 1;

		for(auto v : g[u]) {

			if(v == fa) continue;

			dfs(v, u);

			sz[u] += sz[v];

		}

	};

	

	function<int(int, int)> getCen = [&](int u, int fa) {

		for(auto v : g[u]) {

			if(v == fa || sz[v] * 2 <= n) continue;

			return getCen(v, u);

		}

		return u;

	};

	

	dfs(0, -1);

	int root = getCen(0, -1);

	dfs(root, -1);

	

	vector<int> cnt(n, 0);

	for(auto v : g[root]) {

		cnt[sz[v]] += 1;

	}

	f[0] = 1;

	for(int i = 1; i < n; i++) {

		if(cnt[i]) {

			int k = 1;

			while(k <= cnt[i]) {

				f |= f << (i * k);

				cnt[i] -= k;

				k <<= 1;

			}

			if(cnt[i]) f |= f << (i * cnt[i]);

		}

	}

	

	ll res = 0;

	for(int i = 0; i < n; i++) {

		if(f[i]) res = max(res, (ll)i * (n - i - 1));

	}

	res += accumulate(sz.begin(), sz.end(), 0ll);

	cout << res << '\n';

	

	return 0;	

}