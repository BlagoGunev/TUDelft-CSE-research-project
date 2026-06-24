/**
 *    author:  tourist
 *    created: 30.03.2024 10:23:11
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    if (k == n) {
      for (int i = 0; i < n; i++) {
        cout << 1 << " \n"[i == n - 1];
      }
    } else {
      if (k == 1) {
        for (int i = 0; i < n; i++) {
          cout << i + 1 << " \n"[i == n - 1];
        }
      } else {
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}