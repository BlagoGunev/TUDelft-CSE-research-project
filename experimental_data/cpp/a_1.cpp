#include <iostream>
using namespace std;



int main()
{
	long long n,m,a;
	cin >> n >> m >> a;
	long long d1 = 1, d2 = 1;
	if (n%a==0)
		d1 = n/a;
	else
		if (n/a != 0)
			d1 = n/a+1;
	if (m%a==0)
		d2 = m/a;
	else
		if (m/a != 0)
			d2 = m/a + 1;
	cout << d1 * d2;
	cin >> n;
	return 0;
}