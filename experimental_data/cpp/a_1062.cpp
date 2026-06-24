#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <iomanip>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, char> pci;

void Solve() {
  int n; cin >> n;
  vector<int> a = {0};
  for (int i = 0; i < n; ++i) { int x; cin >> x; a.push_back(x); }
  a.push_back(1001);
  int res = 0;
  for (int l = 1; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      if (a[r + 1] - a[l - 1] == r - l + 2) {
        res = max(res, r - l + 1);
      }
    }
  }
  cout << res << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests_count = 1;
  for (int test_index = 0; test_index < tests_count; ++test_index) {
    Solve();
  }
  return 0;
}