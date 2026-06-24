#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in insert
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

#define int long long

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
// typedef pair<int, int> P;

template<typename T, typename U>
ostream & operator << (ostream &out, const pair<T, U> &c) {
	out << c.first << ' ' << c.second;
	return out;
}

template<typename T>
ostream & operator << (ostream &out, vector<T> &v) {
	const int sz = v.size();
	for (int i = 0; i < sz; i++) {
		if (i) out << ' ';
		out << v[i];
	}
	return out;
}

template<typename T>
istream & operator >> (istream &in, vector<T> &v) {
	for (T &x : v) in >> x;
	return in;
}

template<typename T, typename U>
	istream & operator >> (istream &in, pair<T, U> &c) {
	in >> c.first;
	in >> c.second;
	return in;
}

template<typename T>
void mxx(T &a, T b){if(b > a) a = b;}
template<typename T>
void mnn(T &a, T b){if(b < a) a = b;}

const int mxn = 2e5 + 10, MXLOG = 22, mod = 1e9 + 7;// P = 1181, D = 1523, N = 2500;
const long long inf = 2e18 + 10;

void go() {
	int n, p;
	cin >> n >> p;
	vector<int> c(n);
	cin >> c;
	vector<int> id(n);
	iota(all(id), 0ll);
	sort(all(id), [&](int x, int y) {
		if(c[x] == c[y]) return x > y;
		else return c[x] < c[y];
	});

	vector<int> fn(n + 1, 0);

	auto add = [&](int x, int y) -> void {
		x++;
		for(; x <= n; x += (x & -x)) {
			fn[x] += y;
		}
	};

	auto get = [&](int x) -> int {
		x++;
		int ret = 0;
		for(; x > 0; x -= (x & -x)) {
			ret += fn[x];
		}
		return ret;
	};

	int ans = 0;
	set<pair<int, int>> s;
	for(int i = 0; i < n; i++) {
		add(i, p);
		s.emplace(-i, p);
	}
	for(int i : id) {
		if(get(i - 1) < c[i]) continue;
		ans++;
		while(c[i] > 0) {
			auto val = *s.upper_bound(make_pair(-i, inf));
			s.erase(val);
			add(-val.ff, -val.ss);
			if(val.ss >= c[i]) {
				val.ss -= c[i];
				c[i] = 0;
			} else {
				c[i] -= val.ss;
				val.ss = 0;
			}
			add(-val.ff, val.ss);
			if(val.ss != 0) s.in(val);
		}
	}
	cout << ans << endl;
}


signed main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--) {
		go();
	}
	return 0;
}