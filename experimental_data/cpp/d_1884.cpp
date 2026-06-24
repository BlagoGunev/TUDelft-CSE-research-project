/*
    IN THE NAME OF GOD
*/
#include <bits/stdc++.h>

// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

#define F                                      first
#define S                                      second
#define Mp                                     make_pair
#define pb                                     push_back
#define pf                                     push_front
#define size(x)                                ((ll)x.size())
#define all(x)                                 (x).begin(),(x).end()
#define kill(x)		                           cout << x << '\n', exit(0);
#define fuck(x)                                cout << "(" << #x << " , " << x << ")" << endl
#define endl                                   '\n'

const int N = 2e6+23, lg = 18;
ll Mod = 1e9+7; //998244353;

inline ll MOD(ll a, ll mod=Mod) {a%=mod; (a<0)&&(a+=mod); return a;}
inline ll poww(ll a, ll b, ll mod=Mod) {
    ll ans = 1;
    a=MOD(a, mod);
    while (b) {
        if (b & 1) ans = MOD(ans*a, mod);
        b >>= 1;
        a = MOD(a*a, mod);
    }
    return ans;
}

ll n, t, a[N], cnt[N], cnt2[N], dp[N];
int mark[N];

void solve() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]; cnt[a[i]]++;
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j+=i) cnt2[i] += cnt[j];
		if(cnt[i] > 0) {
			for(int j=i; j<=n; j+=i) mark[j] = 1;
		}
	}

	ll ans = 0;
	for(int i=n; i>=1; i--) {
		dp[i] = cnt2[i]*(cnt2[i]-1)/2;
		for(int j=2*i; j<=n; j+=i) {
			dp[i] -= dp[j];
		}
		if(mark[i] == 0) ans += dp[i];
	}

	cout<<ans<<endl;
}

void reset() {
	fill(cnt, cnt+n+2, 0);
	fill(cnt2, cnt2+n+2, 0);
	fill(dp, dp+n+2, 0);
	fill(mark, mark+n+2, 0);
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);

	cin>>t;
	while(t--) {
		solve();
		reset();
	}

	return 0;
}