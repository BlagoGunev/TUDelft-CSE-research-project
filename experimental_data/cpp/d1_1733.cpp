#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e9;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n, x, y, sum = 0, num = 0, num2 = 0;
		string a, b;
		cin >> n >> x >> y >> a >> b;
		for (ll i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				num++;
				
			}
		}
		for (ll i = 0; i < n; i++)
		{
			if (i!=0&&a[i] != b[i]&&a[i-1]!=b[i-1])
			{
				num2++;
				i++;
			}
		}
		if(num%2==1)
			cout << -1 << endl;
		else
		{
			if (num == 2 && num2 == 1)
			{
				cout << min(x, 2 * y) << endl;
			}
			else
				cout << num / 2 * y << endl;
		}
	}
	return 0;
}