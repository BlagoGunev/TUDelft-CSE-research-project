#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#define R register
#define ll long long
using namespace std;

int n, maxx, maxy;

inline void read(int &x)
{
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

inline void readch(char &ch)
{
	ch = getchar();
	while (ch != '+' && ch != '?') ch = getchar();
	return;
}

inline void swap(int &x, int &y)
{
	int z = x;
	x = y, y = z;
	return;
}

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	char opr;
	int x, y;
	read(n);
	while (n--)
	{
		readch(opr), read(x), read(y);
		if (x > y)
			swap(x, y);
		if (opr == '+')
			maxx = max(maxx, x), maxy = max(maxy, y);
		else
			printf("%s\n", maxx <= x && maxy <= y ? "YES" : "NO");
	}
	return 0;
}