#include <cstdio>
#define N 1010

int n;
int lnk[N];
int u, v;
int ans;

int main()
{
	scanf("%d", &n);
	ans = n;
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &u, &v);
		if (lnk[u] == 1) ans--;
		if (lnk[v] == 1) ans--;
		lnk[u]++; lnk[v]++;
	}
	printf("%d", ans);
}