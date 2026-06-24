//In the name of God
#include <algorithm>
#include <iostream>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define X first
#define Y second
//#define X imag()
//#define Y real()
//#define cin fin
//#define cout fout
#define err(x) cerr << #x << ' ' << x << endl ;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;

ll n, l, t, tot, ans, a[2000 * 1000 + 10];
ld ret;

int main ()
{
  ios :: sync_with_stdio(0);
  cin >> n >> l >> t ;
  for(int i = 0 ; i < n ; i++)
    cin >> a[i] ;
  for(int i = n ; i < 2 * n ; i++)
    a[i] = a[i - n] + l;
  tot = (n * (n - 1));
  ans += (ll)((t / l) * tot) * 2;
  t %= l;
  for(int j = 0, i = 1 ; i < 2 * n ; i++)
    {
      while((a[j] + 2 * t) < a[i])
	j ++;
      if(j >= n)
	break;
      ans += i - j;
      ans -= max((ll)0, i - n);
    }

  err(tot);err(ans);

  ll tmp = ans % 4;
  ans /= 4;
  cout << ans ;
  if(tmp == 0)
    cout << endl ;
  if(tmp == 1)
    cout << ".25" << endl ;
  if(tmp == 2)
    cout << ".50" << endl ;
  if(tmp == 3)
    cout << ".75" << endl ;
}