#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') { if(ch == '-') f = -1; ch = getchar(); }
	do x = x * 10 + ch - 48, ch = getchar(); while(ch >= '0' && ch <= '9');
	return x * f;
}

int n,a[51];

int main() {
	int t = read();
	while(t--) {
		int n = read();
		for(int i = 1;i <= n;i++) a[i] = read();
		int ans = 0;
		for(int i = 1;i < n;i++) {
			int x = a[i], y = a[i + 1];
			if(x > y) std::swap(x,y);
			while(y > x * 2) x = x * 2, ans++;
		}
		std::printf("%d\n",ans);
	}
	return 0;
}