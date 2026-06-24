#include<bits/stdc++.h>
namespace imzzy{
	#define fi first
	#define se second
	#define rgi register int
	#define endl '\n'
	using std::cerr;
	typedef long long ll;
	typedef unsigned long long ull;
	typedef unsigned int uint;
	typedef std::pair<int,int> pii;
	class fastin{public:int _ch,_f;
	template<typename _T>inline fastin&operator>>(_T&_x){_x=0;
	while(!isdigit(_ch))_f|=(_ch=='-'),_ch=getchar();
	while(isdigit(_ch))_x=_x*10+(_ch^'0'),_ch=getchar();
	if(_f)_f=0,_x=-_x;return *this;}fastin(){_ch=_f=0;}
	}fin;
	class fastout{public:template<typename _T>inline void write(_T _x){
	if(_x<0)putchar('-'),_x=-_x;if(_x>9)write(_x/10);putchar(_x%10+'0');}
	inline fastout&operator<<(char _c){return putchar(_c),*this;}
	template<typename _T>inline fastout&operator<<(_T _x){return write(_x),*this;}
	}fout;
	std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
}using namespace imzzy;
// -------------------------------
// using namespace std;
#define int ll
const ll mod=998244353,G=3,iG=(mod+1)/G,i2=(mod+1)/2,inf=1e9+7;
const int maxn=2004,maxm=54;
inline ll powmod(ll a,ll b=mod-2) {ll res=1; for(a%=mod;b;b>>=1,(a*=a)%=mod) if(b&1) (res*=a)%=mod; return res;}
ll fact[maxn],inv[maxn],invf[maxn];

ll dp[2][maxn][maxn];
// dp[.][i][j]: coefficient of x^i e^(j/s)x
// x^i e^jx * x^a e^bx = x^(i+a) e^(j+b)x
// \sum_{i=0}^{a/k}  (-1)^i/i!  [ ((a-ik)x/s)^i + i*((a-ik)x/s)^(i-1) ]  e^((a-ik)x/s)

int n,k,a[maxm];
ll s,invs;
signed main() {
	// freopen("tmp.in","r",stdin);
	// freopen("tmp.out","w",stdout);
	// freopen("tmp.txt","w",stderr);
	inv[1]=fact[0]=invf[0]=1;
	for(rgi i=2;i<maxn;++i) inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(rgi i=1;i<maxn;++i) fact[i]=fact[i-1]*i%mod,invf[i]=invf[i-1]*inv[i]%mod;
	
	fin>>n>>k;
	for(rgi i=1;i<=n;++i) fin>>a[i],s+=a[i];
	std::sort(a+1,a+1+n,std::greater<int>());
	int o=0;
	invs=inv[s],dp[0][0][0]=1;
	for(rgi d=1;d<=n;++d) {
		o^=1,memset(dp[o],0,sizeof(dp[o]));
		for(rgi i=0;i<=s;++i) for(rgi j=0;j<=s;++j) if(dp[o^1][i][j]) {
			for(rgi p=0;p*k<a[d];++p) {
				int q=j+a[d]-p*k;
				ll mul=dp[o^1][i][j]*((p&1)?(mod-1ll):1ll)%mod*invf[p]%mod;
				(dp[o][i+p][q]+=mul*powmod((a[d]-p*k)*invs,p))%=mod;
				if(p) (dp[o][i+p-1][q]+=mul*p%mod*powmod((a[d]-p*k)*invs,p-1))%=mod;
			}
		}
	}
	
	ll ans=0,tmp;
	dp[o][0][0]=0;
	for(rgi i=0;i<=s;++i) for(rgi j=0;j<=s;++j) if(dp[o][i][j]) {
		tmp=mod-dp[o][i][j];
		(ans+=tmp*fact[i]%mod*powmod(powmod(mod+1-j*invs%mod,i+1),mod-2))%=mod;
	}
	fout<<ans;
	return 0;
}
// -------------------------------
// by imzzy.