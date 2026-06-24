/*
 * Author: triveni
 * Created: 2023-02-16 20:05:03
**/

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
	#include <debug.h>
#else
	#define debug(...) 0
#endif


using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      sz(v)             (int)(v.size())
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      rep1(i, n)        for(int i = 1; i <= (n); ++i)
#define      all(v)            v.begin(), v.end()
#define      scan(n)           scanf("%d", &n)
#define      scan2(n, m)       scanf("%d%d", &n, &m)
#define      pin(n)            printf("%d\n",n)
#define      pis(n)            printf("%d ",n)
#define      pll(n)            printf("%lld\n", n)
#define      p10               putchar(10)
#define      X                 first
#define      Y                 second
#define      lg2(n)            (31 - __builtin_clz(n))
#define      yesno(f)          puts((f) ? "Yes": "No")

typedef long long ll;
const int mod = 998244353;

int req[100100];
int n;

constexpr int M = 1024;

vi g[100100];
set<int> g1[100100];
bitset<M> mask[100100];

// Think reverse DP
void solve(int tc) {
	int m; scan2(n, m);
	rep(i, n) {
		scan(req[i]);
		g[i].clear();
		g1[i].clear();
	}
	queue<int> poss;
	rep(i, m) {
		int u, v; scan2(u, v); --u, --v;
		g1[u].insert(v);
		g1[v].insert(u);
	}
	rep(i, n) if(sz(g1[i]) == req[i]) poss.push(i);
	vector<int> topo;
	while (!poss.empty()) {
		int u = poss.front(); poss.pop();
		topo.push_back(u);
		for (int c: g1[u]) {
			g1[c].erase(u);
			g[u].push_back(c);
			if (sz(g1[c]) == req[c]) poss.push(c);
		}
	}
	reverse(all(topo));
	debug(topo);
	// rep(i, n) debug(g[i]);
	ll ans = n * (ll)(n + 1) / 2;
	for (int i = 0; i < n; i += M) {
		rep(i, n) mask[i].reset();
		for (int j = i; j < n; ++j) {
			int k = j - i;
			bitset<M> & msk = mask[topo[j]];
			if (k < M) {
				msk.set(k);
			}
			for (int c: g[topo[j]]) {
				msk |= mask[c];
			}
			ans -= msk.count();
		}
	}
	pll(ans);
}

// Do examples

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int T = 1;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		solve(tc);
	}
	return 0;
}