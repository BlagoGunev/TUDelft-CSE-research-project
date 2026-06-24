#include <vector>

#include <iostream>



using namespace std;



int main() {

  ios::sync_with_stdio(false);

  cin.tie(0);

  int tt;

  cin >> tt;

  while (tt--) {

    int n, k, x;

    cin >> n >> k >> x;

    int all = 0;

    for (int i = 1; i <= n; i++) {

      all ^= i;

    }

    if (all != x * (k & 1)) {

      cout << "NO" << '\n';

      continue;

    }

    vector<vector<int>> ans;

    vector<int> was(n + 1);

    for (int i = n; i > 0; i--) {

      if (was[i]) {

        continue;

      }          

      if (i == x) { 

        was[i] = 1;

        ans.emplace_back(1, x);

        continue;

      }

      if ((i ^ x) < i && !was[i ^ x]) {

        was[i] = 1;

        was[i ^ x] = 1;

        ans.push_back({i ^ x, i});

      }

    }

    ans.emplace_back();

    for (int i = 1; i <= n; i++) {

      if (!was[i]) {

        ans.back().push_back(i);

      }

    }                      

    if (ans.back().empty()) ans.pop_back();

    while ((int) ans.size() > k) {

      auto v = ans.back();

      ans.pop_back();

      ans[0].insert(ans[0].end(), v.begin(), v.end());

    }

    if ((int) ans.size() < k) {

      cout << "NO" << '\n';

    } else {

      cout << "YES" << '\n';

      for (int i = ans.size() - 1; i >= 0; i--) {

        cout << (int) ans[i].size();

        for (int e : ans[i]) cout << ' ' << e;

        cout << '\n';

      }

    }

  }

  return 0;

}