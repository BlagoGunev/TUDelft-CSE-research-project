#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define mp make_pair

#define inf 1e9

#define pii pair <int, int>

const int mod = 1e9 + 7;

inline int read () {

	int x = 0, f = 1;

	char ch = getchar ();

	while (ch < '0' || ch > '9') f = ((ch == '-') ? -1 : f), ch = getchar ();

	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar ();

	return x * f;

}

inline void write (ll x) {

	if (x < 0) x = -x, putchar ('-');

	if (x >= 10) write (x / 10);

	putchar (x % 10 + '0');

}

vector <pii> V[1000005];

struct SAM {

	int ch[2000005][26], fa[2000005], len[2000005], s[2000005];

	int Lst = 1, tot = 1;

	int insert (int lst, int c) {

		int p = lst, np = lst = ++tot;

		s[np] = 1;

		len[np] = len[p] + 1;

		while (p && ch[p][c] == 0) ch[p][c] = np, p = fa[p]; 

		if (p == 0) fa[np] = 1;

		else {

			int x = ch[p][c];

			if (len[x] == len[p] + 1) fa[np] = x;

			else {

				int ano = ++tot;

				memcpy (ch[ano], ch[x], sizeof (ch[x]));

				len[ano] = len[p] + 1;

				fa[ano] = fa[x];

				fa[x] = fa[np] = ano;

				while (p && ch[p][c] == x) ch[p][c] = ano, p = fa[p];

			}

		}

		return Lst = lst;

	}

	vector <int> G[2000005];

	int dfs(int x) {

		int ans = 0;

		for(auto y : G[x]) ans += dfs(y), s[x] += s[y];

		if(x != 1) {

			V[len[fa[x]]].push_back(mp(s[x], -1));

			V[len[x]].push_back(mp(s[x], 1));

//			for(int i = len[fa[x]] + 1; i <= len[x]; i++) if(s[x] % i == 0) ans += s[x];

		}

		return ans;

	}

	void solve() {

		for(int i = 2; i <= tot; i++) G[fa[i]].push_back(i);

		dfs(1);

	}

}S;

int n;

char ch[1000005];

int f[1000005];

signed main () {

//	freopen (".in", "r", stdin);

//	freopen (".out", "w", stdout);

	n = read();

	scanf("%s", ch + 1);

	for(int i = 1; i <= n; i++) S.insert(S.Lst, ch[i] - 'a');

	S.solve();

	ll Ans = 0;

	for(int i = 1; i <= 1000000; i++) {

		for(int j = i; j <= 1000000; j += i) f[j]++;

		for(auto j : V[i]) Ans += 1ll * j.second * f[j.first] * j.first;

	}

	write(Ans), putchar('\n');

	return 0;

}

/*

*/