#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <string>
#include <climits>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <list>
#include <random>
#include <deque>
#include <functional>
#include <iomanip>
#include <fstream>
#include <complex>
#include <numeric>
#include <immintrin.h>
#include <cassert>
#include <array>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef long double ld;

#define FOR(i,a) for (int i=0;i<(a);++i)
#define FORD(i,a) for (int i=(a)-1;i>=0;i--)
#define FORT(i,a,b) for (int i=(a);i<=(b);++i)
#define FORTD(i,b,a) for (int i=(b);i>=(a);--i)
#define trav(i,v) for (auto i : v)
#define all(v) v.begin(),v.end()
#define fr first
#define sc second
#define mpr(a,b) make_pair(a,b)
#define pir pair<int,int>
#define all(v) v.begin(),v.end()
#define make_unique(v) v.erase(unique(all(v),v.end())
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define dbg(x);
#define dbgv(v);
#define y1 EsiHancagorcRepa
#ifdef ALEXPC
#define dbg(x); cout<<#x<<" = "<<x<<endl
#define dbgv(v); cout<<#v<<" = ["; trav(tv,v)cout<<"tv,";cout<<"]"<<endl
#endif

const int N = 3 * 1e5 + 6;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	fastio;
	ll m;
	int a, b;
	cin >> m >> a >> b;
	int gd = gcd(a, b);
	int tv = 0, mx = 0;
	ll qan = 0, ans = 0;
	while (tv < min(a + b - gd, (int)m  + 1)) {
		ans += (ll)(min(a + b - gd, (int)m + 1) - mx);
		if (tv >= b)tv -= b;
		else tv += a;
		mx = max(tv, mx);
	}
	if (m +1 <= a + b - gd) {
		cout << ans << endl;
		return 0;
	}
	//cout << ans << endl;
	a /= gd;
	b /= gd;
	
	ll ss = (a + b - 1)*gd;
	//cout << ans << endl;
	//cout << m - ss + 1 << endl;
	ans += (m - ss+1ll)*(ll)(a + b);
	//cout << ans << endl;
	ll qn = (m - ss + 1ll) / gd;
	ans += gd*qn * (qn - 1ll)/2ll;
	ans += (ll)((m - ss + 1ll) % gd)*qn;
	cout << ans << endl;
	return 0;
}