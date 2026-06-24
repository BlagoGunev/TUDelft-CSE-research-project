#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5, INF = 2e18;

int n, m, p, a[N];
vector<int> c[N<<3];

struct SegmentTreeNode {
	int l, r, sum;
}tree[N * 4];

void pushUp(int idx) {
	tree[idx].sum = tree[2*idx+1].sum + tree[2*idx+2].sum;
	int L = tree[idx].l, R = tree[idx].r, mid = (L + R) >> 1;
	int y = -1;
	for(int x=0;x<=mid-L+1;x++) {
		if (y >= 0) c[idx][x + y] = min(c[idx][x + y], max(c[2*idx+1][x], c[2*idx+2][y] - (tree[2*idx+1].sum - p * x)));
		while (y+1<=R-mid && c[2*idx+1][x + 1] - 1 + tree[2*idx+1].sum - p * x >= c[2*idx+2][y + 1]) {
			y++;
			c[idx][x + y] = min(c[idx][x + y], max(c[2*idx+1][x], c[2*idx+2][y] - (tree[2*idx+1].sum - p * x)));
		}
	}
}

void build(int idx, int l, int r) {
	tree[idx].l = l, tree[idx].r = r;
	c[idx].resize(r - l + 3); c[idx][0] = -2e18;
	for(int i=1;i<=r-l+2;i++) c[idx][i] = INF;
	if (l == r) {
		tree[idx].sum = a[l];
		c[idx][1] = (p - a[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(2*idx+1, l, mid);
	build(2*idx+2, mid + 1, r);
	pushUp(idx);
} 

int query(int idx, int l, int r, int L, int R, int v) {
	if (l == L && r == R) {
		return v + tree[idx].sum - (p * (upper_bound(begin(c[idx]), end(c[idx]), v) - begin(c[idx]) - 1));
	}
	int mid = (L + R) >> 1;
	if (r <= mid) return query(2*idx+1, l, r, L, mid, v);
	if (l > mid) return query(2*idx+2, l, r, mid + 1, R, v);
	return query(2*idx+2, mid + 1, r, mid + 1, R, query(2*idx+1, l, mid, L, mid, v));
}

signed main() {
	scanf("%lld%lld%lld", &n, &m, &p);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1, 1, n);
	while (m--) {
		int l, r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n", query(1, l, r, 1, n, 0));
	} 
}