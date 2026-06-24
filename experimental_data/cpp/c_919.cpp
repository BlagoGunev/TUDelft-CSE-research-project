#include <bits/stdc++.h>

using namespace std;

int n, m, k, y[2005], ans, ta;
char x[2005];

int main() {
 scanf("%d%d%d", &n, &m, &k);
 for (int i = 0; i < n; i++) {
  ta = 0;
  scanf("%s", x);
  for (int j = 0; j < m; j++)
   if (x[j] == '*') {
    y[j] = 0;
    ta = 0;
   } else {
    y[j]++;
    ans += y[j] >= k;
    ta++;
    ans += k > 1 && ta >= k;
   }
 }
 printf("%d\n", ans);
 return 0;
}