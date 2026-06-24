#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <bitset>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXN 150010
#define EPS (1e-8)
int P[MAXN];
int T[MAXN];
ll worst_slope[MAXN];
ll best_slope[MAXN];
ll sumT;

int ord[MAXN];
int ord2[MAXN];

ld v(int i) {
  return 1.0 * P[i] / T[i];
}

// a should come before b if..
bool sf(int a, int b) {
  return 1ll*P[a]*T[b] > 1ll*P[b]*T[a];
}

bool eq(int a, int b) {
  return !sf(a,b) && !sf(b,a);
}

bool sf2(int a, int b) {
  if (P[a] == P[b]) return T[a] < T[b]; // < here!!!
  return P[a] > P[b];
}

ld score(int i, ld c, ll* slope) {
  return 1.0l * P[i] * (1.0 - c * slope[i] / sumT);
}

bool works(ld c, int N) {
  FOR(x,N-1) {
    int i = ord[x];
    int j = ord[x+1];
    assert(P[i] >= P[j]);
    if (P[i] == P[j]) continue; // its ok

    // check if score(i) < score(j);
    if (score(i,c,worst_slope) < score(j,c,best_slope)) return false;
  }

  return true;
}

int main() {
  sumT = 0;
  int N;
  scanf("%d",&N);
  FOR(i,N) scanf("%d",&P[i]);
  FOR(i,N) scanf("%d",&T[i]), sumT += T[i];
  FOR(i,N) ord[i] = i;

  // Sort by points in the optimal ordering. And compute the slope
  sort(ord,ord+N,sf);
  int x = 0;
  while(x<N) {
    int y;
    ll sum = 0;
    ll best_prev = (x ? worst_slope[ord[x-1]] : 0);
    for(y = x; y<N && eq(ord[x], ord[y]); ++y) sum += T[ord[y]];
    ll worst_now = best_prev + sum;
    for (y = x; y<N && eq(ord[x], ord[y]); ++y) {
      worst_slope[ord[y]] = worst_now;
      best_slope[ord[y]] = best_prev + T[ord[y]];
    }
    x = y;
  }

  // Now sort by original point value (to check for out of orderness later)
  FOR(i,N) ord[i] = i;
  sort(ord,ord+N,sf2);

  ld low = 0;
  ld high = 1;
  int ITERS = 50;
  while((low < high - EPS) && ITERS) {
    ITERS--;
    ld c = (low+high)/2;
    if (works(c,N)) low = c;
    else high = c;
  }


  cout << fixed << setprecision(12) << low << endl;
}