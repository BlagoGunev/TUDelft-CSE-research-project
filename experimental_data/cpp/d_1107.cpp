#include <bits/stdc++.h>

using namespace std;

const int N = 5205;

char s[N];
string to[N];
int n, p[N][N];

string get (int x) {
  string res = "";
  for (int i = 3; i >= 0; --i) {
    if (x & 1 << i) res += '1';
    else res += '0';
  }
  return res;
}

inline int sum (int i, int j, int x) {
  return p[i + x - 1][j + x - 1] - p[i - 1][j + x - 1] - p[i + x - 1][j - 1] + p[i - 1][j - 1];
}

int main() {
  for (int i = 0; i < 10; ++i) {
    to['0' + i] = get(i);
  }
  for (int i = 10; i < 16; ++i) {
    to[i - 10 + 'A'] = get(i);
  }
  cin >> n;
  int m = n / 4;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1, ptr = 0; j <= m; ++j) {
      for (int k = 0; k < 4; ++k) {
        p[i][++ptr] = to[s[j]][k] - '0';
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    }
  }
  for (int x = n; x > 1; --x) {
    if (n % x) continue;
    int sq = x * x, good = 1, here;
    if (p[n][n] % sq) continue;
    for (int i = 1; good and i <= n; i += x) {
      for (int j = 1; good and j <= n; j += x) {
        here = sum(i, j, x);
        if (here == 0 or here == sq) continue;
        good = 0; break;
      }
    }
    if (good) {
      printf("%d\n", x);
      return 0;
    }
  }
  puts("1");
  return 0;
}