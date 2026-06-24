#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define fi first

#define se second

#define ll long long

#define ld long double

#define sz(x) ((int)(x).size())

#define all(x) 	(x).begin(), (x).end()

#define pb push_back

#define mpp make_pair

#define ve vector

using namespace std;

using namespace __gnu_pbds;

template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const ll inf = 1e18; const int iinf = 1e9;

typedef pair<ll, ll> pll;

typedef pair<int, int> pii;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> inline bool chmin(T& a, T b) { return (a > b ? a = b, 1 : 0); }

template <typename T> inline bool chmax(T& a, T b) { return (a < b ? a = b, 1 : 0); }



constexpr int md = 998244353; constexpr int iv2 = (md + 1) / 2;

inline int add(int a, int b) { if((a+=b)>=md)a-=md; return a; }

inline int sub(int a, int b) { if((a-=b)<0)a+=md; return a; }

inline int mul(int a, int b) { return 1ll*a*b%md; }

inline int bp(int a, int n) { int res = 1;

	for (; n; n >>= 1, a = mul(a, a)) {

		if (n & 1) res = mul(res, a);

	} return res;

}

inline int inv(int a) { return bp(a, md - 2); }



inline void solve() {

	int n;

	cin >> n;

	ve<int> a(n);

	for (auto &i : a) cin >> i;



	int c0 = 0;

	for (auto &i : a) c0 += !i;



	int cnt0 = 0;

	for (int i = 0; i < c0; ++i) {

		cnt0 += !a[i];

	}



	ve<int> e(c0 + 1); e[0] = 0;



	int ps = mul(n, mul(iv2, sub(n, 1)));

	int ipairs = inv(ps);



	for (int i = 1; i <= c0; ++i) {

		int good = mul( i, i );

		int pgood = mul(good, ipairs);



		int p1 = mul(iv2, mul(mul(c0, sub(c0, 1)), ipairs));

		int p2 = mul(iv2, mul(mul(n - c0, sub(n - c0, 1)), ipairs));

		int p3 = mul(sub(mul(c0, n - c0), good), ipairs);

		p1 = add(p1, p3);



		e[i] = mul( inv( sub(1, add(p1, p2)) ), add( add(p1, p2), mul(pgood, add(1, e[i - 1]) ) ));

	}

	cout << e[c0 - cnt0] << '\n';

}



signed main() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int q = 1; cin >> q;

	while (q--) solve();

	cerr << fixed << setprecision(3) << "Time execution: " << (double)clock() / CLOCKS_PER_SEC << endl;

}