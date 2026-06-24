#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define repr(i,a,b) for (ll i = a; i > b; --i)
#define mm(lamb, tttt) memset(lamb, tttt, sizeof lamb)

#define null NULL
#define eps 0.000000001
#define mod 1000000007
#define PI 3.14159265358979323846
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define ALL(V) V.begin(), V.end()
#define sz(V) (ll)V.size()
#define _ <<" "<<

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector<vi> vvi;
typedef pair <ll, ll> ii;
typedef pair<ll, pair<ll,ll> > iii;
typedef vector<ii> vii;

map<ll, ll> m;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;cin>>n;
	rep(i, 0, n) {
		string s;cin>>s;
		ll cnt = 0;
		ll cur = 0;
		for (auto ch : s) {
			cnt += (ch == '(' ? 1 : -1);
			if (cnt < 0) cnt++, cur ++;
		}
		if (cnt > 0 and cur > 0) continue;
		else if (cnt > 0) m[cnt]++;
		else if (cur > 0) m[-cur]++;
		else m[0]++;
	}
	ll ans = 0;
	for (auto v : m) {
		if (v.fi > 0) break;
		if (v.fi == 0) {
			ans += v.se/2;
			break;
		}
		else {
			if (m.count(-v.fi) > 0) ans += min(v.se, m[-v.fi]);
		}
	}
	cout<<ans<<endl;
	return 0;
}