#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

void output(char c, int k) {
  while (k--)
    putchar(c);
}

int main() {
  int a, b, c, d;
  while (~scanf("%d %d %d %d", &a, &b, &c, &d)) {
    if (c == d) {
      if (a >= c + 1 and b >= c) {
        output('4', a - c);
        for (int i = 0; i < c; i++) {
          output('7', i == c - 1 ? 1 + b - c : 1);
          output('4', 1);
        }
        puts("");
      } else if (a >= c and b >= c + 1) {
        output('7', 1);
        for (int i = 0; i < c; i++) {
          output('4', i == 0 ? 1 + a - c : 1);
          output('7', i == c - 1 ? b - c : 1);
        }
        puts("");
      } else {
        puts("-1");
      }
    } else if (c == d + 1) {
      if (a >= c and b >= c) {
        for (int i = 0; i < c; i++) {
          output('4', i == 0 ? 1 + a - c : 1);
          output('7', i == c - 1 ? 1 + b - c : 1);
        }
        puts("");
      } else {
        puts("-1");
      }
    } else if (d == c + 1) {
      if (a >= d and b >= d) {
        for (int i = 0; i < d; i++) {
          output('7', i == d - 1 ? 1 + b - d : 1);
          output('4', i == 0 ? 1 + a - d : 1);
        }
        puts("");
      } else {
        puts("-1");
      }
    } else {
      puts("-1");
    }
  }
  return 0;
}