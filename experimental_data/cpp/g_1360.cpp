#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>

using namespace std;


int main()
{
	int t, n, m, a, b;
	string res;
	cin >> t;
	while (t)
	{
		t--;
		cin >> n >> m >> a >> b;
		if (n * a != m * b)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int beg = 0;
		for (int i = 0; i < n; i++)
		{
			res = "";
			for (int j = 0; j < m; j++)
				res += '0';
			for (int j = 0; j < a; j++)
			{
				res[beg] = '1';
				beg++;
				beg %= m;
			}
			cout << res << '\n';
		}
	}
	return 0;
}