#include <bits/stdc++.h>

using namespace std;

int ntest;
int n, m;
vector<int> adj[1000001];
int disc[1000001], low[1000001];
int cnt_v = 0;
stack<int> stk;
bool is_in_stack[1000001];
int scc[1000001], sz[1000001];
int cnt_scc = 0;
int in_deg[1000001];
vector<int> ans[2];

template <typename T>
inline T read() {
	T x = 0;
	T multiplier = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			multiplier = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch & 15);
		ch = getchar();
	}
	return x * multiplier;
}

void tarjan(int u) {
	disc[u] = low[u] = ++cnt_v;
	stk.push(u);
	is_in_stack[u] = true;

	for (auto v : adj[u]) {
		if (!disc[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (is_in_stack[v]) {
			low[u] = min(low[u], disc[v]);
		}
	}

	if (disc[u] == low[u]) {
		cnt_scc++;
		int x = 0;
		while (x ^ u) {
			x = stk.top();
			stk.pop();
			is_in_stack[x] = false;
			scc[x] = cnt_scc;
			sz[cnt_scc]++;
		}
	}
}

int main() {
	ntest = read<int>();
	while (ntest--) {
		n = read<int>(), m = read<int>();

		cnt_v = cnt_scc = 0;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			disc[i] = 0, low[i] = 0;
			is_in_stack[i] = false;
			scc[i] = 0, sz[i] = 0;
			in_deg[i] = 0;
		}
		while (!stk.empty()) {
			stk.pop();
		}
		ans[0].clear(), ans[1].clear();

		for (int i = 1; i <= m; i++) {
			int u = read<int>(), v = read<int>();
			if (u ^ v) {
				adj[u].push_back(v);
			}
		}

		for (int i = 1; i <= n; i++) {
			if (!disc[i]) {
				tarjan(i);
			}
		}

		for (int u = 1; u <= n; u++) {
			for (auto v : adj[u]) {
				if (scc[u] ^ scc[v]) {
					++in_deg[scc[v]];
				}
			}
		}

		if (sz[scc[1]] == n) {
			puts("NO");
			continue;
		}

		for (int i = 1; i <= cnt_scc; i++) {
			if (!in_deg[i] && sz[i]) {
				puts("YES");
				for (int j = 1; j <= n; j++) {
					ans[scc[j] == i].push_back(j);
				}

				printf("%d %d\n", ans[0].size(), ans[1].size());
				for (auto x : ans[0]) {
					printf("%d ", x);
				}
				puts("");
				for (auto x : ans[1]) {
					printf("%d ", x);
				}
				puts("");

				goto ans_found;
			}
		}
		puts("NO");
	ans_found:;
	}
	return 0;
}