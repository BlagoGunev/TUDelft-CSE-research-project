#include <bits/stdc++.h>
using namespace std;
int	f[500003], h[503], c[500003], F[5003], ans, Mx;
int main()
{
	int	N, k;
	scanf("%d%d", &N, &k);
	for(int i = 1, x; i <= N * k; i++)
	{
		scanf("%d", &x);
		c[x]++, Mx = max(Mx, x);
	}
	for(int i = 1, x; i <= N; i++)
	{
		scanf("%d", &x);
		f[x]++;
	}
	for(int i = 1; i <= k; i++)
		scanf("%d", &h[i]);
	for(int x = 1; x <= Mx; x++)
	{
		if(!c[x]||!f[x])
			continue;
		memset(F, 0, sizeof(F));
		for(int i = 1; i <= f[x]; i++)
			for(int j = c[x]; j >= 0; j--)
				for(int t = 0; t <= j && t <= k ; t++)
					F[j] = max(F[j], F[j - t] + h[t]);
		int	cnt = 0;
		for(int i = 0; i <= c[x]; i++)
			cnt = max(cnt, F[i]);
		ans += cnt;
	}
	printf("%d\n", ans);
	return 0;
}