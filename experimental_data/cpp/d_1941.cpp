#include "bits/stdc++.h"

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--) {

    int n, m; cin >> n >> m;
    int x; cin >> x;

    vector<int> a(n);
    a[x - 1] = 1;

    while (m--) {

      vector<int> b(n);

      int y; cin >> y;
      char c; cin >> c;

      for (int i = 0; i < n; i++) {
        if (a[i]) {
          if (c != '0') {
            b[(i + n - y) % n] = 1;
          }
          if (c != '1') {
            b[(i + y) % n] = 1;
          }
        }
      }

      swap(a, b);

    }

    cout << count(a.begin(), a.end(), 1) << "\n";
    for (int i = 0; i < n; i++) {
      if (a[i]) {
        cout << i + 1 << " ";
      }
    }
    cout << "\n";

  }
  
}