#include <bits/stdc++.h>



using namespace std;



#ifndef ONLINE_JUDGE

#include "debug.h"

#else

#define debug(...) 

#endif



void solve () {

  string s, t;

  cin >> s >> t;

  int n = s.size(), m = t.size();

  int j = m - 1, k = n;

  for (int i = n - 1; i >= 0 && j >= 0; i--) {

    if (s[i] == t[j]) {

      if ((k - i) & 1) {

        k = i;

        j -= 1;

      }

    }

  }

  cout << (j <= -1? "YES": "NO") << "\n";

}



int main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);



  int tt;

  cin >> tt;

  while (tt--) {

    solve();

  }

  return 0;

}