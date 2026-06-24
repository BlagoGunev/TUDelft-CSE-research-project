#include <bits/stdc++.h>
#define int long long
#define inf 2e18
typedef std::pair<int, int> pii;
const int N = 4e5 + 10;

int n, m;
std::vector<pii> g[N];
int dist[N];
bool st[N];

void dijkstra() {
	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;
	for(int i = 1; i <= 2 * n; i ++)
		dist[i] = inf;
	dist[1] = 0;
	q.push({dist[1], 1});
	while(!q.empty()) {
		auto t = q.top();
		q.pop();
		int u = t.second;
		if(st[u]) continue;
		st[u] = true;
		for(auto ne : g[u]) {
			int v = ne.second;
			int w = ne.first;

			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				q.push({dist[v], v});
			}
		}
	}
	for(int i = 2; i <= n; i ++) {
		int t = std::min(dist[i], dist[i + n]);
		if(t == inf) t = -1;
		std::cout << t << " ";
	}
	std::cout << "\n";
}

signed main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		g[i].push_back({0, n + i});
	while(m --) {
		int a, b, c;
		std::cin >> a >> b >> c;
		g[a].push_back({c, b});
		g[b + n].push_back({c, a + n});
	}
	dijkstra();
	return 0;
}