#include <bits/stdc++.h>
using namespace std;

int pos[100000];
int a, b;

long long gao(int *begin, int *end, int l, int r)
{
	// empty
	if (end == begin)
		return a;
	// not empty
	long long ans = 1ll * (end - begin) * (r - l) * b;
	if (r - l == 1)
		return ans;
	int m = l + (r - l) / 2;
	int *p;
	for (p = begin; p != end && *p < m; p++);
	ans = min(ans, gao(begin, p, l, m) + gao(p, end, m, r));
	return ans;
}

int main()
{
	int n, k;
	scanf("%d%d%d%d", &n, &k, &a, &b);
	for (int i = 0; i < k; i++)
		scanf("%d", &pos[i]);
	sort(pos, pos + k);
	cout << gao(pos, pos+k, 1, (1<<n)+1) << '\n';
	return 0;
}