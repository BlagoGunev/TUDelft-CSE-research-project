// Problem: D. Balanced String
// Contest: Educational Codeforces Round 153 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1860/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
hxz还是爬的好
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define wt int tt=d;while(tt--)
#define py puts("Yes")
#define pn puts("No")
#define pritnf printf
#define edfl endl
#define fe(i,e) for(int i=0;i<e.size();i++)
#define vi vector<ll>
inline ll rd() {
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
namespace binom{
	const ll Lim=300010,mod=998244353;
	ll jc[Lim],inv[Lim],inc[Lim];
	void pre(){
		jc[0]=jc[1]=inc[0]=inc[1]=inv[0]=inv[1]=1;
		f(i,2,Lim-1)jc[i]=jc[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod,
		inc[i]=inc[i-1]*inv[i]%mod;
	}ll C(ll n,ll m){if(n<0||m<0||n<m)return 0;return jc[n]*inc[m]%mod*inc[n-m]%mod;}
}
// using namespace binom;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
#define d rd()
#define pb push_back
const ll N=300010;
struct edge{ll v,w,nx;}e[N<<1];
ll hd[N],cnt;
void add(ll u,ll v,ll w){e[++cnt]=(edge){v,w,hd[u]};hd[u]=cnt;}
ll qp(ll a,ll b,ll p){
	ll ans=1;while(b){
		if(b&1)ans=ans*a%p;
		a=a*a%p;b>>=1;
	}return ans;
}ll n,m,a,b;
char c[110];
ll dp[2][110][5010];
int main(){
	cin>>c+1;n=strlen(c+1);
	f(i,1,n){
		if(c[i]=='0')a++;
		else b++;
	}ll K=n*(n+1)/2-a*(a+1)/2+b*(b+1)/2;
	K/=2;memset(dp[0],0x3f,sizeof(dp[0]));
	dp[0][0][0]=0;f(i,1,n){
		memset(dp[i&1],0x3f,sizeof(dp[i&1]));
		f(k,0,K)f(j,0,b){
			dp[i&1][j][k]=min(dp[i&1][j][k],dp[i&1^1][j][k]+(c[i]=='1'));
			dp[i&1][j+1][k+i]=min(dp[i&1][j+1][k+i],dp[i&1^1][j][k]+(c[i]=='0'));
		}
	}cout<<dp[n&1][b][K]/2;
	return 0;
}
/*
wy还是爬的好
*/