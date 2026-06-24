#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#define lson (p << 1)
#define rson (p << 1 | 1)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
int n;
int w[maxn], h[maxn];

ll ksm(ll x, ll y) {
  ll ret = 1;
  do {
    if(y % 2 ==1) {
      ret = ret * x % mod;
    }
    x = x * x % mod;
  } while(y >>= 1);
  return ret;
}

void solve() {
  cin >> n;
  for(int i = 1;i<=n;i++) {
    cin >> w[i];
  }
  int ans = 1e9;
  for(int i = 1;i<=n;i++) {
    int cnt = 0;
    for(int j = i + 1;j<=n;j++) {
      if(w[j] > w[i]) {
        cnt++;
      }
    }
    ans = min(ans, i - 1 + cnt);
  }
  cout << ans << "\n";
}

int main() {
  int _ = 1;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> _;
  while (_--) {
    solve();
  }
}