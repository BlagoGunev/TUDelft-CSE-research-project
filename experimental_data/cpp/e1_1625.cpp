#include<bits/stdc++.h>

#define debug(x) cerr << #x << " = " << x << '\n';

#define debug_(x) cerr << #x << " = " << x << ' ';



using namespace std;



typedef long long ll;



const int N = (int)3e5;



template<int N> struct Fenw {

	ll t[N + 1];

	Fenw() {

		fill(t + 1, t + N + 1, 0ll);

	}

	void add(ll p, ll x) {

		for (ll i = p; i <= N; i += i & (-i)) {

			t[i] += x;

		}

	}

	ll get(ll p) {

		ll ret = 0;

		for (ll i = p; i > 0; i -= i & (-i)) {

			ret += t[i];

		}

		return ret;

	}

	ll get(ll l, ll r) {

		return get(r) - get(l - 1);

	}

};



Fenw<N> fw_dfs, fw_bfs;



int main() {

	std::ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	

	int T = 1;

//	cin >> T;

	while(T--) {

		int n, m;

		string s;

		cin >> n >> m >> s;

		// Init

		stack<int> S;

		vector<int> id(n, -1);

		int ID = 1;

		for(int i = 0; i < n; i++) {

			if(s[i] == '(') {

				S.push(i);

			} else if(!S.empty()) {

				++ID;

				id[i] = id[S.top()] = ID;

				S.pop();

			}

		}

		int rt = 1;

		auto g = vector(ID + 1, vector<int>());

		vector<int> FA(ID + 1, -1);

		function<int(int, int)> getTree = [&](int pos, int fa) {

			while(pos < n) {

				while(pos < n && id[pos] == -1) pos += 1;

				if(pos < n) {

					if(s[pos] == '(') {

						g[fa].push_back(id[pos]);

						FA[id[pos]] = fa;

						pos = getTree(pos + 1, id[pos]);

					} else if(s[pos] == ')') {

						return pos + 1;	

					}

				}

			}

			return pos;

		};

		getTree(0, rt);

		vector<ll> soncnt(ID + 1, 0);

		for(int i = 0; i <= ID; i++) {

			soncnt[i] = g[i].size();

		}

		// Build

		vector<int> dfn(ID + 1), sz(ID + 1), bfn(ID + 1);

		int DFN = 0;

		

		function<void(int)> dfs = [&](int u) {

			dfn[u] = ++DFN;

			sz[u] = 1;

			fw_dfs.add(dfn[u], soncnt[u] * (soncnt[u] + 1) / 2);

			for(auto v : g[u]) {

				dfs(v);

				sz[u] += sz[v];

			}

		};

		dfs(rt);

		

		vector<int> Q;

		Q.push_back(rt);

		for(int i = 0; i < (int)Q.size(); i++) {

			bfn[Q[i]] = i + 1;

			fw_bfs.add(i + 1, 1);

			for(auto v : g[Q[i]]) {

				Q.push_back(v);	

			}

		}

		// Work

		for(int i = 0; i < m; i++) {

			int t, l, r;

			cin >> t >> l >> r;

			l--, r--;

			if(t == 1) {

				int u = id[l];

				int ff = FA[u];

				if(~ff) {

					fw_dfs.add(dfn[ff], -soncnt[ff] * (soncnt[ff] + 1) / 2);

					soncnt[ff] -= 1;

					fw_dfs.add(dfn[ff], soncnt[ff] * (soncnt[ff] + 1) / 2);

				}

				fw_bfs.add(bfn[u], -1);

			} else {

				int u = id[l], v = id[r];

				ll res = 0;

				res += fw_dfs.get(dfn[v] + sz[v] - 1);

				res -= fw_dfs.get(dfn[u] - 1);

				ll cnt = fw_bfs.get(bfn[v]) - fw_bfs.get(bfn[u] - 1);

				res += cnt * (cnt + 1) / 2;

				cout << res << '\n';

			}

		}

	}

	

	return 0;

}