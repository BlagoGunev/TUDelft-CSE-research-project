//File uses UTF-8 encoding.
//By: Luogu@tzl_Dedicatus545(UID:308854) Yuanshen@tzl_Dedicatus(UID:273152640)
//Ayaka bless me!
// #define _TZL_DEBUG_
#if defined(_TZL_DEBUG_) && defined(TZL_MEOW)
#define GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define rep(i,x,y,z) for(int i=(x);i<=(y);i+=(z))
#define per(i,x,y,z) for(int i=(x);i>=(y);i-=(z))
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define i128 __int128
#define _1 first
#define _2 second
#define ld long double
#define cint const int
#define pcnt __builtin_popcountll
#define vint vector<int>
#define vpii vector<pair<int,int> >
using namespace std;

const int inf=(sizeof(int)==4?0x3f3f3f3f:0x3f3f3f3f3f3f3f3f);
const int mod=998244353;
const long double EPS=1e-7;
const int maxn=2.2e5;
int gcd(int a,int b){
	unsigned az=__builtin_ctz(a),bz=__builtin_ctz(b);unsigned z=min(az,bz);b>>=bz;
	while(a){	a>>=az;int d=a-b;az=__builtin_ctz(d),b=min(a,b),a=(d<0?-d:d);}
	return b<<z;
}
int read()
{
	int ch = getchar(), t = 1, n = 0;
	while (ch < '0' || ch > '9') { if (ch == '-') t = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { n = n * 10 + ch - '0', ch = getchar(); }
	return n * t;
}
template<typename T>void chkmin(T& x,const T& y){return y<x?(x=y,void()):void();}
template<typename T>void chkmax(T& x,const T& y){return x<y?(x=y,void()):void();}
bool Mbe;
pii operator+(const pii &x,const pii &y){return {x._1+y._1,x._2+y._2};}
pii operator%(const pii &x,const int &y){return {x._1%y,x._2%y};};
pii operator*(const pii &x,const int &y){return {x._1*y,x._2*y};};
void inc(int &x,int y){	x=(x+y>=mod?x+y-mod:x+y);}
void dec(int &x,int y){	x=(x-y<0?x-y+mod:x-y);}
int mul(vint vec){int ans=1;for(auto x:vec)	ans*=x,ans%=mod;return ans;}

int fac[maxn],finv[maxn];
ll fpow(ll x,int y){
	ll rt=1;
	for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) rt=1ll*rt*x%mod;
	return rt;
}int inv(int x){	return fpow(x,mod-2);}
void init(int n){
#if 1
	fac[0]=fac[1]=1;finv[0]=finv[1]=1;
	rep(i,2,n,1){	fac[i]=1ll*fac[i-1]*i%mod;}finv[n]=inv(fac[n]);
	per(i,n-1,1,1){	finv[i]=1ll*finv[i+1]*(i+1)%mod;}
#endif
}int C(int n,int m){
	if(n<m || n<0 || m<0)	return 0;
	return 1ll*fac[n]*finv[m]%mod*finv[n-m]%mod;
}

//Think at 8:30
//8:35 : 0
//8:40：容斥，钦定S中只能给同组
//8:48 : 0
//Code at 8:54
//Fin at 9:10

vint vec[maxn];
int c[maxn];
int f[210][210];
int g[210][210];

bool Med;
signed main()
{ios::sync_with_stdio(0);cin.tie(0);init(maxn-1);cerr<<fixed<<setprecision(3)<<(&Mbe-&Med)/1048576.0<<"MiB"<<endl;
	int n;cin>>n;
	rep(i,1,n,1)	vec[i].pb(-1);
	rep(i,1,n,1)	cin>>c[i];
	rep(i,1,n,1){int t;cin>>t;vec[t].pb(i);}
	g[0][0]=1;
	rep(i,1,n,1){
		rep(j,0,n,1)	rep(k,0,n,1)	f[j][k]=0;
		f[0][0]=1;int su=0;
		rep(j,1,(int)vec[i].size()-1,1){
			int t=c[vec[i][j]];
			su+=t;
			rep(k,0,n,1){
				rep(w,0,min(k,t),1){
					inc(f[j][k],f[j-1][k-w]*finv[w]%mod*finv[t-w]%mod);
				}
			}
		}int cu=vec[i].size()-1;
		rep(j,0,n,1){
			rep(k,0,min(j,cu),1){	//k张票被钦定
				if(k%2==0)	inc(g[i][j],g[i-1][j-k]*f[cu][k]%mod*finv[cu-k]%mod*fac[cu]%mod);
				else		dec(g[i][j],g[i-1][j-k]*f[cu][k]%mod*finv[cu-k]%mod*fac[cu]%mod);
			}
		}
	}int ans=0;rep(i,0,n,1){
		inc(ans,g[n][i]*fac[n-i]%mod);
	}
	cout<<ans%mod<<endl;
	return 0;
}