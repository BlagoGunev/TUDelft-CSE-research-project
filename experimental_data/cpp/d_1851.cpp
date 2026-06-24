#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>
#include <stack>
#include <bitset>
typedef long long ll;
using namespace std;
const int N = 1e6 + 100;
ll n, m;
ll a[N], flag[N];

void solve()
{
	cin >> n;
	map<ll, ll> mp;
	vector<ll> ve;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		flag[i] = 0;
		sum += i;
	}
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> a[i];
		if (a[i] - a[i - 1] <= n && !flag[a[i] - a[i - 1]])
		{
			flag[a[i] - a[i - 1]] = 1;
		}
		else
		{
			ve.push_back(a[i] - a[i - 1]);
		}
		mp[a[i] - a[i - 1]]++;
	}
	if (a[n - 1] > sum)
	{
		cout << "NO\n";
		return;
	}
	if (a[n - 1] < sum)
	{
		ll t = sum - a[n - 1];
		if (t <= n && !flag[mp[t]])
		{
			flag[t] = 1;
		}
		else
		{
			ve.push_back(t);
		}
		mp[t]++;
		int ff = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!flag[i])
				ff = 0;
		}
		cout << (ff == 0 ? "NO\n" : "YES\n");
	}
	else
	{
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!flag[i])
				sum += i;
		}
		if (sum == ve[0])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}