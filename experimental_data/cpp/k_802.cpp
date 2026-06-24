#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a ; i <= b; ++ i) 
const int N = 200005 ;
using namespace std ;

int n, k, e, ter[N], nxt[N], lnk[N], w[N], f[N][2], d[N];

void add(int x, int y, int z) {
	ter[++ e] = y, nxt[e] = lnk[x], lnk[x] = e, w[e] = z ;
}

void dfs(int p, int las) {
	f[p][0] = f[p][1] = 0 ;
	for (int i = lnk[p]; i; i = nxt[i]) if (ter[i] != las) {
		dfs(ter[i], p) ;
	}
	d[0] = 0 ;
	for (int i = lnk[p]; i; i = nxt[i]) if (ter[i] != las)
		d[++ d[0]] = f[ter[i]][0] + w[i] ;
	sort(d + 1, d + d[0] + 1) ;
	reverse(d + 1, d + d[0] + 1) ;
	int sz = min(d[0], k - 1), sum = 0 ;
	rep(i, 1, sz)
		f[p][0] += d[i], sum += d[i] ;
	for (int i = lnk[p]; i; i = nxt[i]) if (ter[i] != las) {
		if (f[ter[i]][0] + w[i] >= d[sz] && sz)
			f[p][1] = max(f[p][1], sum + (sz < d[0] ? d[sz + 1] : 0) - f[ter[i]][0] + f[ter[i]][1]) ;
		else f[p][1] = max(f[p][1], sum + f[ter[i]][1] + w[i]) ;
	}
}

int main() {
	scanf("%d%d", &n, &k) ;
	int x, y, z ;
	rep(i, 1, n - 1) {
		scanf("%d%d%d", &x, &y, &z) ;
		++ x, ++ y ;
		add(x, y, z) ;
		add(y, x, z) ;
	}
	dfs(1, 0) ;
	printf("%d\n", f[1][1]) ;
	return 0 ;
}