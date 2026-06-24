#include <iostream>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int t = (cin >> t, t); t--; ) {
    int n; cin >> n;
    string s[3];
    int d[3];
    for (int i = 0; i < 3; ++i) {
      cin >> s[i];
      d[i] = n - 1 - s[i].rfind(s[i].back() ^ 1);
    }
    int ans = 0;
    for (int i = 0; i < 3; ++i) if (s[i].back() != s[(i + 1) % 3].back() && s[i].back() != s[(i + 2) % 3].back()) {
      ans = min(d[i], d[(i + 1) % 3]) + min(d[i], d[(i + 2) % 3]);
    }
    cout << min(ans, n) << '\n';
  }
}