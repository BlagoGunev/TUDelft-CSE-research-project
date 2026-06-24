#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 9;

vector<pair<int, int>>graph[N];

bool vis[N];

bool ans[N];

int par[N];

int lv[N];

void dfs(int x, int p) {

	vis[x] = 1;

	if (x == 1)lv[1] = 0;

	else lv[x] = lv[p] + 1;

	for (auto y : graph[x]) {

		if (!vis[y.first]) {

			ans[y.second] = 1;

			par[y.first] = y.second;

			dfs(y.first, x);

		}

	}

}

int main() {

	ios::sync_with_stdio(0);

	cin.tie(0);

	int t;

	cin >> t;

	while (t--) {

		int n, m;

		cin >> n >> m;

		for (int i = 0; i <= m; i++) {

			ans[i] = 0;

			vis[i] = 0;

			graph[i].clear();

		}

		vector<pair<int, int>>edges;

		for (int i = 0; i < m; i++) {

			int a, b;

			cin >> a >> b;

			graph[a].push_back({b, i});

			graph[b].push_back({a, i});

			edges.push_back({a, b});

		}

		dfs(1, 0);

		if (m == n + 2) {

			set<int>st;

			vector<int>ed;

			for (int i = 0; i < m; i++) {

				if (!ans[i]) {

					st.insert(edges[i].first);

					st.insert(edges[i].second);

					ed.push_back(i);

				}

			}

			// for (int x : st) {

			// 	cout << x << endl;

			// }

			if (st.size() == 3) {

				int mn = -1;

				int id1 = 0, id2 = 0;

				for (int i = 0; i < 3; i++) {

					if (lv[edges[ed[i]].first] > mn) {

						mn = lv[edges[ed[i]].first];

						id1 = ed[i];

						id2 = par[edges[ed[i]].first];

					}

					if (lv[edges[ed[i]].second] > mn) {

						mn = lv[edges[ed[i]].second];

						id1 = ed[i];

						id2 = par[edges[ed[i]].second];

					}

				}

				swap(ans[id1], ans[id2]);

			}



		}

		for (int i = 0; i < m; i++) {

			cout << ans[i];

		}

		cout << '\n';

	}



}