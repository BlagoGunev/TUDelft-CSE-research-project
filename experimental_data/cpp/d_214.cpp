#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)(x).size())
#define rep(i,l,r) for(int i=(l);i<(r);++i)
//-------head-------
const int N = 107;
const int MOD = 1e9 + 7;
int n, a[10], dp[N][N], c[N][N];
void inc(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}
int main() {
	rep(i, 0, N) {
		c[i][0] = c[i][i] = 1;
		rep(j, 1, i)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	scanf("%d", &n);
	rep(i, 0, 10) scanf("%d", a + i);
	dp[0][0] = 1;
	rep(i, 1, 10)
		rep(j, a[i], n + 1)
			rep(k, a[i], j + 1)
				inc(dp[i][j], 1ll * dp[i - 1][j - k] * c[j][k] % MOD);
	rep(j, a[0] + 1, n + 1)
		rep(k, a[0], j)
			inc(dp[10][j], 1ll * dp[9][j - k] * c[j - 1][k] % MOD);
//	rep(i, 1, 11)
//		rep(j, 0, n + 1)
//			if (dp[i][j])
//				printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	int ans = 0;
	rep(i, 1, n + 1)
		inc(ans, dp[10][i]);
	printf("%d", ans);
	return 0;
}