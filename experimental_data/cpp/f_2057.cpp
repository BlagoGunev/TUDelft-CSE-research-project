#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#if 0
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
 
    template<class T>
    using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;
#endif

#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

#define each(a,x) for (auto& a: x)
#define tcT template<class T
#define tcTU tcT, class U
#define tcTUU tcT, class ...U
template<class T> using V = vector<T>; 
template<class T, size_t SZ> using AR = array<T,SZ>;

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
 
mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());
 
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

tcTU> void re(pair<T,U>& p);
tcT> void re(V<T>& v);
tcT, size_t SZ> void re(AR<T,SZ>& a);

tcT> void re(T& x) { cin >> x; }
void re(double& d) { str t; re(t); d = stod(t); }
void re(long double& d) { str t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }

tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
tcT> void re(V<T>& x) { each(a,x) re(a); }
tcT, size_t SZ> void re(AR<T,SZ>& x) { each(a,x) re(a); }
tcT> void rv(int n, V<T>& x) { x.rsz(n); re(x); }

constexpr bool multitest() {return 1;}
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
	if (multitest()) cin >> t;
	for (; t; t--) solve();
}






















struct event {
	ll pos;
	int type;
	ll val;

	bool operator<(const event& ot) const {
		if (pos != ot.pos) return pos < ot.pos;
		if (type != ot.type) return type < ot.type;
		return val < ot.val;
	}
};

ll shift(ll val, int hm) {
	ll inf = 2000000001ll;
	if ( (inf>>hm) < val ) return inf;
	return val<<hm;
}

void solve() {
	int n, q; re(n, q);

	vector<ll> a(n); re(a);

	int stt = *max_element(all(a));

	vector< vector<event> > ev(40);

	for (int i = 0; i < n; i++) {
		vector<ll> cutoffs;

		ll tot = 0;

		for (int j = 0; i-j >= 0 && j < 40; j++) {
			tot += a[i-j];

			// CHECK FOR OVERFLOW IN FR CUTOFF
			ll fr = shift(a[i-j], j);
			ll cutoff = 2000000001ll;
			if (i-j-1 >= 0) cutoff = shift(a[i-j-1], j+1);

			ev[j].push_back(event{fr, 0, tot});
			ev[j].push_back(event{cutoff, 1, tot});
		}
	}

	vector< vector< pair<ll, ll> > > bests(40);

	for (int j = 0; j < 40; j++) {
		bests[j].push_back({-2000000000ll, -2000000000ll});
		sort(all(ev[j]));

		multiset<ll> best;
		int i = 0;

		while (i < sz(ev[j])) {
			int cp = ev[j][i].pos;
			
			while (i < sz(ev[j]) && ev[j][i].pos == cp) {
				if (ev[j][i].type == 1) best.erase(best.find(ev[j][i].val));
				if (ev[j][i].type == 0) best.insert(ev[j][i].val);
				i++;
			}

			bests[j].push_back( {cp, best.empty() ? -2000000000ll : *best.rbegin() } );
		}
	}

	for (; q; q--) {
		int k; re(k);

		ll st = stt, ed = 2000000000ll;
		while (st < ed) {
			ll md = (st+ed+1)/2;

			ll need = 0;
			ll curm = md;
			ll best = 4000000000ll;
			for (int j = 0; j < 40; j++) {
				need += curm;
				curm = (curm+1)/2;

				ll sub = prev(upper_bound(all(bests[j]), pair<ll,ll>{md, -4000000000ll}))->second;
				ctmin(best, need - sub);
			}

			if (best <= k) st=md;
			else ed=md-1;
		}

		pr(st, " ");
	}
	ps();
}