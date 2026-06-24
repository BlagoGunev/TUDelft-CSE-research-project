//#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

const int iinf = 0x7fffffff;

const ll linf = ~(1LL<<63);

typedef pair<int, int> pii;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef map<ll, int> mli;

typedef map<ll, ll> mll;

template<typename T>

inline T gcd(T a, T b) {

	if(a < 0) return gcd(-a, b);

	if(b < 0) return gcd( a,-b);

	if(a < b) return gcd(b, a);

	if(b == 0) return a;

	return gcd(b, a%b);

}



ll qpow(ll a, ll n, ll mod) {

	a %= mod;

	ll ans = 1LL;

	while(n) {

		if(n & 1) ans = (ans*a % mod);

		a = (a*a % mod);

		n >>= 1;

	}

	return ans;

}



// unsigned

ll qmul(ll a, ll b, ll mod) {

	a %= mod;

	b %= mod;

	ll ans = 0LL;

	while(b) {

		if(b & 1) ans = (ans+a) % mod;

		a = (a<<1) % mod;

		b >>= 1;

	}

	return ans;

}

inline ll rev(ll a, ll p) {

	return qpow(a, p - 2, p);

}



struct Point {

	int x, y;

};



#define all(v) v.begin(), v.end()

#define sz(v) v.size()

#define rep(x, st, en) for(int x = st; x < en; x++)

#define pb push_back

#define mp make_pair

#define dbgm(msg, var) cerr<<#msg<<" "<<#var<<" = "<<var<<endl; 

#define dbg(var) cerr<<#var<<" = "<<var<<endl;

#ifdef ALNDBG

clock_t s, e;

#endif



inline void tic() {

#ifdef ALNDBG

	s = clock();

#endif

}



inline void toc() {

#ifdef ALNDBG

	e = clock();

	cerr<<1000.0 * (e - s) / CLOCKS_PER_SEC<<" ms"<<endl;

#endif

}



// -------------------- Spliters ------------------------

const int maxn = 5055;



int n, m;

ll T;



struct edge{

	int to;

	ll dist;

};



vector<edge> E[maxn];





map<int, int> dp[maxn];

short nxt[maxn][maxn];



bool vis[maxn];



void dfs(int s) {

	vis[s] = true;

	if(s == n) {

		dp[s][1] = 0;

		nxt[s][1] = -1;

	}

	for(auto& edg : E[s]) {

		if(!vis[edg.to])

			dfs(edg.to);

		for(auto kv : dp[edg.to]) {

			int i = kv.first;

			if((ll)kv.second + (ll)edg.dist > T) continue;

			if(dp[s].find(i + 1) == dp[s].end() || kv.second + edg.dist < dp[s][i + 1]) {

				dp[s][i + 1] = kv.second + edg.dist;

				nxt[s][i + 1] = edg.to;

			}

		}

	}

}



int main() {

	scanf("%d%d%lld", &n, &m, &T);

	memset(vis, 0 ,sizeof vis);

	int u, v;

	ll t;

	rep(i, 0, m) {

		scanf("%d%d%lld", &u, &v, &t);

		E[u].pb({v, t});

	}

	dfs(1);

	int cur = 1;

	int ans = -1;

	for(auto kv : dp[cur]) {

		if(kv.second <= T)

			ans = max(kv.first, ans);

	} printf("%d\n", ans);

	printf("1 ");

	for(int j = 2; j <= ans; j++) {

		int nt = nxt[cur][ans - j + 2];

		printf("%d ", nt);

		cur = nt;

	}

	

	return 0;

}



// --USE C++11