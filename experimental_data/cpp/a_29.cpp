#include <cstdio>
#include <cstring>

int n;
int a[100], b[100];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	bool flag = false;
	for (int i = 0; i < n && !flag; i++) {
		for (int j = 0; j < n && !flag; j++) {
			flag = (a[i] + b[i] == a[j] && a[j] + b[j] == a[i]);
		}
	}
	if (flag) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}