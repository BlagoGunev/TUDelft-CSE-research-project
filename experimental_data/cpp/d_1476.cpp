#include <bits/stdc++.h>
using namespace std;
template <typename T>
void readin(T &x) {
	x = 0;
	char ch = getchar();
	T fh = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= fh;
}
template <typename T>
void wt(T x) {
	if (x > 9) wt(x / 10);
	putchar(x % 10 + 48);
}
template <typename T>
void writeln(T x, char ch) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	wt(x);
	putchar(ch);
}
const int N = 3e5 + 5;
char s[N];
int r[N][2], l[N][2];
int main() {
    int T;
    readin(T);
    while (T --) {
        int n;
        readin(n);
        scanf("%s", s + 1);
        for (int i = 0; i <= n; i ++) {
            l[i][0] = l[i][1] = r[i][0] = r[i][1] = 0;
        }
        for (int i = n - 1; i >= 0; i --) {
            if (s[i + 1] == 'R') {
                r[i][0] = r[i + 1][1] + 1;
            }
            else r[i][1] = r[i + 1][0] + 1;
        }
        for (int i = 1; i <= n; i ++) {
            if (s[i] == 'L') {
                l[i][0] = l[i - 1][1] + 1;
            }
            else l[i][1] = l[i - 1][0] + 1;
        }
        for (int i = 0; i < n; i ++) writeln(l[i][0] + r[i][0] + 1, ' ');
        writeln(l[n][0] + r[n][0] + 1, '\n');
    }
	return 0;
}