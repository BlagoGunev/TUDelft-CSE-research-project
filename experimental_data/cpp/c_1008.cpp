#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 9;

int n;
int a[maxN];

int main()
{
	int ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[ans])
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}