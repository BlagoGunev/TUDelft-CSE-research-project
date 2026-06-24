// LUOGU_RID: 98574949
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sqr(x) ((x)*(x))
#define all(x) (x).begin(),(x).end()
#define Tim ((double)clock()/CLOCKS_PER_SEC)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
int const N=1e7+10;
int const mod=1e9+7;
int fac[N],inv[N];
inline int qpow(int a,int b,int t=1){for(;b;b>>=1,a=a*a%mod)if(b&1)t=t*a%mod;return t;}
inline int C(int n,int m){if (n<m || m<0) return 0;return fac[n]*inv[m]%mod*inv[n-m]%mod;}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fac[0]=1;
	for (int i=1;i<N;++i) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=qpow(fac[N-1],mod-2);
	for (int i=N-2;~i;--i) inv[i]=inv[i+1]*(i+1)%mod;
	int t;cin>>t;
	while (t--){
		int n,m;cin>>n>>m;
		int ans=0,f=0,g=0,h=0;
		for (int i=0;i<=m;++i){
			int x=C(m,i);
			f+=i*i%mod*x%mod;f%=mod;
			g+=i*x%mod;g%=mod;
			h+=x;h%=mod;
		}
		for (int i=1;i<=n;++i){
			int s=(f+(2*i+1)*g%mod+(i*i%mod+i)%mod*h%mod)%mod;
			ans+=s*C(n,i)%mod*C(m+i-1,i-1)%mod;
			ans%=mod;
		}
		cout<<ans*qpow(n,mod-2)%mod<<'\n';
	}
	return 0;
}