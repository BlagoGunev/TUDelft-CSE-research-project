#include <bits/stdc++.h>

using namespace std;

const int hor[] = { -1, +1, 0, 0 };
const int ver[] = { 0, 0, -1, +1 };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  for (cin >> t; t--;) {
    string s;
    cin >> s;
    int n = (int)s.length();
    set<pair<int, int> > blocks;
    for (int x0 = 0, y0 = 0, i = 0; i < n; ++i) {
      if (s[i] == 'L') x0--;
      else if (s[i] == 'R') x0++;
      else if (s[i] == 'D') y0--;
      else y0++;
      blocks.insert({x0, y0});
      for (int k = 0; k < 4; ++k) {
        int x1 = x0 + hor[k];
        int y1 = y0 + ver[k];
        blocks.insert({x1, y1});
      }
    }
    blocks.erase({0, 0});
    bool ok = false;
    for (const auto [x0, y0] : blocks) {
      int x = 0, y = 0;
      for (int i = 0; i < n; ++i) {
        int tx = x, ty = y;
        if (s[i] == 'L') tx--;
        else if (s[i] == 'R') tx++;
        else if (s[i] == 'D') ty--;
        else ty++;
        if (tx != x0 || ty != y0) {
          x = tx;
          y = ty;
        }
      }
      if (x == 0 && y == 0) {
        ok = true;
        cout << x0 << ' ' << y0 << endl;
        break;
      }
    }
    if (!ok) {
      cout << "0 0" << endl;
    }
  }
  return 0;
}