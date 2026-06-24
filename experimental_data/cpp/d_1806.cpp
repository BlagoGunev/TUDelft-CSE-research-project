#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define F first
#define S second

constexpr int mod = 998244353;

void compute() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i <= n - 1; i++) cin >> a[i];

  vector<ll> dp(n + 1);
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] * (i - 1 - a[i - 1]) % mod;
  }

  ll ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    (ans *= i) %= mod;
    if (!a[i]) (ans += dp[i]) %= mod;
    cout << ans << " ";
  }
  cout << "\n";
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) compute();

  return 0;
}