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
























void solve() {
	int n, m; re(n,m);

	vector< pair<int, pii> > a(n); re(a);

	for (int i = 0; i < n; i++) swap(a[i].second.first, a[i].second.second);

	set<int> seen;
	for (int i = 0; i < n; i++) seen.insert(a[i].second.first);

	vector<vi> cit(m);

	for (int i = 0; i < m; i++) {
		int k; re(k);
		cit[i].resize(k);
		re(cit[i]);

		for (int & x : cit[i]) x--;
	}
	
	

	int m1 = 0, m2 = 1000000001;
	for (int & y : cit[1]) m1 = max(m1, a[y].first);
	for (int & x : cit[0]) m2 = min(m2, a[x].first);

	
	map<int, int> probs;
	

	map<int, int> nd;

	for (int & x : cit[0]) {
		if (a[x].first >= m1+1) continue;
		if (a[x].second.second <= m1) {
			ps(-1);
			return;
		}

		int tp = a[x].second.first;
		if (probs.count(tp)) {
			ctmin(probs[tp], a[x].second.second);
			ctmin(nd[tp], a[x].first);
		}
		else {
			probs[tp] = a[x].second.second;
			nd[tp] = a[x].first;
		}
	} 

	for (int & y : cit[1]) {
		int tp = a[y].second.first;
		if (probs.count(tp) && a[y].second.second >= probs[tp] && a[y].first >= m2) {
			ps(-1);
			return;
		}
	}

	int t1 = 0;
	for (int i = 0; i < 2*n; i++) {
		while (seen.count(t1)) t1++;
		seen.insert(t1);
		probs[t1] = m1+1;
	}
	for (int i = 0; i < 2*n; i++) {
		while (seen.count(t1)) t1++;
		seen.insert(t1);
		probs[t1] = m2;
	}

	ps(sz(probs));
	for (auto [tp, d] : probs) {
		ps(d, tp);
	}
}