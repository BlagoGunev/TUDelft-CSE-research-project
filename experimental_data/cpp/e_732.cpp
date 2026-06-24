#include <cstdio>

#include <algorithm>

#include <map>

#include <vector>

#include <queue>

#define N_MAX 200000

#define M_MAX 200000

int n, m, i, j, k, a[M_MAX + 1], b[N_MAX + 1], c, u;

struct dat

{

	int k, v; bool t;

	inline bool operator < (const dat & x) const

	{

		return v < x.v;

	}

} p[N_MAX + 1], s[M_MAX + 1];

int main()

{

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; ++i)

		scanf("%d", &p[i].v), p[i].k = i;

	for (j = 1; j <= m; ++j)

		scanf("%d", &s[j].v), s[j].k = j;

	std::sort(p + 1, p + n + 1);

	std::sort(s + 1, s + m + 1);

	do

	{

		for (i = n, j = m; i && j; --i)

			if (!p[i].t)

			{

				while (j && (s[j].t || s[j].v > p[i].v)) --j;

				if (j && s[j].v == p[i].v)

					++c, u += a[b[p[i].k] = s[j].k] = k, p[i].t = s[j--].t = true;

			}

		for (j = m; j; --j)

			s[j].v = (s[j].v + 1) >> 1;

		++k;

	}

	while (k < 31);

	printf("%d %d\n", c, u);

	for (j = 1; j <= m; ++j)

		printf("%d%c", a[j], j < m ? ' ' : '\n');

	for (i = 1; i <= n; ++i)

		printf("%d%c", b[i], i < n ? ' ' : '\n');

	return 0;

}