#include <bits/stdc++.h>
#define N 150010
using namespace std;
template <typename node> void chkmax(node &x, node y) {x = max(x, y);}
template <typename node> void chkmin(node &x, node y) {x = min(x, y);}
template <typename node> void read(node &x) {
	x = 0; int f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
int a[N], b[N], x[N];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
	int len = 0;
	for (int i = 2; i * i <= a[1]; i++) {
		if (a[1] % i == 0) {
			x[++len] = i;
			while (a[1] % i == 0)
				a[1] /= i;
		}
	}
	if (a[1] > 1) x[++len] = a[1];
	for (int i = 2; i * i <= b[1]; i++) {
		if (b[1] % i == 0) {
			x[++len] = i;
			while (b[1] % i == 0) b[1] /= i;
		}
	}
	if (b[1] > 1) x[++len] = b[1];
	for (int i = 1; i <= len; i++) {
		bool flag = true;
		for (int j = 2; j <= n; j++)
			if (a[j] % x[i] != 0 && b[j] % x[i] != 0) flag = false;
		if (flag) {cout << x[i] << "\n"; return 0;}
	}
	cout << "-1\n";
	return 0;
}