#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
pair<int, int> a[300010];
int b[300010];
inline int Work(int p, int n, int x)
{
	if(x <= a[p].first || x > a[n].first)
		return 0;
	int L = p + 1, R = n;
	while(L < R)
	{
		int mid = (L + R) >> 1;
		if(x <= a[mid].first)
			R = mid;
		else
			L = mid + 1;
	}
	return n - L + 1;
}
signed main()
{
	int T;
	scanf("%lld", &T);
	while(T--)
	{
		int n, m;
		scanf("%lld %lld", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i].first), a[i].second = -i;
		for(int i = 1; i <= m; i++)
			scanf("%lld", &b[i]);
		sort(a + 1, a + n + 1);
		int p = -1;
		for(int i = 1; i <= n; i++)
			if(a[i].second == -1)
				p = i;
		if(p == n)
		{
			for(int i = 1; i <= m; i++)
				printf("%lld ", m / i);
			putchar('\n');
		}
		else
		{
			for(int i = 1; i <= m; i++)
				b[i] = Work(p, n, b[i]);
			sort(b + 1, b + m + 1);
			for(int i = 1; i <= m; i++)
			{
				int ans = m / i;
				for(int j = i; j <= m; j += i)
					ans += b[j];
				printf("%lld ", ans);
			}
			putchar('\n');
		}
	}
	return 0;
}