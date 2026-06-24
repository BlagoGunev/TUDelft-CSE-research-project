#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

#define MOD 1000000007
 
void test_case(){
	int n;
	cin >> n;
	
	vector<int> x(n);
	for(int i=0; i<n; i++) cin >> x[i];
	
	vector<int> pwr(n);
	pwr[0] = 1;
	for(int i=1; i<n; i++) pwr[i] = (pwr[i-1]*2) %  MOD;
	
	int ans = 0;
	
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			int lval = 2*x[i] - x[j];
			int llower = abs(lower_bound(x.begin(), x.begin() + i, lval) - x.begin());
			int rval = 2*x[j] - x[i];
			int rlower = abs(lower_bound(x.begin() + j, x.end(), rval) - x.end());
			ans += pwr[llower + rlower];
			ans = ans % MOD;
		}
	}
	
	cout<<ans<<endl;
	return;
}
 
 
using LL = long long;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	// cin >> T;
	while (T--) {
		test_case();
	}
}