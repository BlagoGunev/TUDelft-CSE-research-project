#include <cmath>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <algorithm>



using namespace std;



/* fast read */



int fastIn() {

	int aa, bb, ch;

	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');

	ch == '-' ? (bb = 1, aa = 0) : (bb = 0, aa = ch - 48);

	while (ch = getchar(), ch >= '0' && ch <= '9') aa = (aa << 1) + (aa << 3) + ch - 48;

	return bb ? -aa : aa;

}



const int mod = 1e9 + 7;



char s[100010], t[100010];

int fail[100010], r[100010];

long long sum[100010], f[100010];



int main() {

	scanf("%s%s", s + 1, t + 1);

	int n = strlen(s + 1), m = strlen(t + 1);

	int j = 0;

	fail[1] = 0;

	for (int i = 2; i <= m; ++ i) {

		while (j && t[j + 1] != t[i]) j = fail[j];

		if (t[j + 1] == t[i]) ++ j;

		fail[i] = j;

	}

	j = 0;

	for (int i = 1; i <= n; ++ i) {

		while (j && t[j + 1] != s[i]) j = fail[j];

		if (t[j + 1] == s[i]) ++ j;

		if (j == m) r[i] = i - m + 1;

	}

	for (int i = 1; i <= n; ++ i) if (!r[i]) r[i] = r[i - 1];

	//for (int i = 1; i <= n; ++ i) printf("%d ", r[i]);

	for (int i = 1; i <= n; ++ i) {

		f[i] = f[i - 1];

		if (r[i]) {

			f[i] = (f[i] + sum[r[i] - 1] + r[i]) % mod;

		}

		sum[i] = (sum[i - 1] + f[i]) % mod;

	}

	cout << f[n];

	return 0;

}