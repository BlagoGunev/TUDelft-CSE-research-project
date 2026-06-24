#include <iostream>
using namespace std;

void solve();

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

void solve()
{
	int n;
	cin >> n;
	int a[n], count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == i + 1)
			count++;
	}
	cout << (count / 2) + (count % 2) << "\n";
	return;
}