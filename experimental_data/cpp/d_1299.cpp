/*



_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/

 _/    _/      _/      _/     _/    _/     _/           _/

  _/  _/      _/               _/  _/      _/           _/

   _/_/       _/                 _/        _/           _/_/_/_/

  _/  _/      _/                 _/        _/           _/

 _/    _/      _/      _/        _/        _/           _/

_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/



*/

#include <bits/stdc++.h>

#define ll long long

#define lc(x) ((x) << 1)

#define rc(x) ((x) << 1 | 1)

#define ru(i, l, r) for (int i = (l); i <= (r); i++)

#define rd(i, r, l) for (int i = (r); i >= (l); i--)

#define mid ((l + r) >> 1)

#define pii pair<int, int>

#define mp make_pair

#define fi first

#define se second

#define sz(s) (int)s.size()

#define maxn 100005

using namespace std;

const int mo = 1e9 + 7;

inline int read() {

	int x = 0, w = 0; char ch = getchar();

	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}

	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}

	return w ? -x : x;

}

int n, m, vis[maxn];

vector<pii> G[maxn];

int dep[maxn], tp, fl;

int haha[7];

int f[5005][5005];

void clear() {

	ru(i, 0, 4) haha[i] = 0;

}

void ins(int x) {

//	printf("!!! %d %d\n", x, fl);

	rd(i, 4, 0) if((x >> i) & 1) {

		if(!haha[i]) {

			haha[i] = x;

			ru(i, 0, 4) if(haha[i]) {

				rd(j, i - 1, 0) if(haha[j] && ((haha[i] >> j) & 1)) {

					haha[i] ^= haha[j];

				}

			}

			return;

		}

		x ^= haha[i];

	}

	fl = 1;

}

inline int calc() {

	int tmp[5] = {haha[0], max(0, haha[1] - 1), max(0, haha[2] - 3), max(0, haha[3] - 7), max(0, haha[4] - 15)};

	return tmp[0] * 3 * 5 * 9 * 17 + tmp[1] * 5 * 9 * 17 + tmp[2] * 9 * 17 + tmp[3] * 17 + tmp[4] + 1;

}

int D[maxn];

void dfs(int x, int fa) {

	vis[x] = 1;

	for (auto t: G[x]) if(t.fi != fa) {

		int V = t.fi, w = t.se;

		if(V == 1) tp = dep[V] ^ dep[x] ^ w;

		else if(vis[V]) {

			if(D[V] < D[x]) ins(dep[V] ^ dep[x] ^ w);

		}

		else dep[V] = dep[x] ^ w, D[V] = D[x] + 1, dfs(V, x);

	}

}

int b[10];

int arr[5005][10], tot, id[5005];

void work() {

	ru(i, 0, 4) ru(j, i + 1, 4) if(b[i] && b[j] && ((b[j] >> i) & 1)) {

		return;

	}

	ru(i, 0, 4) haha[i] = b[i];

	tot++;

	id[calc()] = tot;

	ru(i, 0, 4) arr[tot][i] = b[i];

}

void dfs(int step) {

	if(step > 4) {

		work();

		return;

	}

	b[step] = 0;

	dfs(step + 1);

	ru(i, (1 << step), (1 << (step + 1)) - 1) {

		b[step] = i;

		dfs(step + 1);

	}

}

int dp[4600], nxt[4600];

inline void upd(int &x, int y) {

	x += y; if(x >= mo) x -= mo;

}

int main() {

	dfs(0);

//	printf("%d\n", tot);

	n = read(), m = read();

	ru(i, 1, m) {

		int x = read(), y = read(), z = read();

		G[x].push_back(mp(y, z));

		G[y].push_back(mp(x, z));

	}

	ru(i, 0, tot) ru(j, 0, tot) {

		ru(k, 0, 4) haha[k] = arr[i][k];

		fl = 0;

		ru(k, 0, 4) if(arr[j][k]) ins(arr[j][k]);

		if(fl) f[i][j] = -1;

		else f[i][j] = id[calc()];

	}

	dp[1] = 1;

	vis[1] = 1;

//	printf("cnm %d\n", f[1][2295]);

	for (auto t: G[1]) if(!vis[t.fi]) {

		clear();

		tp = -1, fl = 0;

		dep[t.fi] = t.se, dfs(t.fi, 1);

//		printf("%d %d\n", fl, tp);

		if(fl) continue;

		int tmp = id[calc()];

		memcpy(nxt, dp, sizeof(nxt));

		if(tp > -1) {

			ins(tp);

				ru(i, 1, tot) if(dp[i] && f[i][tmp] > -1) {

					upd(nxt[f[i][tmp]], 2ll * dp[i] % mo);

				}

//				printf("???%d ", tmp);

			if(!fl) {

				tmp = id[calc()];

				ru(i, 1, tot) if(dp[i] && f[i][tmp] > -1) {

					upd(nxt[f[i][tmp]], dp[i]);

			}

//			printf("%d\n", tmp);

			}

		}

		else {

				ru(i, 1, tot) if(dp[i] && f[i][tmp] > -1) {

					upd(nxt[f[i][tmp]], dp[i] % mo);

				}

		}

		memcpy(dp, nxt, sizeof(dp));

//		ru(i, 0, 4599) if(dp[i]) {

//			printf("%d %d\n", i, dp[i]);

//		}

	}

	int ans = 0; ru(i, 1, tot) ans = (ans + dp[i]) % mo;

	printf("%d\n", ans);

	return 0;

}