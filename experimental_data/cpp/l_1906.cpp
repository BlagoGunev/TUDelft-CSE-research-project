#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 2137
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  if (k < n / 2 || k == n) {
    cout << "-1\n";
    return 0;
  }
  k -= n / 2;
  string s;
  for (int i = 0; i < k / 2; i++) {
    s += "()";
  }
  for (int i = 0; i < n / 2 - k; i++) {
    s += "(";
  }
  for (int i = 0; i < n / 2 - k; i++) {
    s += ")";
  }
  for (int i = 0; i < (k + 1) / 2; i++) {
    s += "()";
  }
  cout << s << '\n';
}