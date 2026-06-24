#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...) void(0)
#endif

using i64 = int64_t;
using u64 = uint64_t;
using f64 = double_t;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    string s;
    cin >> s;
    int h = stoi(s.substr(0, 2));
    cout << setw(2) << setfill('0') << (h % 12 ?: 12) << ":" << s.substr(3) << " " << (h >= 12 ? "PM" : "AM") << "\n";
  }
}