// learned from https://www.luogu.com.cn/article/j3hgg8z8
#include <bits/stdc++.h>
using namespace std;
const int maxk = 15;
const int maxn = 8200;
const int mod = 998244353;
int k, n;
void solve(char *s, int *f) {
  int rev[maxn];
  for (int i = 0; i < (1 << k + 1); i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
  for (int i = 0; i < (1 << k + 1); i++)
    if (i < rev[i]) swap(s[i], s[rev[i]]);
  vector<vector<vector<int>>> dp[maxk];
  for (int i = 0; i <= k + 1; i++) {
    dp[i].clear();
    dp[i].resize(1 << i);
    for (int j = 0; j < (1 << i); j++) {
      dp[i][j].resize((1 << k + 1 - i));
      for (int l = 0; l < (1 << k + 1 - i); l++) {
        int c = i - __builtin_popcount(j);
        dp[i][j][l].resize((1 << c) + 1);
      }
    }
  }
	
  for (int i = 0; i < (1 << k + 1); i++) {
    if (s[i] != '1') dp[0][0][i][0] = 1;
    if (s[i] != '0') dp[0][0][i][1] = 1;
  }
	
  for (int i = 1; i <= k + 1; i++) {
    for (int j = 0; j < (1 << i - 1); j++) {
      for (int l = 0; l < (1 << k + 1 - i); l++) {
        int c = i - 1 - __builtin_popcount(j);
        for (int x = 0; x <= (1 << c); x++)
          for (int y = 0; y <= (1 << c); y++) {	
            dp[i][j][l][x + y] = (dp[i][j][l][x + y] + 1ll * dp[i - 1][j][l << 1][x] * dp[i - 1][j][l << 1 | 1][y]) % mod;
					}
        for (int x = 0; x <= (1 << c); x++) {	
          dp[i][j + (1 << i - 1)][l][x] = 1ll * dp[i - 1][j][l << 1][x] * dp[i - 1][j][l << 1 | 1][x] % mod;
				}
      }
    }
  }
  for (int i = 0; i < (1 << k + 1) - 1; i++)
    f[i] = dp[k + 1][i][0][1 << (k - __builtin_popcount(i))];
}

int f[maxn], g[maxn];
char s[maxn], t[maxn];
int main() {
  scanf("%d%s%s", &k, s, t);
  n = (1 << k + 1);
  reverse(t, t + n);
  solve(s, f);
  solve(t, g);
  int res = 0;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < (1 << k + 1); j++)
      if (~j >> i & 1)
        f[j] = (f[j] - f[j | (1 << i)] + mod) % mod;
  for (int i = 0; i < (1 << k + 1); i++)
    res = (res + 1ll * f[i] * g[(1 << k + 1) - 1 - i]) % mod;
  printf("%d\n", res);
}