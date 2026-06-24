#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

int f[100000];

int n, m;

int adj[100000], subs[100000], d[100000], e[100000];

int ans;

int main()
{

	scanf("%d %d", &n, &m);
	f[0] = n + 1;
	int a, b, c;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &a, &b, &c);

		subs[i] = adj[a]; adj[a] = i; d[i] = c; e[i] = b;
	}

	int j, temp;
	for (int i = 1; i <= n; ++i)
	{
		j = adj[i];
		while (j > 0)
		{
			for (int k = n; k >= d[j]; --k)
			{
				temp = f[k - d[j]];
				if (temp < i) continue;
				if (temp > e[j]) temp = e[j];
				if (temp > f[k]) f[k] = temp;
			}
			j = subs[j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (f[i] > 0) ++ans;
	}

	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i)
	{
		if (f[i] > 0) printf("%d ", i);
	}

	return 0;
}