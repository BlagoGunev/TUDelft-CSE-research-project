#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N	100000
#define N1	100
#define L	18	/* L = ceil(log2(N * 2 + 1)) */
#define N_	(1 << L)
#define MD	998244353

int abs_(int a) { return a > 0 ? a : -a; }
int max(int a, int b) { return a > b ? a : b; }

int pp2[N + 1], vv[N + 1], ff[N + 1], gg[N + 1], ww[N + 1], ww_[N + 1];
int *wwu[L + 1], *wwv[L + 1], vv_[L + 1];

int choose(int n, int k) {
	return k < 0 || k > n ? 0 : (long long) ff[n] * gg[k] % MD * gg[n - k] % MD;
}

long long power(long long a, int k) {
	long long p = 1;

	while (k) {
		if (k & 1)
			p = p * a % MD;
		a = a * a % MD;
		k >>= 1;
	}
	return p;
}

void ntt_(int *aa, int l, int inverse) {
	if (l) {
		int n = 1 << l, m = n >> 1, *ww = inverse ? wwv[l] : wwu[l], i, j;

		ntt_(aa, l - 1, inverse), ntt_(aa + m, l - 1, inverse);
		for (i = 0; (j = i + m) < n; i++) {
			int a = aa[i], b = (long long) aa[j] * ww[i] % MD;

			if ((aa[i] = a + b) >= MD)
				aa[i] -= MD;
			if ((aa[j] = a - b) < 0)
				aa[j] += MD;
		}
	}
}

void ntt(int *aa, int l, int inverse) {
	int n, m, i, j, tmp;

	n = 1 << l;
	for (i = 0, j = 1; j < n; j++) {
		for (m = n >> 1; ((i ^= m) & m) == 0; m >>= 1)
			;
		if (i < j)
			tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
	}
	ntt_(aa, l, inverse);
}

void multiply(int *aa, int n, int *bb, int m) {
	static int aa_[N_], bb_[N_];
	int n_, l, i;

	l = 0;
	while (1 << l < n + m - 1)
		l++;
	n_ = 1 << l;
	for (i = 0; i < n_; i++) {
		aa_[i] = i < n ? aa[i] : 0;
		bb_[i] = i < m ? bb[i] : 0;
	}
	ntt(aa_, l, 0), ntt(bb_, l, 0);
	for (i = 0; i < n_; i++)
		aa_[i] = (long long) aa_[i] * bb_[i] % MD;
	ntt(aa_, l, 1);
	for (i = 0; i < n_; i++)
		aa_[i] = (long long) aa_[i] * vv_[l] % MD;
	memcpy(aa, aa_, (n + m - 1) * sizeof *aa_);
}

void dc(int *aa, int *ww, int n) {
	static int aa1[N * 2 + 1];
	int *aa_, m, i, d;

	if (n == 1) {
		ww[0] = aa[0];
		return;
	}
	m = n / 2;
	aa_ = (int *) malloc((n - m) * sizeof *aa_);
	for (i = 0; i < m; i++)
		aa_[i] = aa[i];
	dc(aa_, ww, m);
	memset(aa1, 0, (m * 2 + 1) * sizeof *aa1);
	for (d = -m; d <= m; d += 2)
		aa1[m + d] = choose(m, (m + d) / 2);
	multiply(aa1, m * 2 + 1, aa, n);
	memset(aa_, 0, (n - m) * sizeof *aa_);
	for (i = 0; i <= n + m * 2; i++) {
		d = abs_(i - m);
		if (d < n - m)
			aa_[d] = (aa_[d] + aa1[i]) % MD;
	}
	dc(aa_, ww + m, n - m);
	free(aa_);
}

void init(int mode, int print) {
	int n, m, i, l, u, v;

	pp2[0] = 1, ff[0] = gg[0] = 1;
	for (n = 1; n <= N; n++) {
		pp2[n] = pp2[n - 1] * 2 % MD;
		vv[n] = n == 1 ? 1 : (long long) vv[n - MD % n] * (MD / n + 1) % MD;
		ff[n] = (long long) ff[n - 1] * n % MD;
		gg[n] = (long long) gg[n - 1] * vv[n] % MD;
	}
	u = power(3, MD - 1 >> L), v = power(u, MD - 2);
	for (l = L; l > 0; l--) {
		n = 1 << l, m = n >> 1;
		wwu[l] = (int *) malloc(m * sizeof *wwu[l]);
		wwv[l] = (int *) malloc(m * sizeof *wwv[l]);
		vv_[l] = power(n, MD - 2);
		wwu[l][0] = wwv[l][0] = 1;
		for (i = 1; i < m; i++) {
			wwu[l][i] = (long long) wwu[l][i - 1] * u % MD;
			wwv[l][i] = (long long) wwv[l][i - 1] * v % MD;
		}
		u = (long long) u * u % MD;
		v = (long long) v * v % MD;
	}
	vv_[0] = 1;
	for (n = 0; n <= N; n++)
		ww[n] = choose(n, n / 2);
	if (mode == 0) {
		static int dp[N1 + 1][N1 + 1], dq[N1 + 1][N1 + 1];
		int d, d_, q, q_;

		ww_[0] = 1;
		dp[0][0] = 1;
		for (n = 1; n <= N1; n++) {
			for (d = 0; d <= n; d++)
				memset(dq[d], 0, (n - d + 1) * sizeof *dq[d]);
			for (d = 0; d < n; d++)
				for (q = 0; d + q < n; q++) {
					int x = dp[d][q];

					if (x == 0)
						continue;
					d_ = d + 1, q_ = max(q - 1, 0);
					dq[d_][q_] = (dq[d_][q_] + x) % MD;
					if (d > 0) {
						d_ = d - 1, q_ = q + 1;
						dq[d_][q_] = (dq[d_][q_] + x) % MD;
					}
				}
			for (d = 0; d <= n; d++)
				memcpy(dp[d], dq[d], (n - d + 1) * sizeof *dq[d]);
			for (d = 0; d <= n; d++)
				ww_[n] = (ww_[n] + dp[d][0]) % MD;
		}
	} else if (mode == 1) {
		int n, d, k, x;

		for (n = 0; n <= N1; n++) {
			ww_[n] = 0;
			for (d = n % 2; d <= n; d += 2) {
				x = 0;
				for (k = 0; (d + 2) * (k * 2 + 1) - 2 <= n; k++) {
					x = (x + choose(n, (n + (d + 2) * (k * 2 + 1) - 2) / 2)) % MD;
					x = (x - choose(n, (n + (d + 2) * (k * 2 + 1)) / 2) * 2) % MD;
					x = (x + choose(n, (n + (d + 2) * (k * 2 + 1) + 2) / 2)) % MD;
				}
				if (x < 0)
					x += MD;
				ww_[n] = (ww_[n] + x) % MD;
			}
		}
	} else {
		static int aa[N + 1];
		int d, d_, k;

		for (d = 0; d <= N; d++)
			for (k = 0; (d_ = (d + 2) * (k * 2 + 1) - 2) <= N; k++) {
				aa[d_]++;
				if (d_ + 2 <= N)
					aa[d_ + 2] -= 2;
				if (d_ + 4 <= N)
					aa[d_ + 4]++;
			}
		for (d = 0; d <= N; d++)
			if (aa[d] < 0)
				aa[d] += MD;
		dc(aa, ww_, N + 1);
	}
	if (print) {
		for (n = 0; n <= N1; n++)
			printf("%d ", ww_[n]);
		printf("\n");
	}
}

void dc_(char *cc, int *dp, int n) {
	static int aa[N * 2], bb[N * 2];
	int m, i, d;

	if (n == 1) {
		if (cc[0] == '1')
			dp[0] = 0;
		return;
	}
	m = n / 2;
	dc_(cc, dp, m);
	for (i = 0; i < m; i++)
		aa[i] = dp[i];
	for (d = 1; d < n; d++)
		bb[d] = (MD - ww_[d - 1]) % MD;
	multiply(aa, m, bb, n);
	for (i = m; i < n; i++)
		dp[i] = (dp[i] + aa[i]) % MD;
	dc_(cc + m, dp + m, n - m);
}

int solve(char *cc, int n) {
	static int dp[N];
	int i, ans;

	for (i = 0; i < n; i++)
		dp[i] = cc[i] == '0' ? ww[i] : 0;
	dc_(cc, dp, n);
	ans = 0;
	for (i = 0; i < n; i++)
		if (cc[i] == '0')
			ans = (ans + (long long) dp[i] * ww[n - 1 - i]) % MD;
	return ans;
}

int main() {
	static char cc[N + 1];
	int n, i, ans;

#if 0
	init(0, 1);
	init(1, 1);
	init(2, 1);
#else
	init(2, 0);
#endif
	scanf("%d%s", &n, cc);
	ans = pp2[n];
	ans = (ans - solve(cc, n) + MD) % MD;
	for (i = 0; i < n; i++)
		cc[i] = cc[i] == '0' ? '1' : '0';
	ans = (ans - solve(cc, n) + MD) % MD;
	printf("%d\n", ans);
	return 0;
}