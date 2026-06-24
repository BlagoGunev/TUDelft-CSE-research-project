#include <bits/stdc++.h>
#define N (1000 + 10)
using namespace std;
inline int read() {
	int cnt = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -f; c = getchar();}
	while (isdigit(c)) {cnt = (cnt << 3) + (cnt << 1) + c - '0'; c = getchar();}
	return cnt * f;
}
int q, n;
int tmp;
int a[N];
int main() {
	q = read();
	while (q--) {
		bool flag = 0;
		n = read();
		for (register int i = 1; i <= 4 * n; i++) a[i] = read();
		sort(a + 1, a + 4 * n + 1);
		tmp = a[1] * a[4 * n];
		if (a[1] != a[2] || a[3] != a[4] || a[4 * n] != a[4 * n - 1] || a[4 * n - 2] != a[4 * n - 3] || (a[3] * a[4 * n - 3] != tmp)) {flag = 1;}
        register int i = 5, j = 4 * n - 4;
		for (;i <= 2 * n && j >= 2 * n + 1; i += 4, j -= 4) {
			if (flag == 1) break;
			if ((a[i] != a[i + 1]) || a[j] != a[j - 1] || a[i + 2] != a[i + 3] || a[j - 2] != a[j - 3]) {
				flag = 1;
			}
			if (a[i] * a[j] != tmp || a[i + 2] * a[j - 2] != tmp) {
				flag = 1;
			}
		}
        if (flag) printf("NO\n");
		if (!flag) printf("YES\n");
	}
	return 0;
}