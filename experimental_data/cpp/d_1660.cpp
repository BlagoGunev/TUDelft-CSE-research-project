#include <bits/stdc++.h>



using namespace std;



#ifdef LOCAL

#include <algo/debug.h>

#else

#define debug(...) 42

#endif



int main() {

  ios_base::sync_with_stdio(false);

  cin.tie(0);

  int tt;

  cin >> tt;

  while (tt--) {

    int n;

    cin >> n;

    vector<int> a(n);

    vector<int> z = {-1};

    for (int i = 0; i < n; i++) {

      cin >> a[i];

      if (a[i] == 0) {

        z.push_back(i);

      }

    }

    z.push_back(n);

    pair<int, pair<int, int>> ans = make_pair(0, make_pair(n, 0));

    for (int p = 0; p + 1 < (int) z.size(); p++) {

      int s = z[p] + 1;

      int e = z[p + 1] - 1;

      int sgn = 1;

      int two = 0;

      for (int i = s; i <= e; i++) {

        if (a[i] < 0) {

          sgn = -sgn;

        }

        if (abs(a[i]) == 2) {

          ++two;

        }

      }

      int pref_del = s, suff_del = n - (e + 1);

      int pref_edel = 0, suff_edel = 0;

      if (sgn < 0) {

        int pref_two = 0;

        int suff_two = 0;

        for (int i = s; i <= e; i++) {

          if (abs(a[i]) == 2) {

            ++pref_two;

          }

          ++pref_edel;

          if (a[i] < 0) {

            break;

          }

        }

        for (int i = e; i >= s; i--) {

          if (abs(a[i]) == 2) {

            ++suff_two;

          }

          ++suff_edel;

          if (a[i] < 0) {

            break;

          }

        }

        if (pref_two < suff_two) {

          pref_del += pref_edel;

        } else {

          suff_del += suff_edel;

        }

        two -= min(pref_two, suff_two);

      }

      ans = max(ans, make_pair(two, make_pair(pref_del, suff_del)));

    }

    cout << ans.second.first << ' ' << ans.second.second << '\n';

  }

  return 0;

}