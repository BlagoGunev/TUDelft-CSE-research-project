#include<bits/stdc++.h>

 

using namespace std;

typedef long long ll;

 

const int N = 2000 + 5, K = 100 + 5, Mod = 998244353;

int n = 0, k = 0, b[N] = {}, m = 0, p = 0;

int dp[2][K][N] = {}, g[N] = {}, ans = 0;

 

int main(){

	scanf("%d %d", &n, &k);

	for(int i = 1 ; i <= n ; ++ i) scanf("%d", &b[i]);

	dp[0][k][0] = 1;

	for(int i = 1 ; i <= n ; ++ i){

		p = p ^ 1;

		for(int j = 0 ; j <= i + 1 ; ++ j) g[j] = 0;

		for(int mex = m ; mex <= min(b[i] + k, i) ; ++ mex) for(int j = 0 ; j <= i - mex ; ++ j){

			g[j] = 1ll * g[j + 1] * (j + 1) % Mod;

			if(mex > m && mex - 1 <= b[i - 1] + k) g[j] = (g[j] + dp[p ^ 1][mex - 1 - b[i - 1] + k][j]) % Mod;

			if(mex >= b[i] - k){

				dp[p][mex - b[i] + k][j] = g[j];

				if(mex <= b[i - 1] + k && mex < i){

					if(j + mex < i) dp[p][mex - b[i] + k][j] = (dp[p][mex - b[i] + k][j] + 1ll * dp[p ^ 1][mex - b[i - 1] + k][j] * (j + mex)) % Mod;

					if(j && j + mex - 1 < i) dp[p][mex - b[i] + k][j] = (dp[p][mex - b[i] + k][j] + dp[p ^ 1][mex - b[i - 1] + k][j - 1]) % Mod;

				}

			}

		}

		m = max(m, b[i] - k);

	}

	for(int j = 0 ; j <= n ; ++ j) g[j] = 0;

	for(int mex = m ; mex <= n ; ++ mex) for(int j = 0 ; j <= n - mex ; ++ j){

		if(mex <= b[n] + k) g[j] = (g[j] + dp[p][mex - b[n] + k][j]) % Mod;

		if(j) g[j - 1] = 1ll * g[j] * (n - mex) % Mod;

		else ans = (ans + g[j]) % Mod;

	}

	printf("%d", ans);

	return 0;

}