//#include <cstdio>
//#include <cstdint>
//#include <algorithm>
//using namespace std;
//const int N = 100005;
//int n, r[N], a[N], inv[N];
//struct Rand {
//	uint64_t now[64];
//	Rand() {
//		for (int i = 0; i < 64; i++) {
//			now[i] = 1ull << i;
//		}
//	}
//};
//Rand operator << (const Rand & a, int d) {
//	Rand b;
//	for (int i = 0; i < d; i++) {
//		b.now[i] = 0;
//	}
//	for (int i = d; i < 64; i++) {
//		b.now[i] = a.now[i - d];
//	}
//	return b;
//}
//Rand operator >> (const Rand & a, int d) {
//	Rand b;
//	for (int i = 64 - d; i < 64; i++) {
//		b.now[i] = 0;
//	}
//	for (int i = 0; i < 64 - d; i++) {
//		b.now[i] = a.now[i + d];
//	}
//	return b;
//}
//Rand operator ^= (Rand & a, const Rand & b) {
//	for (int i = 0; i < 64; i++) {
//		a.now[i] ^= b.now[i];
//	}
//	return a;
//}
//int lowbit(int x) {
//	return x & -x;
//}
//uint64_t f[114];
//int g[114], m;
//bool know[64];
//void print() {
//	for (int i = 0; i < m; i++) {
//		printf("%2d ", i);
//		for (int j = 0; j < 64; j++) {
//			printf("%llu", (f[i] >> j) & 1);
//			if (j % 8 == 7) {
//				printf(" ");
//			}
//		}
//		printf("%d\n", g[i]);
//	}
//	printf("----\n");
//}
//uint64_t x;
//void dfs(int u) {
//	if (u == -1) {
////		printf("x = %llu\n", x);
//	} else if (!know[u]) {
//		dfs(u - 1);
//		x ^= 1ull << u;
//		for (int i = 0; i < m; i++) {
//			if (((f[i] >> u) & 1) == 1) {
//				g[i] ^= 1;
//			}
//		}
//		dfs(u - 1);
//		x ^= 1ull << u;
//		for (int i = 0; i < m; i++) {
//			if (((f[i] >> u) & 1) == 1) {
//				g[i] ^= 1;
//			}
//		}
//	} else {
//		if (g[u] == 1) {
//			x ^= 1ull << u;
//		}
//		dfs(u - 1);
//	}
//}
//int main() {
//	freopen("in.txt", "r", stdin);
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &a[i]);
//		inv[a[i]] = i;
//	}
//	for (int i = n; i >= 1; i--) {
//		r[i] = inv[i];
//		swap(inv[i], inv[a[i]]);
//		swap(a[i], a[r[i]]);
//	}
//	Rand x;
//	for (int i = 1; i <= 50; i++) {
//		x ^= x << 13;
//		x ^= x >> 7;
//		x ^= x << 17;
//		for (int j = 0; (1 << j) < lowbit(i); j++) {
//			f[m] = x.now[j];
//			g[m] = ((r[i] - 1) >> j) & 1;
//			m++;
//		}
//	}
//	for (int i = 0, nowline = 0; i < 64; i++) {
//		int s = -1;
//		for (int j = nowline; j < m; j++) {
//			if (((f[j] >> i) & 1) == 1) {
//				s = j;
//				break;
//			}
//		}
//		if (s == -1) {
//			continue;
//		}
//		know[i] = true;
//		swap(f[s], f[nowline]);
//		swap(g[s], g[nowline]);
//		for (int j = 0; j < m; j++) {
//			if (nowline != j && ((f[j] >> i) & 1) == 1) {
//				f[j] ^= f[nowline];
//				g[j] ^= g[nowline];
//			}
//		}
//		nowline++;
//	}
//	print();
//	dfs(63);
//	return 0;
//}
///*
//1110011100110010101110000001000111001100010011010111001011000011
//*/
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200005;
ll val[N][3];
int p[3];
int ans[3][2];
int main() {
	int T;
	scanf("%d", &T);
	for (int n; T != 0; T--) {
		scanf("%d", &n);
		for (int j = 0; j < 3; j++) {
			for (int i = 1; i <= n; i++) {
				scanf("%lld", &val[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				val[i][j] += val[i - 1][j];
			}
		}
		ll tot = val[n][0];
		p[0] = 0;
		p[1] = 1;
		p[2] = 2;
		bool flag = true;
		do {
			int left = 1, right;
			for (int i = 0; i < 3; i++) {
				int x = p[i];
				right = left;
				while (right <= n) {
					if (val[right][x] - val[left - 1][x] >= (tot + 2) / 3) {
						break;
					}
					right++;
				}
				ans[x][0] = left;
				ans[x][1] = right;
				left = right + 1;
			}
			if (right <= n) {
				for (int i = 0; i < 3; i++) {
					printf("%d %d ", ans[i][0], ans[i][1]);
				}
				printf("\n");
				flag = false;
				break;
			}
		} while (next_permutation(p, p + 3));
		if (flag) {
			printf("-1\n");
		}
	}
	return 0;
}