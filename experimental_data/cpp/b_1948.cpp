#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> b({a[n - 1]});
    for (int i = n - 2; i >= 0; --i) {
      if (a[i] > b.back()) {
        b.pb(a[i] % 10);
        b.pb(a[i] / 10);
      } else {
        b.pb(a[i]);
      }
    }
    cout << (is_sorted(b.rbegin(), b.rend()) ? "YES" : "NO") << '\n';
  }
}