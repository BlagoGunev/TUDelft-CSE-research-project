#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int mod = 998244353;
void solve()
{
	int k; cin >> k;
	vector<int>a(1 << k);
	vector<ll>f((1 << k) + 1);
	f[0] = 1;
	for (int i = 1; i <= (1 << k); i++)f[i] = i * f[i - 1] % mod;
	for (int i = 0; i < (1 << k); i++)cin >> a[i];
	ll res = 1;
	// 1<<(k)+ 1 
	while (k--)
	{
		int n = a.size(), cnt = 0;
		vector<int>t;
		ll p = 1;
		for (int i = 0; i < n; i += 2)//i i+1
		{
			if (a[i + 1] < a[i])swap(a[i], a[i + 1]);
			if (a[i] != -1)
			{
				if (a[i] > (1 << k) || (a[i + 1]) <= (1 << k))
				{
					cout << 0;
					return;
				}
				else
				{
					t.push_back(a[i]);
				}
			}
			else
			{
				if (a[i + 1] > (1 << k))
				{
					t.push_back(-1);
				}
				else
				{
					t.push_back(a[i + 1]);
					cnt++;
					if (a[i + 1] == -1)p = p * 2 % mod;
				}
			}
		}
		res = res * f[cnt]%mod * p % mod;
		//cout << cnt << ' ' << p << endl;
		a = t;
	}
	cout << res << '\n';
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}