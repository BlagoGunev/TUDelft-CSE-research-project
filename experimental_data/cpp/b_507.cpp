/*input

4 5 6 5 6

*/

#include <bits/stdc++.h>

//#include <iostream>

#define ll long long

//#define int long long

#define ld long double

//#define db double

#define pb push_back

#define ppb pop_back

#define mp make_pair

#define ft first

#define sd second

#define sz size()

#define bn begin()

#define ed end()

#define get(x) scanf("%d", &x);

#define getl(x) scanf("%I64d", &x);



using namespace std;



const int N = 1e5 + 7, M = 28, mod = 1000000000, inf = 1000000007;

const ll lmod = 1000000007, linf = 1e18 + 77;

const ld eps = 1e-14;



main() {

  ios_base::sync_with_stdio(false);



  ld r, x, y, x1, y1;

  cin >> r >> x >> y >> x1 >> y1;

  if (x == x1 && y == y1) {

    cout << 0 << endl;

    return 0;

  }

  r *= 2;

  ld dist = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));



  

  cout << (ll)((dist / r) - eps) + 1 << endl;



}