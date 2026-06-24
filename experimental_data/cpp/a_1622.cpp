#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int ar[3];
    for (int i = 0; i < 3; i++) {
      cin >> ar[i];
    }
    bool foo = 0;
    for (int i = 0; i < 3; i++) {
      int a = ar[i], b = ar[(i + 1) % 3], c = ar[(i + 2) % 3];
      foo |= a + b == c;
      if (a == b) foo |= c % 2 == 0;
    }
    
    cout << (foo ? "YES" : "NO") << '\n';
  }
  return 0;
}