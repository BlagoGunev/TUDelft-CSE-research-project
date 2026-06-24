#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <complex>
#include <cassert>
#include <iterator>
#include <numeric>
#include <functional>
using namespace std;
#define REP(i,n) for(int i=0,e__=(n);i<e__;++i)
#define rep(i,s,n) for(int i=(s),e__=(n);i<e__;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const double PI = 3.14159265358979323846264338327950288;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
int in_c() { int c; while ((c = getchar()) <= ' ') { if (!~c) return ~0; } return c; }
int in() {
  int x = 0, c;
  while ((ui)((c = getchar()) - '0') >= 10) { if (c == '-') return -in(); if (!~c) return ~0; }
  do { x = 10 * x + (c - '0'); } while ((ui)((c = getchar()) - '0') < 10);
  return x;
}

struct Edge {
  int to, w;
};
typedef vector<vector<Edge> > Graph;

const int MN = 1000, MM = 1000;
const ll INF = 1LL << 60;
int N, M;
int T[MN], C[MN];
ll dp[MN];
bool visited[MN];
ll memo[MN];

struct S {
  int pos;
  ll cost;
  bool operator < (const S& s) const {
    return cost > s.cost;
  }
};

ll Dijkstra(const Graph& g, int src, int dst) {
  priority_queue<S> q;
  REP(i, N) dp[i] = INF, visited[i] = false;
  dp[src] = 0;
  q.push((S) { src, 0 });
  while (!q.empty()) {
    S s = q.top(); q.pop();
    if (visited[s.pos]) continue;
    visited[s.pos] = true;
    if (s.pos == dst) {
      return s.cost;
    }
    // BFS
    fill(memo, memo + N, -1);
    queue<int> que;
    que.push(s.pos);
    memo[s.pos] = 0;
    while (!que.empty()) {
      int p = que.front(); que.pop();
      FOR(it, g[p]) if (memo[it->to] == -1 &&
                        memo[p] + it->w <= T[s.pos]) {
        memo[it->to] = memo[p] + it->w;
        que.push(it->to);
        if (!visited[it->to] && s.cost + C[s.pos] < dp[it->to]) {
          dp[it->to] = s.cost + C[s.pos];
          q.push((S) { it->to, dp[it->to] } );
        }
      }
    }
  }
  return -1;
}

int main() {
  while (cin >> N >> M) {
    Graph g(N);
    int start, end;
    cin >> start >> end;
    --start, --end;
    REP(i, M) {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      g[u].push_back((Edge) { v, w });
      g[v].push_back((Edge) { u, w });
    }
    REP(i, N) cin >> T[i] >> C[i];
    ll ans = Dijkstra(g, start, end);
    cout << ans << endl;
  }
  return 0;
}