#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

inline int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}

int f[2][209];
int nf[2][209];

int main() {
  memset(f, 0, sizeof f);
  for (int i = 0; i <= 200; ++i) {
    f[0][i] = 1;
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    memset(nf, 0, sizeof nf);
    int x;
    scanf("%d", &x);
    for (int j = 1; j <= 200; ++j) {
      nf[0][j] = nf[0][j - 1];
      nf[1][j] = nf[1][j - 1];
      if (x == -1 || j == x) {
        nf[0][j] = add(nf[0][j], add(f[0][j - 1], f[1][j - 1]));
        nf[1][j] = add(nf[1][j], sub(f[0][j], f[0][j - 1]));
        nf[1][j] = add(nf[1][j], sub(f[1][200], f[1][j - 1]));
      }
    }
    memcpy(f, nf, sizeof f);
  }
  printf("%d\n", f[1][200]);
}