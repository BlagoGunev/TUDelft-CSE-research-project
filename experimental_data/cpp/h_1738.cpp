#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = array<int, 2>;
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
const int MAXN = 1000005;

struct bit {
	int tree[MAXN], sum, lastPtr;
	void add(int x, int v) {
		tree[x] += v;
		if (x >= lastPtr)
			sum += v;
	}
	int query(int x) {
		while (x > lastPtr) {
			sum -= tree[lastPtr++];
		}
		return sum;
	}
} bit;
char a[MAXN];
int nxt[MAXN][26];
int par[MAXN], len[MAXN], slink[MAXN], ptr[MAXN], diff[MAXN], series[MAXN], piv;

void mian(string fuck, vector<pi> qq) {
	int n = fuck.size();
	for (int i = 1; i <= n; i++)
		a[i] = fuck[i - 1] - 'a';
	int q = sz(qq);
	vector<vector<pi>> query(n + 1);
	vector<int> ret(q);
	for (int i = 0; i < q; i++) {
		int u = qq[i][0];
		int v = qq[i][1];
		query[v].push_back({u, i});
	}
	par[0] = 0;
	par[1] = 1;
	a[0] = -1;
	len[0] = -1;
	piv = 1;
	int cur = 1;
	vector<vector<pi>> stk(n + 5);
	auto insert = [&](int j, int i) {
		int head = series[j];
		while (sz(stk[head]) && stk[head].back()[0] <= len[j]) {
			stk[head].pop_back();
		}
		stk[head].push_back({len[j], i});
	};
	for (int i = 1; i <= n; i++) {
		while (a[i] != a[i - len[cur] - 1])
			cur = slink[cur];
		if (!nxt[cur][a[i]]) {
			nxt[cur][a[i]] = ++piv;
			par[piv] = cur;
			len[piv] = len[cur] + 2;
			int lnk = slink[cur];
			while (a[i] != a[i - len[lnk] - 1]) {
				lnk = slink[lnk];
			}
			if (nxt[lnk][a[i]])
				lnk = nxt[lnk][a[i]];
			if (len[piv] == 1 || lnk == 0)
				lnk = 1;
			slink[piv] = lnk;
			diff[piv] = len[piv] - len[lnk];

			if (diff[piv] == diff[lnk])
				series[piv] = series[lnk];
			else
				series[piv] = piv;

			insert(piv, i);
			bit.add(i - len[piv] + 1, +1);
		}
		cur = nxt[cur][a[i]];
		for (int j = cur; len[j] >= 1; j = slink[series[j]]) {
			int ptr = series[j];
			assert(sz(stk[ptr]));
			int s = 0, e = sz(stk[ptr]) - 1;
			while (s != e) {
				int m = (s + e + 1) / 2;
				if (stk[ptr][m][0] < len[j])
					e = m - 1;
				else
					s = m;
			}
			int lpos = stk[ptr][s][1];
			int leftmost = lpos - len[j] + 1;
			int rightmost = i - len[series[j]] + 1;
			bit.add(leftmost, -1);
			bit.add(rightmost, +1);
			leftmost = rightmost;
		}
		for (int j = cur; len[j] >= 1; j = slink[series[j]]) {
			insert(j, i);
		}
		for (auto &[pos, idx] : query[i]) {
			ret[idx] = bit.query(pos);
		}
		ptr[i] = cur;
	}
	for (auto &x : ret)
		cout << x << "\n";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	string vect;
	int ptr = 0;
	vector<pi> query;
	while (q--) {
		string s;
		cin >> s;
		if (s == "push") {
			string t;
			cin >> t;
			vect.push_back(t[0]);
		} else {
			ptr++;
		}
		query.push_back({ptr + 1, sz(vect)});
	}
	mian(vect, query);
}