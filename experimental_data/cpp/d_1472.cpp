#include <bits/stdc++.h>

 

using namespace std;

typedef long long ll;

typedef long double ld;

const int MAX_INT = 1000000007;



int t, n;



int main() {

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);



  cin >> t;

  while (t--) {

    cin >> n;



    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    

    sort(a.begin(), a.end());

    ll balance = 0;

    for (int i = n - 1; i >= 0; i--) {

      if ((n - i) % 2 == 1) {

        if (a[i] % 2 == 0) balance += a[i];

      } else {

        if (a[i] % 2 == 1) balance -= a[i];

      }

    }



    if (balance > 0) {

      cout << "Alice";

    } else if (balance < 0) {

      cout << "Bob";

    } else {

      cout << "Tie";

    }



    cout << '\n';

  }

}