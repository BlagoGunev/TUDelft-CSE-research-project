#include <bits/stdc++.h>

using namespace std;

int main() {

        ios::sync_with_stdio(false);

  cin.tie(0);

  int t;

  cin >> t;

  while (t--) {

    int l, r;

    cin >> l >> r;

    long long len = r - l + 1;

    long long ans = len * (len - 1) * (len - 2) / 6;

    vector<int> cnt(r + 1);

    for (int i = l; i <= r; i++) {

      for (int j = i + i; j <= r; j += i) {

        cnt[j] += 1;

      }

    }

    for (int i = l; i <= r; i++) {

      ans -= cnt[i] * (cnt[i] - 1) / 2;

    }

    for (int x = 12; x <= 2 * r; x += 12) {

      if (x / 2 <= r && x / 4 >= l ) ans--;

      

    }

    for (int x = 30; x <= 2 * r; x += 30) {

        if (x / 2 <= r && x / 5 >= l ) ans--;

  }

    cout << ans << '\n';

  }

 

    

    

    

}