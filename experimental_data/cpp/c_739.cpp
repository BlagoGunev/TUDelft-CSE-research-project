#define _CRT_SECURE_NO_WARNINGS
#define TASK "insider"
#pragma comment(linker, "/STACK:67108864")
#include <stdio.h>
#include <iostream>
#include <iomanip> 
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <assert.h>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>

const int MOD = 1163962801;
const int INF = 1000111111;
const double EPS = 1e-6;
const int HASH_POW = 29;
const double PI = acos(-1.0);

using namespace std;

double workTime()
{
	return double(clock()) / CLOCKS_PER_SEC;
}

void my_return(int code)
{
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << workTime() << endl;
#endif
	exit(code);
}

int n, h[300010];
long long delta[300010];

struct node
{
	int ans, pref, suff;
} t[1200010];

inline void calc(int v, int tl, int tr)
{
	int mid = (tl + tr) >> 1;
	int left = (v << 1), right = ((v << 1) | 1);

	t[v].ans = max(t[left].ans, t[right].ans);
	t[v].pref = t[left].pref;
	t[v].suff = t[right].suff;
	if (delta[mid] && delta[mid + 1] && !(delta[mid] > 0 && delta[mid + 1] < 0))
	{
		t[v].ans = max(t[v].ans, t[left].suff + t[right].pref);
		if (t[left].pref == mid - tl + 1)
			t[v].pref = t[left].pref + t[right].pref;
		if (t[right].suff == tr - mid)
			t[v].suff = t[right].suff + t[left].suff;
	}
}

void build(int v, int tl, int tr)
{
	if (tl == tr)
	{
		delta[tl] = h[tl] - h[tl + 1];
		if (!delta)
			t[v].ans = t[v].pref = t[v].suff = 0;
		else
			t[v].ans = t[v].pref = t[v].suff = 1;
	}
	else
	{
		int mid = (tl + tr) >> 1;
		build((v << 1), tl, mid);
		build((v << 1) | 1, mid + 1, tr);
		calc(v, tl, tr);
	}
}

void update(int v, int tl, int tr, int pos, int val)
{
	if (tl == tr)
	{
		delta[tl] += val;
		if (!delta)
			t[v].ans = t[v].pref = t[v].suff = 0;
		else
			t[v].ans = t[v].pref = t[v].suff = 1;
	}
	else
	{
		int mid = (tl + tr) >> 1;
		if (pos <= mid)
			update((v << 1), tl, mid, pos, val);
		else
			update((v << 1) | 1, mid + 1, tr, pos, val);
		calc(v, tl, tr);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	mt19937_64 mt_rand(1);
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	/*freopen(TASK".in", "rt", stdin);
	freopen(TASK".out", "wt", stdout);*/
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);

	if (n == 1)
	{
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; ++i)
			printf("1\n");
		my_return(0);
	}
	
	build(1, 1, n - 1);

	int q;
	scanf("%d", &q);
	while (q-- > 0)
	{
		int ll, rr, d;
		scanf("%d %d %d", &ll, &rr, &d);
		if (ll > 1)
			update(1, 1, n - 1, ll - 1, -d);
		if (rr < n)
			update(1, 1, n - 1, rr, d);
		printf("%d\n", t[1].ans + 1);
	}

	my_return(0);
}