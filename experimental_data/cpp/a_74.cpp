/*
 * CF68_A.cpp
 *
 *  Created on: 15.04.2011
 *      Author: Authentic911
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	string X, Y;

	cin >> n;

	X = "";
	int p, m, a, b, c, d, e, tmp;
	int max = -1000000000;

	for(int i = 0; i < n; i++)
	{
		cin >> Y >> p >> m >> a >> b >> c >> d >> e;
		tmp = (p * 100) - (50 * m) + a + b + c + d + e;
//		cout << Y << " = " << tmp << endl;
		if(max < tmp)
		{
			max = tmp;
			X = Y;
		}
	}

	cout << X << endl;

	return 0;
}