#include <cstdio>

#define N_MAX 100000

inline int I()

{

	register int x = 0, c;

	do c = getchar(); while (c < '0' || c > '9');

	do x = x * 10 - '0' + c, c = getchar(); while (c >= '0' && c <= '9');

	return x;

}

typedef long long ill;

typedef long double dec;

struct edge

{

	int i, v; edge * e;

} GE[N_MAX * 2], * CE = GE, * GA[N_MAX + 1];

inline void edge_new(int i, int u, int v)

{

	*CE = (edge) {i, v, GA[u]}, GA[u] = CE++;

	*CE = (edge) {i, u, GA[v]}, GA[v] = CE++;

}

int n, siz[N_MAX + 1];

ill cnt[N_MAX];

void dfs(int u, int a = 0)

{

	siz[u] = 1;

	register int v;

	for (register edge * e = GA[u]; e; e = e->e)

		if ((v = e->v) != a)

			dfs(v, u), siz[u] += siz[v], cnt[e->i] = (ill(siz[v]) * (n - siz[v]) * 6);

}

int q, i, u, v, w[N_MAX], x;

ill m, s;

int main()

{

	n = I(), m = ill(n) * (n - 1);

	for (i = 1; i < n; ++i)

		u = I(), v = I(), w[i] = I(), edge_new(i, u, v);

	dfs(1);

	for (i = 1; i < n; ++i)

		s += w[i] * cnt[i];

	q = I();

	while (q--)

	{

		i = I(), x = I();

		s += (x - w[i]) * cnt[i], w[i] = x;

		printf("%.13f\n", double(dec(s) / dec(m)));

	}

	return 0;

}