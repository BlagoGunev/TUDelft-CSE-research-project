#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
 
using namespace std;

template <typename tn> void read (tn & a) {
	tn x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){ if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9'){ x = x * 10 + c - '0'; c = getchar(); }
	a = f == 1 ? x : -x;
}

const int MAXN = 200100; 
int n, k;
int r[MAXN], a[MAXN];
int ans[MAXN];

long long solve (long long x) {
	long long left = 0, right = n + 1;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (a[mid] >= x) right = mid; else left = mid;
	}
	return left;
}

int main() {
	read(n);
	read(k);
	for (int i = 1; i <= n; ++i) {
		read(r[i]);
		a[i] = r[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		ans[i] = solve(r[i]);
	}
	while (k--) {
		int x, y;
		read(x);
		read(y);
		if (r[x] > r[y]) {
			--ans[x];
		}
		if (r[x] < r[y]) {
			--ans[y];
		}
	}
	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0;
}