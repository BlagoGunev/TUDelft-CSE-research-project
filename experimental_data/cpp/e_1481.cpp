#include <bits/stdc++.h>
#ifdef __LOCAL__
  #include <debug_local.h>
#endif
using namespace std;
void testCase() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> freq(n + 1), first(n + 1), last(n + 1);
  for (int i = 1; i <= n; i++) {
    freq[a[i]]++;
    if (freq[a[i]] == 1) first[a[i]] = i;
    last[a[i]] = i;
  }
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; i++) {
    if (last[a[i]] == i) dp[i] = dp[first[a[i]] - 1] + freq[a[i]];
    dp[i] = max(dp[i], dp[i - 1]);
  }
  int ans = 0;
  int mx = 0;
  freq.assign(n + 1, 0);
  for (int i = n; i >= 1; i--) {
    if (last[a[i]] == i) {
      ans = max(ans, dp[i] + mx);
    }
    freq[a[i]]++;
    mx = max(mx, freq[a[i]]);
  }
  cout << n - ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  testCase();
}