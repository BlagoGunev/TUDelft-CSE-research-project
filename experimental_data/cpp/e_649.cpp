// #pragma optimize ("g",on)
// #pragma GCC optimize("inline")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC optimize ("03")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")

#include <bits/stdc++.h>

#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout);
#define adiyer(); ios_base::sync_with_stdio(0); cin.tie(0);
#define bitcount(n) __builtin_popcountll(n)
#define puts(x) (x ? "YES\n" : "NO\n");
#define ent (i == n ? '\n' : ' ')
#define all(x) x.begin(), x.end()
#define md ((l + r) >> 1)
#define rv(v) ((v << 1) | 1)
#define lv(v) (v << 1)
#define rs(v) rv(v), md + 1, r
#define ls(v) lv(v), l, md
#define len(s) (int) s.size()

#define pb push_back
#define S second
#define F first

// #define int long long

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector < ll > vll;
typedef pair < ll, ll > pll;
typedef vector < pair < ll, ll > > vpll;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int N = 2e5 + 3;
const int K = 750;
const int mod = 998244353;
const ll inf = 1e9 + 11;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll n, k;
ll lf[N], rg[N], id[N];

pair < pll, ll > a[N];

vll v;

bool f(ll x){
	v.clear();
	set < pll > q;
	for(ll i = 1; i <= n; i++){
		while(len(q) && (*q.begin()).F <= lf[i])
			v.pb((*q.begin()).S), q.erase(q.begin());
		if(len(q) == x){ 
			if((*q.rbegin()).F > rg[i]) q.erase(*q.rbegin()), q.insert({rg[i], id[i]});
		} else {
			q.insert({rg[i], id[i]});
		}
	}
	for(auto it : q) v.pb(it.S);
	return len(v) >= k;
}

void output(){
	cin >> n >> k;
	for(ll i = 1; i <= n; i++) cin >> a[i].F.F >> a[i].F.S, a[i].S = i;
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++) lf[i] = a[i].F.F, rg[i] = lf[i] + a[i].F.S, id[i] = a[i].S;
	ll l = 0, r = k;
	while(r - l > 1){
		if(f(md)) r = md;
		else l = md;
	}
	f(r), sort(all(v)), cout << r << '\n';
	while(len(v) > k) v.pop_back();
	for(ll x : v) cout << x << ' ';
}

const bool cases = 0;

signed main(){
//  file("disrupt");
    adiyer(); 
    int tt = 1;
    if(cases) cin >> tt;
    for(int i = 1; i <= tt; i++){
    	output();
		// stupid();
    	// stress();
    }	
}