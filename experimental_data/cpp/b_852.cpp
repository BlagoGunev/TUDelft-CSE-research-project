#include <bits/stdc++.h>

template <class T>
void scan(T &x) {
	register char ch; x = 0;
	for (ch = getchar(); ~ch && (ch < '0' || ch > '9'); ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

typedef long long ll;
const int Mod = 1e9 + 7;

struct Matrix {
	int mat[105][105], r, c;
	
	Matrix() {
		memset(mat, 0, sizeof mat);
		r = c = 0;
	}
	
	Matrix operator * (const Matrix &rhs) const {
		Matrix res; res.r = r; res.c = rhs.c;
		for (int i = 0; i < res.r; ++i)
			for (int j = 0; j < res.c; ++j) {
				ll tmp = 0;
				for (int k = 0; k < c; ++k)
					tmp = (tmp + 1ll * mat[i][k] * rhs.mat[k][j]) % Mod;
				res.mat[i][j] = tmp;
			}
		return res;
	}
	
	void unit(int x) {
		memset(mat, 0, sizeof mat);
		r = c = x;
		for (int i = 0; i < x; ++i)
			mat[i][i] = 1;
	}
	
	void print() {
		puts("--------");
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				printf("%d%c", mat[i][j], " \n"[j == c - 1]);
		puts("--------");
	}
} A, B;

Matrix qpow(Matrix a, int x) {
	Matrix res; res.unit(a.r);
	for (; x; x >>= 1) {
		if (x & 1) res = res * a;
		a = a * a;
	}
	return res;
}

int n, l, m;
int a[105], b[105], c[105], d[1000005];

int ans[105];

int main() {
//	freopen("in.txt", "r", stdin);
	
	scan(n); scan(l); scan(m);
	for (int x, i = 1; i <= n; ++i) {
		scan(x); ++a[x % m];
	}
	for (int i = 1; i <= n; ++i) {
		scan(d[i]); ++b[d[i] % m];
	}
	for (int x, i = 1; i <= n; ++i) {
		scan(x); d[i] += x;
		++c[d[i] % m];
	}
	
	B.r = m, B.c = 1;
	
	for (int i = 0; i < m; ++i)
		B.mat[i][0] = a[i];
	
	A.r = A.c = m;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			A.mat[(i + j) % m][i] = b[j];
	
	A = qpow(A, l - 2);
	
	B = A * B;
	
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			ans[(i + j) % m] = (ans[(i + j) % m] + 1ll * B.mat[i][0] * c[j]) % Mod;
	
	printf("%d\n", ans[0]);
	
	return 0;
}