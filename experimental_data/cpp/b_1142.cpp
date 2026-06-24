#include<bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, q;
int p[maxn], a[maxn], pos[maxn], last[maxn], len[maxn], first[maxn], nxt[maxn], mm[maxn], d[22][maxn];
int pre[22][maxn];

int main(){
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &a[i]);
	}
	// for (int i = 1; i <= n; i ++) {
	// 	if (!last[i]) {
	// 		for (int i = 1; i <= q; i ++)
	// 			printf("0");
	// 		puts("");
	// 		return 0;
	// 	}
	// }
	for (int i = 1; i <= m; i ++) {
		int t = p[pos[a[i]] - 1];
		if (t == 0) {
			t = p[n];
		}
		pre[0][i] = last[t];
		last[a[i]] = i;
		// len[i] = len[Last] + 1;
		// first[i] = first[Last];
		// if (len[i] == 1) {
		// 	first[i] = i;
		// }
		// if (len[i] == n + 1) {
		// 	len[i] = n;
		// 	first[i] = nxt[first[i]];
		// }
		// if (Last) {
		// 	nxt[Last] = i;
		// }
		// last[a[i]] = i;
		// if (len[i] == n) {
		// 	d[0][i] = first[i];
		// }
	}
	for (int k = 1; (1 << k) <= n; k ++)
		for (int i = 1; i <= m; i ++) {
			pre[k][i] = pre[k - 1][pre[k - 1][i]];
	}
	for (int i = 1; i <= m; i ++) {
		int now = n - 1;
		int x = i;
		for (int k = 20; k >= 0; k --) {
			if (now - (1 << k) < 0) continue;
			now -= (1 << k);
			x = pre[k][x];
		}
		d[0][i] = x;
	}
	// for (int i = 1; i <= m; i ++) {
	// 	printf("%d ", first[i]);
	// }
	// puts("");
	// for (int i = 1; i <= m; i ++) {
	// 	printf("%d ", len[i]);
	// }
	for (int i = 2; i <= m; i ++)
		mm[i] = mm[i >> 1] + 1;
	for (int k = 1; (1 << k) <= m; k ++)
		for (int i = 1; i + (1 << k) - 1 <= m; i ++) {
			d[k][i] = max(d[k - 1][i], d[k - 1][i + (1 << k - 1)]);
		}
	for (int i = 1; i <= q; i ++) {
		int l, r;
		scanf("%d%d", &l, &r);
		int L = mm[r - l + 1];
		int t = max(d[L][l], d[L][r - (1 << L) + 1]);
		if (t >= l) {
			printf("1");
		} else {
			printf("0");
		}
	}
}