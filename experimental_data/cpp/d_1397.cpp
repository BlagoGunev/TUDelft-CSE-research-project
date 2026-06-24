#include <bits/stdc++.h>



#ifdef LOCAL

#include "debug.h"

#else

#define debug(...)

#endif



using namespace std;



int main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int t;

  cin >> t;

  while (t--) {

    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {

      cin >> a[i];

    }

    int s = accumulate(a.begin(), a.end(), 0);

    int mx = *max_element(a.begin(), a.end());

    if (2 * mx > s) {

      cout << "T\n";

    } else {

      cout << (s & 1 ? "T" : "HL") << '\n';

    }

  }

  return 0;

}