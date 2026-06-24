#include <bits/stdc++.h>

using namespace std;



int main()

{

  

  int64_t x0, y0, ax, ay, bx, by, xs, ys, t;

  cin >> x0 >> y0 >> ax >> ay >> bx >> by;

  cin >> xs >> ys >> t;

  

  vector<int64_t> x(1, x0), y(1, y0);

  int64_t LIMIT = (1LL << 62) - 1;

  while ((LIMIT - bx) / ax >= x.back() && (LIMIT - by) / ay >= y.back()) {

    x.push_back(ax * x.back() + bx);

    y.push_back(ay * y.back() + by);

  }

  

  int n = x.size();

  int ans = 0;

  for (int i=0; i<n; i++) {

    for (int j=i; j<n; j++) {

      int64_t length = x[j] - x[i] + y[j] - y[i];

      int64_t d2l = abs(xs - x[i]) + abs(ys - y[i]);

      int64_t d2r = abs(xs - x[j]) + abs(ys - y[j]);

      if (length <= t - min(d2l, d2r))

	ans = max(ans, j-i+1);

    }

  }

  cout << ans << endl;	

}