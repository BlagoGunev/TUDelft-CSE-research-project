#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
using namespace std;

///////////////// macros and typedefs ///////////////////
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define CLEAR(a) memset((a), 0, sizeof(a));
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define ppb pop_back
//#define y second
//#define x first
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n;
ll pos;
ll X, Y;
int x[100000];
int y[100000];

void solution()
{
   cin >> n >> pos;
   cin >> X >> Y;
   rep(i, n)
      scanf("%d %d", x+i, y+i);

   /*int TX = X, TY = Y;
   rep(i, pos) {
      TX = (2*x[i%n] - TX);
      TY = (2*y[i%n] - TY);
   }
   printf("%d %d\n", TX, TY);*/

   int cyc = (pos/n)%2;
   int tail = pos%n;
   int sign = tail%2 == 1 ? +1 : -1;
   if (cyc == 1) {
      rep(i, n) {
         X = (2*x[i] - X);
         Y = (2*y[i] - Y);
      }
   }
   rep(i, tail) {
      X = (2*x[i] - X);
      Y = (2*y[i] - Y);
   }
   cout << X << " " << Y << endl;
   //printf("%d %d\n", X, Y);
}

int main()
{
#ifdef _LOCALTEST_
   freopen("my.in", "rt", stdin);
   //freopen("my.out", "wt", stdout);
#endif
   solution();
   return 0;
}