#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> II;

const int N = (int) 5e3 + 10;
const int INF = (int) 0x3f3f3f3f;
int n, a[N], f[N], g[N];
short nxt[3][N][N];
short dp[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

	for (int i = 1; i <= n; ++i) nxt[0][n + 1][i] = n + 1;
	for (int i = 1; i <= n; ++i) nxt[1][n + 1][i] = n + 1;
	for (int i = 1; i <= n; ++i) nxt[2][n + 1][i] = n + 1;
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= n; ++j) nxt[0][i][j] = nxt[0][i + 1][j];
		for (int j = 1; j <= n; ++j) nxt[1][i][j] = nxt[1][i + 1][j];
		for (int j = 1; j <= n; ++j) nxt[2][i][j] = nxt[2][i + 1][j];
		for (int j = 1; j <= n; ++j) {
			if (a[i] % 7 == a[j] % 7) nxt[0][i][j] = i;
			if (a[i] - a[j] == 1) nxt[1][i][j] = i;
			if (a[j] - a[i] == 1) nxt[2][i][j] = i;
		}
	}

	for (int i = 1; i <= n; ++i) f[i] = g[i] = 1;
	for (int i = 1; i <  n; ++i) {
		for (int k = 0; k < 3; ++k) {
			int t = nxt[k][i + 1][i]; if (t == n + 1) continue;
			f[t] = max(f[t], f[i] + 1);
		}
	}
	for (int i = n - 1; i >= 1; --i) {
		for (int k = 0; k < 3; ++k) {
			int t = nxt[k][i + 1][i]; if (t == n + 1) continue;
			g[i] = max(g[i], g[t] + 1);
		}
	}

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = -20000;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i - 1; ++j)
			dp[i][j] = f[j] + 1;
	for (int i = 1; i < n; ++i) for (int p = 1; p <= n - 1; ++p) {
		for (int k = 0; k < 3; ++k) {
			int f = nxt[k][i + 1][i]; if (f == n + 1) continue;
			dp[f][p] = max((int) dp[f][p], dp[i][p] + 1);
		}
		for (int k = 0; k < 3; ++k) {
			int f = nxt[k][i + 1][p]; if (f == n + 1) continue;
			dp[f][i] = max((int) dp[f][i], dp[i][p] + 1);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i - 1; ++j)
			ans = max(ans, dp[i][j] + g[i] - 1);
	printf("%d", ans);
	return 0;
}