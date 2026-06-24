#include <cstdio>
#include <cctype>
using namespace std;

const int max_s = 100000;
char s[max_s+1];

#define gc getchar
inline int read()
{
	int c = gc(), t = 1, n = 0;
	while (isspace(c)) { c = gc(); }
	if (c == '-') { t = -1, c = gc(); }
	while (isdigit(c)) { n = n * 10 + c - '0', c = gc(); }
	return n * t;
}
#undef gc

int main()
{
	int cas = read(), px, py, n;

	while (cas--)
	{
		px = read(), py = read();

		scanf("%s", s);
		for (n = 0; s[n]; n++)
		{
			if (s[n] == 'U')
				py--;
			else if (s[n] == 'D')
				py++;
			else if (s[n] == 'L')
				px++;
			else
				px--;
		}

		for (int i = 0; i < n; i++)
		{
			if (py > 0 && s[i] == 'D')
				py--;
			else if (py < 0 && s[i] == 'U')
				py++;
			else if (px > 0 && s[i] == 'L')
				px--;
			else if (px < 0 && s[i] == 'R')
				px++;
		}

		if (px == 0 && py == 0)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}