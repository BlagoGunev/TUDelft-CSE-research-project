#include <algorithm>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#define REP(i,a,b) for((i)=(a);(i)<(int)(b);(i)++)
#define rep(i,b) REP(i,0,b)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;
typedef long long ll;
const double eps = 1e-10;
const int inf = 1<<28;

int in() { int x; scanf("%d", &x); return x; }
ll In() { ll x; cin >> x; return x; }
double inreal() { double x; scanf("%lf", &x); return x; }
string instr() { char buf[1001]; scanf("%s", buf); return (string)buf; }

int am[100011], bm[100011];

int main() {  
  int i, j, k, n = in();
  rep(i, n) am[n - 1 - i] = in();
  int mn = 1000111000;
  rep(i, n) {
    if (mn > am[i]) mn = am[i];
    bm[i] = mn;
  }
//  rep(i, n) cout << am[i] << ' '; puts("");
//  rep(i, n) cout << bm[i] << ' '; puts("");
  reverse(am, am + n);
  reverse(bm, bm + n);
//  rep(i, n) cout << am[i] << ' '; puts("");
//  rep(i, n) cout << bm[i] << ' '; puts("");
  rep(i, n) {
    int pos = lower_bound(bm, bm + n, am[i]) - bm - 1;
    int res = pos - i - 1;
    if (res < 0) res = -1;
    printf("%d ", res);
  }
  puts("");

  return 0;
}