#include<bits/stdc++.h>
using namespace std;
#define Re register int
typedef long long ll;

int t, n;
ll minn, sum, k, a[300005], b[300005];

inline ll read()
{
	ll ans = 0;
	char c = getchar();
	while (c < 48 || c > 57) c = getchar();
	while (c >= 48 && c <= 57) ans = (ans << 3) + (ans << 1) + (c ^ 48), c = getchar();
	return ans;
}

inline void write(ll x)
{
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	t = read();
	while (t--)
	{
		n = read(), sum = 0;
		for (Re i = 0; i < n; ++i)
		{
			a[i] = read(), b[i] = read();
			if (i && a[i] > b[i - 1]) sum += a[i] - b[i - 1];
		}
		if (a[0] > b[n - 1]) sum += a[0] - b[n - 1], minn = b[n - 1];
		else minn = a[0];
		for (Re i = 1; i < n; ++i)
		{
			if (a[i] > b[i - 1]) k = b[i - 1];
			else k = a[i];
			if (k < minn) minn = k;
		}
		write(minn + sum), putchar('\n');
	}
	return 0;
}