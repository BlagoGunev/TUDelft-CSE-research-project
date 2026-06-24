#include <bits/stdc++.h>

using namespace std;



const long long INF = 6e18 + 23;



long long safe(long long a, long long b) {

  if (a == 0 or b == 0) return 0;



  if (a > INF/b) return INF;



  return a*b;

}



long long lcm(long long a, long long b) {

  long long q = __gcd(a, b);

  a /= q;

  return safe(a, b);

}



int main()

{

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  long long t, w, b;

  cin >> t >> w >> b;

  long long full = lcm(w, b);

  long long mn = min(w, b);



  long long offset = t % full;

  if (offset >= mn) offset = mn-1;

  long long steps = t / full;

  long long ans = (steps+1) * offset + steps * (mn-offset);

  

  long long e = ans, d = t;

  long long g = __gcd(e, d);

  e /= g, d /= g;

  cout << e << '/' << d << '\n';

}

// g++ -W -Wall -Wextra -pedantic -std=c++0x -o p main.cpp