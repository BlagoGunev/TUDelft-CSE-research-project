/*
           _                   _         _       __  __  _____ 
     /\   | |            /\   | |       | |     |  \/  |/ ____|
    /  \  | |__   ___   /  \  | |__   __| | ___ | \  / | |     
   / /\ \ | '_ \ / _ \ / /\ \ | '_ \ / _` |/ _ \| |\/| | |     
  / ____ \| |_) | (_) / ____ \| |_) | (_| | (_) | |  | | |____ 
 /_/    \_\_.__/ \___/_/    \_\_.__/ \__,_|\___/|_|  |_|\_____|
*/

// build command:
// g++ -std=gnu++17 -O3 -DDEBUG -g -fsanitize=signed-integer-overflow -fsanitize=bounds-strict -fsanitize=address -fsanitize=integer-divide-by-zero -fsanitize=float-divide-by-zero -fsanitize=pointer-overflow -fsanitize=shift-exponent -fsplit-stack -Wshadow -Wall -fconcepts -Wno-unused-result

// REMEMBER:
// BS, Offline, Persistent SegTree, SQRT, Treap, MaxFlow, FFT, Matrices

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

// DEBUG STUFF
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.

int getrand(int l,int r) {
	return uniform_int_distribution<int>(l, r)(RNG);
}

const ld eps = 1e-9;
const int mod = 1e9 + 7;
const int oo = 1e9 + 7;
const ll lloo = 1e18 + 7;
const int N = 1e6 + 7;

void solve(int tc) {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	
	map<vector<int>,int> freq1,freq2,freq3,freq;
	
	for(int i = 0 ; i < n-2 ; i++) {
		freq1[{a[i+1],a[i+2]}]++;
		freq2[{a[i],a[i+2]}]++;
		freq3[{a[i],a[i+1]}]++;
		freq[{a[i],a[i+1],a[i+2]}]++;
	}
	
	ll ans = 0;
	for(int i = 0 ; i < n-2 ; i++) {
		ans += freq1[{a[i+1],a[i+2]}];
		ans += freq2[{a[i],a[i+2]}];
		ans += freq3[{a[i],a[i+1]}];
		ans -= 3*freq[{a[i],a[i+1],a[i+2]}];
	}
	
	cout << ans/2 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	int T = 1;
	cin >> T;
	for(int i = 0 ; i < T ; i++) solve(i+1);
	return 0;
}