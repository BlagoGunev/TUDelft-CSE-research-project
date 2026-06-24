#include <bits/stdc++.h>
typedef unsigned int uint;
typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;



int main()
{
	ull n, k;
	cin >> n >> k;

	if (k % n) {
		cout << k / n + 1 << endl;
	}
	else {
		cout << k / n << endl;
	}

	return 0;
}