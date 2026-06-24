#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <complex>

using namespace std;

#define pb push_back
#define pii pair<int, int>
#define pdi pair<double, int>
#define pdii pair<pdi, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define vi vector<int>
#define inf 2000000000
#define mod 1000000007
#define y1 uhgeg
#define lim 31700
#define eps 1e-9
#define prime 3001

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> comp;

int n, m, j, i, h, l, k, q1, q2, a[100500], ans, ptr;
vector<pli> summ;
ll q;

void solve()
{
	summ.resize(n * k + 1);
	summ.pb(pii(0, 0));
	scanf ("%d%d", &n, &k);
	for (j = 1; j <= n; j++)
	{
		scanf ("%d", &a[j]);
		for (i = 1; i <= k; i++)
		{
			summ.pb(pii(a[j] * i, i));
		}
	}
	sort (summ.begin(), summ.end());
	scanf ("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf ("%I64d", &q);
		ans = inf;
		ptr = summ.size() - 1;
		for (j = 0; j < summ.size() && summ[j].first <= (q >> 1); j++)
		{
			while (ptr > j && summ[ptr].first > (q - summ[j].first))
			{
				ptr--;
			}
			while (ptr > j && summ[ptr].first == (q - summ[j].first))
			{
				ans = min(summ[j].second + summ[ptr].second, ans);
				ptr--;
			}
		}
		if (ans > k)
		{
			printf ("-1\n");
		}
		else
		{
			printf ("%d\n", ans);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
	srand(333);
	solve();
	return 0;
}