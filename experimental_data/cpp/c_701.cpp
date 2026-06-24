#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int f[0xFF];

char s[maxn];

int main()

{

	int n;

	scanf ("%d", &n);

	scanf ("%s", s);

	int tot = 0;

	for (int i = 0; i < n; i++)

		if (!f[s[i]]) tot++, f[s[i]] = 1;

	memset (f, 0, sizeof (f));

	int l = 0, num = 0;

	int ans = 0x7FFFFFFF;

	for (int i = 0; i < n; i++)

	{

		f[s[i]]++;

		if (f[s[i]] == 1) num++;

		while (f[s[l]] >= 2)

		{

			f[s[l]]--;

			l++;

		}

		if (num == tot) ans = min (ans, i - l + 1);

	}

	printf ("%d\n", ans);

	return 0;

}