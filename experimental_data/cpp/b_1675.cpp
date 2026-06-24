#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    int cnt = 0;
    bool ok = false;
    for (int i = n - 2; i >= 0; i--) {
      while (v[i] > 0 && v[i] >= v[i + 1]) {
        v[i] /= 2;
        cnt++;
      }
      if (v[i] == v[i + 1]) {
        ok = true;
        break;
      }
    }
    cout << (ok ? -1 : cnt) << "\n";
  }
}