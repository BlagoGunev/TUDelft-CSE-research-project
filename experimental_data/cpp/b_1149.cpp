#include <stdio.h>
#include <string.h>
#include <algorithm>

char ch;
void read(int &x) {
	ch = getchar();
	while (ch <= 32) ch = getchar();
	x = 0;
	while (ch > 32) x = x * 10 + ch - 48, ch = getchar();
}

const int MAXN = 100005;
const int MAXLEN = 255;

char a[MAXN];
int nextpos[MAXN][26];

int a1[MAXLEN], a2[MAXLEN], a3[MAXLEN];

int f[MAXLEN][MAXLEN][MAXLEN];
int l1, l2, l3;

void add1(int c) {
	a1[++l1] = c;
	f[l1][0][0] = nextpos[f[l1 - 1][0][0]][c];
	
	for (int i = 1; i <= l2; i++) {
		f[l1][i][0] = std::min(nextpos[f[l1][i - 1][0]][a2[i]], nextpos[f[l1 - 1][i][0]][c]);
	}
	for (int i = 1; i <= l3; i++) {
		f[l1][0][i] = std::min(nextpos[f[l1][0][i - 1]][a3[i]], nextpos[f[l1 - 1][0][i]][c]);
	}
	
	for (int i = 1; i <= l2; i++) {
		for (int j = 1; j <= l3; j++) {
			int tmp = std::min(nextpos[f[l1][i - 1][j]][a2[i]], nextpos[f[l1][i][j - 1]][a3[j]]);
			f[l1][i][j] = std::min(tmp, nextpos[f[l1 - 1][i][j]][c]);
		}
	}
}

void add2(int c) {
	a2[++l2] = c;
	f[0][l2][0] = nextpos[f[0][l2 - 1][0]][c];
	
	for (int i = 1; i <= l1; i++) {
		f[i][l2][0] = std::min(nextpos[f[i - 1][l2][0]][a1[i]], nextpos[f[i][l2 - 1][0]][c]);
	}
	for (int i = 1; i <= l3; i++) {
		f[0][l2][i] = std::min(nextpos[f[0][l2][i - 1]][a3[i]], nextpos[f[0][l2 - 1][i]][c]);
	}
	
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l3; j++) {
			int tmp = std::min(nextpos[f[i - 1][l2][j]][a1[i]], nextpos[f[i][l2][j - 1]][a3[j]]);
			f[i][l2][j] = std::min(tmp, nextpos[f[i][l2 - 1][j]][c]);
		}
	}
}

void add3(int c) {
	a3[++l3] = c;
	f[0][0][l3] = nextpos[f[0][0][l3 - 1]][c];
	
	for (int i = 1; i <= l1; i++) {
		f[i][0][l3] = std::min(nextpos[f[i - 1][0][l3]][a1[i]], nextpos[f[i][0][l3 - 1]][c]);
	}
	for (int i = 1; i <= l2; i++) {
		f[0][i][l3] = std::min(nextpos[f[0][i - 1][l3]][a2[i]], nextpos[f[0][i][l3 - 1]][c]);
	}
	
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			int tmp = std::min(nextpos[f[i - 1][j][l3]][a1[i]], nextpos[f[i][j - 1][l3]][a2[j]]);
			f[i][j][l3] = std::min(tmp, nextpos[f[i][j][l3 - 1]][c]);
		}
	}
}

int main() {
	int n, q;
	read(n);
	read(q);
	ch = getchar();
	while (ch <= 32) ch = getchar();
	for (int i = 1; i <= n; i++) {
		a[i] = ch;
		ch = getchar();
	}
	for (int i = 0; i < 26; i++) {
		nextpos[n][i] = n + 1;
		nextpos[n + 1][i] = n + 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		memcpy(nextpos[i], nextpos[i + 1], 26 * sizeof(int));
		nextpos[i][(int) a[i + 1] - 'a'] = i + 1;
	}
	
	for (int i = 1; i <= q; i++) {
		char op, c;
		int id;
		op = getchar();
		while (op <= 32) op = getchar();
		if (op == '+') {
			read(id);
			c = getchar();
			while (c <= 32) c = getchar();
			c -= 'a';
			if (id == 1) add1(c);
			if (id == 2) add2(c);
			if (id == 3) add3(c);
		} else {
			read(id);
			if (id == 1) --l1;
			if (id == 2) --l2;
			if (id == 3) --l3;
		}
		puts(f[l1][l2][l3] <= n ? "YES" : "NO");
	}
}