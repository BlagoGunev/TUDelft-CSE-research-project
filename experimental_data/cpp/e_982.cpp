#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a%b);
}

ll gcdExtended(ll a, ll b, ll *x, ll *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  ll x1, y1;
  ll gcd = gcdExtended(b%a, a, &x1, &y1);
  *x = y1-(b/a)*x1;
  *y = x1;
  return gcd;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n,m,x,y,vx,vy;
  cin >> n >> m >> x >> y >> vx >> vy;
  if (vx == 0) {
    if (vy == 1 && x == 0)
      cout << 0 << ' ' << m << endl;
    else if (vy == 1 && x == n)
      cout << n << ' ' << m << endl;
    else if (vy == -1 && x == 0)
      cout << 0 << ' ' << 0 << endl;
    else if (vy == -1 && x == n)
      cout << n << ' ' << 0 << endl;
    else
      cout << -1 << endl;
    return 0;
  }
  if (vy == 0) {
    if (vx == 1 && y == 0)
      cout << n << ' ' << 0 << endl;
    else if (vx == 1 && y == m)
      cout << n << ' ' << m << endl;
    else if (vx == -1 && y == 0)
      cout << 0 << ' ' << 0 << endl;
    else if (vx == -1 && y == m)
      cout << 0 << ' ' << m << endl;
    else
      cout << -1 << endl;
    return 0;
  }
  int c1, c2;
  if (vx > 0)
    c1 = n-x;
  else
    c1 = x;
  if (vy > 0)
    c2 = m-y;
  else
    c2 = y;
  
  // k1*n+c1=k2*m+c2
  // k1*n-k2*m=c2-c1
  if (abs(c2-c1)%gcd(n,m)) {
    cout << -1 << endl;
    return 0;
  }
  ll a,b;
  ll d = gcdExtended(n,m,&a, &b);
  a *= (c2-c1)/d;
  b *= (c2-c1)/d;
  b = -b;
  ll aa = m/d;
  ll bb = n/d;
  if (a<0) {
    int kk = -a/aa+1;
    a += kk*aa;
    b += kk*bb;
  }
  if (b < 0) {
    int kk = -b/bb+1;
    a += kk*aa;
    b += kk*bb;
  }
  int mini = min(a/aa, b/bb);
  a -= aa*mini;
  b -= bb*mini;
  int px = (vx > 0);
  int py = (vy > 0);
  px = (px+(a%2))%2;
  py = (py+(b%2))%2;
  if (px)
    cout << n << ' ';
  else
    cout << 0 << ' ';
  if (py)
    cout << m << endl;
  else
    cout << 0 << endl;
}