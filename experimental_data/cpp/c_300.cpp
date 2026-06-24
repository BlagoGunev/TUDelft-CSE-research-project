#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i,n) for((int)(i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second
#define inf int(2e9)
#define sz(x) int((x).size())
#define sqr(x) (x) * (x)

const double eps = 1e-9;
const double pi = acos(-1.0);
typedef long long ll;

int mod = 1000000007;

int a, b, n;
ll fact[1000111];


bool check(int x) {
 	if(x == 0) return (a == 0 || b == 0);
 	while(x) {
 	 	if(x % 10 != b && x % 10 != a) return 0;
 	 	x /= 10;
 	}
 	return 1;
}

ll binpow (ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1LL;
	}
	return res;
}

ll rev(ll x) {
 	return binpow(x, mod - 2);
}


ll c(int n, int k) {
        return ((fact[n] * rev(fact[n - k])) % mod * rev(fact[k])) % mod;
}
int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	cin >> a >> b >> n;
	fact[0] = 1;
	for(int i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % mod;

	ll ans = 0;
	for(int x = 0; x <= n; ++x) {
	 	int y = n - x, sum = a * x + b * y;
	 	if(check(sum)) {
	 		ans = (ans + c(n, x)) % mod;
	 	}
	}

	cout << ans;
	
	return 0; 
}