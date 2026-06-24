#include<bits/stdc++.h>

typedef long long ll;

typedef unsigned long long ull;

#define rep(i, a, b) for(int i = (a); i <= (b); i ++)

#define per(i, a, b) for(int i = (a); i >= (b); i --)

#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)

using namespace std;



const int P = 998244353, Q = 13331;

inline int plu(int x, int y) {return x + y >= P ? x + y - P : x + y;}

inline int del(int x, int y) {return x - y <  0 ? x - y + P : x - y;}

inline void add(int &x, int y) {x = plu(x, y);}

inline void sub(int &x, int y) {x = del(x, y);}

inline int qpow(int a, int b) {int s = 1; for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) s = 1ll * s * a % P; return s;}



inline int read() {

	int x = 0, f = 1; char c = getchar();

	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();

	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();

	return x * f;

}



const int N = 2e5 + 10;

int n, q, f[N][2], g[N], p[N];

char str[N];



int calc(int l, int r) {

	int o = l & 1;

	return del(f[r][o], 1ll * f[l - 1][o] * p[g[r] - g[l - 1]] % P);

}



int main() {

	n = read();

	scanf("%s", str + 1);

	q = read();

	

	p[0] = 1; rep(i, 1, n) p[i] = 1ll * p[i - 1] * Q % P;

	rep(i, 1, n)

		if(str[i] == '1') f[i][0] = f[i - 1][0], f[i][1] = f[i - 1][1], g[i] = g[i - 1];

		else

			f[i][0] = plu(1ll * f[i - 1][0] * Q % P, (i & 1) ? 2 : 3), 

			f[i][1] = plu(1ll * f[i - 1][1] * Q % P, (i & 1) ? 3 : 2), 

			g[i] = g[i - 1] + 1;

	

	while(q --) {

		int x = read(), y = read(), len = read();

		int vx = calc(x, x + len - 1);

		int vy = calc(y, y + len - 1);

		puts(vx == vy ? "Yes" : "No");

	}

	return 0;

}