#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

typedef long long LL;

inline int readInt() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f *= -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}

const int N = 300050;

struct Mach{
  int x, y;
  bool operator<(const Mach & p) const {
    return x < p.x;
  }
}A[N];

int main() {
  int n = readInt();
  int x1 = readInt();
  int x2 = readInt();
  for (int i = 0; i < n; ++i) {
    A[i].x = readInt();
    A[i].y = i + 1;
  }
  std::sort(A, A + n);
  int i = n;
  while (i >= 0 && (LL)A[i].x * (n - i) < x1) --i;
  int j = i;
  while (j >= 0 && (LL)A[j].x * (i - j) < x2) --j;
  if (j >= 0) {
    puts("Yes");
    printf("%d %d\n", n - i, i - j);
    for (int k = i; k < n; ++k)
      printf("%d ", A[k].y);
    printf("\n");
    for (int k = j; k < i; ++k)
      printf("%d ", A[k].y);
    return 0;
  }
  i = n;
  while (i >= 0 && (LL)A[i].x * (n - i) < x2) --i;
  j = i;
  while (j >= 0 && (LL)A[j].x * (i - j) < x1) --j;
  if (j >= 0) {
    puts("Yes");
    printf("%d %d\n", i - j, n - i);
    for (int k = j; k < i; ++k)
      printf("%d ", A[k].y);
    printf("\n");
    for (int k = i; k < n; ++k)
      printf("%d ", A[k].y);
    return 0;
  }
  puts("No");
  return 0;
}