#include<cstdio>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cstring>

#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define Set(a, b) memset(a, b, sizeof a)
#define Cpy(a, b) memcpy(a, b, sizeof a)
#define debug(x) cout << "------------- " << x << " --------------\n"

using namespace std;

int _x; bool _f; char _c;
inline int rd() {
	_x = 0, _f = 1, _c = getchar();
	for (; !isdigit(_c); _c = getchar()) if (_c == '-') _f = 0;
	for (; isdigit(_c); _c = getchar()) _x = _x * 10 + _c - '0';
	return _f ? _x : -_x;
}
template <typename T> inline void chkmax(T&x, T y) {if (x < y) x = y;}
template <typename T> inline void chkmin(T&x, T y) {if (x > y) x = y;}
//inline int dw(int x) {return x < P ? x : x - P;}
//inline int up(int x) {return x < 0 ? x + P ? x;}

const int N = 60, M = 2e4 + 10;
int n, m, k, pre[M];
int f[N][M];

inline int sum(int l, int r) {
	return pre[r] - pre[l - 1];
}

signed main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	n = rd(),m = rd(), k = rd();
	fox (j, 1, m) pre[j] = pre[j - 1] + rd();
	fox (j, 1, m - k + 1) f[1][j] = sum(j, j + k - 1);
	fox (i, 2, n) {
		fox (j, 1, m) pre[j] = pre[j - 1] + rd();
		int g = 0;
		fox (j, 1, m - 2 * k + 1) {
			chkmax(g, f[i - 1][j] + sum(j, j + k - 1));
			chkmax(f[i][j + k], g + sum(j + k, j + k * 2 - 1));
		}
		g = 0;
		for (int j = m - k + 1; j > k; --j) {
			chkmax(g, f[i - 1][j] + sum(j, j + k - 1));
			chkmax(f[i][j - k], g + sum(j - k, j - 1));
		}
		
		fox (j, 1, m - k + 1) {
			fox (o, max(1, j - k), min(m - k + 1, j + k - 1)) {
				chkmax(f[i][j], f[i - 1][o] + sum(min(o, j), max(o + k, j + k) - 1));
			}
		}
	}
	
	int ans = 0;
	fox (i, 1, m) chkmax(ans, f[n][i]);
	printf("%d\n", ans);
	return 0;
}