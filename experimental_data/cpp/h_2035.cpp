#include <bits/stdc++.h>
using namespace std;
// #include "../lib/hori.h"

struct ds {
  vector<int> occ, pos;
  int counter, n;
  ds() {}
  ds(vector<int> perm) {
    counter = 0;
    n = ssize(perm);
    occ = vector<int>(n, 0);
    pos = vector<int>(2 * n, 0);  // store n + i - update
    for (int i = 0; i < n; i++) {
      occ[perm[i]] = i;
      pos[n + i - 0] = perm[i];
    }
  }
  int query(int x) {  // find the i such that a[i] = x;
    return occ[x] + counter;
  }
  void op(int i) {  // funny operation
    int a = pos[n + i - 1 - counter];
    int b = pos[n + i - counter];
    int c = pos[n + n - 1 - counter];
    counter++;
    if (i) pos[n + 0 - counter] = a, occ[a] = -counter;
    pos[n + i - counter] = b, occ[b] = i - counter;
    if (i != n - 1) pos[n + i + 1 - counter] = c, occ[c] = i + 1 - counter;
  }
  int at(int i) {  // return a[i]
    return pos[n + i - counter];
  }
  vector<int> get() {  // return the new permutation
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      arr[i] = pos[n + i - counter];
    }
    return arr;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t; for (int tt = 0; tt < t; tt++) {
    int n; cin >> n;
    vector<int> aa(n), bb(n), pos_b(n), a(n);
    for (auto& i : aa) cin >> i, i--;
    for (auto& i : bb) cin >> i, i--;
    for (int i = 0; i < n; i++) pos_b[bb[i]] = i;
    for (int i = 0; i < n; i++) a[i] = pos_b[aa[i]];
    if (a == vector<int>{1, 0}) {
      cout << -1 << endl;
      continue;
    }
    ds d(a);
    vector<int> ans;
    auto op = [&] (int i) {
      d.op(i);
      ans.push_back(i + 1);
      if (d.counter > n - 1) d = ds(d.get());
    };
    for (int i = n - 1; i >= 0; i--) {
      int j = d.query(i);
      if (j != n - 1) {
        op(j + 1);
      } else if (i != 0) {
        int k = d.query(i - 1);
        op(k + 1);
        int j = d.query(i);
        if (j == n - 1) op(0);
        else op(j + 1), i += (i == n - 1);
        i--;
      } else {
        op(0);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (i != n - 2 and d.at(n - 3) > d.at(n - 2)) op(n - 2), i++;
      op(n - 1);
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " "; cout << endl;
  }
}