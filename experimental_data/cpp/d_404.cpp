#include <bits/stdc++.h>



using namespace std;



const int N = 1000006, MOD = 1000000007;

char s[N];

int dp[N][3];



int main() {

#ifndef ONLINE_JUDGE

  freopen("in.txt", "r", stdin);

#endif

  scanf("%s", s);

  int n = strlen(s);

  dp[n][0] = dp[n][2] = 1;

  for (int i = n - 1; i >= 0; --i) {

    if (s[i] == '?') {

      dp[i][0] = (dp[i + 1][0] + dp[i + 1][1]) % MOD;

      dp[i][1] = dp[i + 1][2];

      dp[i][2] = ((dp[i + 1][0] + dp[i + 1][1]) % MOD + dp[i + 1][2]) % MOD;

    } else if (s[i] == '0') {

      dp[i][0] = dp[i + 1][0];

    } else if (s[i] == '1') {

      dp[i][0] = dp[i + 1][1];

      if (i)

        dp[i][2] = dp[i + 1][0];

    } else if (s[i] == '2') {

      if (i)

        dp[i][2] = dp[i + 1][1];

    } else {

      dp[i][1] = dp[i + 1][2];

      dp[i][2] = dp[i + 1][2];

    }

  }

  printf("%d\n", (dp[0][0] + dp[0][1]) % MOD);

}