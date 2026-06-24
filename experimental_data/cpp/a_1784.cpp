// LUOGU_RID: 101695931
// Problem: Monsters (easy version)

// Contest: Luogu

// URL: https://www.luogu.com.cn/problem/CF1784A

// Memory Limit: 500 MB

// Time Limit: 4000 ms

// time: 2023-02-08 14:16:55



#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")

using namespace std;

template<typename T>

inline bool cmax(T&x,const T& y){return x<y?x=y,1:0;}

template<typename T>

inline bool cmin(T&x,const T& y){return y<x?x=y,1:0;}

typedef long long ll;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;

typedef vector<int> vi;

typedef vector<vector<int> > vii; 

typedef unsigned long long ull;

#define sz(x) (int(x.size()))

#define all(x) (x).begin(),(x).end()

#define X first

#define Y second

const int mod=998244353;

inline void MOD(int&x){x-=mod,x+=x>>31&mod;}

inline void MOD(ll& x){x-=mod,x+=x>>63&mod;}

inline void add(int& x,int y){MOD(x+=y);}

inline int mul(int x,int y){return 1ll*x*y%mod;}

template<typename ... A>

int mul(const int& x,const A&... p){return 1ll*x*mul(p...)%mod;}

inline ll ksm(ll a,ll p=mod-2)

{

	ll ans=1;

	for(;p;p>>=1,a=a*a%mod)if(p&1)ans=ans*a%mod;

	return ans;

}

typedef long double LD;

const int MAXN=2e5+10;

int a[MAXN];

inline void solve()

{

	int n;

	cin>>n;

	vi cnt(n+1);

	for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;

	int tt=0;

	for(int i=1;i<=n;i++)while(cnt[i]--)a[++tt]=i;

	ll ans=0,c=0;

	for(int i=1;i<=n;i++)

	{

		if(a[i]>c)c++;

		ans+=a[i]-c;

	}

	cout<<ans<<'\n';

}

int main()

{

	

	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(10);

	int T;

	cin>>T;

	while(T--)solve();

	return 0;

}