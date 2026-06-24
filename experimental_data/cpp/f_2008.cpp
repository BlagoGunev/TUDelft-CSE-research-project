#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <bits/Bingbong.h>
#endif
using namespace std;
#define i64 long long
#define pi acos(-1)
const i64 mod = 1e9 + 7;
i64 ksm(i64 a, i64 b) {
  a %= mod;
  i64 ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
void solve() {
  i64 n;
  cin >> n;
  vector<i64> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  i64 ans = 0;
  vector<i64> s(n + 2);
  for (int i = n; i >= 1; i--) {
    s[i] = s[i + 1] + a[i];
    s[i] %= mod;
  }
  for (int i = 1; i <= n; i++) {
    ans = ans + a[i] * s[i + 1] % mod;
    ans %= mod;
  }
  ans = ans * ksm(n * (n - 1) / 2, mod - 2) % mod;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}