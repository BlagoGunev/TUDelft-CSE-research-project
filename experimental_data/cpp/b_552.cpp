#include<iostream>



#include<vector>

#include<array>

#include<string>

#include<map>

#include<list>



#include<cmath>

#include<cstring>

#include<algorithm>

#include<iomanip>



typedef long long int llint;

typedef unsigned long long int ullint;

using namespace std;



int main()

{

	llint n, a = 1,

		b = 9,

		i = 1,

		res = 0,

		numc = 0;

	cin >> n;

	for (llint copy_n = n; copy_n > 0; copy_n /= 10, ++numc);

	for (; i < numc; ++i)

	{

		res += (b - a + 1) * i;

		a *= 10;

		(b *= 10) += 9;

	}

	res += (n - a + 1) * i;

	cout << res;

	return 0;

}