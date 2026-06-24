#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int n, a, b, c, root, q, x, y, t, s[2];
int len, Next[210000], till[210000], f[210000], go[210000], tx[210000], belong[210000], fa[210000], sum[210000];
long long ma, h[210000][2], d[210000], l;
bool used[210000];

void add(int a, int b, int c) {
	Next[++len] = till[a];
	till[a] = len;
	go[len] = b;
	f[len] = c;
}

bool cmp(int x, int y) {
	return d[x] < d[y];
}

void dfs(int k, int fa, long long s) {
	if (s > ma) {
		ma = s;
		t = k;
	}
	for (int i = till[k]; i; i = Next[i])
		if (go[i] != fa)
			dfs(go[i], k, s + f[i]);
}

void dfs1(int k, int fa, int t, long long s) {
	h[k][t] = s;
	for (int i = till[k]; i; i = Next[i])
		if (go[i] != fa)
			dfs1(go[i], k, t, s + f[i]);
}

int gf(int x) {
	if (fa[x] != x) fa[x] = gf(fa[x]);
	return fa[x];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	ma = 0;
	dfs(1, 0, 0);
	x = t;
	ma = 0;
	dfs(x, 0, 0);
	y = t;

	dfs1(x, 0, 0, 0);

	dfs1(y, 0, 1, 0);

	for (int i = 1; i <= n; i++)
		if (h[i][0] <= h[i][1]) belong[i] = 0, d[i] = h[i][1];
		else belong[i] = 1, d[i] = h[i][0];


	for (int i = 1; i <= n; i++)
		for (int j = till[i]; j; j = Next[j])
			if (belong[i] != belong[go[j]])
				x = i, y = go[j];
	for (int i = 1; i <= n; i++)
		tx[i] = i;
	sort(tx + 1, tx + n + 1, cmp);
	scanf("%d", &q);
	while (q--) {
		scanf("%I64d", &l);
		int r = n, ans = 0;
		for (int i = 1; i <= n; i++)
			fa[i] = i, sum[i] = 1, used[i] = false;
		for (int i = n; i; i--) {
			while (r && d[tx[r]] + l >= d[tx[i]]) {
				for (int j = till[tx[r]]; j; j = Next[j])
					if (belong[go[j]] == belong[tx[r]] && d[go[j]] > d[tx[r]]) {
						fa[go[j]] = tx[r];
						sum[tx[r]] += sum[go[j]];
					}
				ans = max(ans, sum[tx[r]]);
				used[tx[r]] = true;
				r--;
			}
			if (used[x] && used[y])
				ans = max(ans, i - r);
			sum[gf(tx[i])]--;
		}
		printf("%d\n", ans);
	}
}