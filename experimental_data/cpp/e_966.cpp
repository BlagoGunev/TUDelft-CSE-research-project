#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
const int inf = 1e9 + 7;

#define nd second
#define st first
#define mp make_pair
#define pb push_back

const int SQ = 300;
const int N = 1e5 + 5;

int h[N], IND[N], Lazy[N], val[N], sum[N], T, up[N], start[N], finish[N], root[N], x, y, z, n, m, S, ss[N], ff[N], belong[N];
vector< pii > v1, v2;
vector< int > v[N], comp[N], pre[N];
vector< pii > sorted[N];

int dfs(int node) {
	sum[node] = 1;
	for(auto go: v[node])
		sum[node] += dfs(go);
	return sum[node];
}

void hld(int node, int up) {
	::up[node] = up;
	start[node] = ++T;
	int t = 0;
	for(auto go: v[node])
		if(sum[t] <= sum[go])
			t = go;
	if(t)
		hld(t, up);
	for(auto go: v[node])
		if(go != t)
			hld(go, go);
	finish[node] = T;
}

void update_fast(int ind, int add) {
	Lazy[ind] += add;
	while(comp[ind][IND[ind]] + Lazy[ind] >= 0) IND[ind]--;
	while(comp[ind][IND[ind] + 1] + Lazy[ind] < 0) IND[ind]++;
}

void init(int c) {
	comp[c].clear();
	pre[c].clear();
	int sz = sorted[c].size();
	comp[c].pb(-inf);
	pre[c].pb(0);
	for(int i = 0; i < sz; i++) {
		int j = i;
		int ss = h[sorted[c][i].nd];
		while(j + 1 < sz && sorted[c][j + 1].st == sorted[c][i].st) { ss += h[sorted[c][j+1].nd]; j++; }
		comp[c].pb(sorted[c][i].st);
		pre[c].pb(ss);
		i = j;
	} 
	comp[c].pb(inf);
	pre[c].pb(0);
	sz = comp[c].size();
	for(int i = 0; i < sz; i++) {
		if(comp[c][i] < 0)
			IND[c] = i;
	}
	for(int i = 1; i < sz; i++)
		pre[c][i] += pre[c][i - 1];
}

void update_naive(int c, int x, int y, int add) {
	v1.clear();
	v2.clear();
	for(auto xx: sorted[c]) {
		if(x <= xx.nd && xx.nd <= y) {
			v2.pb(mp(xx.st + add + Lazy[c], xx.nd));
			val[xx.nd] += add + Lazy[c];
		}
		else {
			v1.pb(mp(xx.st + Lazy[c], xx.nd));
			val[xx.nd] += Lazy[c];
		}
	}
	Lazy[c] = 0;
	sorted[c].clear();
	sorted[c].resize(v1.size() + v2.size());
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),sorted[c].begin());
	init(c);
}

void update(int x, int y, int add) {
	if(belong[x] == belong[y]) {
		update_naive(belong[x], x, y, add);
		return ;
	}
	update_naive(belong[x], x, ff[belong[x]], add);
	update_naive(belong[y], ss[belong[y]], y, add);
	for(int i = belong[x] + 1; i <= belong[y] - 1; i++)
		update_fast(i, add);
}

int get() {
	int ans = 0;
	for(int i = 1; i <= S; i++)
		ans += pre[i][IND[i]];
	return ans;
}

void aadd(int x) {
	x = start[x];
	h[x] = 1;
	int c = belong[x], v = val[x];
	int f = 0;
	for(int i = 0; i < comp[c].size(); i++) {
		if(comp[c][i] >= v)
			pre[c][i]++;
	}
}

void adel(int x) {
	x = start[x];
	h[x] = 0;
	int c = belong[x], v = val[x];
	int f = 0;
	for(int i = 0; i < comp[c].size(); i++) {
		if(comp[c][i] >= v) {
			pre[c][i]--;
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);

	for(int i = 2; i <= n; i++) {
		scanf("%d", &x);
		v[x].pb(i);
		root[i] = x;
	}

	dfs(1);
	hld(1, 1);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		val[start[i]] = x;
		h[i] = 1;
	}

	for(int i = 1; i <= n; i++) {
		belong[i] = (i - 1) / SQ + 1;
		if(ss[belong[i]] == 0) ss[belong[i]] = i;
		ff[belong[i]] = i;
		sorted[belong[i]].pb(mp(val[i], i));
		S = belong[i];
		Lazy[belong[i]] = 0;
	}

	for(int i = 1; i <= S; i++) {
		sort(sorted[i].begin(), sorted[i].end());
		init(i);
	}

	for(int i = 1; i <= m; i++) {
		scanf("%d", &x); 
		int add = -1;
		if(x < 0) { add = 1; x = -x; }
		if(add == 1) aadd(x);
		else adel(x);
		x = root[x];
		while(x) {
			update(start[up[x]], start[x], add);
			x = root[up[x]];
		}
		printf("%d\n", get());
	}	

	return 0;
}