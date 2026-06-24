#include <stdio.h>
#include <string.h>

typedef long long LL;
const int N = 300005;

int n, a[N], b[N], d[N], p[N];
int res[N], sz;

void bfs() {
	
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		a[i] = i - a[i];
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", b + i);
		b[i] = i + b[i];
	}
	d[0] = -1;
	int cur = n;
	for (int i = n; i; --i) {
		int high = a[b[i]];
		if (high >= cur) continue;
		for (int j = high; j < cur; ++j) {
			d[j] = d[i] + 1;
			p[j] = i;
		}
		cur = high;
	}
	printf("%d\n", d[0]);
	if (~d[0]) {
		int i = 0;
		while (i != n) {
			res[sz++] = i;
			i = p[i];
		}
		for (int i = sz - 1; ~i; --i) {
			printf("%d ", res[i]);
		}
	}
	return 0;
}