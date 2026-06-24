#include <cstdio>

int B[510][510], C[510][510], D[510][510], E[510][510];

int main () {
  int n, m;
  scanf ("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf ("%d", &B[i][j]);
      C[i][j + 1] = C[i][j] + B[i][j];
      D[i + 1][j + 1] = D[i][j + 1] + C[i][j + 1];
      E[i][j] = B[i][j];
    }
  int klim = n;
  int ans = (int)-2e9;
  if (m < klim) klim = m;
  for (int k = 3; k <= klim; k += 2) {
    for (int i = 0; i <= n - k; i++)
      for (int j = 0; j <= m - k; j++) {
	int A = D[i + k][j + k] - D[i + k][j] - D[i][j + k] + D[i][j];
	E[i][j] = A - B[i + 1][j] - E[i + 1][j + 1];
	if (E[i][j] > ans) ans = E[i][j];
	//printf ("%d %d %d: %d\n", i, j, k, E[i][j]);
      }
  }
  printf ("%d\n", ans);
  return 0;
}