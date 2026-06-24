// Author: Olaf Surgut (surgutti)
// Created on 11-12-2024 09:27:32
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define ll long long
#define ld long double

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(x) begin(x),end(x)
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
#define ROF(i,r,l) for(int i=(r);i>=(l);i--)

auto& operator<<(auto &o, pair<auto, auto> p) {
	return o << "(" << p.st << ", " << p.nd << ")";}
auto operator<<(auto &o, auto x)->decltype(end(x), o) {
	o << "{"; int i=0; for (auto e : x) o << ","+!i++ << e;
	return o << "}";}

#ifdef LOCAL
#define debug(x...) cerr << "[" #x "]: ", [](auto...$) { \
	((cerr << $ << "; "),...) << endl; }(x)
#else
#define debug(...)
#endif

#define rep(i,a,b) for(int i = a; i < (b); i++)
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 32768;

int n, m;
vector<int> adj[N + 1];
map<pii, int> cnt;

int bdfs() {
	vector<int> S;
	vector<int> FLAG(N + 1, false);
	int counter = 0;

	S.pb(1);
	while (sz(S)) {
		int u = S.back();
		// debug(S, u);
		S.pop_back();
		
		FLAG[u] = true;

		for (int v : adj[u]) {
			counter = counter + 1;
			cnt[make_pair(u, v)]++;
			if (FLAG[v] == false) {
				S.pb(v);
			}
		}
	}

	return counter;
}

void solve() {
	int k;
	cin >> k;

	if (k < 11 && k % 2 == 1) {
		cout << "-1 -1\n";
		return;
	}

	auto add_edge = [&](int u, int v) {
		adj[u].pb(v);
		adj[v].pb(u);
	};

	// return;

	vi xd;
	
	auto f = [&](int a) {
		return a * a + a + 2 * (a - 1) + 2;
	};

	ROF(i, N - 10, 1) {
		// debug(i, f(i), k);
		while (k - f(i) > 11) {
			xd.pb(i);
			k -= f(i);
		}
	}


	int nxt = 2;

	vector<int> yy;

	for (int a : xd) {
		int x = nxt++;

		yy.pb(nxt);

		rep(i, 0, a) {
			int u = nxt++;
			add_edge(x, u);	
		}

		rep(i, 0, a - 1) {
			add_edge(nxt - 1 - i, nxt - 1 - i - 1);
		}
	}

	for (int u : yy) {
		add_edge(1, u);
	}


	if (k >= 11 && k % 2 == 1) {	
		int A = 1;
		int B = nxt++;
		int C = nxt++;
		int D = nxt++;

		add_edge(A, B);
		add_edge(B, C);
		add_edge(C, A);
		add_edge(B, D);
	
		k -= 11;
	}

	while (k >= 2) {
		add_edge(1, nxt++);
		k -= 2;
	}
	
	FOR(i, 1, N) {
		sort(all(adj[i]));
	}

	debug(bdfs());
	
	vector<pii> edges;
	FOR(i, 1, N) {
		for (int v : adj[i]) {
			if (i < v)
				edges.eb(i, v);
		}
	}

	cout << N << ' ' << sz(edges) << '\n';
	for (auto [u, v] : edges) {
		cout << u << ' ' << v << '\n';
	}
}
	
signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int tt = 1;
	// cin >> tt;
	while (tt--)
		solve();

	return 0;
}