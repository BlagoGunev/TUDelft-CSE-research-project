#include <bits/stdc++.h>

#include <chrono> 

 

using namespace std;

using namespace std::chrono; 

 

 #pragma GCC target ("avx2")

 #pragma GCC optimization ("O3")

 #pragma GCC optimization ("unroll-loops")

 #pragma optimization_level 3

 #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")

 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

 

#define f0r(a, b) for (int a = 0; a < (b); ++a)

#define f1r(a, b, c) for (int a = (b); a < (c); ++a)

#define f0rd(a, b) for (int a = (b); a >= 0; --a)

#define f1rd(a, b, c) for (int a = (b); a >= (c); --a)

#define ms(arr, v) memset(arr, v, sizeof(arr))

#define pb push_back

#define send {ios_base::sync_with_stdio(false);}

#define help {cin.tie(NULL); cout.tie(NULL);}

#define fix(prec) {cout << setprecision(prec) << fixed;}

#define mp make_pair

#define f first

#define s second

#define all(v) v.begin(), v.end()

#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}

#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}

#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];

#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];

#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}

#define vsz(x) ((long long) x.size())

typedef long long ll;

typedef long double lld;

typedef unsigned long long ull;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef vector<pii> vpi;

typedef vector<pll> vpl;

 

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {

	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";

}

template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {

	cin >> p.first;

	return cin >> p.second;

}

 

mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// mt19937 rng(61378913);

/* usage - just do rng() */

 

void usaco(string filename) {

  // #pragma message("be careful, freopen may be wrong")

	freopen((filename + ".in").c_str(), "r", stdin);

	freopen((filename + ".out").c_str(), "w", stdout);

}

 

const lld pi = 3.14159265358979323846;

 const ll mod = 1000000007;

// const ll mod = 998244353;

// ll mod;







//ll n, m, k, q, l, r, x, y, z;

const ll tas = 1e6 + 585;

//ll a[template_array_size];

//ll b[template_array_size];

//ll c[template_array_size];

string s, t;

ll ans = 0;

int n;

bool get(int aa[],int val){

	vi v;

	f0r(i,n){

		if(aa[i]!=val){

			v.pb(aa[i]);

		}

	}

	int k=v.size()-1;

	int i=0;

	while(i<=k){

		if(v[i]!=v[k])

		return false;

		i++;

		k--;

	}

	return true;

}



void solve(int tc = 0) {

	cin>>n;

	int a[n];

	f0r(i,n){

		cin>>a[i];

	}

	int j=n-1;int i=0;

	int k=0;

	while(i<=j){

		if(a[i]!=a[j]){

			if(get(a,a[i])|| get(a,a[j])){

				cout<<"YES"<<endl;

				return;

			}

			else{

				k=-1;

				break;

			}

		}

		else{

			i++;

			j--;

		}

	}

	if(k!=-1){

		cout<<"YES"<<endl;

	}

	else

	cout<<"NO"<<endl;

}

 

int main() {

	#ifdef farhaan_mahmood_local

		auto begin = std::chrono::high_resolution_clock::now();

	#endif

	

	send help

 

	#ifndef farhaan_mahmood_local

		// usaco("cowland");

	#endif

	

	// usaco("cowland");

 

	int tc = 1;

	 cin >> tc;

	for (int t = 0; t < tc; t++) solve(t);

	

	#ifdef farhaan_mahmood_local

		auto end = std::chrono::high_resolution_clock::now();

		cout << setprecision(12) << fixed;

		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;

	#endif

}