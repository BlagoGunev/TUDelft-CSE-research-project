#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string.h>

#include <bitset>

#include <stdlib.h>
#include <list>
#include <algorithm>
#include <math.h>
#include <iomanip>      // std::setprecision
#include <unordered_map>
#include <set>
#define FOR(x,y,z) for(int x = (y); x < (z); x++)
#define FORD(x,y,z) for(int x = (y); x >= z; x--)
#define REP(r,n) for(int r = 0; r < (n); r++)
#define MP make_pair
#define ST first
#define MAXUS 5009
#define ND second
#define PB push_back
#define MAXUS2 2003
#define PI 3.1415926
#define LOGN 17
#define SIZE(c) ((int)((c).size()))
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); i++)
#define ALL(u) (u).begin(),(u).end()
#define epsilon 0.000001
#define MAXUS3 3000010
#define INF 2000000009
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> PR; // LL or int

const LL WW = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    LL k, x; // k+1
    cin >> x >> k;
    LL base = 2;
    base %= WW;
  LL pierw = 1;
  LL exp = k;  
  while (exp > 0) {
    if (exp & 1) pierw = (pierw * base) % WW;
    base = (base * base) % WW;
    exp >>= 1;
  }
//    cout << pierw << endl;
    LL result = (2 * x-1) % WW;
    result = ((result * pierw) % WW + 1) % WW;
    if (x != 0)
      cout << result << endl;
    else 
      cout << 0 << endl;
    return 0;
}