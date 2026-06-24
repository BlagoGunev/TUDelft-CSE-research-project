//  author: tih-a
//  #IDK
//  I just pulled up in a lot, girl
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
  //  https://codeforces.com/contest/1836/submission/211170763
  //  Update
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  vector<int> p(*max_element(all(a)) + 1, 0);
  for (auto i : a)
    p[i]++;
  reverse(all(p));
  string ans = "YES";
  for (int i = 1; i < p.size(); ++i) {
    if (p[i] < p[i - 1]) {
      ans = "NO";
      break;
    }
  }
  cout << ans << '\n';
}

signed main() {
  //  Optimize Gang
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  cin >> tt;
  while (tt--)
    solve();
  return 0;
}