//g++ -std=c++17 -Wl,--stack,268435456 Ahoyy.cpp -o Ahoyy.exe

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pb push_back
#define fi first
#define se second
#define UP(a,b,c) for(ll (a)=(b);(a)<(c);++(a))
#define UU(a,b,c) for(ll (a)=(b);(a)<=(c);++(a))
#define DN(a,b,c) for(ll (a)=(b);(a)>(c);--(a))
#define DU(a,b,c) for(ll (a)=(b);(a)>=(c);--(a))
#define lc(i) i+1
#define rc(i) i+(m-l+1)*2

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, nuint_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll expo(ll a, ll b, int mod) {
	if(b == 0) return 1;
	if(b == 1) return a % mod;
	ll ret = expo(a, b>>1, mod);
	ret *= ret;
	if(ret >= mod) ret %= mod;
	if(b & 1) {
		ret *= a;
		if(ret >= mod) ret %= mod;
	}
	return ret;
}

ll inv(ll v, int mod) {
	return expo(v, mod - 2, mod);
}

ll n, a[105], b[105], DP[105][10005], sum[105];

void reset() {
}

void input() {
	cin >> n;
	UU(i, 1, n) cin >> a[i];
	UU(i, 1, n) cin >> b[i];
	UU(i, 1, n) sum[i] = sum[i - 1] + a[i] + b[i];
}

ll p2(ll x) {
	return x * x;
}

ll dp(int i, ll mul) {
	if(i == n + 1) return 0;
	ll &ret = DP[i][mul];
	if(ret != -1) return ret;

	ret = 1e18;
	ret = min(ret, dp(i + 1, mul + a[i]) + p2(a[i]) * (n - 1) + p2(b[i]) * (n - 1) + mul * 2 * a[i] + (sum[i - 1] - mul) * 2 * b[i]);
	ret = min(ret, dp(i + 1, mul + b[i]) + p2(a[i]) * (n - 1) + p2(b[i]) * (n - 1) + mul * 2 * b[i] + (sum[i - 1] - mul) * 2 * a[i]);

	return ret;
}

void solve() {
	UU(i, 0, n) UU(j, 0, 10000) DP[i][j] = -1;
	cout << dp(1, 0) << endl;
}

void Ahoy() {
	solve();
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	// freopen("in.txt", "r", stdin);
	// freopen("out1.txt", "w", stdout);

	int TC = 1;
	cin >> TC;
	UU(t, 1, TC) {
		// cout << "Case #" << t << ": ";
		input();
		Ahoy();
		reset();	
	}

	return 0;
}

/*

(a + b)^2 = a^2 + 2ab + b^2
(2a + 2b) * x = 2(a + b) * x = (a + b) * x * 2 
*/