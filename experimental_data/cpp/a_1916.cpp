#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <long long> a(n);
    long long prod = 1;
    for (auto &x : a) scanf("%lld", &x), prod *= x;
    if (2023 % prod) {
      cout << "NO\n";
      continue;
    }
    long long value = 2023 / prod;
    cout << "YES\n" << value << " ";
    for (int i = 1; i < k; ++i) cout << "1 ";
    cout << '\n';
  }
  return 0;
}