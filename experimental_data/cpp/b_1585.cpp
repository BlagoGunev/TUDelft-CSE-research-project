#include <bits/stdc++.h>



using namespace std;



#ifdef LOCAL

#include "library/debug.hpp"

#else

#define debug(...)

#endif



int main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int tt;

  cin >> tt;

  while (tt--) {

    int n;

    cin >> n;

    vector<int> a(n);

    int mx = 0;

    for (int i = 0; i < n; i++) {

      cin >> a[i];

      mx = max(mx, a[i]);

    }

    int k = 0, last = n - 1;

    while (last >= 0) {

      if (a[last] == mx) {

        break;

      }

      k++;

      int p = last;

      while (p >= 0 && a[p] <= a[last]) {

        p--;

      }

      last = p;

    }

    cout << k << '\n';

  }

  return 0;

}