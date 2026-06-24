// LUOGU_RID: 100884088
#include<iostream>

#include<cstdio>

#include<algorithm>

#include<vector>

#include<iomanip>

#include<cmath>

#include<cstring>

#include<functional>

#include<set>

#include<unordered_map>

#include<random>

#include<iomanip>

#include<queue>

#pragma GCC optimize("Ofast")

using namespace std;

template<typename T>

inline bool cmax(T&x,const T& y){return x<y?x=y,1:0;}

template<typename T>

inline bool cmin(T&x,const T& y){return y<x?x=y,1:0;}

typedef long long ll;

typedef pair<int,int> pii;

typedef vector<int> vi;

typedef vector<vector<int> > vii; 

typedef unsigned long long ull;

#define X first

#define Y second

const int mod=998244353;

inline void MOD(int&x){x-=mod,x+=x>>31&mod;}

inline void add(int& x,int y){MOD(x+=y);}

inline int mul(int x,int y){return 1ll*x*y%mod;}

inline ll ksm(ll a,ll p=mod-2)

{

	ll ans=1;

	for(;p;p>>=1,a=a*a%mod)if(p&1)ans=ans*a%mod;

	return ans;

}

typedef long double LD;

const int MAXN=114514;

vector<ll>pr;

int jc[MAXN],inv[MAXN];

inline int getans(ll x)

{

	int ans=1,sum=0;

	for(auto&p:pr)if(x%p==0)

	{

		int cnt=0;

		while(x%p==0)x/=p,cnt++;

		sum+=cnt;

		ans=mul(ans,inv[cnt]);

	}

	return mul(ans,jc[sum]);

}

int main()

{

	jc[0]=1;for(int i=1;i<MAXN;i++)jc[i]=mul(jc[i-1],i);

	inv[MAXN-1]=ksm(jc[MAXN-1]);for(int i=MAXN-1;i;i--)inv[i-1]=mul(inv[i],i);

	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(10);

	ll n;

	cin>>n;

	for(ll i=2;i*i<=n;i++)if(n%i==0)

	{

		while(n%i==0)n/=i;

		pr.push_back(i);

	}

	if(n>1) pr.push_back(n);

	int T;

	cin>>T;

	while(T--)

	{

		ll x,y;

		cin>>x>>y;

		ll g=__gcd(x,y);

		cout<<mul(getans(x/g),getans(y/g))<<'\n';

	}

	return 0;

}