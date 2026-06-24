#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef long long llong;

#define mp make_pair
#define lowbit(x) ((x) & (-(x)))
#define pf(x) ((x) * (x))
#define two(x) (1 << (x))
#define twoL(x) ((llong) 1 << (x))


void ch_max(int &x, int y) {if (x < y) x = y;}
void ch_min(int &x, int y) {if (x > y) x = y;}

const double pi = acos(-1.0);
const double eps = 1e-9;


const int N = 100005;
struct E {
	int v;
	E * next;
}*e[N], mem[N * 2];
int mm;

void add(int u, int v) {
	mem[mm].v = v;
	mem[mm].next = e[u];
	e[u] = &mem[mm++];

	mem[mm].v = u;
	mem[mm].next = e[v];
	e[v] = &mem[mm++];
}
int vis[N], t_vis;
int con[N];

int zx;
int cal_zx(int v, int tot) {
	int i, j, k;
	vis[v] = t_vis;
	int ret = 1, tmax = 0;
	for (E *p = e[v]; p; p = p->next) {
		j = p->v;
		if (vis[j] == t_vis || con[j]) continue;
		int tmp = cal_zx(j, tot);
		ch_max(tmax, tmp);
		ret += tmp;
	}
	ch_max(tmax, tot - ret);
	if (tmax <= (tot >> 1)) zx = v;
	return ret;
}

int n, m;

int que[N];
int vv[N], vv_cnt;

llong ans;

int size[N], a[N], b[N];
void cal_it(int v, int now) {
	int i, j, k;
	vis[v] = t_vis;
	size[v] = 1;
	a[now]++;
	for (E *p = e[v]; p; p = p->next) {
		j = p->v;
		if (vis[j] == t_vis || con[j]) continue;
		cal_it(j, now + 1);
		size[v] += size[j];
	}
}
void solve(int v, int tot) {
	int i, j, k;
	t_vis++;
	cal_zx(v, tot);
	v = zx;
	t_vis++;
	for (i = 0; i < tot; ++i) b[i] = a[i] = 0;
	for (i = 0; i <= m; ++i) b[i] = 0;
	cal_it(v, 0);
	con[v] = 1;

	int lcnt = vv_cnt;
	for (E *p = e[v]; p; p = p->next) {
		j = p->v;
		if (con[j]) continue;
		vv[vv_cnt++] = j;
	}
	int rcnt = vv_cnt;

	b[0] = 1;
	for (i = lcnt; i < rcnt; ++i) {
		j = vv[i];
		for (k = 0; k <= size[j]; ++k) a[k] = 0;
		t_vis++;
		cal_it(j, 1);
		for (k = 0; k <= size[j] && k <= m; ++k) {
			ans += (llong) a[k] * b[m - k];
		}
		for (k = 0; k <= size[j]; ++k) b[k] += a[k];
	}

	for (i = lcnt; i < rcnt; ++i) {
		j = vv[i];
		solve(j, size[j]);
	}
}

void solve_it() {
	int i, j, k;
	t_vis = 0;
	memset(vis, 0, sizeof(vis));
	memset(con, 0, sizeof(con));
	vv_cnt = 0;
	ans = 0;
	solve(1, n);
}
int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int i, j, k, t, nc = 0;
	while (scanf("%d%d", &n, &m) != EOF) {
		mm = 0;
		memset(e, 0, sizeof(e));
		for (i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
		}
		solve_it();
		printf("%I64d\n", ans);
	}
	return 0;
}