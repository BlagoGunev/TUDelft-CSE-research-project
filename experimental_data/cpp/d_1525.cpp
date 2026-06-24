#include <bits/stdc++.h>

const int N = 5010;
const long long INF = 1ll<<60;
const int inf = 0x3f3f3f3f;
typedef std::pair<int, int> PairInt; 
typedef std::pair<long long, int> Pair;
const long long mod = 1e9 + 7;

int t, n;
int a[N];
int b[N], c[N], cntB, cntC;
int dp[2][N];
int preMin[2][N];
int cur;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 0) b[++cntB] = i;
    else c[++cntC] = i;
  }
  if (!cntC) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= cntB; ++i) {
    dp[cur][i] = abs(c[1] - b[i]);
    if (i == 1) preMin[cur][i] = dp[cur][i];
    else preMin[cur][i] = std::min(dp[cur][i], preMin[cur][i - 1]);
    // printf("%d: %d\n", i, preMin[cur][i]);
    dp[cur ^ 1][i] = inf;
    preMin[cur ^ 1][i] = inf;
  }

  for (int i = 2; i <= cntC; ++i) {
    for (int j = i; j <= cntB; ++j) {
      dp[cur ^ 1][j] = preMin[cur][j - 1] + abs(c[i] - b[j]);
      preMin[cur ^ 1][j] = std::min(dp[cur ^ 1][j], preMin[cur ^ 1][j - 1]);
      // printf("[%d %d]: %d\n", i, j, dp[cur ^ 1][j]);
    }
    for (int j = 1; j <= cntB; ++j) dp[cur][i] = preMin[cur][i] = inf;
    cur ^= 1;
  }
  int ans = inf;
  for (int i = cntC; i <= cntB; ++i) ans = std::min(ans, dp[cur][i]);
  printf("%d\n", ans);
  return 0;
}