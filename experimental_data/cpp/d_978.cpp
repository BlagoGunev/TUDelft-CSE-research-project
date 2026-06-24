#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <math.h>
#include <cmath>
#include <time.h>
#include <string.h>
#include <vector>
#include <set>
#include <deque>
#include <stack>
#include <time.h>
#include <map>
#include <queue>
#include <functional>
#include <cctype>
#include <iomanip>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define pb(a)        push_back(a)
#define mp(a, b)     make_pair(a, b)
#define fi           first
#define se           second
#define all(a)       a.begin(),a.end()
#define szz(a)       (int)a.size()
#define endl         '\n'

typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;

const ll MOD = 1e9 + 7;
const int INF = 0x7fffffff;
const ll LLINF = 0x7fffffffffffffff;
const db PI = acos(-1.0);
const db eps = 1e-5;

int n;
int v[100005];

int judge(const int& v1, const int& v2, int res)
{
	ll p = v2 - v1;
	ll now = v2 + p;
	for (int i = 3; i <= n; i++, now += p) {
		if (abs(v[i] - now) > 1) return INF;
		else if (abs(v[i] - now) == 0) continue;
		else ++res;
	}
	return res;
}

const int mov[][3] = { {0, 0}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}, {0, 1}, {0, -1} };

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);

	int ans = INF, res = INF;
	for (int i = 0; i < 9; i++) {
		int v1 = v[1] + mov[i][0], v2 = v[2] + mov[i][1];
		res = judge(v1, v2, abs(mov[i][0]) + abs(mov[i][1]));
		ans = min(res, ans);
	}
	
	if (ans == INF) return !printf("-1\n");
	else printf("%d\n", ans);
}