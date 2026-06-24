#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

const int maxn = 101000;
const int maxm = 20;

char s[maxn];
char bad[maxm][maxm];
int bl[maxm];
int best = 0, pos = 0, n, l;

int PosBad(int p) {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    bool prov = true;
    if (bl[i] <= (p+1)) {
      for (int j = 0; j < bl[i]; ++j) {
        if (s[p-bl[i]+1+j] != bad[i][j]) {
          prov = false;
          break;
        }
      }
      if (prov) {
        if (p-bl[i]+2 > ans) {
          ans = p-bl[i]+2;
        }
      }
    }
  }

  return ans;
}

int main() {
//#define DBG
#ifdef DBG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  std::scanf("%s", s);
  int len = std::strlen(s);
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::scanf("%s", bad[i]);
    bl[i] = std::strlen(bad[i]);
  }

  l = 0;
  for (int r = 0; r < len; ++r) {
    int u = PosBad(r);
    if (u > l) {
      l = u;
    }
    if (r-l+1 > best) {
      best = r-l+1;
      pos = l;
    }
  }

  std::cout << best << " " << pos << std::endl;

  return 0;
}