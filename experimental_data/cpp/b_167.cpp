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
#include <fstream>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define FOR(i, s, n) for (int i = (s) ; i < (n) ; i ++)

#define eps 1e-13
#define le(a, b) ((a) < (b) + eps)

typedef long long int64 ;
typedef pair<int64, int64> pint ;

#define MAXN 100005

//#define DEBUG

#ifdef DEBUG
  ifstream in("input.txt") ;
  ofstream out("output.txt") ;
#endif

typedef pair<bool, int> conf ;

int n, minWin, startSpace ;
double p [205] ; // dp [205] [205] [205] ;

int main() {
#ifdef DEBUG
  in >> n >> minWin >> startSpace ;
#else
  scanf("%d%d%d", &n, &minWin, &startSpace) ;
#endif
  double dp [205] [205] [2] ;
  double pwin [205] [2], pspace [205] [205] [2] ;
  int cur = 0, ncur;
  memset(pwin, 0, sizeof(pwin)) ;
  memset(pspace, 0, sizeof(pspace)) ;
  pwin [0] [cur] = 1.0 ; pspace [0] [startSpace] [cur] = 1.0 ;

  int curProb [205], curSpace [205] ;
  double prob ;
  for (int i = 0 ; i < n ; i ++) scanf("%d", curProb + i) ;
  for (int i = 0 ; i < n ; i ++) scanf("%d", curSpace + i) ;
  for (int it = 0 ; it < n ; it ++) {
    ncur = cur ^ 1 ;
    for (int i = 0 ; i < 205 ; i ++) { pwin [i] [ncur] = 0.0 ; for (int j = 0 ; j < 205 ; j ++) pspace [i] [j] [ncur] = 0.0 ; }
    prob = 0.01 * curProb [it] ;
    if (curSpace [it] == -1) {
      for (int iwin = 0 ; iwin < 205 ; iwin ++) if (pwin [iwin] [cur] > 0) {
        pwin [iwin + 1] [ncur] += pwin [iwin] [cur] * prob ;
        pwin [iwin] [ncur] += pwin [iwin] [cur] * (1 - prob) ;
      }
      for (int iwin = 0 ; iwin < 205 ; iwin ++) for (int ispace = 0 ; ispace < 205 ; ispace ++) pspace [iwin] [ispace] [ncur] = pspace [iwin] [ispace] [cur] ;
    } else {
      for (int iwin = 0 ; iwin < 205 ; iwin ++) for (int ispace = 0 ; ispace < 205 ; ispace ++) if (pspace [iwin] [ispace] [cur] > 0) {
        pspace [iwin + 1] [MIN(200, ispace + curSpace [it])] [ncur] += pspace [iwin] [ispace] [cur] * prob ;
        pspace [iwin] [ispace] [ncur] += pspace [iwin] [ispace] [cur] * (1 - prob) ;
      }
      for (int iwin = 0 ; iwin < 205 ; iwin ++) pwin [iwin] [ncur] = pwin [iwin] [cur] ;
    }
    cur = ncur ;
  }
  double ret = 0.0 ;
  for (int iwin = minWin ; iwin <= n ; iwin ++) {
    for (int iwin1 = 0 ; iwin1 <= iwin ; iwin1 ++) {
      for (int ispace = iwin1 ; ispace < 205 ; ispace ++) {
        ret += pwin [iwin1] [cur] * pspace [iwin - iwin1] [ispace] [cur] ;
      }
    }
  }

  printf("%.10lf\n", ret) ;
  return 0 ;
}