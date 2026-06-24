#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

#define endl '\n'
#define pb push_back
#define vi vector<int>
using pi = pair<int, int>;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  
  while (t--) {
    int x, n;
    cin >> x >> n;
    
    // g * (n things here) = x
    vector<int> div;
    for (int d = 1; d * d <= x; ++d) {
      if (x % d == 0) {
        div.pb(d);
        if (x / d != d) div.pb(x / d);
      }
    }
    
    int ans = 0;
    for (int d : div) {
      if (x / d >= n) ans = max(ans, d);
    }
    
    cout << ans << endl;
  }
}