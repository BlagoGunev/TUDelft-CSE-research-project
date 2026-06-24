#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0) 
#define sz(a) (a).size()
#define triple pair<pill, ll>
#define pinode pair<node*, node*>
#define quadra pair<pill, pill>
#define ld long double
using namespace std;
 
const ll N = 2e5 + 10;
const ll M = 2e5 + 1;
const ll big = 1e18;
const ll hsh2 = 1964325029 ;
const long long mod = 1e9 + 7;
const long double EPS = 1e-14;
const ll block = 1e7;
const ll shift = 2e3;
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());

ll t;
ll a[N];
ll F[N];
ll bp(ll b, ll c) {
	ll d = 1;
	while(c) {
		if(c&1)
			d = b * d % mod;
		c >>= 1;
		b = b * b % mod;	
	}
	return d;
}

ll inv(ll a) {
	return bp(a, mod - 2);
}
ll C(ll n, ll k) {
	if(n < k)
		return 0;
	return F[n] * inv(F[n - k] * F[k] % mod) % mod;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    F[0] = 1;
	for(int i = 1; i <= n; i++)
		cin >> a[i], F[i] = F[i - 1] * i % mod;
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for(ll i = 1, l = 1; i <= n; i++) {
		while(a[i] - a[l] > k)
			l++;
		ans = (ans + C(i - l, m - 1)) % mod;
	}
	cout << ans << '\n';
}

int main() {
	speed;
	cin >> t;
	while(t--)solve(); 	
}              
/*
qiwwqdesw
1
d
 
*/