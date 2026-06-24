#include <bits/stdc++.h>

using namespace std;



#ifdef LOCAL

#include "debug.h"

#else

#define debug(...) 42

#endif



signed main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  int n, m;

  cin >> n >> m;

  string s;

  string t;

  cin >> s >> t;

  s.insert(s.begin(), '.');

  t.insert(t.begin(), '.');

  vector <vector <int>> dp(n + 1, vector <int> (m + 1));

  dp[0][0] = 0;

  int ans = 0;

  for (int i = 1; i <= n; ++i) {

    for (int j = 1; j <= m; ++j) {

      if (s[i] == t[j]) {

        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);

      } else {

        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;

      }

      dp[i][j] = max(dp[i][j], 0);

      ans = max(ans, dp[i][j]);

    }

  }

  cout << ans << '\n';

  return 0;

}