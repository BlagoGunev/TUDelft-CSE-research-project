#include <bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

typedef pair <ll, ll> pii;

const int N = 1e5 + 7, lg = 17, inf = 1e9 + 7;
const ll I = 1e18;

ll n, q, T, cur;
vector <pii> adj[N];
string s;
ll par[N][lg+1], dub[N];
ll zbr[N], zbr2[N], dis[N], dp[N][lg+1], dp2[N][lg+1];

ll F(ll x, ll y) {return (x+y-1)/y;}
void dfs(int x, ll d = 0, int p = 0) {
	par[x][0] = p;
	dub[x] = dub[p]+1;
	zbr[x] = zbr[p] + d;
	zbr2[x] = zbr2[p] + F(d, (1 << cur));
	dp[x][0] = -zbr[x] + zbr2[x] + dis[x];
	dp2[x][0] = -zbr2[x] + zbr[x] + dis[x];
//	cout << x << " -- " << dp[x][0][0] << "\n";
	for (auto it : adj[x]) if (it.F != p) dfs(it.F, it.S, x);
}

void Init() {
//	if (cur > 3) return;
//	cout << cur << " -------------\n";
	set <pii> qq;
	for (int i = 1; i <= n; i++) dis[i] = I;
	for (int j = 1; j <= n; j++) if (s[j] == '1') {
		qq.insert({0, j});
		dis[j] = 0;
	}
	while (!qq.empty()) {
		auto p = qq.begin();
		int x = (*p).S;
		qq.erase(p);
//			if (i <= 3)cout << x << "a\n";
		for (auto it : adj[x]) {
			ll y = it.F, w = it.S + F(it.S, (1 << cur));
//				if (i <= 3)cout << y << " " << w << " " << dis[x][i] << " " << dis[y][i] << "\n";
			if (dis[x] + w < dis[y]) {
				if (dis[y] != I) qq.erase({dis[y], y});
				dis[y] = dis[x] + w;
				qq.insert({dis[y], y});
			}
		}
	}
	dfs(1);
	for (int k = 1; k <= lg; k++) {
		for (int i = 1; i <= n; i++) {
			par[i][k] = par[par[i][k-1]][k-1];
			dp[i][k] = min(dp[i][k-1], dp[par[i][k-1]][k-1]);
			dp2[i][k] = min(dp2[i][k-1], dp2[par[i][k-1]][k-1]);
		}
	}
	/*for (int i = 1; i <= n; i++) {
		cout << dis[i] << "\n";
		for (int j = 0; j <= 3; j++) {
			cout << dp[i][j] << " " << dp2[i][j] << "\n";
		}
	}*/
}

struct dat {
	ll x, mn, mn2;
};
dat Lift(int x, int k) {
	ll mn = I, mn2 = I;
	for (int i = lg; i >= 0; i--) {
		if (k & (1 << i)) {
			mn = min(mn, dp[x][i]);
			mn2 = min(mn2, dp2[x][i]);
			x = par[x][i];
		}
	}
	return {x, min(mn, dp[x][0]), min(mn2, dp2[x][0])};
}

int lca(int x, int y) {
	if (dub[x] < dub[y]) swap(x, y);
	x = Lift(x, dub[x]-dub[y]).x;
	if (x == y) return x;
	for (int i = lg; i >= 0; i--) {
		int z = par[x][i], w = par[y][i];
		if (z != w) x = z, y = w;
	}
	return par[x][0];
}

void task() {
	cin >> n >> T;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
	
	for (int i = 1; i < n; i++) {
		ll x, y, d; cin >> x >> y >> d;
		adj[x].pb({y, d});
		adj[y].pb({x, d});
	}
	
	cin >> s >> q; s = " " + s;
	
	vector <ll> X(q+1), Y(q+1), res(q+1, I);
	for (int i = 1; i <= q; i++) {
		cin >> X[i] >> Y[i];
	}
	
	for (cur = 0; cur <= 20; cur++) {
		Init();
		for (int ii = 1; ii <= q; ii++) {
			int x=X[ii], y=Y[ii]; int z = lca(x, y);
			int dx = dub[x] - dub[z], dy = dub[y] - dub[z];
			if (!cur) res[ii] = zbr[x] + zbr[y] - 2*zbr[z];
			else {
				res[ii] = min(res[ii], T*cur + zbr[x] + Lift(x, dx).mn + zbr2[y] - 2*zbr2[z]);
				res[ii] = min(res[ii], T*cur + zbr[x] - 2*zbr[z] + zbr2[y] + Lift(y, dy).mn2);
			}
		}
	}
	for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}

int main () {
	FIO;
	dub[0] = -1;
	for (int i = 0; i <= lg; i++) {
		dp[0][i] = dp2[0][i] = I;
	}
	int tt; cin >> tt;
	while (tt--) task();

	return 0;
}