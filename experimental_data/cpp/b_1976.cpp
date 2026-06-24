#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define ret(msg) cout << msg << '\n'; return
#define rep(i,a,b) for(ll i = a; i < b; i++)
#define rrep(i,a,b) for(ll i = a; i >= b; i--)
#define iter(v) for(auto &el:v)
#define trav(a, v) for(auto&a:v)
#define all(x) x.begin(),x.end()
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0)
template<typename T> void print(T t, bool newln = true){
	cout << t;
	if(newln) cout << '\n';
	else cout << " ";
}
template<typename T> void print(vector<T> t){
	iter(t) print(el, false);
	cout << '\n';
}
template<typename T, typename U> void print(pair<T, U> t){
	print(t.F, false);
	print(t.S);
}
template<typename T> void read(T &t){
	cin >> t;
}
template<typename T> void read(vector<T> &t){
	iter(t) read(el);
}
template<typename T, typename U> void read(pair<T, U> &t){
	cin >> t.F >> t.S;
}
template<typename T, typename... Args> void read(T& t, Args&... args){
	read(t);
	read(args...);
}

void solve(){
    ll n; read(n);
    vll a(n); read(a);
    vll b(n+1); read(b);
    ll ans = 0;
    rep(i,0,n) ans += llabs(a[i] - b[i]);
    ll best = 1e18;
    rep(i,0,n){
        ll m = min(a[i], b[i]);
        ll M = max(a[i], b[i]);
        if(m <= b[n] && M >= b[n]){
            best = 0;
        } else if (M < b[n]){
            best = min(best, b[n] - M);
        } else if (m > b[n]){
            best = min(best, m - b[n]);
        }
    }
    ans += best;
    ans++;
    print(ans);
}

int main(){
	FAST;
	int t; cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}