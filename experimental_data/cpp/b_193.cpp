#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n, u, r, p[50], a[50][50], b[50], k[50];
long long ans;

void calc(int x)
{
	long long ret = 0;
	for (int i = 1; i <= n; i++)
		ret += a[x][i] * k[i];
	if (ret > ans) ans = ret;
/*	cout << x << endl;
	for (int i = 0; i <= x; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;*/
}

void dfs(int x)
{
	for (int i = 1; i <= n; i++)
		a[x][i] = (a[x - 1][i] ^ b[i]);
	if ((u - x) % 2 == 0) calc(x);
	for (int j = 1; j <= n; j++)
		a[x + 1][j] = a[x][p[j]] + r;
	if ((u - x - 1) % 2 == 0) calc(x + 1);
	for (int i = x + 1; i < u; i++)
	{
		dfs(i + 1);
		for (int j = 1; j <= n; j++)
			a[i + 1][j] = a[i][p[j]] + r;
		if ((u - i - 1) % 2 == 0) calc(i + 1);
	}
}

int main()
{
	scanf("%d%d%d", &n, &u, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[0][i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &k[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	ans = 0;
	if (u % 2 == 0)
		for (int i = 1; i <= n; i++)
			ans += a[0][i] * k[i];
	else
		for (int i = 1; i <= n; i++)
			ans += (a[0][i] ^ b[i]) * k[i];
	for (int i = 1; i <= u; i++)
	{
//		cout << "\t" << i << endl;
		dfs(i);
		for (int j = 1; j <= n; j++)
			a[i][j] = a[i - 1][p[j]] + r;
		if ((u - i) % 2 == 0) calc(i);
	}
	cout << ans << endl;
	return 0;
}