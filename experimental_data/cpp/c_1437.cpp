#include<bits/stdc++.h>
using namespace std;
template <typename T>
void readin(T &x) {
	x = 0;
	T fh = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= fh;
}
void d_read(double &x) {
	x = 0.0;
	int fh = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
	if (ch == '.') {
		double num = 1.0;
		ch = getchar();
		for (; isdigit(ch); ch = getchar()) x = x + (num /= 10) * (ch ^ 48);
	}
	x *= fh;
}

template <typename T>
void wt(T x) {
	if (x > 9) wt(x / 10);
	putchar(x % 10 + 48);
}
template <typename T>
void writeln(T x, char c) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	wt(x);
	putchar(c);
}
int a[205], b[205];
int main() {
	int t;
	readin(t);
	while (t --) {
		int n;
		readin(n);
		for (int i = 1; i <= n; i ++) {
			readin(a[i]);
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i ++) {
			b[i] = i;
		}
		for (int i = 1; i <= n; i ++) {
			int pos = -1, tot = 0;
			for (int j = 1; j <= n; j ++) {
				if (b[j] < a[j]) {
					if (pos == -1) pos = j;
					tot ++;
				}
				else {
					tot --;
					if (tot <= 0) {
						pos = -1;
						tot = 0;
					}
				}
			}
			if (pos == -1) break;
			else {
				for (int j = pos; j <= n; j ++) {
					b[j] ++;
				}
			}
		}
	//	for (int i = 1; i <= n; i ++) cout << b[i] << ' ';
	//	cout << endl;
		int ans = 0;
		for (int i = 1; i <= n; i ++) ans += abs(a[i] - b[i]);
		writeln(ans, '\n');
	}
	return 0;
}