#include<bits/stdc++.h>

using namespace std;

using ll = long long;

using a3 = array<array<array<ll, 2>, 2>, 3>;

const ll lnf = 2e18;



void clr(a3 &a) {

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 2; j++) {

			for (int k = 0; k < 2; k++) {

				a[i][j][k] = lnf;

			}

		}

	}

}



void upd(ll &v, ll val) {

	v = min(v, val);

}



struct Tree {

	vector<vector<pair<int, int>>> e;

	vector<a3> f;

	Tree(int n) : e(n + 1), f(n + 1) {

		for (int i = 1; i < n; i++) {

			int u, v, w;

			cin >> u >> v >> w;

			e[u].emplace_back(v, w);

			e[v].emplace_back(u, w);

		}

		for (int i = 0; i <= n; i++) {

			clr(f[i]);

		}

	}

	void solve() {

		dfs(1, 1);

		ll ans = lnf;

		for (int c = 0; c < 3; c++) {

			if (c == 2) {

				ans = min(ans, f[1][c][1][0]);

			} else {

				ans = min({ans, f[1][c][1][0], f[1][c][1][1]});

			}

		}

		printf("%lld\n", ans);

	}

	void dfs(int v, int fa) {

		for (auto [u, w] : e[v]) {

			if (u != fa) {

				dfs(u, v);

			}

		}

		{

			for (int c = 0; c < 3; c++) {

				f[v][c][0][0] = f[v][c][1][1] = 0;

			}

			for (auto [u, w] : e[v]) {

				if (u != fa) {

					static a3 tmp;

					clr(tmp);

					for (int cv = 0; cv < 3; cv++) {

						for (int cu = 0; cu + cv < 3; cu++) {

							int cs = cu + cv;

							upd(tmp[cs][0][0], f[v][cv][0][0] + f[u][cu][0][0] + w * 2);

							upd(tmp[cs][1][0], f[v][cv][1][0] + f[u][cu][0][0] + w * 2);

							upd(tmp[cs][1][1], f[v][cv][1][1] + f[u][cu][0][0] + w * 2);

							if (cs + 1 < 3) {

								upd(tmp[cs + 1][1][0], f[v][cv][1][1] + f[u][cu][0][0] + w * 2);

							}



							upd(tmp[cs][0][0], f[v][cv][0][0] + f[u][cu][1][0]);

							upd(tmp[cs][1][0], f[v][cv][0][0] + f[u][cu][1][0] + w * 2);

							upd(tmp[cs][1][0], f[v][cv][1][0] + f[u][cu][1][0]);

							upd(tmp[cs][1][1], f[v][cv][1][1] + f[u][cu][1][0]);

							if (cs + 1 < 3) {

								upd(tmp[cs + 1][1][0], f[v][cv][1][1] + f[u][cu][1][0]);

							}



							if (cs + 1 < 3) {

								upd(tmp[cs + 1][0][0], f[v][cv][0][0] + f[u][cu][1][1]);

								upd(tmp[cs + 1][1][0], f[v][cv][0][0] + f[u][cu][1][1] + w);

							}

							upd(tmp[cs][1][1], f[v][cv][0][0] + f[u][cu][1][1] + w);

							if (cs + 1 < 3) {

								upd(tmp[cs + 1][1][0], f[v][cv][1][0] + f[u][cu][1][1]);

							}

							upd(tmp[cs][1][1], f[v][cv][1][0] + f[u][cu][1][1] + w);

							if (cs + 1 < 3) {

								upd(tmp[cs + 1][1][1], f[v][cv][1][1] + f[u][cu][1][1]);

								upd(tmp[cs + 1][1][0], f[v][cv][1][1] + f[u][cu][1][1] + w);

							}

						}

					}

					f[v] = tmp;

				}

			}

		}

	}

};



int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr), cout.tie(nullptr);

	int n;

	cin >> n;

	Tree tr(n);

	tr.solve();

	return 0;

}