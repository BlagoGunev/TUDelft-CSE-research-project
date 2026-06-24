#include <algorithm> 
#include <iostream> 
#include <valarray> 
#include <iomanip> 
#include <fstream> 
#include <sstream> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <complex> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <bitset> 
#include <ctime> 
#include <cmath> 
#include <queue> 
#include <stack> 
#include <deque> 
#include <map> 
#include <set> 

using namespace std; 

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i) 
#define FOR(i, a, n) for (int i = (a); i < int(n); ++i) 
#define error(x) cout << #x << " = " << (x) << endl; 
#define all(n) (n).begin(), (n).end() 
#define Size(n) ((int)(n).size()) 
#define mk make_pair 
#define pb push_back 
#define F first 
#define S second 

int _;
#define scanf _ = scanf

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef complex<double> point; 

template <class P, class Q> void smin(P &a, Q b) { if (b < a) a = b; } 
template <class P, class Q> void smax(P &a, Q b) { if (b > a) a = b; } 
template <class P, class Q> bool in(const P &a, const Q &b) { return a.find(b) != a.end(); }

const int MAXK = 11*1000, MAXN = 101*1000;


ll h;
ll dp[MAXK];
int k, n, m, c[MAXN];
ll a[MAXN];

struct by_c { bool operator() (const int a, const int b) const { if (c[a] != c[b]) return c[a] > c[b]; return a < b; } };
struct by_a { bool operator() (const int _a, const int b) const { if (a[_a] != a[b]) return a[_a] > a[b]; return _a < b; } };

set<int, by_a> candidates[MAXK];
set<int, by_c> available;

bool mark[MAXK];

void add_operation(ll x) {
	fill(mark, mark+k, false);
	FOR(cur, 0, k) if (!mark[cur]) {
		vector<int> p;
		int now = cur;
		while (!mark[now]) {
			p.pb(now);
			mark[now] = true;
			now = (now+x)%k;
		}
		FOR(rep, 0, 2) FOR(ind, 0, Size(p)) {
			int i = p[ind];
			int j = p[(ind+1)%Size(p)];
			if (dp[j] > dp[i]+x) {
				dp[j] = dp[i]+x;
				while (!candidates[j].empty() && a[*candidates[j].begin()] >= dp[j]) {
					int cur = *candidates[j].begin();
					candidates[j].erase(cur);
					available.insert(cur);
				}
			}
		}
	}
}

void decrease_resource(int x, int y) {
	if (in(available, x)) {
		available.erase(x);
		c[x] -= y;
		available.insert(x);
	} else c[x] -= y;
}

void stats() {
	return;

	cout << "dp:";
	FOR(i, 0, k) cout << " " << dp[i];
	cout << endl;
	FOR(i, 0, k) {
		cout << i << ":";
		FOREACH(it, candidates[i]) cout << " " << *it << "(" << a[*it] << ")";
		cout << endl;
	}
	cout << "av:";
	FOREACH(it, available) cout << " " << *it << "(" << c[*it] << ")";
	cout << endl << endl;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> h >> n >> m >> k;

	fill(dp, dp+k, h);
	dp[0] = 0;

	FOR(i, 0, n) {
		cin >> a[i] >> c[i];
		a[i]--;
		candidates[a[i]%k].insert(i);
	}

	stats();

	FOREACH(it, candidates[0]) available.insert(*it);
	candidates[0].clear();

	while (m--) {
		
		stats();

		int tp;
		cin >> tp;
		if (tp == 1) {
			ll x;
			cin >> x;
			add_operation(x);
		} else if (tp == 2) {
			int x, y;
			cin >> x >> y;
			decrease_resource(x-1, y);
		} else if (tp == 3) {
			if (!available.empty()) {
				int best = *available.begin();
				cout << c[best] << "\n";
				decrease_resource(best, c[best]);
			} else {
				cout << 0 << "\n";
			}
		}
	}

	stats();

	return 0;
}