#include <bits/stdc++.h>
using namespace std;

char str[111111];

int main()
{
	int n, k;
	int st, fr, nfr, lst, cnt, ans;

	scanf("%d%d", &n, &k);
	scanf("%s", str);

	st = 0;
	while (str[st] == '1')
		st++;
	cnt = k;
	lst = st;
	while (cnt)
	{
		lst++;
		while (str[lst] == '1')
			lst++;
		cnt--;
	}

	fr = 0;
	nfr = fr + 1;
	while (str[nfr] == '1')
		nfr++;
	while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st))
	{
		fr = nfr;
		nfr = fr + 1;
		while (str[nfr] == '1')
			nfr++;
	}

	ans = n - 1;
	do
	{
		ans = min(ans, max(lst - fr, fr - st));
		st++;
		while (str[st] == '1')
			st++;
		lst++;
		while (str[lst] == '1')
			lst++;
		while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st))
		{
			fr = nfr;
			nfr = fr + 1;
			while (str[nfr] == '1')
				nfr++;
		}
	} while (lst < n);

	printf("%d\n", ans);

	return 0;
}