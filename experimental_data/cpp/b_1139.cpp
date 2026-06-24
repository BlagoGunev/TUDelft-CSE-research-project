#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	typedef pair<int, int> pii;
	const int N = 2e5 + 10;

	inline int read()
	{
		int x = 0, f = 0, ch = getchar();
		while (!isdigit(ch))
			f |= (ch == '-'), ch = getchar();
		while (isdigit(ch))
			x = x * 10 + ch - '0', ch = getchar();
		return f ? -x : x;
	}

	int n, a[N];

	void work()
	{
		n = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		ll ans = 0, last = LLONG_MAX;
		for (int i = n; i; i--)
		{
			ll t = max(min((ll)a[i], last - 1), 0LL);
			last = t;
			ans += t;
		}
		printf("%lld\n", ans);
	}
}

int main()
{
	TYC::work();
	return 0;
}