#include<bits/stdc++.h>

using namespace std;

using INT = long long;

const int NN = 1e6 + 111;
const int MM = 22;

int id = 1, cur = 1;
vector<pair<int, int> > adj[NN];
int ans[NN];

int fa[NN][MM];
int prv[NN];

int make_node(int u, int w) {
	adj[u].push_back({++id, w});
	prv[id] = u;
	fa[id][0] = u;
	for(int i = 1; i < MM; i ++) {
		fa[id][i] = fa[fa[id][i-1]][i-1];
	}
	return id;
}

int k_th(int u, int k) {
	int U = u;
	for(int i = MM - 1; i >= 0; i --) {
		if((k >> i) & 1) {
			u = fa[u][i];
		}
	}
	adj[u].push_back({++id, -u});
	fa[id][0] = fa[u][0];
	for(int i = 1; i < MM; i ++) {
		fa[id][i] = fa[fa[id][i-1]] [i-1];
	}
	prv[id] = U;
	return id;
}

vector<int> _ans[NN];

int dist = 0;
int cnt[NN];

void add(int u) {
	cnt[u] ++;
	if(cnt[u] == 1) dist ++;
}

void sub(int u) {
	cnt[u] --;
	if(cnt[u] == 0) dist --;
}

void solve(int u) {
	for(auto v : _ans[u]) {
		ans[v] = dist;
	}
	for(auto p : adj[u]) {
		if(p.second >= 0) add(p.second);
		solve(p.first);
		if(p.second >= 0) sub(p.second);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int Q; cin >> Q;
	for(int i = 0; i < MM; i ++) {
		fa[1][i] = 1;
	}
	
	int qr = 0;
	
	while(Q--) {
		char s; scanf(" %c", &s);
		if(s == '+') {
			int u; scanf("%d", &u);
			cur = make_node(cur, u);
		}
		if(s == '-') {
			int k; scanf("%d", &k);
			cur = k_th(cur, k);
		}
		if(s == '?') {
			ans[++qr] = cur;
			_ans[cur].push_back(qr);
		}
		if(s == '!') {
			cur = prv[cur];
		}
	}
	
	solve(1);
	
	for(int i = 1; i <= qr; i ++) {
		printf("%d\n", ans[i]);
	}
}