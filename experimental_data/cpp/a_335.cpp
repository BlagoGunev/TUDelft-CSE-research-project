#include <bits/stdc++.h>

using namespace std;



char s[1005];

int n;



int main()

{

	scanf("%s", s);

	scanf("%d", &n);

	int lo = 1;

	int hi = 1001;

	int cnt[26] = {0};

	int len = strlen(s);

	for (int i = 0; i < len; i++)

	{

		cnt[s[i]-'a']++;

	}

	int md;

	while (lo <= hi)

	{

		md = (lo + hi) / 2;

		int need = 0;

		for (int i = 0; i < 26; i++)

		{

			need += (cnt[i]+md-1) / md;

		}

		if (need > n)

			lo = md+1;

		else

			hi = md - 1;

	}

	if (lo > len)

		printf("-1\n");

	else

	{

		string res = "";

		for (int i = 0; i < 26; i++)

		{

			int x = (cnt[i]+lo-1) / lo;

			for (int j = 0; j < x; j++)

			{

				res += (i+'a');

			}

		}

		while (res.size() < n)

			res += 'a';

		printf("%d\n%s\n", lo, res.c_str());

	}

}