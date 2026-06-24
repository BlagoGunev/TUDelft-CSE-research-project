// LUOGU_RID: 154179201
#include <bits/stdc++.h>
using namespace std;
int m, X, Y, n, a[405];
long long b[405], dp[405][405], g[405][405], f[405][405];
int main(){
	scanf("%d%d%d", &m, &X, &Y);
	for(int i = 1; i <= m; i++){
		int x;
		scanf("%d", &x);
		if(a[n] == x) b[n]++;
		else a[++n] = x, b[n] = 1;
	}
	for(int i = 1; i <= n; i++) b[i] *= Y;
	memset(dp, 0x3f, sizeof(dp));
	memset(f, 0x3f, sizeof(f));
	memset(g, 0x3f, sizeof(g));
	
	for(int i = 1; i <= n; i++)dp[i][i] = X;
	for(int i = 1; i <= n + 1; i++){
		dp[i][i - 1] = f[i][i - 1] = g[i][i - 1] = 0;
	}
	
	for(int l = n; l >= 1; l--){
		f[l][l] = 2 * b[l], g[l][l] = b[l];
		for(int r = l + 1; r <= n; r++){
			dp[l][r] = dp[l + 1][r] + X;
			if(a[r] != a[l]){
				for(int pos = l; pos < r; pos++){
					if(a[pos] == a[l]){
						dp[l][r] = min(dp[l][r], min(f[l][pos] - 2 * b[pos], g[l][pos]) + dp[pos + 1][r] + X);
					}
				}
			} else {
				for(int pos = l; pos < r; pos++){
					if(a[pos] == a[l]){
						f[l][r] = min(f[l][r], f[l][pos] + dp[pos + 1][r - 1] + b[r] * 2);
					}
				}
				for(int pos = l; pos < r; pos++){
					if(a[pos] == a[l]){
						g[l][r] = min(g[l][r], g[l][pos] + dp[pos + 1][r - 1] + b[r]);
					}
				}
				for(int pos = l; pos <= r; pos++){
					if(a[pos] == a[l]){
						dp[l][r] = min(dp[l][r], min(f[l][pos] - 2 * b[pos], g[l][pos]) + dp[pos + 1][r] + X);
					}
				}
			}
		}
	}
	printf("%lld", dp[1][n]);
	return 0;
}