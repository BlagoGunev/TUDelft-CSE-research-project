#include <stdio.h>
#define INF 999999

int n, m;

int a[55][3];
char t[55];
int ans = INF,ansi[3];

void input(int p, int q) {
	char tt = t[q];
	int k;
	if (tt >= '0' && tt <= '9') k = 0;
	else if (tt >= 'a' && tt <= 'z') k = 1;
	else k = 2;

	if (a[p][k] > q) a[p][k] = q;
	if (a[p][k] > (m - q)) a[p][k] = m - q;
}

void dfs(int cnt) {
	if (cnt == 3) {
		if (ansi[0] != ansi[1] && ansi[1] != ansi[2] && ansi[2] != ansi[0]) {
			int tmpans = a[ansi[0]][0]+ a[ansi[1]][1]+ a[ansi[2]][2];
			ans = (ans > tmpans) ? tmpans : ans;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		ansi[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		a[i][0] = INF;
		a[i][1] = INF;
		a[i][2] = INF;
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", &t);
		for (int j = 0; j < m; j++) {
			input(i, j);
		}
	}
	dfs(0);
	printf("%d", ans);
}