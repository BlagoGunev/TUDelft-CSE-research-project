#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 5e5 + 5, MAXM = 1e6 + 5;

struct BIT {
	LL c[MAXM];
	int lowbit(int x) {return x & -x;}
	void add(int i, int x) {
		for (; i <= 1e6; i += lowbit(i)) c[i] += x;
	}
	LL query(int i) {
		LL res = 0;
		for (; i; i -= lowbit(i)) res += c[i];
		return res;
	}
	void add(int l, int r, int x) {
		add(l, x), add(r + 1, -x);
	}
}bit;
string s, t;
vector<int> vec[MAXM];
int fa[20][MAXM], lent;
struct ACATM {
	int tr[MAXM][26], num[MAXM], fail[MAXM], tott, dfn[MAXM], id[MAXM], pos[MAXM * 5], len[MAXM];
	void insert() {
		int p = 0, lens = s.size();
		for (int i = 0; i < lens; i++) {
			if (!tr[p][s[i] - 'a']) tr[p][s[i] - 'a'] = ++tott, len[tr[p][s[i] - 'a']] = len[p] + 1;
			p = tr[p][s[i] - 'a'];
			id[i] = p;
			// cout << p << ' ';
		}
		// cout << '\n';
		++num[p];
	}
	vector<int> e[MAXM];
	int sz[MAXM];
	void build() {
		queue<int> q;
		for (int i = 0; i < 26; i++) if (tr[0][i]) q.push(tr[0][i]);
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			e[fail[p]].push_back(p), num[p] += num[fail[p]];
			for (int i = 0; i < 26; i++) {
				if (!tr[p][i]) tr[p][i] = tr[fail[p]][i];
				else fail[tr[p][i]] = tr[fail[p]][i], q.push(tr[p][i]);
			}
		}
	}
	int tim;
	void dfs(int u) {
		dfn[u] = ++tim, sz[u] = 1;
		for (auto v : e[u]) dfs(v), sz[u] += sz[v];
	}
	void walk() {
		int p = 0;
		for (int i = 1; i <= lent; i++)
			p = tr[p][t[i] - 'a'], pos[i] = p;
	}
}ac1, ac2;

LL cnt[MAXM * 5], ans[MAXN];
vector<pair<int, int> > qu[MAXM];

void dfs(int u) {
	for (auto x : vec[u]) bit.add(ac1.dfn[x], ac1.dfn[x] + ac1.sz[x] - 1, 1);
	for (auto [id, x] : qu[u]) ans[id] -= bit.query(ac1.dfn[x]);
	for (auto v : ac2.e[u]) dfs(v);
	for (auto x : vec[u]) bit.add(ac1.dfn[x], ac1.dfn[x] + ac1.sz[x] - 1, -1);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		// cout << "i: " << i << '\n';
		cin >> s, ac1.insert();
		reverse(s.begin(), s.end()), ac2.insert();
		int len = s.size();
		for (int j = 0; j < len - 1; j++) vec[ac2.id[j]].push_back(ac1.id[len - 2 - j]);
	}
	ac1.build(), ac2.build(), ac1.dfs(0), ac2.dfs(0);
	for (int i = 1; i <= ac2.tott; i++) fa[0][i] = ac2.fail[i];
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= ac2.tott; j++) fa[i][j] = fa[i - 1][fa[i - 1][j]];
	lent = t.size(); t = ' ' + t;
	int p = 0;
	for (int i = 1; i <= lent; i++) 
		p = ac1.tr[p][t[i] - 'a'], ac1.pos[i] = p, cnt[i] = cnt[i - 1] + ac1.num[p];
	p = 0;
	for (int i = lent; i >= 1; i--) p = ac2.tr[p][t[i] - 'a'], ac2.pos[i] = p;
	for (int i = 1; i <= m; i++) {
		int l, r; cin >> l >> r;
		int p1 = ac1.pos[l - 1], p2 = ac2.pos[l];
		// cout << p2 << ' ';
		for (int j = 19; j >= 0; j--)
			if (ac2.len[fa[j][p2]] > r - l + 1) p2 = fa[j][p2];
		if (ac2.len[p2] > r - l + 1) p2 = ac2.fail[p2];
		// cout << p2 << '\n';
		ans[i] = cnt[r] - cnt[l - 1], qu[p2].push_back({i, p1});
	}
	dfs(0);
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	cout << '\n';
	cerr << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}