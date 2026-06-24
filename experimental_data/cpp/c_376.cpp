// rc.cpp
//

#include <math.h>
#include <string.h>

#include <iterator>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long long uint64;

#define PI 3.1415926535897932384626433832795
#define EPS 1E-8

char s[1000001];

uint cx[10];

int main(int argc, char* argv[])
{
	cin >> s;

	char* p = s;

	while (*p)
	{
		++cx[*p - '0'];
		++p;
	}

	uint len = p - s;
	--cx[1];
	--cx[6];
	--cx[8];
	--cx[9];

	int sum = 0,
		d = 0,
		cd = 0,
		cu = 10;

	for (uint i = 1; i < 10; ++i)
	{
		for (uint x = 0; x < cx[i]; ++x)
		{
			d += i * cu;
			cu *= 10;

			if (cu == 1000)
			{
				cu = 1;
				if (cd & 1)
					sum += d;
				else
					sum -= d;
				++cd;
				d = 0;
			}
		}
	}

	if (cu != 1)
	{
		if (cd & 1)
			sum += d;
		else
			sum -= d;
	}

	int r[] = {1, 6, 8, 9};

	do
	{
		int curs = sum;

		curs -= r[0];
		curs += r[1] * 100 + r[2] * 10 + r[3];

		if (abs(curs) % 7 == 0)
			break;
	}while (next_permutation(r, r + 4));

	cu = 0;
	for (uint i = 9; i != 0; --i)
	{
		for (uint x = 0; x < cx[i]; ++x)
			s[cu++] = i + '0';
	}

	for (uint i = 0; i < 4; ++i)
		s[cu++] = r[i] + '0';

	for (uint i = 0; i < cx[0]; ++i)
		s[cu++] = '0';

	s[cu] = 0;
	cout << s << endl;
	return 0;
}