#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <list>
#include <numeric> 
#include <sstream>
#include <iomanip>
#include <limits>

#define CLR(a, b) memset(a, (b), sizeof(a))
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef pair <int, ll> pil;

const double PI = acos(-1.0);
const double E = exp(1.0);
const double eps = 1e-8;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5 + 5;
const int MOD = 1e9;

struct node
{
	int x, y, vis;
}q[30];

bool comp(node x, node y)
{
	if (x.x == y.x)
		return x.y < y.y;
	return x.x < y.x;
}

bool solve(int n)
{
	int len = (n << 1);
	for (int i = 1; i < len; i++)
		if (q[i].vis == q[i - 1].vis)
			return false;
	return true;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &q[i].x, &q[i].y);
		q[i].vis = 0;
	}
	for ( ; i < m + n; i++)
	{
		scanf("%d%d", &q[i].x, &q[i].y);
		q[i].vis = 1;
	}
	sort(q, q + (n + m), comp);
	if (n != m)
		printf("No\n");
	else
	{
			printf("Yes\n");
	}
}