#include <iostream>
#include <vector>
using namespace std;

 long double binpow(long double a, long long n)
 {
	if (n == 0)
		return 1.0;
	if (n % 2 == 1)
		return binpow(a, n - 1) * a;
	else {
		long double b = binpow(a, n / 2);
		return b * b;
	}
}

int main()
{
	long double n, k, ans;
	cin >> n >> k;
	ans = n * binpow(1.000000011, k);

	printf("%0.40Lf", ans);
	return 0;
}