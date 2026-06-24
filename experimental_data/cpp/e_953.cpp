#include <stdio.h>

// NOT MY CODE
// Testing to submit this code
// because I cannot understand that it runs slow

int n, i, j, x, a[200100], ae;
int main(void) {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    a[ae] = x;
    ae++;
    while (ae > 1 && a[ae - 1] == a[ae - 2]) {
      a[ae - 2]++;
      ae--;
    }
  }
  printf("%d\n", ae);
  for (i = 0; i < ae; i++) {
    printf("%d ", a[i]);
  }
  puts("");
  return 0;
}