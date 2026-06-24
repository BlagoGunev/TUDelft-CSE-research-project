#include <bits/stdc++.h>

#ifdef ZAYIN
#include "dbg/dbg.h"
#else
#define dbg(...)
#define dbgf(...)
#endif

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int testcase;
  std::cin >> testcase;
  while (testcase--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::vector<int> cur_mex(n + 1, -1);
    std::vector<std::vector<std::pair<int, int>>> Ls(n + 1);
    for (int i = 1; i <= n; ++i) {
      std::vector<bool> vis(n + 1);
      int mex = 0;
      for (int j = i; j; --j) {
        vis[a[j]] = true;
        while (vis[mex]) ++mex;
        if (cur_mex[j] == mex) continue;
        cur_mex[j] = mex;
        if (j == i || cur_mex[j] != cur_mex[j + 1]) {
          Ls[i].emplace_back(j, mex);
        }
      }
    }
    constexpr int w = 8192;
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(w));
    dp[0][0] = true;
    for (int r = 1; r <= n; ++r) {
      dp[r] = dp[r - 1];
      for (auto [l, mex] : Ls[r]) {
        for (int x = 0; x < w; ++x)
          if (dp[l - 1][x ^ mex]) {
            dp[r][x] = true;
          }
      }
    }

    int ans = w - 1;
    while (!dp[n][ans]) --ans;
    std::cout << ans << std::endl;
    dbg(Ls);
  }
  return 0;
}
/*
[README BEFORE SUBMISSION]
1. should use long long?
2. is sum of n/m/q guaranteed if multiple testcase enable?
*/