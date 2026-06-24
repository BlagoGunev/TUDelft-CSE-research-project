#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <algorithm>
#define N 123
template <typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) { if (c == '-')	flag = true; c = getchar(); }
	while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
int h[N];
int lk[N];
int stk[N], stop;
int main() {
	int _; read(_);
	while (_--) {
		stop = 0;
		int n; read(n); for (int i = 1; i <= n; ++i)	read(h[i]);
		for (int i = 1; i <= n; ++i) {
			read(lk[i]);
			if (!lk[i])	stk[++stop] = h[i];
		}
		sort(stk + 1, stk + 1 + stop);
		for (int i = 1; i <= n; ++i) {
			if (lk[i])	printf("%d ", h[i]);
			else	printf("%d ", stk[stop--]);
		}
		puts("");
	}
	return 0;
}