#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lwb lower_bound
#define upb upper_bound
#define ld double
#define ins insert
#define del erase
#define ull unsigned long long
using namespace std;
const ll big=3e6+9;
const ll sml=1e3+9;
const ll tny=20;
const ll inf=1e15;
const ll hug=1e6+9;
const ll mod=998244353;
struct tr{
	ll fi,se,th;
	tr(ll _fi=0, ll _se=0, ll _th=0){fi=_fi; se=_se; th=_th;}
};
ll mxz(ll &t, ll val){if (t<val){t=val; return 1;} return 0;}
ll mnz(ll &t, ll val){if (t>val){t=val; return 1;} return 0;}
ll qpw(ll n, ll k, ll m=mod){ll p=1, t=n%m; while (k){if (k&1) p=p*t%m; t=t*t%m; k>>=1;} return p;}
ll n,m,k,q;
ll d[big];
ll dp[big];
ll fac[big], inv[big];
ll phi[big];
ll solve(){
	ll a,b,c; cin>>a>>b>>c>>n;
	for (ll i=1; i<=n; ++i) cin>>d[i];
	ll gcdd=0;
	for (ll i=1; i<=n; ++i) gcdd=__gcd(gcdd,d[i]);
	ll cub=a*b*c;
	for (ll i=1; i*i<=cub; ++i) if (cub%i==0){
		if (gcdd%i==0){
			ll tmp=fac[cub/i];
			for (ll j=1; j<=n; ++j) tmp=tmp*inv[d[j]/i]%mod;
			dp[cub/i]=tmp;
		}
		if (gcdd%(cub/i)==0){
			ll tmp=fac[i];
			for (ll j=1; j<=n; ++j) tmp=tmp*inv[d[j]/(cub/i)]%mod;
			dp[i]=tmp;
		}
	}
	ll sol=0;
	vector<ll> faca, facb, facc;
	for (ll i=1; i<=a; ++i) if (a%i==0) faca.eb(i);
	for (ll i=1; i<=b; ++i) if (b%i==0) facb.eb(i);
	for (ll i=1; i<=c; ++i) if (c%i==0) facc.eb(i);
	for (ll i: faca) for (ll j: facb) for (ll k: facc){
		ll cur=i*j/__gcd(i,j);
		cur=cur*k/__gcd(cur,k);
		if (gcdd%cur) continue;
		sol=(sol+phi[i]*phi[j]*phi[k]%mod*dp[cub/cur])%mod;
	}
	sol=sol*qpw(cub,mod-2)%mod;
	cout<<sol<<"\n";
	return 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("INPUT.TXT","r",stdin);
//    freopen("OUTPUT.TXT","w",stdout);
	fac[0]=1; for (ll i=1; i<big; ++i) fac[i]=fac[i-1]*i%mod;
	inv[big-1]=qpw(fac[big-1],mod-2); for (ll i=big-2; i>=0; --i) inv[i]=inv[i+1]*(i+1)%mod;
	for (ll i=1; i<big; ++i) phi[i]=i;
	for (ll i=2; i<big; ++i) if (phi[i]==i) for (ll j=i; j<big; j+=i) phi[j]-=phi[j]/i;
	ll tst=1;
	cin>>tst;
	for (; tst; --tst) solve();
    return 0;
}