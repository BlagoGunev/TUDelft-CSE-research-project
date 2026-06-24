#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;
int phi[N];
void totient() {
  for (int i = 1; i < N; i++) phi[i] = i;
  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
    }
  }
}
long long dp[N], cur, mul[N];
vector<int> d[N];
int a[N];
void add(int x, int k) {
  cur -= phi[x] * mul[x] * mul[x];
  mul[x] += k;
  cur += phi[x] * mul[x] * mul[x];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  totient();
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      d[j].push_back(i);
    }
  }
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = i; j <= n; j += i) {
      for (auto x: d[a[j]]) {
        add(x, 1);
      }
    }
    dp[i] = cur;
    for (int j = i; j <= n; j += i) {
      for (auto x: d[a[j]]) {
        add(x, -1);
      }
    }
    for (int j = i + i; j <= n; j += i) {
      dp[i] -= dp[j];
    }
    ans += dp[i] % mod * i % mod;
    ans %= mod;
  }
  cout << ans << '\n';
  return 0;
}