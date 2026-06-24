#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define pb push_back



using T = __int128;

// ax + by = __gcd(a, b)

// returns __gcd(a, b)

T extended_euclid(T a, T b, T &x, T &y) {

  T xx = y = 0;

  T yy = x = 1;

  while (b) {

    T q = a / b;

    T t = b; b = a % b; a = t;

    t = xx; xx = x - q * xx; x = t;

    t = yy; yy = y - q * yy; y = t;

  }

  return a;

}

// finds x such that x % m1 = a1, x % m2 = a2. m1 and m2 may not be coprime

// here, x is unique modulo m = lcm(m1, m2). returns (x, m). on failure, m = -1.

pair<T, T> CRT(T a1, T m1, T a2, T m2) {

  T p, q;

  T g = extended_euclid(m1, m2, p, q);

  if (a1 % g != a2 % g) return make_pair(0, -1);

  T m = m1 / g * m2;

  p = (p % m + m) % m;

  q = (q % m + m) % m;

  return make_pair((p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) %  m, m);

}



int32_t main() {

  ios_base::sync_with_stdio(0);

  cin.tie(0);

  //cout << (int)CRT(1, 31, 0, 7).first << '\n';



  ll m , n , k , i ;

  cin >> n >> m >> k ;



  vector<ll> a(n) , b(m) , posa(2*(n+m + 2) , -1 ) ,  posb(2*(n+m + 2) , -1 ) ;





  for (i =0  ;i < n ; i++ ) cin >> a[i] ,  posa[a[i]-1] = i ;

  for (i = 0 ;i < m ; i++ ) cin >> b[i] ,  posb[b[i]-1] = i ;





    vector<ll> good ;

    ll lcm = -1 ;

    for (i = 0 ; i< 2 * (n+m+2) ; i++) {

        if (posa[i]!=-1 and posb[i]!=-1) {

            pair<ll,ll> sol = CRT(posa[i],n,posb[i],m) ;

            if (sol.first == -1 or sol.second == -1) continue ;

            //cout << sol.first << ' ' << sol.second << ' ' << posa[i] << ' ' << posb[i] << ' ' << i << endl ;

            lcm = sol.second ;

            good.pb(sol.first) ;

        }

    }

    sort(good.begin(),good.end()) ;

    good.resize(unique(good.begin(), good.end()) - good.begin());

    ll l =0 , r = 1e18 ;

    if (lcm == -1 ) {

        cout << k << endl ;

        return 0 ;

    }

    while( l  < r) {

        ll mi = (l+r) / 2 ;

        ll cnt = mi ;

        cnt -= ( mi/lcm ) * (ll) good.size() ;

        ll rem = mi % lcm ;

        for (auto it : good) {

            if (it < rem) cnt-- ;

        }



        if (cnt >= k) r = mi ;

        else l = mi + 1 ;



        //cout << mi << ' ' ;



    }



    cout << l << endl ;





  return 0;

}