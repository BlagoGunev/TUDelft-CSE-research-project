#include "bits/stdc++.h"

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--) {

    int n, k; cin >> n >> k;

    vector<int> a(k);
    for (int &i : a) {
      cin >> i;
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 0; i + 1 < k; i++)
      ans += (a[i] * 2 - 1);

    cout << ans << "\n";

  }
  
}