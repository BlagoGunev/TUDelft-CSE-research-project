#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)x.size())

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  string a;
  cin >> n >> k >> a;
  int ans = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    int cur_ans = 0;
    int b = 0, e = 0;
    while (b < n) {
      int u = 0;
      while (e < n && a[e] == a[b]) {
        e++;
        u++;
      }
      if (a[b] == c) {
        cur_ans += (u / k);
      }
      b = e;
    }
    ans = max(ans, cur_ans);
  }
  cout << ans << '\n';
  return 0;
}