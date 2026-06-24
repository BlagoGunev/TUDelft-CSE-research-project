#include <bits/stdc++.h>

using namespace std;



int main() {

  int n, k;

  cin >> n >> k;

  vector d(n, vector<int>(n));

  for (int i = 0; i < n; i++)

    for (int j = 0; j < n; j++) {

      int x;

      cin >> x;

      d[i][j] = x;

    }



  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

  int ans = 1e9;

  for (int it = 0; it < 10000; it++) {

    vector<int> L, R;

    for (int i = 0; i < n; i++) {

      if (rng() % 2 || i == 0)

        L.push_back(i);

      else

        R.push_back(i);

    }



    vector dp(k + 1, vector<int>(n, 1e9));

    for (int v : R)

      dp[1][v] = d[0][v];



    for (int i = 1; i < k; i++) {

      if (i % 2)

        for (int rv : R)

          for (int lv : L)

            dp[i + 1][lv] = min(dp[i + 1][lv], dp[i][rv] + d[rv][lv]);

      else

        for (int lv : L)

          for (int rv : R)

            dp[i + 1][rv] = min(dp[i + 1][rv], dp[i][lv] + d[lv][rv]);

    }

    ans = min(ans, dp[k][0]);

  }

  cout << ans << "\n";

}