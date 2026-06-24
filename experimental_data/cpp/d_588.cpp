#include <cstdio>
#include <iostream>
#include <algorithm>

#define MOD 1000000007ll

using namespace std;

int GetInt()
{
 register int aa = 0, bb = 1;
 register char ch = getchar();
 while ((ch < '0' || ch > '9') && ch != '-')
  ch = getchar();
 ch == '-' ? aa = 0, bb = -1 : aa = ch - '0';
 while (ch = getchar(), ch >= '0' && ch <= '9')
  aa = (aa << 1) + (aa << 3) + ch - '0';
 return bb == 1 ? aa : -aa;
}

int n, k, a[1000010], a2[1000010];
long long l, f[2][1000010], ans;

int main()
{
 register int i, j, c, t = 0;
 register long long tmp, x, y;
 cin >> n >> l >> k;
 y = l % n;
 for (i = 1; i <= n; i++)
  a[i] = a2[i] = GetInt();
 std::sort(a2 + 1, a2 + n + 1);
 std::sort(a + 1, a + y + 1);
 x = l / n + 1;
 for (i = 1; i <= n; i++)
  f[0][i] = 1;
 ans = l % MOD;
 for (i = 2; i <= k; i++)
 {
  if (x - i < 0) break;
  t = t ^ 1;
  tmp = 0;
  for (j = 1, c = 1; j <= n; j++)
  {
   while (a2[c] <= a2[j] && c <= n)
   {
    tmp += f[t ^ 1][c];
    tmp %= MOD;
    c++;
   }
   f[t][j] = tmp;
   ans += (x - i) % MOD * f[t][j] % MOD;
   ans %= MOD;
  }
  tmp = 0;
  for (j = 1, c = 1; j <= y; j++)
  {
   while (a2[c] <= a[j] && c <= n)
   {
    tmp += f[t ^ 1][c];
    tmp %= MOD;
    c++;
   }
   ans += tmp;
   ans %= MOD;
  }
 }
 cout << ans % MOD;
}