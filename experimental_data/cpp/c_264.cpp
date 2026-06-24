#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 100010;
const long long inf = 100000000000LL;

int datc[maxn], datv[maxn];
int a, b, n, q;

void update(long long& max1, long long& max2, long long x)
{
	if (x > max1) max2 = max1, max1 = x;
	else if (x > max2) max2 = x;
}

long long getother(long long max1, long long max2, long long x)
{
	if (x == max1) return max2;
	else return max1;
}

long long getmaxval()
{
	static long long fmax[maxn];
	long long max1 = -inf, max2 = -inf;
	for (int i = 1; i <= n; i++) fmax[i] = -inf;
	
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		long long now = fmax[datc[i]] + (long long)a * datv[i];
		now = max(now, getother(max1, max2, fmax[datc[i]]) + (long long)b * datv[i]);
		now = max(now, (long long)b * datv[i]);
		
		if (fmax[datc[i]] < now)
		{
			if (fmax[datc[i]] == max1) max1 = now;
			else update(max1, max2, now);
			fmax[datc[i]] = now;
		}
		
		ans = max(ans, now);
	}
	
	return ans;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) scanf("%d", &datv[i]);
	for (int i = 0; i < n; i++) scanf("%d", &datc[i]);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%lld\n", getmaxval());
	}
	return 0;
}