#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	typedef pair<int, int> pii;
	const int N = 1e5 + 10;
	const int p = 1e9 + 7;

	int size[N], fa[N], vis[N];

	inline int read()
	{
		int x = 0, f = 0, ch = getchar();
		while (!isdigit(ch))
			f |= (ch == '-'), ch = getchar();
		while (isdigit(ch))
			x = x * 10 + ch - '0', ch = getchar();
		return f ? -x : x;
	}

	int find(const int a)
	{
		return a == fa[a] ? a : fa[a] = find(fa[a]);
	}

	inline ll qpow(ll x, ll tim)
	{
		ll ans = 1;
		for (; tim; tim >>= 1, x = x * x % p)
			if (tim & 1)
				ans = ans * x % p;
		return ans;
	}

	void work()
	{
		int n = read(), k = read();
		for (int i = 1; i <= n; i++)
			fa[i] = i, size[i] = 1;
		for (int i = 1; i < n; i++)
		{
			int u = read(), v = read(), type = read();
			if (!type)
			{
				int fu = find(u), fv = find(v);
				if (fu != fv)
				{
					fa[fu] = fv;
					size[fv] += size[fu];
				}
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int f = find(i);
			if (!vis[f])
			{
				vis[f] = 1;
				ans = (ans + qpow(size[f], k)) % p;
			}
		}
		printf("%lld\n", (qpow(n, k) - ans + p) % p);
	}
}

int main()
{
	TYC::work();
	return 0;
}