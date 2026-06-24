# include <bits/stdc++.h>

  using namespace std;

  pair< int, int > arr[110];

  int ans[110];

  int main()

  {

      ios_base::sync_with_stdio(0);

      cin.tie(NULL);

      cout.tie(NULL);

      long long n, m, i;

      cin >> n >> m;

      for(i = 1; i <= n; i++){

        cin >> arr[i].first;

        arr[i].second = i;

      }

      sort(arr + 1, arr + 1 + n);

      for(i = 1; i <= n; i++){

        ans[arr[i].second] = i % 2;

      }

      for(i = 1; i <= n; i++){

        cout << ans[i] << " ";

      }

      return 0;

  }