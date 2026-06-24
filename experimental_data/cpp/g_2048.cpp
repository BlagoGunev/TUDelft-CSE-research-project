#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,del##i##verme=int(n);i<del##i##verme;++i)
#define rep1(i,n) for(int i=1,parano##i##a=int(n);i<=parano##i##a;++i)
#define per(i,n) for(int i=int(n)-1;i>=0;--i)
#define per1(i,n) for(int i=int(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define y0 LingLuo
#define y1 VividCycle
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
using namespace std;
const ll mod1=998244353;
unsigned time_related_rand()
{
	return unsigned(std::chrono::steady_clock::now().time_since_epoch().count());
}
int t,n,v,m;
ll fac[1000005],ivf[1000005];
ll qkpw(ll x,ll y)
{
	if(x==0) return y==0;
	if(x==1) return 1;
	ll r=1;
	while(y)
	{
		if(y&1)r=r*x%mod1;
		x=x*x%mod1;
		y>>=1;
	}
	return r;
}
void init()
{
	fac[0]=1;rep1(i,1000000)fac[i]=fac[i-1]*i%mod1;
	ivf[1000000]=qkpw(fac[1000000],mod1-2);per(i,1000000)ivf[i]=ivf[i+1]*(i+1)%mod1;
}
ll f(int a,int b)
{
	ll ans=0;
	rep(i,n+1)
	{
		ll cur=fac[n]*ivf[i]%mod1*ivf[n-i]%mod1;
		ll nw=(qkpw(v,n-i)*qkpw(a-1,i)-qkpw(v-b,n-i)*qkpw(a-b-1,i))%mod1;
		ll qaq=qkpw(nw,m)*cur%mod1;
		if(i&1)ans-=qaq;
		else ans+=qaq;
	}
	return ans%=mod1;
}
void Q()
{
	ll res=0;
	cin>>n>>m>>v;
	rep1(i,v-1)
	{
		res+=f(i+1,i);
		if(i>=2) res-=f(i+1,i-1);
	}
	res=qkpw(v,n*1ll*m)-res;
	res%=mod1;if(res<0)res+=mod1;
	cout<<res<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;init();
	while(t--)
	Q();
	return 0; 
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not ?????? or few affect?
*/