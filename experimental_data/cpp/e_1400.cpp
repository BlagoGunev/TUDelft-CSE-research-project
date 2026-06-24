#include<bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;

#define ha putchar(' ')
#define he putchar('\n')

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
		x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

inline void write(int x)
{
	if(x < 0)
	{
		putchar('-');
		x = -x;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + 48);
}

const int _ = 1e4 + 10;

int n, h[_];

int solve(int l, int r, int H)
{
	if(l == r) return h[l] ? 1 : 0;
	int mn = LLONG_MAX, res = 0;
	for(int i = l; i <= r; ++i) mn = min(mn, h[i]);
	res += mn - H;
	int p;
	for(int i = l; i <= r; i = p + 1)
	{
		p = i;
		if(h[i] == mn) continue;
		for(int j = i + 1; j <= r; ++j)
		{
			if(h[j] == mn) break;
			p = j;
		}
		res += solve(i, p, mn);
	}
	return min(res, r - l + 1);
}

signed main()
{
	n = read();
	for(int i = 1; i <= n; ++i) h[i] = read();
	write(solve(1, n, 0)), he;
	return 0;
}