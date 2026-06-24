#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define ld long double
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,x,n) for(int i=x;i<n;++i)
#define forn(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define itr_ iterator
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define m_p make_pair
#define debug(x) cout<<#x<<":"<<x<<endl;
#define lowbit(x) (x&(-x))
#define setp setprecision
#define over(x) {cout<<x<<endl;return;}
using namespace std;
const int INF=0x3f3f3f3f;
const ll INFL=1e18;
const ll mod=998244353;
const ld eps=1e-14;
int qpow(int a,int b,int m=mod,int res=1){
	a%=m;
	while(b>0)res=(b&1)?(res*a%m):(res),a=a*a%m,b>>=1;
	return res;
}
int fac[2000005],inv[2000005];
void init(int n){
	fac[0]=inv[0]=1;
	REP(i,1,n+1)fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;--i)inv[i]=inv[i+1]*(i+1)%mod;
}
int binom(int x,int y){
	return x<y||y<0? 0:fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int f[1000005],g[1000005];

void tc(){
	int x;
	cin>>x;
	cout<<g[x]<<endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	forn(i,4,1000000){
		f[i]=(f[i-1]*i%mod+i-2)%mod;
	}
	per(i,1000000,4){
		f[i]=(f[i]-f[i-1]+mod)%mod;
	}
	g[1]=0,g[2]=1,g[3]=2,g[4]=5,g[5]=19;
	forn(i,6,1e6){
		g[i]=(f[i]+g[i-1]*2%mod-g[i-2]+mod)%mod;
	}
	int T=1;
	cin>>T;
	while(T--){
		tc();
	}
	return 0;
}