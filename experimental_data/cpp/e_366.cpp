#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 2300, K = 11, S = int(2e5), inf = ~0u >> 2;

int leftmost[K][N], rightmost[K][N], maxD[K][N][2], maxU[K][N][2], dis[K][K];
int n, m, kcnt, s, Q[S];

inline int solve (int i, int j, int nk)
{
	if (j < 1 || j > m)
		return 0;
	return max(max(i + j + maxD[nk][i][0], i - j + maxD[nk][i][1]),
			   max(-i + j + maxU[nk][i][0], -i - j + maxU[nk][i][1]));
}

int main ()
{
	scanf("%d%d%d%d", &n, &m, &kcnt, &s);
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= kcnt; ++j)
		{
			leftmost[j][i] = inf;
			rightmost[j][i] = -inf;
		}
		for (int j = 1, k; j <= m; ++j)
		{
			scanf("%d", &k);
			leftmost[k][i] = min(leftmost[k][i], j);
			rightmost[k][i] = max(rightmost[k][i], j);
		}
	}

	for (int k = 1; k <= kcnt; ++k)
	{
		maxD[k][0][0] = maxD[k][0][1] = -inf;
		for (int i = 1; i <= n; ++i)
		{
			maxD[k][i][0] = max(maxD[k][i - 1][0], -i - leftmost[k][i]);
			maxD[k][i][1] = max(maxD[k][i - 1][1], -i + rightmost[k][i]);
		}
		maxU[k][n + 1][0] = maxU[k][n + 1][1] = -inf;
		for (int i = n; i >= 1; --i)
		{
			maxU[k][i][0] = max(maxU[k][i + 1][0], i - leftmost[k][i]);
			maxU[k][i][1] = max(maxU[k][i + 1][1], i + rightmost[k][i]);
		}
	}
	
	for (int a = 1; a <= kcnt; ++a)
		for (int b = 1; b <= kcnt; ++b)
		{
			dis[a][b] = 0;
			for (int i = 1; i <= n; ++i)
			{
				int cur = max(solve(i, leftmost[a][i], b), solve(i, rightmost[a][i], b));
				dis[a][b] = max(dis[a][b], cur);
			}
		}

	int res = 0;
	for (int i = 1; i <= s; ++i)
	{
		scanf("%d", &Q[i]);
		if (i > 1)
			res = max(res, dis[Q[i - 1]][Q[i]]);
	}
	printf("%d\n", res);
	return 0;
}