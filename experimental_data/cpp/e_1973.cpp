#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
constexpr int MAXN = 1e6 + 7;
constexpr int INF = 2e9;
constexpr ll INFF = 1e18;
constexpr ll MOD = 998244353;
#define mkp make_pair
#define F first
#define S second
#define pb emplace_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    int pre = 0, suf = n + 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == i)
        pre = i;
      else
        break;
    }
    for (int i = n; i >= 1; i--) {
      if (a[i] == i)
        suf = i;
      else
        break;
    }

    if (pre == n) {
      cout << (n * 2) * 1LL * (n * 2 + 1) / 2 << '\n';
      continue;
    }

    ll ans = (n * 2) * 1LL * (n * 2 + 1) / 2;
    // calculate l = r
    bool ok = 1;
    int cur = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] != i) {
        if (a[a[i]] != i)
          ok = 0;
        else if (cur == -1)
          cur = i + a[i];
        else if (cur != i + a[i])
          ok = 0;
      }
    }
    if (ok) {
      ans -= (2 * n - 1);
    } else {
      ans -= 2 * n;
    }

    // calculate l != r
    for (int r = 2; r <= n + 1; r++) {
      if (r - 1 < suf - 1)
        ans -= (r - 1);
    }
    for (int l = n + 1; l <= 2 * n; l++) {
      if (l - n > pre + 1)
        ans -= (2 * n - l);
    }
    cout << ans << '\n';
  }
}