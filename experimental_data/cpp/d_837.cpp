#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int const N = 100 * 1000 + 16;
int const M = 1000*1000*1000 + 7;

int n, k;
int a[256];
int b[256];
int dp[256][6000];
bool vis[256][6000];

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    while(x % 2 == 0)
      ++a[i], x >>= 1;
    while(x % 5 == 0)
      ++b[i], x /= 5;
  }

  vis[0][0] = true;
  dp[0][0] = 0;

  for(int i = 0; i < n; ++i) {
    for(int s = min(i, k-1), last = 25*i+1; s >= 0; --s, last -= 25) {
      for(int j = 0; j <= last; ++j)
        if(vis[s][j]) {
          vis[s+1][j+b[i]] = true;
          dp[s+1][j+b[i]] = max(dp[s+1][j+b[i]], dp[s][j] + a[i]);
        }
    }
  }

  int best = 0;
  for(int i = 1; i <= 5000; ++i)
    if(vis[k][i])
      best = max(best, min(i, dp[k][i]));

  cout << best;
}