#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 200005;

int n;
LL ans;

struct _point {
	int x, y;

	bool operator == (const _point &a) const {
		return x == a.x && y == a.y;
	}
} p[maxn];

inline int iread() {
	int f = 1, x = 0; char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) f = ch == '-' ? -1 : 1;
	for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	return f * x;
}

inline bool cmp1(_point a, _point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

inline bool cmp2(_point a, _point b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int main() {
	n = iread();	
	for(int i = 1; i <= n; i++) p[i].x = iread(), p[i].y = iread();

	sort(p + 1, p + 1 + n, cmp1);
	for(int i = 1; i <= n; ) {
		int cnt = 0;
		for(int x = p[i].x; p[i].x == x && i <= n; i++) cnt++;
		ans += (LL)cnt * (cnt - 1) >> 1LL;
	}

	sort(p + 1, p + 1 + n, cmp2);
	for(int i = 1; i <= n; ) {
		int cnt = 0;
		for(int y = p[i].y; p[i].y == y && i <= n; i++) cnt++;
		ans += (LL)cnt * (cnt - 1) >> 1LL;
	}

	for(int i = 2; i <= n; i++) {
		int cnt = 0;
		for(; p[i] == p[i - 1] && i <= n; i++) cnt++;
		ans -= (LL)cnt * (cnt + 1) >> 1LL;
	}

	printf("%I64d\n", ans);
	return 0;
}