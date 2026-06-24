#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Re register int

int t, n, s, lc;
ll l, r, k; 

inline ll read()
{
	ll ans = 0;
	char c = getchar();
	while (c < 48 || c > 57) c = getchar();
	while (c >= 48 && c <= 57) ans = (ans << 3) + (ans << 1) + (c ^ 48), c = getchar();
	return ans;
}

inline void write(int x)
{
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	t = read();
	while (t--)
	{
		n = read(), l = read(), r = read(), k = 0;
		for (Re i = 1; i < n; ++i)
		{
			s = (n - i) << 1;
			if (k + s < l)
			{
				k += s;
				continue;
			}
			if (k < l) lc = l - k - 1, k = l - 1;
			else lc = 0;
			for (Re j = lc; j < s - 1; ++j)
			{
				++k;
				if (k > r) break;
				if (!(j & 1)) write(i);
				else write((j >> 1) + i + 1);
				putchar(' ');
			}
			if (k > r) break;
			++k;
			if (k > r) break;
			write(n), putchar(' ');
		}
		if (k < r) putchar(49);
		putchar('\n');
	}
	return 0;
}