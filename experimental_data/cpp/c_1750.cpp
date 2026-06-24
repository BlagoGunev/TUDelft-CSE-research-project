#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_move(pair<int, int> p) { cout << p.first + 1 << ' ' << p.second + 1 << '\n'; }

void solve() {
  int n; cin >> n;
  string a, b; cin >> a >> b;
  vector<int> b_flips(n, 0);
  vector<pair<int, int>> moves;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') {
      // insert moves into move array
      moves.emplace_back(i, i);
      // flip left chunk of b
      if (i > 0) {
        int l = 0, r = i - 1;
        b_flips[l]++;
        if (r + 1 < n) b_flips[r + 1]--;
      }
      // flip right chunk of b
      if (i < n - 1) {
        int l = i + 1;
        int r = n - 1;
        b_flips[l]++;
        // don't need to decrement b_flips[r + 1] because it's out of range
      }
    }
  }
  for (int i = 1; i < n; i++) b_flips[i] += b_flips[i - 1];
  int zeroes = 0, ones = 0;
  for (int i = 0; i < n; i++) {
    if (b_flips[i] & 1) b[i] = (b[i] == '1' ? '0' : '1');
    if (b[i] == '1') ones++;
    else zeroes++;
  }
  if (zeroes != n && ones != n) {
    cout << "NO\n";
    return;
  } else if (zeroes == n) {
    cout << "YES\n";
    cout << (int)moves.size() << '\n';
    for (auto move : moves) print_move(move);
  } else {
    // ones == n
    cout << "YES\n";
    moves.emplace_back(0, 0);
    moves.emplace_back(1, n - 1);
    moves.emplace_back(0, n - 1);
    cout << (int)moves.size() << '\n';
    for (auto move : moves) print_move(move);
  }
}

int main() {
  cin.tie(nullptr), ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) solve();
  return 0;
}