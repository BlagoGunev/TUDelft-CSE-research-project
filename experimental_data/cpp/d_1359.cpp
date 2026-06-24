// Author: envy <3 uwu

// Problem: D. Yet Another Yet Another Task

// Attempted: 2023-02-11 13:58:59 EST



#include <bits/stdc++.h>

#ifndef LOCAL

#define debug(...) 0

#else

#include "C:\programmingfunnyxd\debug.cpp"

#endif

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

const ll INF = 1e18;

 

#define F first

#define S second

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define pb push_back

#define pq priority_queue

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)

#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)

#define ROF(i,a,b) for(int i = (a); i >= (b); --i)

#define trav(a,x) for(auto& a: x)

#define sz(x) (int)x.size()

#define make_unique(v) sort(all(v)); v.erase(unique(all(v)), v.end())



template<class T> using minpq = pq<T, vector<T>, greater<T>>;

template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}

template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>

	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};

template<typename T> struct vt<1, T> : public vector<T> {

	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};

template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};



void solve() {

	int n; cin >> n;

	vector<int> a(n); cin >> a;

	

	int ans = 0;

	FORE(mx,-30,30){

		int mx_end = 0, cur_mx = -1e9;

		trav(i, a){

			if(i > mx){

				mx_end = 0;

				continue;

			}

			mx_end += i;

			ckmax(cur_mx, mx_end);

			ckmax(mx_end, 0);

		}

		ckmax(ans, cur_mx - mx);

	}

	cout << ans << "\n";

}



signed main() {

	cin.tie(0) -> sync_with_stdio(0);

	int t = 1;

	//cin >> t;

	for(int test = 1; test <= t; test++){

		solve();

	}

}