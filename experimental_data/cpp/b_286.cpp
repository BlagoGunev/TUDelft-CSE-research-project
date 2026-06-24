#include <iostream>
#include <algorithm>
using namespace std;

int n, x[4444444], *f = x;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		x[i] = i;
	for (int i = 2; i <= n; ++i)
	{
		f[n+1] = f[(n/i)*i+1];
		for (int j = (n / i) * i; j - i + 1 >= 1; j -= i)
			f[j+1] = f[j-i+1];
		++f;
	}
	for (int i = 1; i < n; ++i)
		cout << f[i] << ' ';
	cout << f[n] << '\n';
	return 0;
}