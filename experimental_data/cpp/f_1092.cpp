/**********************************************
 *Author*        :XzzF
 *Created Time*  : 2018/12/18 23:43:13
 *Ended  Time*  : 2018/12/19 0:03:39
*********************************************/

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef long long LL;
const int inf = 1 << 30;
const LL INF = 1LL << 60;
const int MaxN = 200000;

int n;
int a[MaxN + 5];
int pre[2 * MaxN + 5], last[MaxN + 5], other[2 * MaxN + 5];
LL res[MaxN + 5], siz[MaxN + 5];

int all;

void build(int x, int y) {
	pre[++all] = last[x];
	last[x] = all;
	other[all] = y;
}

void PDfs(int x, int fa, int dep) {
	siz[x] = a[x];
	res[1] += 1LL * dep * a[x];
	for(int ed = last[x]; ed != -1; ed = pre[ed]) {
		int dr = other[ed];
		if(dr != fa) {
			PDfs(dr, x, dep + 1);
			siz[x] += siz[dr];
		}
	}
}

void Dfs(int x, int fa) {
	if(x != 1) res[x] = res[fa] - siz[x] + (siz[1] - siz[x]);
	for(int ed = last[x]; ed != -1; ed = pre[ed]) {
		int dr = other[ed];
		if(dr != fa) Dfs(dr, x);
	}
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		all = -1; memset(last, -1, sizeof(last));
		memset(res, 0, sizeof(res));
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i < n; i++) {
			int u, v; scanf("%d %d", &u, &v);
			build(u, v); build(v, u);
		}
		PDfs(1, 0, 0);
		//for(int i = 1; i <= n; i++) printf("%lld\n", siz[i]);
		Dfs(1, 0);
		LL ans = 0LL;
		for(int i = 1; i <= n; i++) ans = max(ans, res[i]);
		printf("%lld\n", ans);
	}
    return 0;
}