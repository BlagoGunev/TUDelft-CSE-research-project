#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const int N = 3e5 + 10;
int p[N], n, s[N];

void insert(int x, int k)
{
	while (x <= n)
	{
		s[x] = max(s[x], k);
		x += lowbit(x);
	}
}

int query(int x)
{
	int res = 0;
	while (x)
	{
		res = max(res, s[x]);
		x -= lowbit(x);
	}
	return res;
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		s[i] = 0;
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int ans = query(p[i]);
		if (ans == 0)res++, ans = 1;
		else if (ans == 1)ans = 2;
		else ans = 1, res++;
		//cout << ans << endl;
		insert(p[i], ans);
	}
	cout << n-res << '\n';
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}