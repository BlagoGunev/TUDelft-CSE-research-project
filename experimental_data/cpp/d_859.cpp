#include <stdio.h>
#include <algorithm>
#define MAX 69

using namespace std;

int pr[MAX][MAX];
double wpr[MAX][MAX], dp[MAX][MAX];

int main() {
  int n;
  scanf("%d", &n);
  int num_participants = (1 << n);
  for (int i = 1; i <= num_participants; i++) {
    for (int j = 1; j <= num_participants; j++) {
      scanf("%d", &pr[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= num_participants; j++) {
      int last = ((j - 1) / (1 << i)) * (1 << i);
      for (int k = 1; k <= (1 << (i - 1)); k++) {
	int op;
	if (j <= last + (1 << (i - 1))) {
	  op = last + (1 << (i - 1)) + k;
	} else {
	  op = last + k;
	}
	if (i == 1) {
	  wpr[i][j] = pr[j][op] / 100.0;
	} else {
	  wpr[i][j] += wpr[i - 1][j] * wpr[i - 1][op] * (pr[j][op] / 100.0);
	}
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= num_participants; j++) {
      int last = ((j - 1) / (1 << i)) * (1 << i);
      for (int k = 1; k <= (1 << (i - 1)); k++) {
	int op;
	if (j <= last + (1 << (i - 1))) {
	  op = last + (1 << (i - 1)) + k;
	} else {
	  op = last + k;
	}
	if (i == 1) {
	  dp[i][j] = wpr[i][j];
	} else {
	  dp[i][j] = max(
	      dp[i][j],
	      dp[i - 1][j] + dp[i - 1][op] + wpr[i][j] * (1 << (i - 1)));
	}
      }
    }
  }
  double ans(0.0);
  for (int i = 1; i <= num_participants; i++) {
    ans = max(ans, dp[n][i]);
  }
  printf("%.10lf\n", ans);
  return 0;
}