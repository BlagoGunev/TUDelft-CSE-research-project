/* https://www.cnblogs.com/aaaaawa/p/16538468.html */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N	100000
#define L	18	/* L = ceil(log2((N + 1) * 2)) */
#define N_	(1 << L)

unsigned int X;

int rand_() {
	return (X *= 3) >> 1;
}

int md;

long long power(long long a, int k) {
	long long p = 1;

	while (k) {
		if (k & 1)
			p = p * a % md;
		a = a * a % md;
		k >>= 1;
	}
	return p;
}

int test(int a) {
	int n = md - 1, p;

	for (p = 2; p <= n / p; p++)
		if (n % p == 0) {
			if (power(a, (md - 1) / p) == 1)
				return 0;
			while (n % p == 0)
				n /= p;
		}
	if (n > 1 && power(a, (md - 1) / n) == 1)
		return 0;
	return 1;
}

int primroot(int md) {
	while (1) {
		int a = rand_() % (md - 2) + 2;

		if (test(a))
			return a;
	}
}

int vv[N + 1], ff[N + 1], gg[N + 1], n;
int vv_[L + 1], *wwu[L + 1], *wwv[L + 1];

void init() {
	struct timeval tv;
	int i, l, u, v;

	gettimeofday(&tv, NULL);
	X = tv.tv_sec ^ tv.tv_usec | 1;
	ff[0] = gg[0] = 1;
	for (i = 1; i <= n; i++) {
		vv[i] = i == 1 ? 1 : (long long) vv[i - md % i] * (md / i + 1) % md;
		ff[i] = (long long) ff[i - 1] * i % md;
		gg[i] = (long long) gg[i - 1] * vv[i] % md;
	}
	u = power(primroot(md), md - 1 >> L), v = power(u, md - 2);
	for (l = L; l > 0; l--) {
		int n = 1 << l, m = n >> 1, i;

		vv_[l] = power(n, md - 2);
		wwu[l] = (int *) malloc(m * sizeof *wwu[l]);
		wwv[l] = (int *) malloc(m * sizeof *wwv[l]);
		wwu[l][0] = wwv[l][0] = 1;
		for (i = 1; i < m; i++) {
			wwu[l][i] = (long long) wwu[l][i - 1] * u % md;
			wwv[l][i] = (long long) wwv[l][i - 1] * v % md;
		}
		u = (long long) u * u % md, v = (long long) v * v % md;
	}
	vv_[0] = 1;
}

void ntt_(int *aa, int l, int inverse) {
	if (l) {
		int n = 1 << l, m = n >> 1, *ww = inverse ? wwv[l] : wwu[l], i, j;

		ntt_(aa, l - 1, inverse), ntt_(aa + m, l - 1, inverse);
		for (i = 0; (j = i + m) < n; i++) {
			int a = aa[i], b = (long long) aa[j] * ww[i] % md;

			if ((aa[i] = a + b) >= md)
				aa[i] -= md;
			if ((aa[j] = a - b) < 0)
				aa[j] += md;
		}
	}
}

void ntt(int *aa, int l, int inverse) {
	int n = 1 << l, i, j;

	for (i = 0, j = 1; j < n; j++) {
		int b = n >> 1, tmp;

		while ((i ^= b) < b)
			b >>= 1;
		if (i < j)
			tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
	}
	ntt_(aa, l, inverse);
}

void multiply(int *aa, int *bb, int *cc, int n) {
	static int aa_[N_], bb_[N_];
	int n_, l, i;

	l = 0;
	while (1 << l < n * 2)
		l++;
	n_ = 1 << l;
	for (i = 0; i < n_; i++) {
		aa_[i] = i < n ? aa[i] : 0;
		bb_[i] = i < n ? bb[i] : 0;
	}
	ntt(aa_, l, 0), ntt(bb_, l, 0);
	for (i = 0; i < n_; i++)
		aa_[i] = (long long) aa_[i] * bb_[i] % md;
	ntt(aa_, l, 1);
	for (i = 0; i < n; i++)
		cc[i] = (long long) aa_[i] * vv_[l] % md;
}

void inv(int *aa, int *bb, int n) {
	static int aa_[N_], bb_[N_];
	int n_, m, l, i;

	if (n == 1) {
		bb[0] = 1;
		return;
	}
	m = (n + 1) / 2;
	inv(aa, bb, m);
	l = 0;
	while (1 << l < n * 2)
		l++;
	n_ = 1 << l;
	for (i = 0; i < n_; i++) {
		aa_[i] = i < n ? aa[i] : 0;
		bb_[i] = i < m ? bb[i] : 0;
	}
	ntt(aa_, l, 0), ntt(bb_, l, 0);
	for (i = 0; i < n_; i++)
		aa_[i] = bb_[i] * (2 - (long long) aa_[i] * bb_[i] % md + md) % md;
	ntt(aa_, l, 1);
	for (i = 0; i < n; i++)
		bb[i] = (long long) aa_[i] * vv_[l] % md;
}

void log_(int *aa, int *bb, int n) {
	static int pp[N + 1], qq[N + 1];
	int i;

	for (i = 0; i < n; i++)
		pp[i] = i + 1 == n ? 0 : (long long) aa[i + 1] * (i + 1) % md;
	inv(aa, qq, n);
	multiply(pp, qq, bb, n);
	for (i = n - 1; i >= 0; i--)
		bb[i] = i == 0 ? 0 : (long long) bb[i - 1] * vv[i] % md;
}

void exp_(int *aa, int *bb, int n) {
	static int aa_[N + 1], bb_[N + 1], cc_[N + 1];
	int m, i;

	if (n == 1) {
		bb[0] = 1;
		return;
	}
	m = (n + 1) / 2;
	exp_(aa, bb, m);
	for (i = 0; i < n; i++)
		bb_[i] = i < m ? bb[i] : 0;
	log_(bb_, cc_, n);
	for (i = 0; i < n; i++)
		aa_[i] = (aa[i] - cc_[i] + md) % md;
	aa_[0] = (aa_[0] + 1) % md;
	multiply(aa_, bb_, bb, n);
}

void tree(int *aa, int n) {
	static int aa_[N + 1], bb_[N + 1], cc_[N + 1], dd_[N + 1], pp_[N + 1], qq_[N + 1], rr_[N + 1], ss_[N + 1];
	int m, i;

	if (n == 1) {
		aa[0] = 0;
		return;
	}
	m = (n + 1) / 2;
	tree(aa, m);
	for (i = 0; i < n; i++)
		aa_[i] = i < m ? aa[i] : 0;
	exp_(aa_, bb_, n);
	for (i = n - 1; i >= 0; i--)
		bb_[i] = i == 0 ? 0 : bb_[i - 1];
	for (i = 0; i < n; i++)
		cc_[i] = (aa_[i] + bb_[i]) % md;
	exp_(cc_, dd_, n);
	multiply(cc_, dd_, pp_, n);
	for (i = n - 1; i >= 0; i--)
		pp_[i] = i == 0 ? 0 : pp_[i - 1];
	for (i = n - 1; i >= 0; i--)
		pp_[i] = (aa_[i] - pp_[i] + md) % md;
	for (i = 0; i < n; i++)
		rr_[i] = bb_[i], ss_[i] = cc_[i];
	rr_[0] = (rr_[0] + 1) % md;
	ss_[0] = (ss_[0] + 1) % md;
	multiply(rr_, ss_, rr_, n);
	multiply(rr_, dd_, rr_, n);
	for (i = n - 1; i >= 0; i--)
		rr_[i] = i == 0 ? 1 : (md - rr_[i - 1]) % md;
	inv(rr_, qq_, n);
	multiply(pp_, qq_, bb_, n);
	for (i = 0; i < n; i++)
		aa[i] = (aa_[i] - bb_[i] + md) % md;
}

int main() {
	static int aa[N + 1], bb[N + 1], cc[N + 1], dd[N + 1], ee[N + 1], yy[N + 1], zz[N + 1];
	int i;

	scanf("%d%d", &n, &md), init();
	tree(aa, n + 1);
	for (i = 0; i <= n; i++)
		yy[i] = (md - aa[i]) % md;
	exp_(aa, bb, n + 1);
	for (i = n; i >= 0; i--)
		bb[i] = i == 0 ? 0 : bb[i - 1];
	for (i = 0; i <= n; i++)
		cc[i] = (aa[i] + bb[i]) % md;
	exp_(cc, dd, n + 1);
	for (i = n; i >= 0; i--)
		dd[i] = i == 0 ? 0 : dd[i - 1];
	for (i = 0; i <= n; i++)
		aa[i] = (aa[i] + dd[i]) % md;
	for (i = 0; i <= n; i++)
		cc[i] = i == 0 ? 1 : (md - aa[i]) % md;
	inv(cc, ee, n + 1);
	multiply(ee, aa, cc, n + 1);
	multiply(cc, bb, cc, n + 1);
	for (i = 0; i <= n; i++)
		cc[i] = i == 0 ? 1 : (md - cc[i]) % md;
	log_(cc, cc, n + 1);
	for (i = 0; i <= n; i++)
		yy[i] = (yy[i] - cc[i] + md) % md;
	for (i = 0; i <= n; i++)
		aa[i] = i == 0 ? 1 : (md - aa[i]) % md;
	log_(aa, aa, n + 1);
	for (i = 0; i <= n; i++)
		yy[i] = (yy[i] - aa[i] + md) % md;
	for (i = 0; i <= n; i++)
		dd[i] = i == 0 ? 1 : (md - dd[i]) % md;
	log_(dd, dd, n + 1);
	for (i = 0; i <= n; i++)
		yy[i] = (yy[i] + dd[i]) % md;
	exp_(yy, zz, n + 1);
	for (i = 1; i <= n; i++)
		printf("%lld\n", (long long) zz[i] * ff[i] % md);
	return 0;
}