#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;
int a[N];
int gcd(int x, int y) { return (x % y == 0) ? (y) : (gcd(y, x % y)); }
bool pre[N], suf[N];
inline void ___()
{
	int n;
	cin >> n;
	pre[0] = suf[n + 1] = true;
	pre[1] = pre[2] = true, suf[n] = suf[n - 1] = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i > 2)
		{
			pre[i] = false;
			if (pre[i - 1] && gcd(a[i - 2], a[i - 1]) <= gcd(a[i - 1], a[i])) pre[i] = true;
		}
	}
	for (int i = n - 2; i >= 1; i--)
	{
		suf[i] = false;
		if (suf[i + 1] && gcd(a[i], a[i + 1]) <= gcd(a[i + 1], a[i + 2])) suf[i] = true;
	}
	// for (int i = 1; i <= n; i++) cout << pre[i]; cout << endl;
	// for (int i = 1; i <= n; i++) cout << suf[i]; cout << endl;
	for (int i = 1; i <= n; i++)
	{
		if (pre[i - 1] && suf[i + 1])
		{
			if (i == 1)
			{
				cout << "YES\n";
				return ;
			}
			if (i == n)
			{
				cout << "YES\n";
				return ;
			}
			if (i == 2 && i <= n - 2)
			{
				if (gcd(a[i - 1], a[i + 1]) <= gcd(a[i + 1], a[i + 2]))
				{
					cout << "YES\n";
					return ;
				}
			}
			else if (i == 2)
			{
				cout << "YES\n";
				return ;
			}
			if (i == n - 1 && i >= 3)
			{
				if (gcd(a[i + 1], a[i - 1]) >= gcd(a[i - 1], a[i - 2]))
				{
					cout << "YES\n";
					return ;
				}
			}
			else if (i == n - 1)
			{
				cout << "YES\n";
				return ;
			}
			if (i > 2 && i < n - 1)
			{
				if (gcd(a[i - 1], a[i + 1]) <= gcd(a[i + 1], a[i + 2]) && gcd(a[i + 1], a[i - 1]) >= gcd(a[i - 1], a[i - 2]))
				{
					cout << "YES\n";
					return ;
				}
			}
		}
	}
	cout << "NO\n";
}
signed main()
{
	int T = 1;
	cin >> T;
	while (T--) ___();
}