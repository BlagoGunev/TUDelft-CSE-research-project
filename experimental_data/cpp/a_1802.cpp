#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> pos(n + 1), neg(n + 1);
    for (int i = 0; i < n; i++) {
      int b;
      cin >> b;
      if (b > 0) {
        pos[b]++;
      } else {
        neg[-b]++;
      }
    }
    vector<int> ans1;
    int now = 1;
    for (int i = 1; i <= n; i++) {
      if (pos[i]) {
        ans1.push_back(now++);
      }
    }
    now--;
    for (int i = 1; i <= n; i++) {
      if (neg[i]) {
        ans1.push_back(--now);
      }
    }
    int both = 0;
    for (int i = 1; i <= n; i++) {
      if (pos[i] && neg[i]) {
        both++;
      }
    }
    vector<int> ans2;
    for (int i = 0; i < both; i++) {
      ans2.push_back(1);
      ans2.push_back(0);
    }
    now = 1;
    for (int i = 0; i < n - 2 * both; i++) {
      ans2.push_back(now++);
    }
    assert(int(ans1.size()) == n);
    assert(int(ans2.size()) == n);
    for (int i = 0; i < n; i++) {
      cout << ans1[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
      cout << ans2[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}