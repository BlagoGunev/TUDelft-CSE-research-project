#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#define ldb long double
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define y1 y1HIT
#define x1 x1HUY
const ldb eps = 1e-9;
const int inf = 1 << 28;
const ldb pi = fabsl(atan2l(0.0, -1.0));
using namespace std;

int n, a[123123];
bool was[1 << 20];
int val[20];

void load()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 20; i++)
		val[i] = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		was[a[i]] = 1;
		for (int j = 0; j < 20; j++)
		{
			if (a[i] & (1 << j))
				val[j] = a[i];
			else
				val[j] |= a[i];
			was[val[j]] = 1;
		}
	}
	int res = 0;
	for (int i = 0; i < (1 << 20); i++)
		res += was[i];
	cout << res;
}

void solve()
{

}

#define problem "a"
int main()
{
	#ifndef ONLINE_JUDGE
	freopen(problem".in", "rt", stdin);
	freopen(problem"3.out", "wt", stdout);
	#endif
	load();
	solve();
	return 0;
}