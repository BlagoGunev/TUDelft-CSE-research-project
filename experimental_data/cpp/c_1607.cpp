#include <bits/stdc++.h>

using namespace std;



void Test() {

  int n; cin >> n;

  vector<int> a(n);

  for (int &x : a) cin >> x;

  sort(a.begin(), a.end());

  int diff = 0;

  int ans = a[0];

  for (int i = 0; i < n; i++) {

    a[i] -= diff;

    diff += a[i];

    ans = max(ans, a[i]);

  }

  cout << ans << '\n';

}

int main() {

  ios_base::sync_with_stdio(false);

  cin.tie(nullptr);

  int tc; cin >> tc;

  while (tc--) {

    Test();

  }  

  return 0; 

}