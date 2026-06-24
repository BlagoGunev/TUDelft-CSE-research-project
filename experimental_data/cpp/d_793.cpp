#include <bits/stdc++.h>
using namespace std;
int f[100][100][100]; // f[l][r], l to r    to right
int g[100][100][100]; 
int inf = 0x3f3f3f3f;
vector<pair<int, int> > a[100];
int n, k, m;
int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[y].push_back(make_pair(x, z));
	}
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	for (int i = 1; i <= n; i++) {
		f[1][i][i] = 0;
		g[1][i][i] = 0;
	}
	for (int v = 1; v < k; v++) {
		for (int l = 0; l <= n; l++) {
			for (int i = 1; i + l <= n; i++) {
				// f[i][i + l]
				if (f[v][i][i + l] != inf) {
					for (int j = 0; j < a[i + l].size(); j++) {
						int x = a[i + l][j].first;
						int y = a[i + l][j].second;
						if (i <= x && x <= i + l) {
							continue;
						}
						if (x < i) {
							g[v + 1][x][i + l] = min(g[v + 1][x][i + l], f[v][i][i + l] + y);
						}
						if (x > i + l) {
							f[v + 1][i][x] = min(f[v + 1][i][x], f[v][i][i + l] + y);
//							printf("f[%d][%d][%d] := %d\n", v + 1, i, x, f[v + 1][i][x]);
						}
//						printf("f[%d][%d][%d] == %d; x==%d; y==%d;\n", v, i, i + l, f[v][i][i + l], x, y);

					}
				}
				// g[i][i + l]
				if (g[v][i][i + l] != inf) {
					for (int j = 0; j < a[i].size(); j++) {
						int x = a[i][j].first;
						int y = a[i][j].second;
						if (i <= x && x <= i + l) {
							continue;
						}
						if (x < i) {
							g[v + 1][x][i + l] = min(g[v + 1][x][i + l], g[v][i][i + l] + y);
//							printf("g[%d][%d][%d] := %d\n", v + 1, x, i + l, g[v + 1][x][i + l]);
						}
						if (x > i + l) {
							f[v + 1][i][x] = min(f[v + 1][i][x], g[v][i][i + l] + y);
						}
//						printf("g[%d][%d][%d] == %d\n", v, i, i + l, g[v][i][i + l]);
					}
				}
			}
		}
	}
	int ans = inf;
	for (int l = 0; l <= n; l++) {
		for (int i = 1; i + l <= n; i++) {
			ans = min(ans, f[k][i][i + l]);
			ans = min(ans, g[k][i][i + l]);
		}
	}
	if (ans == inf) {
		ans = -1;
	}
	cout << ans << endl;
	return 0;
}