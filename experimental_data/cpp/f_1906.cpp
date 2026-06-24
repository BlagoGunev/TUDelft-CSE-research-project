// LUOGU_RID: 163170254
#include <bits/stdc++.h>
#define int long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int N = 1e5 + 10;
int n, m;

struct seg_node {
	int val, sum, lv, rv;
} seg[N * 4];
int czuo[N][4];
vector<int> zuol[N], zuor[N];

struct eq__ {
	int k, l, r, id;
} que[N];
int ans[N];

bool cmp(eq__ a, eq__ b) {
	return a.k < b.k;
}

seg_node merge(seg_node a, seg_node b) {
	seg_node z;
	z.sum = a.sum + b.sum;
	z.val = max({a.val, b.val, a.rv + b.lv});
	z.lv = max(a.lv, a.sum + b.lv);
	z.rv = max(b.rv, b.sum + a.rv);
	return z;
}

void pushup(int now) {
	seg[now] = merge(seg[ls(now)], seg[rs(now)]);
}

seg_node query(int now, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr)
		return seg[now];
	if (qr <= mid)
		return query(ls(now), l, mid, ql, qr);
	if (ql > mid)
		return query(rs(now), mid + 1, r, ql, qr);
	return merge(query(ls(now), l, mid, ql, qr), query(rs(now), mid + 1, r, ql, qr));
}

void update(int now, int l, int r, int pos, int vl) {
	if (l == r) {
		seg[now].lv += vl;
		seg[now].rv += vl;
		seg[now].sum += vl;
		seg[now].val += vl;
		return ;
	}
	if (pos <= mid)
		update(ls(now), l, mid, pos, vl);
	else
		update(rs(now), mid + 1, r, pos, vl);
	pushup(now);
}

signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 3; j++)
			cin >> czuo[i][j];
		zuol[czuo[i][0]].push_back(i);
		zuor[czuo[i][1]].push_back(i);
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
		cin >> que[i].k >> que[i].l >> que[i].r, que[i].id = i;
	sort(que + 1, que + q + 1, cmp);
	int mq = 1;
	for (int i = 1; i <= n; i++) {
		for (auto j : zuol[i])
			update(1, 1, m, j, czuo[j][2]);
		for (auto j : zuor[i - 1])
			update(1, 1, m, j, -czuo[j][2]);
		while (mq <= q && que[mq].k == i) {
			ans[que[mq].id] = query(1, 1, m, que[mq].l, que[mq].r).val;
			mq++;
		}
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
	return 0;
}