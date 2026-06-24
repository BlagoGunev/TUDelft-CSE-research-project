#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 105;
int n, m, MOD;
int dx[4] = {-1, -1, 0, 0};
int dy[4] = {-1, 0, -1, 0};
int sx[4] = {-1, -1, 1, 1};
int sy[4] = {-1, 1, -1, 1};
string mm = "\\//\\";
int mark[MAX][MAX], color[MAX][MAX], a[2 * MAX][2 * MAX];
char c[MAX][MAX];
bool cycle;
bool isav(int x, int y)
{
 return (0 <= x && x < n && 0 <= y && y < m);
}
void dfs(int x, int y, int px, int py, int col)
{
 color[x][y] = col;
 mark[x][y] = 1;
 for (int i = 0; i < 4; i++)
 {
  int xx = x + dx[i];
  int yy = y + dy[i];
  int nx = x + sx[i];
  int ny = y + sy[i];
  if (nx == px && ny == py)
   continue;
  if (isav(xx, yy) && c[xx][yy] == mm[i])
  {
   if (mark[nx][ny] == 1)
    cycle = true;
   if (!mark[nx][ny])
    dfs(nx, ny, x, y, col);
  }
 }
 mark[x][y] = 2;
}
int bpow(int a, int b)
{
 int ans = 1;
 while (b)
 {
  if (b & 1)
   ans = 1LL * ans * a % MOD;
  b >>= 1;
  a = 1LL * a * a % MOD;
 }
 return ans;
}
int det(int n)
{
 int ans = 1;
 for (int i = 1; i < n; i++)
 {
  for (int row = i + 1; row < n; row++)
   if (a[row][i])
   {
    for (int j = i; j < n; j++)
     swap(a[i][j], a[row][j]);
    ans = (MOD - ans) % MOD;
    break;
   }
  if (!a[i][i])
   return 0;
  ans = 1LL * ans * a[i][i] % MOD;
  int inv = bpow(a[i][i], MOD - 2);
  for (int j = i; j < n; j++)
   a[i][j] = 1LL * a[i][j] * inv % MOD;
  for (int row = i + 1; row < n; row++)
   if (a[row][i])
   {
    for (int j = n - 1; j >= i; j--)
     a[row][j] = (a[row][j] - 1LL * a[row][i] * a[i][j] % MOD + MOD) % MOD;
   }
 }
 return ans;
}
int solve(int x)
{
 memset(mark, 0, sizeof(mark));
 cycle = false;
 int cnt = 0;
 for (int i = 0; i <= n; i++)
  for (int j = 0; j <= m; j++)
   if (!mark[i][j] && ((i + j) & 1) == x)
    dfs(i, j, -1, -1, cnt++);
 if (cycle)
  return 0;
 if (cnt > 2 * MAX)
  return 0;
 memset(a, 0, sizeof(a));
 for (int i = 0; i < n; i++)
  for (int j = 0; j < m; j++)
   if (c[i][j] == '*')
   {
    int u, v;
    if (((i + j) & 1) == x)
    {
     u = color[i][j];
     v = color[i + 1][j + 1];
    }
    else
    {
     u = color[i][j + 1];
     v = color[i + 1][j];
    }
    if (u == v)
     continue;
    a[u][u] = (a[u][u] + 1) % MOD;
    a[v][v] = (a[v][v] + 1) % MOD;
    a[u][v] = (a[u][v] - 1 + MOD) % MOD;
    a[v][u] = (a[v][u] - 1 + MOD) % MOD;
   }
 return det(cnt);
}
int main()
{
 ios::sync_with_stdio(false);
 cin >> n >> m >> MOD;
 for (int i = 0; i < n; i++)
  for (int j = 0; j < m; j++)
   cin >> c[i][j];
 cout << (solve(0) + solve(1)) % MOD << "\n";
 return 0;
}