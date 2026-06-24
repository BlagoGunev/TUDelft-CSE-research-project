#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <assert.h>
#include <ctime>
#include <bitset>
#include <numeric>
#include <complex>
using namespace std;

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define FORE(i, a, n) for (i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
#define ll long long
#define pb push_back
#define error(x) cout << #x << " = " << (x) << endl;
#define ull unsigned long long
#define pii pair<int, int>
//#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define point complex<double>
//#define X real()
//#define Y imag()
#define X first
#define Y second
#define EPS 1e-10
//#define endl "\n"
#define pdd pair<double, double>
//#define mp make_pair

const int MAXN = 1001*1000;
int n, m, d[MAXN];
ll tot = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	FOR(i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		d[a]++;
		d[b]++;
	}
	FOR(i, 0, n) tot += 1LL*d[i]*(n-1-d[i]);
	cout << 1LL*n*(n-1)*(n-2)/6 - tot/2 << endl;
	return 0;
}