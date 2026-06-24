#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int dcmp(double x) { return fabs(x) <= eps ? 0 : (x > 0 ? 1 : -1); }

ll n;

int main( )
{
	scanf("%lld", &n);
	ll tmp = n;
	tmp -= n / 2 + n / 3 + n / 5 + n / 7;
	tmp += n / 6 + n / 10 + n / 14 + n / 15 + n / 35 + n / 21;
	tmp -= n / (2 * 3 * 5) + n / (2 * 5 * 7) + n / (3 * 5 * 7) + n / (2 * 3 * 7);
	tmp += n / (2 * 3 * 5 * 7);
	printf("%lld\n", tmp);
	return 0;
}