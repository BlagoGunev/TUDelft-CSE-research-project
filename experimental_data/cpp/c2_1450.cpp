#include <bits/stdc++.h>

using namespace std;



int solve() {

  int n;

  cin >> n;



  vector m(n, string{});

  for (int i = 0; i < n; ++i) {

    cin >> m[i];

  }



  int cnt[2][3]{};

  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < n; ++j) {

      if (m[i][j] != '.') {

        ++cnt[m[i][j] == 'X'][(i + j) % 3];

      }

    }

  }



  int x{};

  for (int i = 1; i < 3; ++i) {

    if (cnt[0][i] + cnt[1][(i + 1) % 3] < cnt[0][x] + cnt[1][(x + 1) % 3]) {

      x = i;

    }

  }



  for (int i = 0; i < n; ++i) {

    for (int j = 0; j < n; ++j) {

      if (m[i][j] != '.') {

        if (m[i][j] == 'O' && (i + j) % 3 == x) {

          m[i][j] = 'X';

        } else if (m[i][j] == 'X' && (i + j) % 3 == (x + 1) % 3) {

          m[i][j] = 'O';

        }

      }

    }

    cout << m[i] << "\n";

  }



  return {};

}



int main() {

  cin.tie(0), ios::sync_with_stdio(0);



  int tests;

  cin >> tests;

  while (tests--) {

    solve();

  }



  return 0 ^ 0;

}