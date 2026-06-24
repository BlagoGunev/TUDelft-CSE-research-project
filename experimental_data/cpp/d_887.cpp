#pragma comment(linker,"/STACK:300000000")
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <ctype.h>
#include <iomanip>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <time.h>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;

#define pb push_back
#define mp make_pair
#define eps 1e-8
#define PI  3.14159265358979323846
#define ACCEPTED return 0;
#define name ""

const int  maxlen = (int)(3e5) + 10;
const int    base = (int)(1e9);
const ll      mod = 1000 * 1000 * 1000 + 7;
const ll   bigmod = 99194853094755497ll;
const ll infinity = (ll) 1e18;
const int    NSeg = 1 << 19;

ll pref1[maxlen];
ll pref2[maxlen];
ll tin[maxlen];

ll t1[1 << 20];
ll t2[1 << 20];

void build(ll * t, int i, ll d)
{
	int v = NSeg + i;
	t[v] = d;
	while (v > 1)
	{
		v >>= 1;
		t[v] = min(t[2 * v], t[2 * v + 1]);
	}
}
ll getmin(ll * t, int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return infinity;
	if (tl == l && tr == r)
		return t[v];
	int tm = (tl + tr) / 2;
	ll r1 = getmin(t, 2 * v, tl, tm, l, min(r, tm));
	ll r2 = getmin(t, 2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
	return min(r1, r2);
}
int main()
{
#ifdef _DEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int n;
	ll a, b, c, d, start, len;
	scanf("%d", &n);
	scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
	scanf("%I64d %I64d", &start, &len);
	pref1[0] = pref2[0] = start;
	tin[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll t;
		int type;
		scanf("%I64d", &t);
		scanf("%d", &type);
		tin[i] = t;

		pref1[i] = pref1[i - 1];
		pref2[i] = pref2[i - 1];

		if (type == 0)
		{
			pref1[i] -= b;
			pref2[i] -= d;
		}
		else
		{
			pref1[i] += a;
			pref2[i] += c;
		}
	}
	pref1[n + 1] = pref2[n + 1] = infinity - 1;

	for (int i = 0; i <= n + 1; ++i)
		build(t1, i, pref1[i]);

	for (int i = 0; i <= n + 1; ++i)
		build(t2, i, pref2[i]);

	ll bal = 0;
	for (int i = 0; i <= n; ++i)
	{
		int j = lower_bound(tin, tin + n + 2, tin[i] + len) - tin;
		ll q = getmin(t2, 1, 0, NSeg - 1, i, j - 1);

		ll lst = (i > 0) ? pref2[i - 1] : 0;
		if (q - lst + bal >= 0)
		{
			
				printf("%I64d", tin[i]);
				return 0;
			
		}
		if (pref1[i] < 0)
			break;
		bal = pref1[i];

		j = lower_bound(tin, tin + n + 2, tin[i] + 1 + len) - tin;
		q = getmin(t2, 1, 0, NSeg - 1, i + 1, j - 1);
		if (q - pref2[i] + bal >= 0)
		{
				printf("%I64d", tin[i] + 1);
				return 0;
		}


	}
	printf("-1");
	ACCEPTED
}