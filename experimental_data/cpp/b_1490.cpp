#include <bits/stdc++.h>
using namespace std;

#define fo(i, x, y) for (int i = (x); i <= (y); ++i)
#define fd(i, x, y) for (int i = (x); i >= (y); --i)

int n;
int s[5];

int getint()
{
	char ch;
	int res = 0, p;
	while (!isdigit(ch = getchar()) && (ch ^ '-'));
	p = ch == '-'? ch = getchar(), -1 : 1;
	while (isdigit(ch))
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res * p;
}

void work()
{
	n = getint();
	memset(s, 0, sizeof(s));
	fo(i, 1, n)
	{
		int x;
		x = getint();
		s[x % 3]++;
	}
	if (s[0] == s[1] && s[1] == s[2])
	{
		printf("0\n");
		return;
	}
	if (s[0] > n / 3 && s[1] > n / 3)
	{
		printf("%d\n", (s[0] - n / 3) * 2 + (s[1] - n / 3));
		return;
	}
	if (s[0] > n / 3 && s[2] > n / 3)
	{
		printf("%d\n", (s[0] - n / 3) + (s[2] - n / 3) * 2);
		return;
	}
	if (s[1] > n / 3 && s[2] > n / 3)
	{
		printf("%d\n", (s[1] - n / 3) * 2 + (s[2] - n / 3));
		return;
	}
	if (s[0] > n / 3)
	{
		printf("%d\n", (n / 3 - s[1]) + (n / 3 - s[2]) * 2);
		return;
	}
	if (s[1] > n / 3)
	{
		printf("%d\n", (n / 3 - s[0]) * 2 + (n / 3 - s[2]));
		return;
	}
	if (s[2] > n / 3)
	{
		printf("%d\n", (n / 3 - s[0]) + (n / 3 - s[1]) * 2);
		return;
	}
}

int main()
{
	int T;
	T = getint();
	while (T--) work();
	return 0;
}