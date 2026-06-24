#include <bits/stdc++.h>
#define ll long long
#define mkp make_pair
#define fir first
#define sec second
#define v_int vector <int>
#define pb push_back
using namespace std;

const int MaxN = 400010, inf = 1e9 + 1000;
int vx[MaxN], vtot;
int x[MaxN], y[MaxN];
int n, k;

struct info {
	int xl, xr, y, z;
	bool operator < (const info &a) const {
		return y < a.y;
	}
}	T[MaxN << 2];
int tot;

int lst[MaxN], val[MaxN];

ll ans[MaxN];

void to_ans(int i, int y) {
	ans[val[i]] += 1ll * (y - lst[i]) * (vx[i + 1] - vx[i]);
//	printf("%d %d %d %d %d\n", val[i], y, lst[i], vx[i + 1], vx[i]);
}
void process(int id) {
	for (int i = T[id].xl - 1; i < T[id].xr; ++i) {
		if (val[i]) to_ans(i, T[id].y);
		lst[i] = T[id].y;
	}
	for (int i = T[id].xl; i < T[id].xr; ++i)
		val[i] += T[id].z;
}

int main() {
	scanf("%d%d", &n, &k);
	vx[++vtot] = -inf;
	vx[++vtot] = inf;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", x + i, y + i);
		vx[++vtot] = x[i] - k + 1;
		vx[++vtot] = x[i] + 1;
	}
	sort(vx + 1, vx + vtot + 1);
	vtot = unique(vx + 1, vx + vtot + 1) - vx - 1;
	for (int i = 1; i <= n; ++i) {
		int xl, xr;
		xl = lower_bound(vx + 1, vx + vtot + 1, x[i] - k + 1) - vx;
		xr = lower_bound(vx + 1, vx + vtot + 1, x[i] + 1) - vx;
		T[++tot] = (info){xl, xr, y[i] - k + 1, 1};
		T[++tot] = (info){xl, xr, y[i] + 1, -1};
	}

	sort(T + 1, T + tot + 1);
	for (int i = 1; i <= tot; ++i) process(i);
	for (int i = 1; i <= n; ++i) printf("%I64d ", ans[i]); puts("");
	return 0;
}