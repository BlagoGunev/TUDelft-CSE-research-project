/* https://acm.timus.ru/problem.aspx?space=1&num=1557 */

#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define N	500000

#define M	500000

#define LN	19	/* LN = ceil(log2(N + 1)) */

#define N_	(1 + M * (LN + 1) * 2)



int *eh[N], eo[N], *ej[N], eo_[N], n;

int uu[M], vv[M], m;



void append(int **ej, int *eo, int i, int j) {

	int o = eo[i]++;



	if (o >= 2 && (o & o - 1) == 0)

		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);

	ej[i][o] = j;

}



int ll[N_], rr[N_], cc[N_], _;



int update(int t, int l, int r, int i) {

	int t_ = _++;



	ll[t_] = ll[t], rr[t_] = rr[t], cc[t_] = cc[t] + 1;

	if (r - l > 1) {

		int m = (l + r) / 2;



		if (i < m)

			ll[t_] = update(ll[t_], l, m, i);

		else

			rr[t_] = update(rr[t_], m, r, i);

	}

	return t_;

}



int query(int t, int l, int r, int ql, int qr) {

	int m;



	if (qr <= l || r <= ql || t == 0)

		return 0;

	if (ql <= l && r <= qr)

		return cc[t];

	m = (l + r) / 2;

	return query(ll[t], l, m, ql, qr) + query(rr[t], m, r, ql, qr);

}



int ff[N], ff_[N], pp[N], pp_[N], ta[N], tb[N], ii[N], kk[N], kk_[N], ttp[N], ttq[N], time;



void dfs1(int f, int p, int i) {

	int o;



	ff[i] = f, pp[i] = p, ii[ta[i] = time++] = i, kk[i] = 0;

	for (o = eo[i]; o--; ) {

		int h = eh[i][o], j = i ^ uu[h] ^ vv[h];



		if (j != p) {

			if (ta[j] == -1) {

				dfs1(h, i, j);

				kk[i] += kk[j];

			} else

				kk[i] += ta[j] < ta[i] ? 1 : -1;

		}

	}

	tb[i] = time;

}



int find(int i) {

	return ff_[i] == -1 ? i : (pp_[i] = find(pp_[i]));

}



int count(int i, int j) {

	return (ta[j] == 0 ? 0 : query(ttp[ta[j] - 1], 0, n, ta[i], tb[i])) + (tb[j] == n ? 0 : query(ttq[tb[j]], 0, n, ta[i], tb[i]));

}



int count_(int i, int j) {

	return kk_[i] + kk_[j] - count(i, j) * 2;

}



int ans, h1_, h2_;



void solve(int *jj, int l, int r, int l_, int r_) {

	int i, i_, j, k, k_;



	if (l > r)

		return;

	j = (l + r) / 2;

	k_ = -1, i_ = -1;

	for (i = l_; i <= r_; i++)

		if (i < j) {

			k = count_(jj[i], jj[j]);

			if (k_ < k)

				k_ = k, i_ = i;

		}

	if (ans < k_)

		ans = k_, h1_ = ff[jj[i_]], h2_ = ff[jj[j]];

	solve(jj, l, j - 1, l_, i_), solve(jj, j + 1, r, i_, r_);

}



void dfs2(int i) {

	static int jj[N];

	int o, cnt;



	for (o = eo[i]; o--; ) {

		int h = eh[i][o], j = i ^ uu[h] ^ vv[h];



		if (pp[j] == i)

			dfs2(j);

		else if (ta[j] > ta[i]) {

			cnt = 0;

			while (1) {

				j = find(j);

				if (ta[j] <= ta[i])

					break;

				ff_[j] = h;

				if (cnt && kk[jj[cnt - 1]] != kk[j])

					solve(jj, 1, cnt - 1, 0, cnt - 1), cnt = 0;

				jj[cnt++] = j;

			}

			if (cnt)

				solve(jj, 1, cnt - 1, 0, cnt - 1);

		}

	}

}



int main() {

	int t;



	scanf("%d", &t);

	while (t--) {

		int k, h, i, i1, i2, j, a, t, o;



		scanf("%d%d", &n, &m);

		for (i = 0; i < n; i++) {

			eh[i] = (int *) malloc(2 * sizeof *eh[i]), eo[i] = 0;

			ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo_[i] = 0;

		}

		for (h = 0; h < m; h++) {

			scanf("%d%d", &i, &j), i--, j--;

			uu[h] = i, vv[h] = j;

			append(eh, eo, i, h), append(eh, eo, j, h);

		}

		scanf("%d", &k);

		while (k--) {

			scanf("%d%d", &i, &j), i--, j--;

			append(ej, eo_, i, j), append(ej, eo_, j, i);

		}

		memset(ta, -1, n * sizeof *ta), memset(tb, -1, n * sizeof *tb);

		time = 0, dfs1(-1, -1, 0);

		_ = 1;

		for (a = 0, t = 0; a < n; a++) {

			i = ii[a];

			for (o = eo_[i]; o--; ) {

				j = ej[i][o];

				if (ta[j] > a)

					t = update(t, 0, n, ta[j]);

			}

			ttp[a] = t;

		}

		for (a = n - 1, t = 0; a >= 0; a--) {

			i = ii[a];

			for (o = eo_[i]; o--; ) {

				j = ej[i][o];

				if (ta[j] < a)

					t = update(t, 0, n, ta[j]);

			}

			ttq[a] = t;

		}

		kk_[0] = -1;

		for (i = 1; i < n; i++)

			kk_[i] = count(i, i);

		ans = 0, h1_ = 0, h2_ = 1;

		memcpy(pp_, pp, n * sizeof *pp), memset(ff_, -1, n * sizeof *ff_);

		dfs2(0);

		i1 = i2 = 0;

		for (i = 1; i < n; i++)

			if (kk[i] == 1) {

				if (ans < kk_[i])

					ans = kk_[i], h1_ = ff[i], h2_ = ff_[i];

			} else if (kk[i] == 0) {

				if (ans < kk_[i])

					ans = kk_[i], h1_ = ff[i], h2_ = h1_ == 0 ? 1 : 0;

				if (kk_[i1] < kk_[i])

					i2 = i1, i1 = i;

				else if (kk_[i2] < kk_[i])

					i2 = i;

			}

		if (i2 != 0 && ans < (k = kk_[i1] + kk_[i2]))

			ans = k, h1_ = ff[i1], h2_ = ff[i2];

		printf("%d\n", ans);

		printf("%d %d\n", uu[h1_] + 1, vv[h1_] + 1);

		printf("%d %d\n", uu[h2_] + 1, vv[h2_] + 1);

		for (i = 0; i < n; i++)

			free(eh[i]), free(ej[i]);

	}

	return 0;

}