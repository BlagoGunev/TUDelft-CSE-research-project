#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <set>
#include <vector>
#include <cstdio>
#include <cmath>
#define LL long long
#define nextLine() {int c = 0; while ((c = getchar()) != EOF && c != 10);}
#define sqr(a) ((a) * (a))
#define fill(a, c) memset(a, c, sizeof a)
#define ldb long double
#define sgn(a) ((a) > eps ? 1 : -1)
const ldb eps = 1e-9;
const ldb pi = fabs(atan2(0.0, -1.0));
const int INF = 1 << 28;
const LL LINF = 1ll << 50;
const ldb LDINF = 1e70;
const ldb cos3 = cos(pi / 3);
const ldb sin3 = sin(pi / 3);
using namespace std;


int n, m, k;
LL add[100100];
int pl[100100];
LL res[100100];


void Load()
{
	cin >> n >> m >> k;
	int i;
	int a, b, c;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		add[a] += (LL)c;
		pl[a]++;
		add[b + 1] -= (LL)c + b - a + 1;
		pl[b + 1]--;
	}
}

void Solve()
{
	int i;
	LL s = 0;
	LL cpl = 0;
	for (i = 1; i <= n; i++)
	{
		s += (LL)add[i];
		cpl += (LL)pl[i];
		res[i] = s;
		s += (LL)cpl;
	}
	
	LL ans = 0;
	int a;
	for (i = 1; i <= k; i++)
	{
		scanf("%d", &a);
		ans += res[a];
	}
	cout << ans;

}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in", "rt", stdin);
	freopen("out", "wt", stdout);
	#endif
	Load();
	Solve();
	return 0;
}