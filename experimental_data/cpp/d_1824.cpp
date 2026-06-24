#include <cstdio>
#include <algorithm>
#define rep(i, d, u) for(int i = d; i <= u; ++i)
int ured() {
	int re = 0;
	char ch;
	do {
		ch = getchar();
	} while('9' < ch || ch < '0');
	do {
		re = re * 10 + (ch ^ '0');
	} while('0' <= (ch = getchar()) && ch <= '9');
	return re;
}
void lwit(long long da) {
	int ch[21], cn = 0;
	do {
		ch[++cn] = da - da / 10 * 10;
	} while(da /= 10);
	do {
		putchar('0' ^ ch[cn]);
	} while(--cn);
}
void dmin(int &le, int ri) {
	if(le > ri) {
		le = ri;
	}
}
const int _maxn = 1000011;
struct node {
	bool st;
	int po, le, ri, fr;
} arry[_maxn << 1];
int n, q, a[_maxn], l, r, x, y, atpo, latp[_maxn], lazf[_maxn << 2], lazt[_maxn << 2];
long long rans[_maxn], tree[_maxn << 2], sums[_maxn << 2], lazs[_maxn << 2];
void addf(int at, int le, int ri, int da) {
	tree[at] += sums[at] * da;
	if(lazt[at]) {
		lazs[at] += 1ll * lazt[at] * da;
	} else {
		lazf[at] += da;
	}
}
void adds(int at, int le, int ri, long long da) {
	tree[at] += 1ll * da * (ri - le + 1), lazs[at] += da;
}
void addt(int at, int le, int ri, int da) {
	sums[at] = 1ll * da * (ri - le + 1), lazt[at] = da;
}
void upda(int at) {
	tree[at] = tree[at << 1] + tree[at << 1 | 1], sums[at] = sums[at << 1] + sums[at << 1 | 1];
}
void push(int at, int le, int ri) {
	if(lazf[at]) {
		addf(at << 1, le, le + ri >> 1, lazf[at]), addf(at << 1 | 1, (le + ri >> 1) + 1, ri, lazf[at]), lazf[at] = 0;
	}
	if(lazs[at]) {
		adds(at << 1, le, le + ri >> 1, lazs[at]), adds(at << 1 | 1, (le + ri >> 1) + 1, ri, lazs[at]), lazs[at] = 0;
	}
	if(lazt[at]) {
		addt(at << 1, le, le + ri >> 1, lazt[at]), addt(at << 1 | 1, (le + ri >> 1) + 1, ri, lazt[at]), lazt[at] = 0;
	}
}
void modi(int at, int le, int ri, int ql, int qr, int da) {
	if(ql <= le && ri <= qr) {
		addt(at, le, ri, da);
	} else {
		push(at, le, ri);
		if(ql <= le + ri >> 1) {
			modi(at << 1, le, le + ri >> 1, ql, qr, da);
		}
		if(qr > le + ri >> 1) {
			modi(at << 1 | 1, (le + ri >> 1) + 1, ri, ql, qr, da);
		}
		upda(at);
	}
}
long long quer(int at, int le, int ri, int ql, int qr) {
	if(ql <= le && ri <= qr) {
		return tree[at];
	} else {
		push(at, le, ri);
		if(ql <= le + ri >> 1 && qr > le + ri >> 1) {
			return quer(at << 1, le, le + ri >> 1, ql, qr) + quer(at << 1 | 1, (le + ri >> 1) + 1, ri, ql, qr);
		} else if(ql <= le + ri >> 1) {
			return quer(at << 1, le, le + ri >> 1, ql, qr);
		} else {
			return quer(at << 1 | 1, (le + ri >> 1) + 1, ri, ql, qr);
		}
	}
}
int main() {
	n = ured(), q = ured();
	rep(i, 1, n) {
		latp[i] = n + 1;
	}
	rep(i, 1, n) {
		a[i] = ured();
	}
	rep(i, 1, q) {
		l = ured(), r = ured(), x = ured(), y = ured(), arry[(i << 1) - 1] . st = 1, arry[(i << 1) - 1] . po = l, arry[i << 1] . po = r + 1;
		arry[(i << 1) - 1] . le = arry[i << 1] . le = x, arry[(i << 1) - 1] . ri = arry[i << 1] . ri = y;
		arry[(i << 1) - 1] . fr = arry[i << 1] . fr = i;
	}
	std :: sort(arry + 1, arry + (q << 1) + 1, [](node le, node ri) {
		return le . po > ri . po;
	}), atpo = n;
	rep(i, 1, q << 1) {
		while(atpo >= arry[i] . po) {
			modi(1, 1, n, atpo, latp[a[atpo]] - 1, atpo), addf(1, 1, n, 1), latp[a[atpo]] = atpo, --atpo;
		}
		if(arry[i] . st) {
			rans[arry[i] . fr] += quer(1, 1, n, arry[i] . le, arry[i] . ri);
		} else {
			rans[arry[i] . fr] -= quer(1, 1, n, arry[i] . le, arry[i] . ri);
		}
	}
	rep(i, 1, q) {
		lwit(rans[i]), putchar('\n');
	}
	return 0;
}