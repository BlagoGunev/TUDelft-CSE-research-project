# include <bits/stdc++.h>

# define IoS ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

# define Open_inout(a, b) freopen(a, "r", stdin); freopen(b, "w", stdout);

# define Open(s) freopen(s, "r", stdin);

  using namespace std;

  int main()

  {

      IoS;

      ///Open("test.cpp");

      long long x1, x2, y1, y2, n, ans, a, b, c, i, t1, t2;

      cin >> x1 >> y1 >> x2 >> y2 >> n;

      ans = 0;

      for(i = 1; i <= n; i++){

        cin >> a >> b >> c;

        t1 = (a * x1) + (b * y1) + c;

        t2 = (a * x2) + (b * y2) + c;

        if((0 < t1) && (t2 < 0)) ans++;

        else if((t1 < 0) && (0 < t2)) ans++;

      }

      cout << ans;

      return 0;

  }