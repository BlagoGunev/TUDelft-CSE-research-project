#include <bits/stdc++.h>

using namespace std;

int x[105], y[105];

int main() {

  int n, a = 0, b = 0, p, q;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {

    scanf("%d %d", &p, &q);

    a += x[p]++ == 0;

    b += y[q]++ == 0;

  }

  printf("%d\n", min(a, b));

  return 0;

}