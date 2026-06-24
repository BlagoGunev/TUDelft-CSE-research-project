#include <iostream>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);

	long long n, p1, p2, p3, t1, t2;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

	long long res = 0;

	int l, r;
	int predr = -1;
	for (int i = 0; i < n; ++i)
	{
		cin >> l >> r;

		if ( predr != -1 )
		{
			if ( (l - predr) > t1 )
			{
				res += t1 * p1;
				if ( (l - predr - t1) > t2 )
				{
					res += t2 * p2;
					res += (l - predr - t1 - t2) * p3; 
				}
				else
				{
					res += (l - predr - t1) * p2;
				}
			}
			else
			{
				res += (l - predr) * p1;
			}
		}

		res += (r - l) * p1;

		predr = r;
	}

	cout << res;

	return 0;
}