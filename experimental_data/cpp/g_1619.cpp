#pragma GCC optimize ("O3")

 

#include <bits/stdc++.h>

using namespace std;

 

typedef long long ll;

typedef long double ld;

typedef unsigned long long ull;

typedef vector<int> vi;

typedef vector<long long> vl;

typedef vector<vector<int>> vii;

typedef pair<int, int> pii;

typedef pair<long long, long long> pll;

typedef map<int, int> mii;

 

#define rp(i, e) for (int (i) = 0; (i) < (int) (e); (i)+=1)

#define rp2(i, a, e) for (int (i) = (a); (i) < (int) (e); (i)+=1)

#define rp3(i, a, e, s) for (int (i) = (a); (i) < (int) (e); (i)+=(s))

#define rp4(i, a, e) for (int (i) = a; (i) > (int) (e); (i)-=1)

#define rp5(i, a, e, s) for (int (i) = a; (i) > (int) (e); (i)+=(s))

 

#define MP make_pair

#define vt vector

#define ar array

#define pb push_back

#define ins insert

#define sz(x) int(x.size())

#define len(x) sz(x)

#define str string

#define tstr(x) to_string(x)

#define all(x) (x).begin(),(x).end()

#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#define fd(x, e) (x.find(e) != x.end())

#define rva(a, n) sort((a), (a)+(n)); reverse((a), (a)+(n));

#define rvs(s) reverse(all(s));

#define nr(a, b) for (int aa = 0; aa < b; aa++) {cin >> (a)[aa];}

#define nr1(a, b) for (int aa = 0; aa < b; aa++) {cin >> (a)[aa+1];}

#define nr2(a, n, m) rp(ii, n){rp(jj, m) cin >> (a)[ii][jj];}

#define fs first

#define sc second

#define ub upper_bound

#define lb lower_bound

#define nl cout << endl;



template <class T> void sort(T &V){ sort(V.begin(), V.end()); }



#define umax(x) *max_element(begin(a), end(a))

#define umin(x) *min_element(begin(a), end(a))

 

template <class T> bool amin(T & a, const T & b) {return b<a?a=b, 1:0;}

template <class T> bool amax(T & a, const T & b) {return a<b?a=b, 1:0;}

 

template<class A> void read(vt<A>& v);

template<class A, size_t S> void read(array<A, S>& a);

template<class T> void read(T& x) { cin >> x;}

 

void read(double& d) {

	string t;

	read(t);

	d=stod(t);

}

void read(long double& d) {

	string t;

	read(t);

	d=stold(t);

}

template<class H, class... T> void read(H& h, T&... t) {

	read(h);

	read(t...);

}

template<class A> void read(vt<A>& x) {

	for (auto a: x)

		read(a);

}

template<class A, size_t S> void read(array<A, S>& x) {

	for (auto a: x)

		read(a);

}

 

str to_string(char c) {

	return string(1, c);

}

str to_string(bool b) {

	return b?"true":"false";

}

str to_string(const char* s) {

	return string(s);

}

str to_string(string s) {

	return s;

}

str to_string(vt<bool> v) {

	string res;

	rp(i, sz(v))

		res+=char('0'+v[i]);

	return res;

}

 

template<size_t S> str to_string(bitset<S> b) {

	string res;

	rp(i, S)

		res+=char('0'+b[i]);

	return res;

}

template<class T> str to_string(T v) {

    bool f=1;

    string res;

    for (auto x: v) {

		if(!f)

			res+=' ';

		f=0;

		res+=to_string(x);

	}

    return res;

}

 

template<class A> void write(A x) {

	cout << to_string(x);

}

template<class H, class... T> void write(const H& h, const T&... t) { 

	write(h);

	write(t...);

}

void print() {

	write("\n");

}

template<class H, class... T> void print(const H& h, const T&... t) { 

	write(h);

	if(sizeof...(t))

		write(' ');

	print(t...);

}



int inf = 1e9+1; 



struct DSU {

	vector<int> e;

	vector<int> f; 



	DSU(int N) { e = vector<int>(N, -1); f = vector<int>(N, -1);}



	// get representive component (uses path compression)

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }



	bool same(int a, int b) { return get(a) == get(b); }



	int size(int x) { return -e[get(x)]; }



	int set(int x, int a) { return f[x] = a; }



	int val(int x) { return f[get(x)]; }

	//int val(int n, int a) { return f[n] >= 0 ? f[n] : f[n] = a; }



	bool unite(int a, int b) {  // union by size

		int x = get(a), y = get(b);

		if (x == y) return false;

		if (e[x] > e[y]) swap(x, y);

		e[x] += e[y]; e[y] = x;

		amin(f[x], f[y]); 

		return true;

	}

};

 

void solve(){

	int n, k; 

	read(n, k); 



	//unite by x, y, k

	//sort scc >, return ans 



	DSU d(n); 





	vt<ar<int, 3>> a, b;  



	rp(i, n){

		int x, y, z; 

		read(x, y, z);

		d.set(i, z); 

		a.pb({x, y, i}); 

		b.pb({y, x, i}); 

	}



	sort(a); 

	sort(b); 



	rp(i, n-1){

		if (a[i][0] == a[i+1][0] && a[i+1][1] - a[i][1] <= k){

			d.unite(a[i][2], a[i+1][2]); 

		}

		if (b[i][0] == b[i+1][0] && b[i+1][1] - b[i][1] <= k){

			d.unite(b[i][2], b[i+1][2]); 

		}

	}



	set<int> s; 

	rp(i, n){

		s.ins(d.get(i)); 

	}



	vector<int> v; 

	for (auto u: s){

		v.pb(d.val(u));

	}



	sort(all(v), greater<int>());



	int ans = 0;



	rp(i, sz(v)){

		amax(ans, min(i, v[i])); 

	}



	print(ans); 



    return;

}

 

int32_t main() {

	quick;

 

	int t = 1; 

	cin >> t; 

	while (t--) solve();

	

    return 0;

}

 

 

 

 

/* stuff you should look for

	* int overflow, ainvay bounds

	* special cases (n=1?)

	* do smth instead of nothing and stay organized

	* WRITE STUFF DOWN

	* DON'T GET STUCK ON ONE APPROACH

*/