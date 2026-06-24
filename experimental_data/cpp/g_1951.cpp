/* Code by pp_orange */
//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define m_p(a,b) make_pair(a,b)
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
#define inf 0x7FFFFFFF
#define inff 9223372036854775807
#define rep(i,l,r) for(int i=l;i<r;++i)
#define repp(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r-1;i>=l;--i)
#define pper(i,r,l) for(int i=r;i>=l;--i)
#define pii pair<int,int>
#define fi first
#define se second
#define p_q priority_queue
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define lb(x) ((x)&-(x))
#define lg(x) (31^__builtin_clz(x))
#define vi vector<int>
#define vii vector<pii >
#define vT vector<T>
#define mm1 mint(1)
const int mod = 1000000007;
//#define int ll
const int intsz = sizeof(int);
using namespace std;
inline int rd(){
	int x(0),f(1);char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
inline void out(int X){
	if(X<0) {X=~(X-1); putchar('-');}
	if(X>9) out(X/10);
	putchar(X%10+'0');
}
ll pw(ll x,int d){
	ll t = 1;
	for(;d;d>>=1,x=x*x%mod)if(d&1)t = t*x%mod;
	return t;
}
#define MAX 600005
struct mint{
	int v;
	mint(){v = 0;}
	mint(int x){v = x;if(v<0)v+=mod;}
	const mint inv()const {return mint(pw(v,mod-2));}
	const bool empty()const {return (v==0);}
	void set(int x){v=x;return ;}
	mint& operator += (const mint y){v+=y.v;if(v>=mod)v-=mod;return *this;}
	const mint operator + (const mint y)const {int rlt=v+y.v;if(rlt>=mod)rlt-=mod;return rlt;}
	mint& operator -= (const mint y){v-=y.v;if(v<0)v+=mod;return *this;}
	const mint operator - (const mint y)const {int rlt=v-y.v;if(rlt<0)rlt+=mod;return rlt;}
	mint& operator *= (const mint y){v=(ll)v*y.v%mod;return *this;}
	const mint operator * (const mint y)const {return (ll)v*y.v%mod;}
	mint& operator /= (const mint y){v=(ll)v*pw(y.v,mod-2)%mod;return *this;}
	const mint operator / (const mint y)const {return (ll)v*pw(y.v,mod-2)%mod;}
	const bool operator < (const mint y)const {assert(false);return 0;}
	const bool operator > (const mint y)const {assert(false);return 0;}
	const bool operator == (const mint y)const {return (v==y.v);};
	const bool operator != (const mint y)const {return (v!=y.v);};
	const mint operator - ()const {return mint(-v);}
};
ostream & operator << (ostream & cout , mint x){cout<<x.v;return cout;}
mint pw(mint x,int d){
	mint t = 1;
	for(;d;d>>=1,x=x*x)if(d&1)t = t*x;
	return t;
}
mint fac[MAX],ifac[MAX],idig[MAX];
struct combinit{
	combinit(){
		fac[0] = mint(1);
		rep(i,1,MAX)fac[i] = fac[i-1]*i;
		ifac[MAX-1] = fac[MAX-1].inv();
		pper(i,MAX-2,0)ifac[i] = ifac[i+1]*(i+1);
		rep(i,1,MAX)idig[i] = ifac[i]*fac[i-1];
	}
}combinit;
mint Comb(int x,int y){//choose y from x itms
	if(x<0||y<0||y>x)return 0;
	return fac[x]*ifac[y]*ifac[x-y];
}
int a[MAX];
signed main(){
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	int T = rd();
	while(T--){
		int n = rd();
		int m = rd();
		repp(i,1,n)a[i] = rd()%m;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		sort(a+1,a+1+n);
		mint ans = mm1*m*(m-1)*(m+1)/6;
		a[n+1] = a[1]+m;
		repp(i,1,n){
			int l = a[i+1]-a[i];
			ans -= mm1*(l+1)*l*(l-1)/6;
		}
		ans = ans/m*n;
		cout<<ans<<endl;
	}
	return 0;
}