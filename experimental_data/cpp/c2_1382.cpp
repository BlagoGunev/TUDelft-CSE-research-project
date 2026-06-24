// Problem: C2. Префиксные перевороты (сложная версия)

// Contest: Codeforces - Codeforces Round #658 (Div. 2)

// URL: https://codeforces.com/problemset/problem/1382/C2

// Memory Limit: 256 MB

// Time Limit: 1000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



//#pragma GCC optomize ("Ofast")

//#pragma GCC optomize ("unroll-loops")

//#pragma GCC target ("avx,avx2,fma")



#include <bits/stdc++.h>

#define F first

#define S second

#define pb push_back

#define sz size

#define cl clear

#define ins insert

#define ers erase

#define pii pair < int , int >

#define pll pair< long long  , long long >

#define all(x) x.begin() , x.end()

#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

#define tostr(x) to_string(x)

#define tonum(s) atoi(s.c_str())

#define seon(x) setprecision(x)

#define bpop(x) __builtin_popcount(x)

#define deb(x) cerr << #x  << " = " << x << endl;



typedef long long ll;

typedef unsigned long long ull;

typedef double db;

typedef long double ldb;

const double PI = 3.14159265;



const ll N = 2e5+5;

const ll inf = 1e9;

const ll INF = 1e18;

const ll mod = 998244353;



using namespace std;



vector<pii> v , v1;

vector<int> ans;

void solve(){

	v.cl();

	v1.cl();

	ans.cl();

	int n;

	cin >> n;

	string a;

	cin >> a;

	string b;

	cin >> b;

	for(int i = 1; i < n; i++){

		if(a[i] != a[i-1]) v.pb({a[i-1]-'0' , i});

	}

	v.pb({a[n-1]-'0' , n});

	for(int i = 1; i < n; i++){

		if(b[i] != b[i-1]) v1.pb({b[i-1]-'0' , i});

	}

	v1.pb({b[n-1]-'0' , n});

	int cnt = 0;

	for(int i = v.sz()-2 ; i >= 0; i--){

		if((v[i].F^cnt) != v.back().F){

			ans.pb(v[i].S);

			cnt ^= 1;

		}

	}

	reverse(all(ans));

	cnt = v.back().F;

	for(int i = v1.sz()-1; i >= 0; i--){

		if(cnt != v1[i].F){

			ans.pb(v1[i].S);

			cnt ^= 1;

		} 

	}

	cout << ans.sz() <<" ";

	for(int x : ans) cout << x <<" ";

	cout << "\n";

}

signed main(){

	ios;

	int t;

	cin >> t;

	while(t--){

		solve();

	}

	return 0;

}

/*

*/