#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5005;

ll b, a[N], temp[N];
int t, n, half_op, sub_op;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> b >> half_op >> sub_op;
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    int bound = min(half_op, sub_op);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    ll ans = LLONG_MAX;
    for (int both = 0; both <= bound; ++both) {
      ll here = 0;
      for (int i = 1; i <= both; ++i) {
        here += max(0LL, (a[i] + 1) / 2 - b);
      }
      int total = half_op - both + sub_op - both, ptr = 0;
      for (int i = both + 1; i <= min(n, both + total); ++i) {
        here += (a[i] + 1) / 2, temp[++ptr] = max(0LL, a[i] - b) - (a[i] + 1) / 2;
      }
      for (int i = min(n, both + total) + 1; i <= n; ++i) here += a[i];
      int rem_sub_op = sub_op - both;
      sort(temp + 1, temp + ptr + 1);
      if (rem_sub_op > ptr) continue;
      for (int i = 1; i <= rem_sub_op; ++i) here += temp[i];
      ans = min(ans, here);
    }
    cout << ans << '\n';
  }
  return 0;
}