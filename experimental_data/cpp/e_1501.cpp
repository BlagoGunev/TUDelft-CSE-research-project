#include <bits/stdc++.h>



using namespace std;



#define endl '\n'

typedef long long LL;

#define NX 1505

int a[NX][NX], b[NX][NX];



queue <int> Q;

int vis[NX], deg[NX];

int id[NX];

int t[NX];

vector <pair <pair <int, int>, int>> V;



int main() {

#ifndef ONLINE_JUDGE

	freopen ("in.txt", "r", stdin);

#endif



	ios::sync_with_stdio(0);

	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) cin >> a[i][j];

	for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) cin >> b[i][j];

	for (int i = 0; i < m; i ++) {

		for (int j = 0; j < n - 1; j ++) if (b[j][i] > b[j + 1][i]) deg[i] ++;

		if (!deg[i]) Q.push(i);

	}

	vector <int> ans;

	ans.clear();

	while (!Q.empty()) {

		int c = Q.front();

		Q.pop();

		ans.push_back(c);

		for (int i = 0; i < n - 1; i ++)

			if (!vis[i] && b[i][c] < b[i + 1][c]) {

				for (int j = 0; j < m; j ++) {

					if (b[i][j] > b[i + 1][j]) {

						deg[j] --;

						if (!deg[j]) Q.push(j);

					}

				}

				vis[i] = 1;

			}

	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < n; i ++) id[i] = i;

	for (auto c : ans) {

		V.clear();

		for (int j = 0; j < n; j ++) V.push_back({{a[id[j]][c], j}, id[j]});

		sort (V.begin(), V.end());

		for (int i = 0; i < n; i ++) id[i] = V[i].second;

	}

	for (int i = 0; i < n; i ++)

		for (int j = 0; j < m; j ++) if (a[id[i]][j] != b[i][j]) {

			cout << -1 << endl;

			return 0;

		}

	cout << ans.size() << endl;

	for (auto v : ans) cout << v + 1 << ' '; cout << endl;

	return 0;

}