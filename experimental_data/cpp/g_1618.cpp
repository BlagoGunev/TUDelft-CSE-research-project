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

#define FORM(x) for (map<int, int>::iterator it = (x).begin(); it < (x).end(); ++it)

 

#define MP make_pair

#define vt vector

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

#define nr(a, b) for (int ar = 0; ar < b; ar++) {cin >> (a)[ar];}

#define nr1(a, b) for (int ar = 0; ar < b; ar++) {cin >> (a)[ar+1];}

#define nr2(a, n, m) rp(ii, n){rp(jj, m) cin >> (a)[ii][jj];}

#define fs first

#define sc second

#define ub upper_bound

#define lb lower_bound

#define nl cout << endl;

 

 

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

 

struct DSU {

	vector<int> e;

	DSU(int N) { e = vector<int>(N, -1); }

 

	// get representive component (uses path compression)

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

 

	bool find(int a, int b) { return get(a) == get(b); }

 

	int size(int x) { return -e[get(x)]; }

 

	bool unite(int x, int y) {  // union by size

		x = get(x), y = get(y);

		if (x == y) return false;

		if (e[x] > e[y]) swap(x, y);

		e[x] += e[y]; e[y] = x; return true;

	}

};

 

 

void solve(){

    ll n, m, q, z;

    read(n, m, q); 

	z = n+m; 

    

	vt<pll> a, qq; 

 

	rp(i, n){

		ll x; cin >> x; 

		a.pb(MP(x, (ll)1));

	}

 

	rp(i, m){

		ll x; cin >> x; 

		a.pb(MP(x, (ll)0)); 

	}

 

	sort(all(a)); 

 

	ll pfx[z+1]; 

	pfx[0] = 0; 

	rp(i, z) pfx[i+1] = pfx[i] + a[i].fs; 

 

    ll ans[q]; 

 

	rp(i, q){

		ll x; cin >> x; 

		qq.pb(MP(x, i)); 

	}

	sort(all(qq)); 

 

    

    ll sum = 0; 

    

	ll l[z], r[z], cnt[z]; 

	rp(i, z){

		l[i] = i-1; 

		r[i] = i+1;

		cnt[i] = a[i].sc; 

		if (a[i].sc) sum += a[i].fs; 

	}

 

	vt<pll> diff; 

	rp(i, z-1){

		diff.pb(MP(a[i+1].fs - a[i].fs, i));



	}

 

	sort(all(diff)); 

 

	ll pos = 0; 

	for (auto u: qq){

 

		while (pos < z-1 && diff[pos].fs <= u.fs){

 

			ll cur = diff[pos].sc; 

			pos++; 

			ll next = r[cur]; 

			sum -= (pfx[cur+1] - pfx[cur-cnt[cur]+1] + pfx[next+1] - pfx[next-cnt[next]+1]);

			cnt[next] += cnt[cur]; 

			ll prev = l[cur]; 

			if (prev != -1){

				r[prev] = next; 

			}

			l[next] = prev; 



			sum += (pfx[next+1] - pfx[next-cnt[next]+1]);



			

		}



		ans[u.sc] = sum; 

 

	}

 

    

	rp(i, q) print(ans[i]); 

 

}

 

int32_t main() {

	quick;

 

	int t = 1; 

//	cin >> t; 

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