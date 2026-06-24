#pragma comment (linker, "/STACK:1073741824")
#define _USE_MATH_DEFINES
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>

using namespace std;

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second

typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

const int nmax = 220100;
vint g[nmax];
bool used[nmax];

int a[nmax];
int all[nmax];
pii row[nmax];
map<int, int> getpos;
int sz;

int topsort[nmax];
int top;

void dfs1(int v) {
  used[v] = true;
  FE(i, g[v]) {
    int to = g[v][i];
    if (!used[to]) dfs1(to);
  }
  topsort[top++] = v;
}

void dfs2(int v) {
  used[v] = true;
  FE(i, g[v]) {
    int to = g[v][i];
    if (!used[to]) {
      cout << -1 << endl;
      exit(0);
    }
  }
}

int ans[nmax/2], ans2[nmax/2], anslen = 0;

int main() {
#ifdef    CENADAR_DEBUG
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else  // CENADAR_DEBUG
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif // CENADAR_DEBUG

  int n, m;
  scanf("%d%d", &n, &m);
  REP(i, n) REP(j, m) {
    scanf("%d", a + i*m + j);
/*    if (a[i*m + j] != -1) {
      all[sz++] = a[i*m + j];
    }*/
  }

  int sz = m;

  REP(i, n) {
    int k = 0;
    REP(j, m) if (a[i*m + j] != -1) {
      row[k++] = MP(a[i*m + j], j);
    }
    if (k == 0) continue;

    sort(row, row + k);
    int prev = -1;
    for(int j = 0; j < k; ) {
      int l = j;
      int valpos = sz++;
      for(; l < k && row[j].XX == row[l].XX; ++l) {
        int cur = row[l].YY;
        if (prev != -1) g[prev].PB(cur);
        g[cur].PB(valpos);
      }
      if (prev != -1) g[prev].PB(valpos);
      prev = valpos;
      j = l;
    }
  }
  REP(v, m) {
    g[sz].PB(v);
  }
  dfs1(sz);
  MEM(used, 0);
  REP(i, top) {
    dfs2(topsort[i]);
  }

  assert(top == sz + 1);
  for(int i = top; i--; ) {
    int curr = topsort[i];
    if (curr < m) ans[anslen++] = curr + 1;//ans[curr] = anslen++;
  }

  REP(i, m) {
    printf("%d%c", ans[i], i + 1 == m ? '\n' : ' ');
  }

  return 0;
}