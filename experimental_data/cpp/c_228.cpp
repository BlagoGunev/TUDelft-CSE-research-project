#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <set>
#include <map>
#include <stack>
#include <fstream>
#include <deque>
#include <list>
#include <ctime>

#define SZ(a) (int(a.size()))
#define MEM(a, val) memset(a, val, sizeof(a))
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define SQR(a) ((a) * (a))

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef double dbl;
typedef pair<int, int> pii ;
typedef vector<int> vint;
typedef vector<LL> vLL;

const int nmax = 509;

int mask[nmax][nmax][15];
bool f[nmax][nmax][15];
int n, m;
int mat[nmax][nmax];

const int ui[] = {1, 1, 0, 0};
const int uj[] = {1, 0, 1, 0};

bool dfs(int i, int j, int k) {
  int l = 1 << k;
  if (!(i >= 1 && i + l - 1 <= n && j >= 1 && j + l - 1 <= m))
    return false;

  if (mask[i][j][k] != -1)
    return f[i][j][k];

  if (l == 2) {
    mask[i][j][k] = (mat[i][j] << 3) + (mat[i][j + 1] << 2) + (mat[i + 1][j] << 1) + (mat[i + 1][j + 1]);
    return f[i][j][k] = 1;
  }

  int l2 = l / 2;
  int pm = 0;
  bool ok = true;
  for (int u = 0; ok && u < 4; ++u) {
    int ni = i + ui[u] * l2;
    int nj = j + uj[u] * l2;
    ok = dfs(ni, nj, k - 1);
    pm ^= ((mask[ni][nj][k-1] != 0) << u);
  }

  for (int u = 0; ok && u < 4; ++u) {
    int ni = i + ui[u] * l2;
    int nj = j + uj[u] * l2;
    ok = (pm == mask[ni][nj][k - 1]) || (mask[ni][nj][k - 1] == 0);
  }
  mask[i][j][k] = pm;
  return f[i][j][k] = ok;
}

int main() {
//--------------------------------------------------------------------------
  #ifdef _DEBUG
	freopen("input.txt", "r", stdin);	freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);	freopen("output.txt", "w", stdout);
	//freopen("confectionery.in", "r", stdin);	freopen("confectionery.out", "w", stdout);
#endif
//--------------------------------------------------------------------------
 MEM(mask, -1);
 
  //scanf("%d %d", &n, &m);
 cin >> n >> m;
 string s;
 for (int i = 1; i <= n; ++i) {
   cin >> s;
   for (int j = 1; j <= m; ++j) {
     if (s[j - 1] == '*')
       mat[i][j] = 0;
     else
       mat[i][j] = 1;
   }
 }
 int ans = 0;
 for (int k = 2; k <= 10; ++k) {
   for (int i = 1; i <= n; ++i) {
     for (int j = 1; j <= m; ++j) {
        ans += dfs(i, j, k);   
     }
   }
 }
 cout << ans << endl;
  return 0;
}