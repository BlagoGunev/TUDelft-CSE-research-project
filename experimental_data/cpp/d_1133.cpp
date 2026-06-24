/* Yuanjie Duane Ding (c) 2019
 * any codes cannot be used for business
 * 2019��������
 * Templates for Codeforces special
*/

#include <bits/stdc++.h>

#define NAME "1133D"

using namespace std;

int cnt;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

struct number {
	int son, mother;
	int sign;
	number(int _son = 1, int _mother = 1) {
		son = _son;
		mother = _mother;
		if(mother != 0) {
			if(son != 0) {
				sign = (son/abs(son))*(mother/abs(mother));
			} else {
				sign = 0;
			}
			son = abs(son);
			mother = abs(mother);
			int g = gcd(son, mother);
			if(g != 0) {
				son /= g;
				mother /= g;
			} else {
				son = 1;
				mother = 0;
			}
		} else if(son == 0) {
			sign = 2;
			++cnt;
			son = mother = 0;
		} else {
			sign = 2;
		}
	}
} cv[200005];

bool operator < (const number &a, const number &b) {
	if(a.sign != b.sign) {
		return a.sign < b.sign;
	} else {
		if(a.mother == b.mother && a.son == b.son) {
			return false;
		}
		bool ret = 1LL*a.son*b.mother < 1LL*b.son*a.mother;
		if(a.sign == -1) {
			ret = !ret;
		}
		return ret;
	}
}

bool operator == (const number &a, const number &b) {
	return !((a < b) || (b < a));
}

const double eps = 1e-11;
int N;
int av[200005], bv[200005];
//double cv[200005];

bool equal(double a, double b) {
	a = abs(a);
	b = abs(b);
	return (max(a, b)/min(a, b)-1) < eps;
}

void readin() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", av+i);
	}
	for(int i = 1; i <= N; ++i) {
		scanf("%d", bv+i);
		cv[i] = number(bv[i], av[i]);
#ifdef DEBUG
		printf("(%d/%d)\n", cv[i].son, cv[i].mother);
#endif
	}
}

void process() {
	sort(cv+1, cv+1+N);
	int ans = 0;
	while(cv[N].sign == 2) {
		--N;
	}
#ifdef DEBUG
	printf("N = %d\n", N);
#endif
	for(int i = 1; i <= N; ++i) {
		int j;
		for(j = i+1; j <= N && cv[i] == cv[j]; ++j);
		ans = max(ans, j-i);
		i = j-1;
	}
	printf("%d\n", ans+cnt);
}

int main() {
#if defined(DEBUG) || defined(DUIPAI)
	freopen(NAME ".in", "r", stdin);
#endif
	
	readin();
	process();

	return 0;
}