// Authored by dolphinigle
// ABBYY Cup 2.0 Hard
// 28 April 2012

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include <cassert>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))
#define RESET(Z,Y) memset(Z,Y,sizeof(Z))

#define SZ(Z) ((int)Z.size())
#define ALL(W) W.begin(), W.end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;
typedef vector<ll> vll;

const int kMaxN = 2050;
string vals[kMaxN];
char buffer[kMaxN];

int n, k;

vint Solve(int a, int b, int preflen) {
  if (vals[a] == vals[b]) {
    int delta = SZ(vals[a]) - preflen;
    vint ret(n+1, 0);
    FORN(i, n+1) {
      int jml = min(i, (b-a+1));
      ret[i] = (jml * (jml-1)) / 2 * delta;
    }
    return ret;
  } 
  // calculate additional prefix
  int np = preflen;
  while (SZ(vals[a]) > np && SZ(vals[b]) > np && vals[a][np] == vals[b][np]) ++np;
  
  // find barrier
  int bar = -1;
  for (int i = a; i < b; ++i) {
    if (SZ(vals[i]) == np) {
      if (SZ(vals[i+1]) == np) continue;
      bar = i;
      break;
    } else {
      if (SZ(vals[i+1]) == np || vals[i][np] != vals[i+1][np]) {
        bar = i;
        break;
      }
    }
  }
  
  assert(bar != -1);
  
  vint kiri = Solve(a, bar, np);
  vint kanan = Solve(bar+1, b, np);
  
  // merge both
  int pnjkiri = bar - a + 1;
  int pnjkanan = b - (bar+1) + 1;
  if (pnjkanan < pnjkiri) {
    swap(kiri, kanan);
    swap(pnjkiri, pnjkanan);
  }
  
  vint ret(n+1, 0);
  FORN(i, n+1) {
    int v = 0;
    int batas = min(pnjkiri, i);
    for (int j = 0; j <= batas; ++j) {
      int t = kiri[j] + kanan[i - j];
      if (t > v) v = t;
    }
    ret[i] = v;
  }
  
  FORN(i, n+1) {
    int jml = min(i, b - a + 1);
    ret[i] += (np - preflen) * (jml) * (jml-1) / 2;
  }
  return ret;
}

int main() {
  
  scanf("%d%d", &n, &k);
  FORN(i, n) {
    scanf("%s", buffer);
    vals[i] = buffer;
  }
  
  sort(vals, vals + n);
  
  vint x = Solve(0, n-1, 0);
  cout << x[k] << endl;
  
}