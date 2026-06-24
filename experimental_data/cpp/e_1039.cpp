#include <bits/stdc++.h>
#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,sse4.2,avx,avx2,bmi,bmi2,popcnt,lzcnt,tune=native")
#endif
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define per(i, r, l) for (int i = r; i >= l; i --)
 
using namespace std;
 
typedef long long ll;
const int _ = 1e5 + 5;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
 
 
int n, maxW, Q;
int a[_], q[_];
int mx[_], mn[_], ans[_];
 
int main () {
    #ifdef LOCAL
        freopen("task.in", "r", stdin);
        freopen("task.out", "w", stdout);
    #endif
	n = read(), maxW = read(), Q = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, Q) {
		q[i] = read();
		q[i] = maxW - q[i];
		mx[i] = mn[i] = a[1];
	}
	rep(i, 2, n) {
		int t = a[i];
		rep(j, 1, Q) {
			mx[j] = max(mx[j], t), mn[j] = min(mn[j], t);
			if (mx[j] - mn[j] > q[j])
				mx[j] = mn[j] = t, ++ ans[j];
		}
	}
	rep(i, 1, Q) printf("%d\n", ans[i]);
	return 0;
}