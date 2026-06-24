#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  if (x == y) {
    puts("=");
  } else if (x < 3 || y < 3) {
    double a = pow(x, y), b = pow(y, x);
    if (a < b) puts("<");
    else if (a > b) puts(">");
    else puts("=");
  } else {
    if (x > y) puts("<");
    else puts(">");
  }
}