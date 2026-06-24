#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define LL long long
#define LD long double
#define maxlongint 2147483647

using namespace std;

const int inf = 999999999;
const int mod = 1000000007;

inline int Getint()
{
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int ret = 0;
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}

int n, x;

int main()
{
	n = Getint();
	int pre = 0;
	LL now = 0, lowest = 0;
	for (int i = 1; i <= n; i++)
	{
		x = Getint();
		now += (LL)(pre - x);
		lowest = min(lowest, now);
		pre = x;
	}
	printf("%I64d\n", -lowest);
	return 0;
}