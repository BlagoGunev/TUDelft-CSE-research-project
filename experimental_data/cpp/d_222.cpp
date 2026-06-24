#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define forn(i, n) for(int i = 0;i < n;i++)

typedef long long ll;
typedef unsigned long long llu;

const int inf = 2e9;
const double eps = 1e-7;
const double pi = 3.1415926535;

vector < int > a, b;

int main() {
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	x--;
	a.resize(n);
	b.resize(n);
	forn(i, n) {
		cin >> a[i];
	}
	forn(i, n) {
		cin >> b[i];
	}
	sort(all(a));
	sort(all(b));
	int points = inf;
	int i1 = -1, i2 = -1;
	forn(i, n) {
		vector < int > :: iterator it = upper_bound(all(b), x - a[i]);
		if(it == b.end()) continue;
		if(a[i] + *it < points) {
			points = a[i] + *it;
			i1 = i;
			i2 = (int)(it - b.begin());
		}
	}
	x++;
	if(i1 == -1 || i2 == -1) throw 42;
	int l = 0, r = n - 1;
	int ans = 0;
	while(l < n && r >= 0) {
		while(l < n && a[l] + b[r] < points) l++;
		if(l < n) ans++;
		l++;
		r--;
	}
	cout << 1 << " " << ans << endl;
	return 0;
}