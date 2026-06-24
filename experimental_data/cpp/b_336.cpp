#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
using namespace::std;

main ()
{
	int im;
	double m, R;
	cin >> im;
	cin >> R;

	double C = 2*sqrt(2.0);
	double C1 = sqrt(2.0);
	m = (double)im;

	double ans = (m*2*R) + 2*(m - 1) * (2*R + C * R/2);
	for (int i = 2; i < im; ++i)
		ans += (2*(m - i)*(2*R*C1 + (i - 1)*2*R));
	ans /= (m*m);
	
	if (im == 1)
	{
		printf("%.6f\n", 2*R);
	}
	else if (im == 2)
	{
		printf("%.6f\n", (4*R + (2*(2*R + (C * R / 2))))/4.0);
	}
	else
	{
		//cout << "n" << endl;
		//cout << m << " " << R << endl;
		printf("%.6f\n", ans);
	}
}