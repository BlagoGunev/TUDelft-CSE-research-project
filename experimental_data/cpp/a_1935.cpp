#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"  // https://github.com/Heltion/debug.h/blob/main/debug.h
#else
#define debug(...) (void)20240305
#endif
using i64 = int64_t;
using u64 = uint64_t;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    string s;
    cin >> s >> s;
    auto r = s;
    ranges::reverse(r);
    if (s <= r) {
      cout << s << "\n";
    } else {
      cout << r + s << "\n";
    }
  }
}