#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 100100
#define MAXP 10010

int n, np, last[MAXN], ss[18], c[18], cnt, num, x, y, ans;
int64_t p[MAXP];
bool b[MAXN];

void rec(int cur, int x)
{
	if (cur == cnt)
	{
		if (last[x] < num - y)
			ans++;
		last[x] = num;
		return;
	}
	for (int i = 0; i <= ss[cur]; i++)
	{
		rec(cur + 1, x);
		x *= c[cur];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int64_t i = 2; i < MAXN; i++)
		if (!b[i])
			for (int64_t j = i * i; j < MAXN; j += i)
				b[j] = true;
	for (int i = 2; i < MAXN; i++)
		if (!b[i])
			p[np++] = i;

	cin >> n;
	for (num = 1; num <= n; num++)
	{
		scanf("%d%d", &x, &y);
		cnt = 0;
		for (int j = 0; j < 18; j++)
			ss[j] = 0;
		for (int j = 0; p[j] * p[j] <= x; j++)
			if (x % p[j] == 0)
			{
				while (x % p[j] == 0)
				{
					x /= p[j];
					ss[cnt]++;
					//if (last[p[j]][s] < i - y)
					//	ss[cnt]++;
					//last[p[j]][s] = i;
				}
				c[cnt++] = p[j];
			}
		if (x != 1)// && last[x][1] < i - y)
		{
			c[cnt] = x;
			ss[cnt++] = 1;
		}
		//last[x][1] = i;
		ans = 0;
		rec(0, 1);
		//for (int j = 0; j < cnt; j++)
		//	ans *= ss[j] + 1;
		//if (i != 1)
		//	ans--;
		printf("%d\n", ans);
	}
	return 0;
}