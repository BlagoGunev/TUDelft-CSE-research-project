#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, r, ans = 1000000000, a, b, c, d;
int x[1000099], t;
int y[1000099], tt;

int main()
{
	scanf("%d%d", &n, &r);
	if (n == 1 && r == 1)
	{
		puts("0\nT");
		return 0;
	}
	for (int i = 1; i < r; ++i)
	{
		a = r, b = i, t = 0, c = 0;
		while (b != 0)
		{
			x[++t] = a / b;
			c += x[t];
			a = a % b;
			swap(a, b);
		}
		if (a == 1 && c == n)
		{
			d = 0;
			for (int j = 1; j <= t; ++j)
				if ((j == 1 || j == t) && x[j] > 1)
					d += x[j] - 2;
				else
					d += x[j] - 1;
			if (d < ans)
			{
				ans = d; tt = t;
				for (int j = 1; j <= t; ++j)
					y[j] = x[j];
			}
		}
	}
	if (ans != 1000000000)
	{
		printf("%d\n", ans);
		a = 0;
		for (int i = 1; i <= tt; ++i, a = 1 - a)
		{
			if (i == 1 && y[i] > 1)
			{
				putchar('T');
				a = 1 - a;
				for (int j = 1; j < y[i]; ++j)
					putchar('B');
				continue;
			}
			if (i == tt && y[i] > 1)
			{
				for (int j = 1; j < y[i]; ++j)
					putchar(a ? 'B' : 'T');
				a = 1 - a;
				putchar(a ? 'B' : 'T');
				continue;
			}
			for (int j = 1; j <= y[i]; ++j)
				putchar(a ? 'B' : 'T');
		}
		putchar('\n');
	}
	else
		puts("IMPOSSIBLE");
	return 0;
}