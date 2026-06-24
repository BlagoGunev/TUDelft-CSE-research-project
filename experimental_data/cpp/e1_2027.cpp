#include<iostream>
#include<cstdio>
#include<fstream>
#define fopen(x, y) freopen(x".in", "r", stdin); freopen(y".out", "w", stdout);
#define int long long
#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif

using namespace std;

int n, a[10005], x[10005], f[45][45], vis[45];

inline int highbit(int x) {
	if(x == 0) return 0;
	int res = 1;
	while((res << 1) <= x) res <<= 1;
	return res;
}
inline int lowbit(int x) {
	return x & -x;
}

inline int hb2(int x) {
	return highbit(x ^ highbit(x));
}

int calc(int a, int x) {
	while(highbit(x) > highbit(a)) x ^= highbit(x);
	int xum = 0;
	if(x <= a) {
		xum ^= __builtin_popcountll(x);
	}
	else if(hb2(x) == hb2(a)) {
		int idf = x & ~a;
//		cout << idf << endl;
		if(idf == lowbit(x)) xum ^= 0;
		else xum ^= __builtin_popcountll(x);
	}
	else {
		if((highbit(x) | lowbit(x)) <= a) xum ^= __builtin_popcountll(x); 
		else xum ^= (__builtin_popcountll(x) - 1) ^ 1;
	} 
	return xum;
}

void work() {
	cin >> n;
	int xum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
//		int xum0 = xum
		xum ^= calc(a[i], x[i]);
//		cout << xum << '\n';
//		else xum ^= __builtin_popcountll(x[i]);
//		if(x[i] <= a[i]) {
//			xum ^= __builtin_popcountll(x[i]);
//			continue;
//		}
		
//		for(int j = 0; j < 31; j++) f[j][j] = 0;
//		f[31][31] = 0;
//		for(int len = 1; len <= 31; len++) {
//			for(int l = 0; l < 31; l++) {
//				for(int r = l + len; r <= 31; r++) {
//					for(int k = 0; k <= r - l + 3; k++) vis[k] = 0;
//					for(int k = l; k <= r; k++) {
//						int p = ((x[i] >> l) << l) ^ ((x[i] >> k) << k);
//						if(p <= a[i] && p > 0) vis[f[k][r]] = 1;
//						p = ((x[i] >> k) << k) ^ ((x[i] >> r) << r);
//						if(p <= a[i] && p > 0) vis[f[l][k]] = 1;
//					}
//					for(int k = 0; k < 31; k++) if(!vis[k]) {
//						f[l][r] = k;
//						break;
//					}
//				}
//			}
//		}
//		xum ^= f[0][31];
//		cout << __builtin_popcountll(x[i]) << ' ';
//		cout << (xum ^ xum0) << ' ';
	}
	cout << ((xum == 0) ? "Bob\n" : "Alice\n");
}

signed main() {
//	freopen("2.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
//	for(int i = 1; i <= 255; i++) {
//		for(int j = 1; j <= 255; j++) {
//			cout << i << ' ' << j << ' ' << calc(i, j) << '\n';
//		}
//	}
//	cout << calc(241, 248) << endl;
	int _ = 1;
	cin >> _;
	while(_--) work();
}