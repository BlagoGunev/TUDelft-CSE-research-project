#include<bits/stdc++.h>

using namespace std;

template<typename T>

bool chmin(T &a, const T &b){if(a > b) return a = b, 1; return 0;}

const int N = 311111, M = N << 1;

int T, n, m, cnt, hd[M], to[M], nxt[M];

vector<int> ans[N];

int dfn[M], low[M], tim, stk[M], tp;

vector<vector<int> > scc;

void tarjan(int x, int fa){

	dfn[x] = low[x] = ++ tim;

	for(int i = hd[x];i;i = nxt[i]){

		int v = to[i];

		if(v == fa) continue;

		if(!dfn[v]){

			stk[++ tp] = i >> 1;

			tarjan(v, x); chmin(low[x], low[v]);

			if(low[v] >= dfn[x]){

				scc.emplace_back();

				do scc.back().push_back(stk[tp]); while(stk[tp --] != (i >> 1)); 

			}

		} else if(dfn[v] < dfn[x]){

			stk[++ tp] = i >> 1;

			chmin(low[x], dfn[v]);

		}

	}

}

int nod[M], nods, nrev[M], q[M], fr, re, ls[M], rs[M], pos[M], ps;

vector<int> G[N];

set<int> st[N];

bool vis[M];

bool chk(){

	memset(vis, 0, nods + 1);

	memset(ls, 0, (nods + 1) << 2);

	memset(rs, 0, (nods + 1) << 2);

	memset(pos, 0, (nods + 1) << 2);

	if(nods == 2){ans[nod[1]].push_back(nod[2]); ans[nod[2]].push_back(nod[1]); return 1;}

	fr = re = ps = 0;

	for(int i = 1;i <= nods;++ i)

		if((st[i] = set<int>(G[i].begin(), G[i].end())).size() == 2)

			q[re ++] = i;

	int rem = nods;

	vector<tuple<int, int, int> > hah; 

	while(fr < re){

		int x = q[fr ++];

		if(vis[x]) continue;

		-- rem; vis[x] = 1;

		if(st[x].empty()) continue;

		int a = *st[x].begin(), b = st[x].size() == 2 ? *++st[x].begin() : 0;

		if(rem == 2 && b){

			if(!st[a].count(b)) return 0;

			vis[a] = vis[b] = 1; rem = 0;

			ls[x] = a; rs[x] = b;

			ls[a] = b; rs[a] = x;

			ls[b] = x; rs[b] = a;

			break;

		}

		hah.emplace_back(x, a, b);

		st[a].erase(x);

		if(b){

			st[b].erase(x);

			if(a != b){

				st[a].insert(b);

				st[b].insert(a);

			}

		}

		if(st[a].size() <= 2) q[re ++] = a;

		if(b && st[b].size() <= 2) q[re ++] = b;

	}

	if(rem) return 0;

	reverse(hah.begin(), hah.end());

	for(auto [x, a, b] : hah){

		ls[x] = a; rs[x] = b;

		if(b){

			if((ls[a] != b && rs[a] != b) || (ls[b] != a && rs[b] != a)) return 0;

			(ls[a] == b ? ls[a] : rs[a]) = x;

			(ls[b] == a ? ls[b] : rs[b]) = x;

		} else (ls[a] ? rs[a] : ls[a]) = x;

	}

	for(int x = 1;vis[x];x = vis[ls[x]] ? ls[x] : rs[x]){vis[x] = 0; pos[x] = ++ ps;}

	for(int i = 1;i <= nods;++ i){

		sort(G[i].begin(), G[i].end(), [&](int u, int v){

			return ((pos[u] < pos[i]) == (pos[v] < pos[i])) == (pos[u] < pos[v]); 

		});

		for(int j : G[i]) ans[nod[i]].push_back(nod[j]);

	}

	return 1;

}

void solve(){

	cin >> n >> m; cnt = 1; tim = tp = 0;

	memset(hd, 0, (n + 1) << 2); scc.clear();

	memset(dfn, 0, (n + 1) << 2);

	memset(low, 0, (n + 1) << 2);

	for(int i = 0;i <= n;++ i) ans[i].clear();

	for(int i = 0, u, v;i < m;++ i){

		cin >> u >> v; ++ u; ++ v;

		to[++ cnt] = v; nxt[cnt] = hd[u]; hd[u] = cnt;

		to[++ cnt] = u; nxt[cnt] = hd[v]; hd[v] = cnt;

	}

	tarjan(1, 0);

	bool flg = 1;

	for(const vector<int> &edg : scc){

		nods = 0;

		for(int i : edg){

			nod[++ nods] = to[i << 1];

			nod[++ nods] = to[i << 1 | 1];

		}

		sort(nod + 1, nod + nods + 1);

		nods = unique(nod + 1, nod + nods + 1) - nod - 1;

		for(int i = 1;i <= nods;++ i) nrev[nod[i]] = i;

		for(int i : edg){

			int u = nrev[to[i << 1]], v = nrev[to[i << 1 | 1]];

			G[u].push_back(v); G[v].push_back(u);

		}

		flg &= chk();

		for(int i = 1;i <= nods;++ i){nrev[nod[i]] = 0; G[i].clear();}

		memset(nod, 0, (nods + 1) << 2);

	}

	if(flg){

		puts("YES");

		for(int i = 1;i <= n;++ i){

			for(int j : ans[i]) printf("%d ", j - 1);

			putchar('\n');

		}

	} else puts("NO");

}

int main(){

	ios::sync_with_stdio(0);

	cin >> T; while(T --) solve();

}