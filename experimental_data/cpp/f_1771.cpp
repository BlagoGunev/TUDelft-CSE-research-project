/*
 * Author: triveni
 * Created: 2023-01-24 03:18:01
**/

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
	#include <debug.h>
#else
	#define dbg(...) 0
#endif


using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      sz(v)             (int)(v.size())
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      rep1(i, n)        for(int i = 1; i <= (n); ++i)
#define      all(v)            v.begin(), v.end()
#define      scan(n)           scanf("%d", &n)
#define      scan2(n, m)       scanf("%d%d", &n, &m)
#define      pin(n)            printf("%d\n",n)
#define      pis(n)            printf("%d ",n)
#define      pll(n)            printf("%lld\n", n)
#define      p10               putchar(10)
#define      X                 first
#define      Y                 second
#define      lg2(n)            (31 - __builtin_clz(n))

typedef long long ll;
const ll mod = 998244353;
const int BIT = 29;

inline int pow_(ll a, int n, int p=mod){
int r=1;while(n){if(n&1)r=r*a%p;n>>=1;a=a*a%p;}return r;}

int tr[200100 << 5][3];
int gc = 1;

int insert(int prev, int num, int i = BIT, int mul = 0) {
	int cur = gc++;
	if (i < 0) {
		tr[cur][2] = tr[prev][2] ? 0 : pow_(2, mul);
		return cur;
	}
	rep(k, 2) tr[cur][k] = tr[prev][k];
	if (num >> i & 1) {
		tr[cur][1] = insert(tr[prev][1], num, i-1, (mul+1)<<1);
	} else {
		tr[cur][0] = insert(tr[prev][0], num, i-1, (mul<<1) + 1);
	}
	tr[cur][2] = tr[tr[cur][0]][2] + tr[tr[cur][1]][2];
	return cur;
}

int query(int r, int l, int i = BIT) {
	// cerr << r << " " << l << " " << tr[r][3] << " " << tr[l][3] << "\n";
	if (i < 0 || tr[r][2] == tr[l][2]) return 0;
	if (tr[tr[r][0]][2] != tr[tr[l][0]][2]) {
		return query(tr[r][0], tr[l][0], i-1);
	}
	return (1 << i) | query(tr[r][1], tr[l][1], i-1);
}

int tries[200100];

void solve(int tc) {
	int n; scan(n);
	rep1(i, n) {
		int x; scan(x);
		tries[i] = insert(tries[i-1], x);
	}
	int q; scan(q);
	int ans = 0;
	while(q--) {
		int l, r; scan2(l, r); 
		l^=ans; r^= ans;
		assert(1 <= l && l <= n);
		assert(1 <= r && r <= n);
		assert(l <= r);
		ans = query(tries[r], tries[l-1]);
		pin(ans);
	}
}

// Do examples

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int T = 1;
	// cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		solve(tc);
	}
	return 0;
}