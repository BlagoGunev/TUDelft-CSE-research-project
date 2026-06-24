#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int t, n, x;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    cin >> n >> x;
    cout << 2 * x << "\n";
  }
}