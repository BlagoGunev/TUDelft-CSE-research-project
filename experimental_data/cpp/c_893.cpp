#include <bits/stdc++.h>
using namespace std;
inline void R(int &v) {
	static char ch;
	v = 0;
	bool p = 0;
	do {
		ch = getchar();
		if (ch == '-') p = 1;
	} while (!isdigit(ch));
	while (isdigit(ch)) {
		v = (v + (v << 2) << 1) + (ch^'0');
		ch = getchar();
	}
	if (p) v = -v;
}
inline void R(long long &v) {
	static char ch;
	v = 0;
	bool p = 0;
	do {
		ch = getchar();
		if (ch == '-') p = 1;
	} while (!isdigit(ch));
	while (isdigit(ch)) {
		v = (v + (v << 2) << 1) + (ch^'0');
		ch = getchar();
	}
	if (p) v = -v;
}
inline void R(double &v) {
	static char ch;
	v = 0;
	bool p = 0;
	do {
		ch = getchar();
		if (ch == '-') p = 1;
	} while (!isdigit(ch));
	while (isdigit(ch)) {
		v = v * 10 + (ch^'0');
		ch = getchar();
	}
	if (p) v = -v;
}
int n, m;
int fa[100005], c[100005];
int zhi[100005];
std::vector<int> q[100005];
inline int getfather(int x) {
	return x == fa[x] ? x : fa[x] = getfather(fa[x]);
}
int main() {
	R(n), R(m);
	for (int i = 1; i <= n; ++i) {
		R(c[i]);
		fa[i] = i;
		zhi[i] = c[i];
	}
	int x, y, fx, fy;
	for (int i = 1; i <= m; ++i) {
		R(x), R(y);
		fx = getfather(x), fy = getfather(y);
		if (fx != fy) {
			fa[fx] = fy;
			zhi[fy] = min(zhi[fy], zhi[fx]);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		fx = getfather(i);
		if (fx == i) {
			ans += zhi[fx];
		}
	}
	cout << ans;
	return 0;
}