#include <iostream>

using namespace std;

int main()
{
	long long n, k, c;
	cin >> n >> k;
	c = n / 2;
	cout << c / (k + 1) << ' ' << (c / (k + 1)) * k << ' ' << n - (c / (k + 1)) - (c / (k + 1)) * k;
}