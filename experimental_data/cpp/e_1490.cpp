#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
const int N = 200001;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') { if(ch == '-') f = -1; ch = getchar(); }
	do x = x * 10 + ch - 48, ch = getchar(); while(ch >= '0' && ch <= '9');
	return x * f;
}

int n,a[N],map[N],can[N];

bool cmp(int x,int y) { return a[x] < a[y]; }

bool Judge(int x) {
	ll token = 0;
	for(int i = 1;i <= x;i++) token += a[map[i]];
	for(int i = x + 1;i <= n;i++) {
		if(token < a[map[i]]) return false;
		token += a[map[i]];
	}
	return true;
}

void Solve() {
	n = read();
	for(int i = 1;i <= n;i++) a[i] = read(), map[i] = i;
	std::sort(map + 1,map + 1 + n,cmp);
	int l = 1, r = n, m, ans;
	while(l <= r) {
		m = (l + r) >> 1;
		if(Judge(m)) ans = m, r = m - 1;
		else l = m + 1;
	}
	std::printf("%d\n",n - ans + 1);
	for(int i = 1;i <= n;i++) can[i] = false;
	for(int i = ans;i <= n;i++) can[map[i]] = true;
	for(int i = 1;i <= n;i++) if(can[i]) std::printf("%d ",i);
	std::puts("");
	return;
}

int main() {
	int t = read();
	while(t--) Solve();
	return 0;
}