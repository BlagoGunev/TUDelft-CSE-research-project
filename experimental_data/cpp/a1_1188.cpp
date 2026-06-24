#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

typedef long long LL;

int read() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f *= -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}

const int N = 100050;

int deg[N];

int main() {
  int n = read();
  for (int i = 1; i < n; ++i) {
    ++deg[read()];
    ++deg[read()];
  }
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 2) return puts("NO") & 0;
  return puts("YES") & 0;
}