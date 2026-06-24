#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;
const int N = 200004;
int n, t, k, a[N], T[N], x[N];
int main()
{
	scanf("%d%d%d", &n, &t, &k);
	a[0] = 1;
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &a[i]);
	}
	if (k < a[t]) return 0 * printf("-1\n");
	k -= a[t];
	int sumek = 0;
	for (int i = 1; i <= t - 1; i++)
	{
		x[i] = max(0, a[i] - a[i + 1]);
		sumek += x[i];
	}
	if (sumek > k) return 0 * printf("-1\n");
	if (sumek < k)
	{
		for (int i = 1; i <= t - 1; i++)
		{
			if (sumek == k) break;
			while (x[i] + 1 <= a[i] - 1 && sumek < k)
			{
				x[i]++;
				sumek++;
			}
		}
	}
	if (sumek != k) return 0 * printf("-1\n");
	int wsk = 2;
	for (int i = 1; i <= t; i++)
	{
		int bomeg = wsk - a[i - 1];
		int j = wsk;
		while (j <= wsk + a[i - 1] - x[i - 1] - 1)
		{
			T[j] = j - a[i - 1];
			j++;
		}
		while (j <= wsk + a[i] - 1)
		{
			T[j] = bomeg;
			j++;
		}
		wsk += a[i];
	}
	printf("%d\n", n);
	for (int i = 2; i <= n; i++)
	{
		printf("%d %d\n", i, T[i]);
	}

	getchar();
	getchar();
	return 0;
}