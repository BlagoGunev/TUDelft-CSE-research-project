#include <iostream>
#include <cmath>
using namespace std;
bool b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

inline bool check(int x);

int main()
{
	long x, y;
	cin >> x;
	float max = sqrt((float) x);
	long count = 0;
	y = x;
	while (y)
	{
		b[y % 10] = true;
		y/=10;
	}
	for (long i = 1; i <= max; i++)
		if (!(x%i))
		{
			if (check(i))
				count++;
			if (x/i != i && check(x/i))
				count++;
		};
	cout << count;
	return 0;
}

inline bool check(int x)
{
	bool ch = false;
	while (x)
	{
		ch = ch || b[x%10];
		x/=10;
	}
	return ch;
}