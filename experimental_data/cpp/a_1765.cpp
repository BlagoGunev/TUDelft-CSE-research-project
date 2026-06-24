#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define ssize(x) int(x.size())
template<class A,class B>auto&operator<<(ostream &o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...)<<'\n';}(x)
#else
#define debug(...) {}
#endif

struct Matching {
	vector<vector<int>> &adj;
	vector<int> mat, vis;
	int t = 0, ans = 0;
	bool mat_dfs(int v) {
		vis[v] = t;
		for(int u : adj[v])
			if(mat[u] == -1) {
				mat[u] = v;
				mat[v] = u;
				return true;
			}
		for(int u : adj[v])
			if(vis[mat[u]] != t && mat_dfs(mat[u])) {
				mat[u] = v;
				mat[v] = u;
				return true;
			}
		return false;
	}
	Matching(vector<vector<int>> &_adj) : adj(_adj) {
		mat = vis = vector<int>(ssize(adj), -1);
	}
	pair<int, vector<int>> operator()() {
		int d = -1;
		while(d != 0) {
			d = 0, ++t;
			REP(v, ssize(adj))
				if(mat[v] == -1)
					d += mat_dfs(v);
			ans += d;
		}
		return {ans, mat};
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector v(n, vector (m, false));
	REP(i, n) {
		REP(j, m) {
			char x;
			cin >> x;
			v[i][j] = x == '1';
		}
	}
	debug(n, m, v);

	vector<vector<int>> graph(2 * m);
	vector same(m, vector<bool> (m));
	REP(i, m) {
		REP(j, i) {
			int left = 0, right = 0;
			REP(k, n) {
				if (v[k][i] and not v[k][j])
					++left;
				if (v[k][j] and not v[k][i])
					++right;
			}
			if (max(right, left) == 0) {
				same[i][j] = true;
				same[j][i] = true;
			}
			if (right == 0) {
				graph[j].emplace_back(i + m);
			}
			else if (left == 0) {
				graph[i].emplace_back(j + m);
			}
		}
	}
	debug(graph);
	debug(same);

	Matching matching(graph);
	auto [score, paring] = matching();
	debug(score, paring);

	const int k = m - score;

	vector<int> rep(m);
	iota(rep.begin(), rep.end(), 0);
	function<int(int)> Find = [&](int x) {
		if (rep[x] != x)
			rep[x] = Find(rep[x]);
		return rep[x];
	};
	auto Union = [&](int a, int b) {
		a = Find(a);
		b = Find(b);
		if (a == b)
			return false;
		rep[a] = b;
		return true;
	};
	REP(i, m) {
		if (paring[i] == -1)
			continue;
		Union(i, paring[i] - m);
	}

	int next = 0;
	vector<int> color(m);
	REP(i, m) {
		if (Find(i) != i)
			continue;
		color[i] = next;
		++next;
	}
	REP(i, m) {
		if (Find(i) != i)
			color[i] = color[Find(i)];
	}
	debug(color);

	assert(next == k);

	vector<int> value(m, 2);
	vector<bool> vis(m);
	function<void(int)> dfs = [&](int x) {
		vis[x] = true;
		for (int e : graph[x]) {
			e -= m;
			if (not vis[e])
				dfs(e);
			if (color[x] == color[e])
				value[x] = max(value[x], value[e] + int(not same[x][e]));
		}
	};
	REP(i, m) {
		if (vis[i])
			continue;
		dfs(i);
	}
	debug(value);

	vector workers(n, vector (k, 1));
	REP(i, n) {
		REP(j, m) {
			if (v[i][j]) {
				workers[i][color[j]] = max(workers[i][color[j]], value[j]);
			}
		}
	}

	cout << k << '\n';

	REP(i, m)
		cout << color[i] + 1 << ' ';
	cout << '\n';

	REP(i, m)
		cout << value[i] << ' ';
	cout << '\n';

	REP(i, n) {
		REP(j, k) {
			cout << workers[i][j] << ' ';
		}
		cout << '\n';
	}
}