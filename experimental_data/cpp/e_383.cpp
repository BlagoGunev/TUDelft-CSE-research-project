#include <ext/algorithm>
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

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef complex<double> point;

template <class P, class Q> void smin(P &a, Q b) { if (b < a) a = b; } 
template <class P, class Q> void smax(P &a, Q b) { if (b > a) a = b; } 
template <class P, class Q> bool in(const P &a, const Q &b) { return a.find(b) != a.end(); }

const int LIM = 1<<24;

struct subproblem {
	int a[LIM];
	
	void add(int index, int value = 1) {
		a[index] += value;
	}

	void solve(int start = 0, int size = LIM) {
		if (size == 1)
			return;
		int half = size/2;
		solve(start, half);
		solve(start+half, half);
		FOR(i, 0, half)
			a[start+half+i] += a[start+i];
	}
};

subproblem sp;

int main() {
	int n;
	cin >> n;
	
	FOR(rep, 0, n) {
		string s;
		cin >> s;
		FOR(mask, 1, 1<<3) {
			int gr = __builtin_popcount(mask)-1;
			int who = 0;
			FOR(i, 0, 3)
				if (mask&(1<<i))
					who |= 1<<(s[i]-'a');
			sp.add(who, gr%2?-1:+1);
		}
	}

	sp.solve();

	int total = 0;
	FOR(i, 0, LIM) {
		int me = sp.a[i];
		total ^= me*me;
	}

	cout << total << endl;
	return 0;
}