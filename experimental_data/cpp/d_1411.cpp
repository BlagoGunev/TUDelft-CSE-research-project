#include<bits/stdc++.h>



std::string s;

int n, x, y; 



void cal_10() { // x > y

  int c0 = 0, c1 = 0;

  long long ans = 0;

  for (int i = 1; i <= n; i++) {

    if (s[i] == '0') {

      c0++;

      ans += 1LL * c1 * y;

    } else {

      c1++;

      ans += 1LL * c0 * x;

    }

  }

  int d0 = 0, d1 = 0;

  long long res = ans;

  for (int i = n; i >= 1; i--) {

    if (s[i] == '?') { // 1 -> 0

      c1--;

      ans -= 1LL * y * d0;

      ans -= 1LL * x * c0;

      ans += 1LL * x * d1;

      ans += 1LL * y * c1;

      d0++;

      res = std::min(res, ans);

    } else if (s[i] == '0') {

      c0--;

      d0++;

    } else if (s[i] == '1') {

      d1++;

      c1--;

    }

  }

  std::cout << res << '\n';

}



void cal_01() { // x < y

  int c0 = 0, c1 = 0;

  long long ans = 0;

  for (int i = 1; i <= n; i++) {

    if (s[i] == '1') {

      c1++;

      ans += 1LL * x * c0;

    } else {

      c0++;

      ans += 1LL * y * c1;

    }

  }

  int d0 = 0, d1 = 0;

  long long res = ans;

  for (int i = n; i >= 1; i--) {

    if (s[i] == '0') {

      d0++;

      c0--;

    } else if (s[i] == '1') {

      d1++;

      c1--;

    } else if (s[i] == '?') { // 0 -> 1

      c0--;

      ans -= 1LL * x * d1;

      ans -= 1LL * y * c1;

      ans += 1LL * y * d0;

      ans += 1LL * x * c0;

      res = std::min(res, ans);

      d1++;

    }

  }

  std::cout << res << '\n';

}



void solve() {

  std::cin >> s;

  n = s.size();

  s = ' ' + s;

  std::cin >> x >> y;

  if (x > y) {

    cal_10();

  } else {

    cal_01();

  }

}



signed main() { 

  std::cin.tie(nullptr) -> sync_with_stdio(false);

  int T = 1; //std::cin >> T;

  while (T--) {

    solve();

  }

  return 0;

}