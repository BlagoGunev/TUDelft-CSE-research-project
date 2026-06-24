#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define deb2(x,y) cerr<<#x<<" = "<<x<<"  "<<#y<<" = "<<y<<endl;
#define print(x) for (auto k:x) cout<<k<<" ";cout<<endl;
#define debmp(x) for(auto k:x) cout<<k.first<<" "<<k.second<<endl;
#define ll long long
#define mod 998244353
#define ff first
#define ss second
#define pb push_back
#define inf 1e18
#define endl "\n"
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

ll add(ll a, ll b) {a = a % mod; b = b % mod; return ((a + b) % mod + mod) % mod;}
ll sub(ll a, ll b) {a = a % mod; b = b % mod; return ((a - b) % mod + mod) % mod;}
ll mul(ll a, ll b) {a = a % mod; b = b % mod; return ((1ll * a * b) % mod + mod) % mod;}
ll expo(ll a, ll n) {ll ans = 1; a = a % mod; while (n) {if (n % 2) {ans = ((ans % mod) * (a % mod)) % mod; n--;} else {a = ((a % mod) * (a % mod)) % mod; n = n / 2;}} return ans;}
ll dv(ll a, ll b) {a = a % mod; b = b % mod; return (a * expo(b, mod - 2)) % mod;}

void solve();


int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	t = 1;

	cin >> t;
	for (ll test = 1; test <= t; test++)
	{
		//cout << "Case #" << test << ": ";
		solve();
	}
	return 0;
}

inline void solve()
{
	ll a, b, x, y, z;
	cin >> a >> b;

	if (b == 1)
	{
		cout << "NO" << endl;
		return;
	}

	x = a;
	y = a * (b - 1);
	z = a * b;

	if (x == y)
	{
		x = 3 * a;
		y = a * (b - 1);
		z = 4 * a;
	}

	cout << "YES" << endl;
	cout << x << " " << y << " " << z << endl;

}