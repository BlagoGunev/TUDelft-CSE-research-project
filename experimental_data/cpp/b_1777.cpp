#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/detail/standard_policies.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



#define all(a) a.begin(), a.end()

#define rall(a) a.rbegin(), a.rend()

                       

typedef long long ll;

typedef string str;



const int N = 1e6 + 5;





void solve() {

   ll n, f = 1, mod = 1e9 + 7;

   cin >> n;

    for(int i = 1;i <= n;i++){

      f *= i;

      f %= mod;

    }

    cout << (n * (n - 1)) % mod * f % mod<< '\n';

}



signed main() {

  ios_base::sync_with_stdio(0);

  cin.tie(0);

  cout.tie(0);

  int tc = 1;

  cin >> tc;

  for (int t = 1; t <= tc; t++) {

    solve();

  }

}