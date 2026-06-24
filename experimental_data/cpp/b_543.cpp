#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define X first
#define Y second

using namespace std;
using i64 = long long;
using Pii = pair<int, int>;

constexpr int MAX = 5010;

vector<int> adj[MAX];
Pii edge[MAX];
int dis[MAX][MAX], que[MAX], front, rear;

void bfs(int src, int* dis) {
  front = rear = 0;
  dis[src] = 0; que[rear++] = src;
  while (front < rear) {
    int x = que[front++];
    for (const auto& y : adj[x]) {
      if (dis[y] == -1) {
        dis[y] = dis[x] + 1;
        que[rear++] = y;
      }
    }
  }
}

inline bool check1(int x, int y, int d) {
  return dis[0][x] + dis[1][y] + 1 == d ||
      dis[1][x] + dis[0][y] + 1 == d;
}

inline bool check2(int x, int y, int d) {
  return dis[2][x] + dis[3][y] + 1 == d ||
      dis[3][x] + dis[2][y] + 1 == d;
}

int solve(int n, int m, int a1, int b1, int l1, int a2, int b2, int l2) {
  memset(dis, -1, sizeof(dis));
  for (int i = 0; i < n; ++i) {
    bfs(i, dis[i]);
  }
  int w1 = dis[a1][b1], w2 = dis[a2][b2];
  if (w1 == -1 || w2 == -1) return -1;
  if (w1 > l1 || w2 > l2) return -1;
  int ret = max(0, m - w1 - w2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int d1 = min(dis[a1][i] + dis[b1][j], dis[a1][j] + dis[b1][i]);
      int d2 = min(dis[a2][i] + dis[b2][j], dis[a2][j] + dis[b2][i]);
      if (d1 + dis[i][j] <= l1 && d2 + dis[i][j] <= l2) {
        ret = max(ret, m - d1 - d2 - dis[i][j]);
      }
    }
  }
  return ret;
}

int main() {
  int n, m, a1, b1, l1, a2, b2, l2;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; ++i) {
      adj[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &edge[i].X, &edge[i].Y);
      --edge[i].X; --edge[i].Y;
      adj[edge[i].X].push_back(edge[i].Y);
      adj[edge[i].Y].push_back(edge[i].X);
    }
    scanf("%d%d%d%d%d%d", &a1, &b1, &l1, &a2, &b2, &l2);
    --a1; --b1; --a2; --b2;
    printf("%d\n", solve(n, m, a1, b1, l1, a2, b2, l2));
  }
  return 0;
}