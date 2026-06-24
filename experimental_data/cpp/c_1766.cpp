#include <algorithm>

#include <cmath>

#include <deque>

#include <iostream>

#include <map>

#include <queue>

#include <set>

#include <vector>

using namespace std;

typedef long long int ll;

int main() {

  ios_base::sync_with_stdio(0);

  cin.tie(0);

  cout.tie(0);

  int t;

  cin >> t;

  while (t--) {

    int n;

    cin >> n;

    vector<string> a(2);

    cin >> a[0] >> a[1];

    a[0].push_back('@');

    a[1].push_back('@');

    int cnt = 0;

    for (int i = 0; i < n; ++i) {

      if (a[0][i] == 'B') {

        cnt++;

      }

      if (a[1][i] == 'B') {

        cnt++;

      }

    }

    int x=0, y=0;

    bool fl = 0;

    vector<vector<bool>> used(2, vector<bool>(n+1));

    for (int j = 0; j < 2; ++j) {

      y = j;

      x = 0;

      int tmp = 0;

      if (a[y][x] != 'B') {

        continue;

      }

      used[y][x] = 1;

      tmp = 1;

      while (1) {

        if (a[(y + 1) % 2][x] == 'B' && !used[(y + 1)%2][x]) {

          tmp++;

          used[(y + 1)%2][x] = 1;

          y = (y + 1) % 2;

        } else if (a[y][x + 1] == 'B' && !used[y][x+1]) {

          used[y][x + 1] = 1;

          x++;

          tmp++;

        } else {

          break;

        }

      }

      if (tmp == cnt) {

        fl = 1;

        break;

      }

      used.clear();

      used.resize(2, vector<bool>(n+1, 0));

    }

    if (fl) {

      cout << "YES" << '\n';

    } else {

      cout << "NO" << '\n';

    }

  }

  return 0;

}