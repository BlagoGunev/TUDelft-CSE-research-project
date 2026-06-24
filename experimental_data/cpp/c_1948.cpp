#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define dbg(x...)
#endif

/*
  Think about which subtasks you can solve.
  Think: If you just had x, you could solve the problem. Can you get x?
  Think from different perspectives. Solve backwards? Solve from the middle?
  Find interesting properties of the problem.
  Visualize and manually solve small example cases.
  Remember you can repeat these tricks more than once on the same problem as you make progress.
*/

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int __, _ = (cin >> __, 0); ++_ <= __;) {
    int n; cin >> n;
    vector<string> grid(2);
    for (auto &i : grid) cin >> i;
    vector vis(2, vector<bool>(n));
    queue<array<int, 2>> bfs;
    bfs.push({0, 0});
    vis[0][0] = 1;
    while (!bfs.empty()) {
      auto [x, y] = bfs.front(); bfs.pop();
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < 2 && ny < n) {
          if (grid[nx][ny] == '>') {
            ny++;
          } else {
            ny--;
          }
          if (nx >= 0 && ny >= 0 && nx < 2 && ny < n && !vis[nx][ny]) {
            bfs.push({nx, ny});
            vis[nx][ny] = true;
          }
        }
      }
    }
    cout << (vis[1][n - 1] ? "YES": "NO") << '\n';
  }
}