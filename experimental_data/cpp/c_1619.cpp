//Josue
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T>& a, const T& b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T>& a, const T& b) { return int(ub(all(a), b) - bg(a)); }

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = ((b)-1); i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

// const int MOD = 1e9+7; // 998244353;
const ll M = 1e9 + 7;
const ll MX = 1e9;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int ddef[4]{ 1,0,-1,0 }, dataq[4]{ 0,1,0,-1 }; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
	return x == 0 ? 0 : 31 - __builtin_clz(x);
} // floor(log2(x)) 
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down

tcT > bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
} // set a = min(a,b)
tcT > bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
} // set a = max(a,b)

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

// make sure to intialize ALL GLOBAL VARS between tcs!
int test;

void solve() {

	str a, s; cin >> a >> s;

	ll szA = sz(a) - 1, szS = sz(s) - 1;

	str b;

	bool can = 1;

	while(szA >= 0 && szS >= 0){
		ll x = a[szA] - '0';
		ll y = s[szS] - '0';
		if(x <= y){
			ll resta = y - x;
			b.pb((char)('0' + resta));
			szA--; szS--;
		}
		else{
			szS--;
			y += (10 * (ll)(s[szS] - '0'));
			ll resta = y - x;
			if(resta > 9 || resta < 0){
				can = 0;
				break;
			}
			b.pb((char)('0' + resta));
			szA--; szS--;
		}
	}

	if(szA >= 0) can = 0;

	if(!can){
		cout << "-1\n";
		return;
	}

	while(szS >= 0){
		b.pb(s[szS--]);
	}

	while(b.back() == '0') b.pop_back();
	reverse(all(b));

	cout << b << '\n';


}

int main() {
	setIO("");
	int TC = 1;
	cin >> TC;
	for (test = 1; test <= TC; test++) solve();
	return 0;
}
/* stuff you should look for
	* always avoid vectors without reference as parameters in the functions
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/