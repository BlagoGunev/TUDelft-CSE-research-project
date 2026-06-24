#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

int one[2222];
int two[2222];
int main() {
 int n; scanf("%d", &n);
 int t;
 int s1 = 0, s2 = 0;
 for (int i = 1; i <= n; i++) {
  scanf("%d", &t);
  if (t == 1)s1++;
  else s2++;
  one[i] = s1;
  two[i] = s2;
 }
 int dap = 0;
 for (int i = 1; i <= n; i++) {
  int h1 = 0, h2 = 0;
  for (int j = 1; j < i; j++) {
   int cur = one[j-1] + two[i-1] - two[j-1];
   h1 = max(h1, cur);
  }
  for (int j = i; j <= n; j++) {
   int cur = two[n] - two[j - 1] + one[j] - one[i-1];
   h2 = max(h2, cur);
  }
  dap = max(dap, h1 + h2);
 }
 printf("%d", dap);
}