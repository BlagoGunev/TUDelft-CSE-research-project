#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define inf 0x3F3F3F3F3F3F3F3F

const int MXN = 2e5 + 5;
const int MXM = 1e4 + 5;
const int B = 15;
const int mod = 998244353;

bitset<MXM> dp[B], zdp, alldp;

void _()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < B; i++)
  {
    for (int j = 0; j <= m; j++) dp[i][j] = 0; 
  }
  for (int j = 0; j <= m; j++) zdp[j] = 0, alldp[j] = 0;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<array<int, 2>> v;
  int cnt = 0;
  for (int i = n; i >= 1; i--)
  {
    if (a[i] != 1)
    {
      v.push_back({a[i], cnt});
      cnt = 0;
    }
    else cnt++;
  }
  reverse(v.begin(), v.end());
  if (v.empty())
  {
    if (cnt >= m)
    {
      cout << "YES\n";
      return;
    }
    cout << "NO\n";
    return;
  }
  int curp = 1;
  alldp[0] = 1;
  dp[14][0] = 1;
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j <= m; j++) dp[i % B][j] = 0;
    if (!v[i][0])
    {
      dp[i % B] |= alldp;
      zdp = dp[i % B];
    }
    else
    {
      dp[i % B] |= zdp;
      int p = v[i][0];
      for (int j = 1; j < B; j++)
      {
        if (i - j < 0) break;
        if (p > m) break;
        dp[i % B] |= (dp[(i - j) % B] << p);
        p *= v[i - j][0];
      }
    }
    if (curp <= m || !v[i][0]) curp *= v[i][0];
    if (curp <= m) dp[i % B][curp] = 1;
    for (int j = 1; j <= v[i][1]; j <<= 1) dp[i % B] |= (dp[i % B] << j), v[i][1] -= j;
    if (v[i][1]) dp[i % B] |= (dp[i % B] << v[i][1]);
    alldp |= dp[i % B];
  }
  int ind = ((int)v.size() - 1) % B;
  for (int j = 1; j <= cnt; j <<= 1) dp[ind % B] |= (dp[ind % B] << j), cnt -= j;
  if (cnt) dp[ind % B] |= (dp[ind % B] << cnt);
  if (dp[ind][m]) cout << "YES\n";
  else cout << "NO\n";
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) _();
}