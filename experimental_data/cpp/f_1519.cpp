#include <bits/stdc++.h>

using namespace std;



#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

char buf[1 << 21], *p1 = buf, *p2 = buf;



inline int qread() {

	register char c = getchar();

	register int x = 0, f = 1;

	while (c < '0' || c > '9') {

		if (c == '-') f = -1;

		c = getchar();

	}

	while (c >= '0' && c <= '9') {

		x = (x << 3) + (x << 1) + c - 48;

		c = getchar();

	}

	return x * f;

}



int n, m, a[10], b[10], pwr5[10], c[10][10], idx[1 << 18], xdi[15625];

long long dp[10][15625];



inline void Read() {

	n = qread(); m = qread();

	for (int i = 0;i < n;i++) a[i] = qread();

	for (int i = 0;i < m;i++) b[i] = qread();

	for (int i = 0;i < n;i++) {

		for (int j = 0;j < m;j++) c[i][j] = qread();

	}

}



inline void Dfs(int rid, int cid, int sta, int lft, long long cost) {

	if (cid >= n) {

		dp[rid][idx[sta]] = min(dp[rid][idx[sta]], cost);

		return;

	}

	int cur = ((sta >> 3 * cid) & 7);

	Dfs(rid, cid + 1, sta, lft, cost);

	for (int i = cur + 1;i <= min(a[cid], lft + cur);i++) Dfs(rid, cid + 1, sta ^ ((cur ^ i) << 3 * cid), lft - i + cur, c[cid][rid - 1] + cost);

}



inline void Solve() {

	memset(idx, -1, sizeof(idx));

	int scnt = 0;

	for (int i = 0;i < (1 << (3 * n));i++) {

		bool flag = 1;

		for (int j = 0;j < n;j++) {

			if (((i >> 3 * j) & 7) > a[j]) {

				flag = 0;

				break;

			}

		}

		if (flag) {

			idx[i] = scnt;

			xdi[scnt] = i;

			scnt++;

		}

	}

	memset(dp, 0x3f, sizeof(dp));

	dp[0][0] = 0;

	// for (int i = 0;i < scnt;i++) cout << xdi[i] << " "; cout << endl;

	for (int i = 0;i < m;i++) {

		for (int j = 0;j < scnt;j++) {

			// cout << min(dp[i][j], 999ll) << " ";

			if (dp[i][j] > 1e14) continue;

			Dfs(i + 1, 0, xdi[j], b[i], dp[i][j]);

		}

		//cout << endl;

	}

	// for (int j = 0;j < scnt;j++) cout << min(dp[m][j], 999ll) << " "; cout << endl;

	if (dp[m][scnt - 1] > 1e14) dp[m][scnt - 1] = -1;

	cout << dp[m][scnt - 1] << endl;

}



int main() {

	Read();

	Solve();

	return 0;

}