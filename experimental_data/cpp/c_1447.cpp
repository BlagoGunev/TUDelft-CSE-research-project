#include <bits/stdc++.h>



#define int long long



using namespace std;



#define MultipleCase       

void Solve(int tc) {

  int n, W;

  cin >> n >> W;

  vector<pair<int,int>> vp(n);

  for (int i = 0; i < n; ++i) {

    int x;

    cin >> x;

    vp[i] = {x, i};

  }

  sort(vp.begin(), vp.end());

  int low = (W + 1) / 2;

  int sum = 0;

  int cur = 0;

  deque<int> ans;

  for (int i = 0; i < n; ++i) {

    auto [x, y] = vp[i];

    sum += x;

    ans.push_back(y);

    while (sum > W) {

      sum -= vp[cur++].first;

      ans.pop_front();

    }

    if (sum >= low) {

      sort(ans.begin(), ans.end());

      cout << (int)ans.size() << '\n';

      for (auto &ind : ans) {

        cout << ind + 1 << " ";

      }

      cout << '\n';

      return;

    }

  }

  cout << -1 << '\n';

}



int32_t main(void) {

  ios::sync_with_stdio(false);

  cin.tie(0);

  int tt = 1, tc = 0;

#ifdef MultipleCase

  cin >> tt;

#endif

  while (tt--) Solve(++tc);

  return 0;

}