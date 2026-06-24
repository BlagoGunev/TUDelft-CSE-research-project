#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define gcd(a,b) __gcd(a,b)

#define lcm(a,b) (a*b)/__gcd(a,b)

#define pb push_back

#define all(b) b.begin(),b.end()

#define revall(b) b.rbegin(),b.rend()

#define yes cout << "YES\n"

#define no cout << "NO\n"

#define F first

#define S second

const int N = 1e6 + 5;

const int mod = 1e9 + 7;



void solve() {

  ll p,q,a,b;

  cin >> p >> q;

  if (p % q != 0) {

    cout << p  << '\n';

    return;

  }

  a = p,b = q;



  map<ll,ll> pf1,pf2;



  for (ll i = 2;i * i <= q;i++) {

    if (q % i == 0) {

      while (q % i == 0) {

        pf2[i]++;

        q /= i;

      }

    }

  }

  if (q > 1)

    pf2[q]++;



  ll ans = 0;



  for (auto x:pf2) {

    p = a;

    while (p % x.F == 0) {

      if ((p / x.F) % b != 0) {

        ans = max(ans,p / x.F);

      }

      p /= x.F;

    }

  }

  cout << ans << '\n';

}



int32_t main() {

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

  cout.tie(NULL);



  



  //freopen("output.txt","w",stdout);

  int t,test = 1;

  cin >> t;

  while (t--) 

    // cout << "Case " << test++ << ": ";

    solve();

  return 0;

}