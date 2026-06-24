#include <iostream>

#include <queue>
#include <vector>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const int maxn = 2e5 + 5;
const int INF = 1e18;

vector<int> g[maxn], gr[maxn], p, dist;

void bfs(int st) {
queue<int> q;
q.push(st);
dist[st] = 0;
while (!q.empty()) {
auto v = q.front();
q.pop();
for (auto u : gr[v]) {
if (dist[u] > dist[v] + 1) {
dist[u] = dist[v] + 1;
q.push(u);
}
}
}
}

signed main() {
fastio;
int n, m;
cin >> n >> m;
dist.resize(n + 5, INF);
for (int i = 0; i < m; ++i) {
int u, v;
cin >> u >> v;
--u, --v;
g[u].push_back(v);
gr[v].push_back(u);
}
int k;
cin >> k;
for (int i = 0; i < k; ++i) {
int x;
cin >> x;
--x;
p.push_back(x);
}
bfs(p.back());
int mi = 0, ma = 0;
for (int i = 0; i < k - 1; ++i) {
int v = p[i];
if (dist[p[i + 1]] > dist[v] - 1)
++mi, ++ma;
else {
for (auto u : g[v]) {
if (u == p[i + 1])
continue;
if (dist[u] == dist[v] - 1) {
++ma;
break;
}
}
}
}
cout << mi << " " << ma;
}