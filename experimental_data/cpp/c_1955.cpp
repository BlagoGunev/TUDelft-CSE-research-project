#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long int n, k;
	cin >> n >> k;
	long long int a[n]{0};
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	long long int ans = 0, att = 0;
	long long int l = 0, r = n-1;
	while (r > l && k > 0)
	{
		att = min(a[l], a[r]);
		a[l] -= att;
		a[r] -= att;
		k -= 2*att;
		if (k >= -1)
		{
			if (a[l] == 0)
			{
				ans += 1;
				l += 1;
			}
		}
		if (k >= 0)
		{
			if (a[r] == 0)
			{
				ans += 1;
				r -= 1;
			}
		}
	}
	while (r == l && k > 0)
	{
		att = a[l];
		a[l] -= att;
		k -= att;
		if (k >= 0) ans += 1;
		l += 1;
	}
	cout << ans;
	
}

int main(){
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
}