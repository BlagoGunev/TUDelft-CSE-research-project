#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <cassert>
#include <map>
#include <queue>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdarg>
#include <utility>
#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template<typename T> int size(T &a) {return (int)a.size();}
template<typename T> T sqr(T a)  { return a * a; }

#define REP(i,a,b) for(int i=(a);i<(b); ++i)
#define REPD(i,a,b)for(int i=(b)-1;i>=a;--i)
#define FOR(it, q) for(decltype((q).begin()) it = (q).begin(); it != (q).end(); it++)
#define _(a,b) memset((a), (b), sizeof(a))
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ve vector
#define _USE_MATH_DEFINES

const int MAXN = 2 * int(1e5) + 100;
const int MOD = int(1e9);
const ll MOD2 = ll(MOD) * MOD;
int add(int a, int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	return a;
}
int mul(int a, int b) {
	return ll(a) * b % MOD;
}
int sub(int a, int b) {
	a -= b;
	if(a < 0) a += MOD;
	return a;
}

struct mat {
	int a[2][2];
	mat() {
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[1][1] = 0;
	}
	void init() {
		_(a, 0);
		a[0][0] = a[1][1] = 1;
	}

	mat operator * (const mat & b) const {
		mat ret;
		REP(i, 0, 2) REP(j, 0, 2) {
			ret.a[i][j] = 0;
			REP(k, 0, 2) 
				ret.a[i][j] = add(ret.a[i][j],
						mul(a[i][k], b.a[k][j]));
		}
		return ret;
	}
};

mat fibMat[MAXN];
int fibs[MAXN];
void initFibMat() {
	mat base;
	fibMat[0].init();
	REP(i, 1, MAXN) fibMat[i] = fibMat[i - 1] * base;

	fibs[0] = fibs[1] = 1;
	REP(i, 2, MAXN) {
		fibs[i] = add(fibs[i - 2], fibs[i - 1]);
	}

	REP(i, 1, MAXN) {
		fibs[i] = add(fibs[i], fibs[i - 1]);
	}
}

int getFibSum(int l, int r) {
	if(r < l) return 0;
	return sub( fibs[r], l == 0 ? 0 : fibs[l - 1] );
}

struct node {
	int sum, offsetSum;
	int over;
	node() {}
	node(int sum, int offsetSum) :
		sum(sum), offsetSum(offsetSum), over(0) {}

	void updateBySons(const node & lSon, const node & rSon,
			int l, int m, int r) {
		int startWith = m + 1 - l;
		sum = add(lSon.sum, rSon.getFibSum(startWith));
		offsetSum = add(lSon.offsetSum, rSon.getFibSum(startWith - 1));
	}

	int getFibSum(int fibNumber = 0) const {
		const mat m = fibMat[fibNumber];
		int ret = add(mul(m.a[0][0], sum),
				mul(m.a[0][1], offsetSum));

		return ret;
	}
};

node tr[MAXN << 2];
int a[MAXN];

void makeTree(int i, int l, int r) {
	//tr[i].l = l;
	//tr[i].r = r;

	if(l == r) {
		tr[i] = node(a[l], 0);
		return;
	}

	int m = (l + r) / 2;
	makeTree( i << 1, l, m );
	makeTree( (i << 1) + 1, m + 1, r );

	tr[i].updateBySons(tr[i << 1], tr[(i << 1) + 1], l, m, r);
}

void add(int i, int l, int r, int val) {
	if(val < 0) val += MOD;
	tr[i].over = add(tr[i].over, val);
	tr[i].sum = add(tr[i].sum, 
			mul(val, getFibSum(0, r - l)));
	tr[i].offsetSum = add(tr[i].offsetSum,
			mul(val, getFibSum(0, r - l - 1)));
}

void addQuery(int i, int l, int r, int ql, int qr, int val) {
	if(ql > r || qr < l) return;

	if(ql <= l && qr >= r) {
		add(i, l, r, val);
		return;
	}

	int m = (l + r) / 2;
	addQuery(i << 1, l, m, ql, qr, val);
	addQuery((i << 1) + 1, m + 1, r, ql, qr, val);

	tr[i].updateBySons(tr[i << 1], tr[(i << 1) + 1], l, m, r);
	int rem = tr[i].over;
	tr[i].over = 0;
	add(i, l, r, rem);
}

void setQuery(int i, int l, int r, int pos, int val) {
	if(pos < l || pos > r) return;
	if(l == r) {
		tr[i] = node(val, 0);
		return;
	}

	int m = (l + r) / 2;
	add(i << 1, l, m, tr[i].over);
	add((i << 1) + 1, m + 1, r, tr[i].over);
	add(i, l, r, -tr[i].over);
	
	setQuery( i << 1, l, m, pos, val );
	setQuery( (i << 1) + 1, m + 1, r, pos, val );

	tr[i].updateBySons(tr[i << 1], tr[(i << 1) + 1], l, m, r);
}

int sumQuery(int i, int l, int r, int ql, int qr, int startWith = 0, int ad = 0) {
	if(r < ql || l > qr) return 0;
	if(ql <= l && qr >= r) {
		int ret = tr[i].getFibSum(startWith);
		int fibSum = getFibSum(startWith, startWith + r - l);

		return add(ret, mul(fibSum, ad));
	}

	ad = add(ad, tr[i].over);
	int m = (l + r) / 2;
	int ret;
	if(ql > m) {
		ret = sumQuery((i << 1) + 1, m + 1, r, ql, qr, startWith, ad);
	} else if(qr <= m) {
		ret = sumQuery(i << 1, l, m, ql, qr, startWith, ad);
	} else {
		ret = add(
				sumQuery(i << 1, l, m, ql, m, startWith, ad),
				sumQuery((i << 1) + 1, m + 1, r, m + 1, qr, 
					startWith + m + 1 - ql, ad)
				);
	}

	return ret;
}

void solve() {
	initFibMat();
	int N, M;
	scanf("%d %d", &N, &M);
	REP(i, 0, N) scanf("%d", &a[i]);

	makeTree(1, 0, N - 1);

	REP(i, 0, M) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		if(t == 1) {
			setQuery(1, 0, N - 1, l - 1, r);
		} else if(t == 2) {
			int sum = sumQuery(1, 0, N - 1, l - 1, r - 1);
			printf("%d\n", sum);
		} else if(t == 3) {
			int d;
			scanf("%d", &d);
			addQuery(1, 0, N - 1, l - 1, r - 1, d);
		}
	}
}

int main() {
#ifdef shindo
	if(false) {
		freopen("input.txt", "w", stdout);
	}
	freopen("input.txt", "r", stdin);                
	freopen("output.txt","w", stdout);       
	freopen("error.txt", "w", stderr);
#else
#endif

	solve();
	
#ifdef shindo
	printf("\n-----------\n\n%.3lf\n", clock() * 1e-3);
#endif
	
	return 0;
}