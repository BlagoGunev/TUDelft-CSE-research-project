// Prashant Mittal

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
#define PPB pop_back
#define LB lower_bound
#define UB upper_bound
#define fir first
#define sec second
#define fab(i, a, b) for (ll i = a; i < b; i++)
#define fba(i, b, a) for (ll i = b - 1; i >= a; i--)
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define take(a) fab(i, 0, a.size()) cin >> a[i];
#define takep(a) fab(i, 0, a.size()) cin >> a[i].first >> a[i].second;
#define print(a) fab(i, 0, a.size()) cout << a[i] << " ";
#define printp(a) fab(i, 0, a.size()) cout << a[i].first + 1 << " " << a[i].second + 1 << endl;
#define inf 1000001
#define mod 998244353
// cout << fixed << setprecision(7) << ans << endl;

ll power(ll a, ll b)
{
	if (b == 0)
	{
		return 1;
	}
	ll res = power(a, b / 2);
	res *= res;
	res %= mod;
	if (b % 2)
	{
		res *= a;
		res %= mod;
	}
	return res;
}

void pre()
{
}

void solve(ll tt)
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	map<int, int> a;
	fab(i, 0, k)
	{
		int x;
		cin >> x;
		a[x - 1] = 1;
	}
	vector<vll> v(n);
	fab(i, 1, n)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (k == 1)
	{
		cout << 0 << endl;
		return;
	}
	queue<pair<int, int>> q;
	int dis = 0;
	auto it = a.begin();
	int ind = it->first;
	vi vis(n, 0);
	q.push({ind, 0});
	vis[ind] = 1;
	while (q.size())
	{
		auto i = q.front();
		q.pop();
		if (i.second > dis && a[i.first])
		{
			dis = i.second;
			ind = i.first;
		}
		for (auto j : v[i.first])
		{
			if (!vis[j])
			{
				q.push({j, i.second + 1});
				vis[j] = 1;
			}
		}
	}
	fab(i, 0, n)
	{
		vis[i] = 0;
	}
	int max_dis = 0;
	q.push({ind, 0});
	vis[ind] = 0;
	while (q.size())
	{
		auto i = q.front();
		q.pop();
		if (i.second > max_dis && a[i.first])
		{
			max_dis = i.second;
		}
		for (auto j : v[i.first])
		{
			if (!vis[j])
			{
				q.push({j, i.second + 1});
				vis[j] = 1;
			}
		}
	}
	cout << (max_dis + 1) / 2 << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t = 1;
	cin >> t;
	pre();
	int x = 1;
	while (t--)
	{
		// cout << "Case #" << x << ": ";
		// x++;
		solve(x - 1);
	}
	return 0;
}