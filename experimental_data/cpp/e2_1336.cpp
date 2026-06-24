// LUOGU_RID: 99313073
#include<bits/stdc++.h>

#define LL long long

#define mod 998244353

using namespace std;

int n,m,cnt=0,idt=0;

LL x;

int id[62];

LL a[62],b[62],t[62],ans[62],pw[200002],ipw[62];

LL c[62][62];

inline void init()

{

	for(int i=0;i<=m;++i)for(int j=c[i][0]=1;j<=i;++j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;

}

inline void ins(LL x)

{

	for(int i=m-1;~i;--i)if((x>>i)&1)

	{

		if(!a[i])return (void)(a[i]=x,++cnt);

		x^=a[i];

	}

}

inline void dfs(int x,LL y)

{

	if(x>idt)return (void)(++ans[__builtin_popcountll(y)]);

	dfs(x+1,y),dfs(x+1,y^a[id[x]]);

}

inline void solve1()

{

	for(int i=0;i<m;++i)if(a[i])id[++idt]=i;

	dfs(1,0);

}

inline void dfs1(int x,LL y)

{

	if(x>idt)return (void)(++t[__builtin_popcountll(y)]);

	dfs1(x+1,y),dfs1(x+1,y^b[id[x]]);

}

inline void solve2()

{

	for(int i=m-1;~i;--i)if(a[i])for(int j=m-1;j>i;--j)if((a[j]>>i)&1)a[j]^=a[i];

	for(int i=m-1;~i;--i)if(!a[i])

	{

		b[i]=(1LL<<i),id[++idt]=i;

		for(int j=m-1;j>i;--j)if((a[j]>>i)&1)b[i]|=(1LL<<j);

	}

	dfs1(1,0);

	for(int i=0;i<=m;++i)

	{

		for(int j=0;j<=i;++j)for(int k=j;k<=m;++k)(ans[i]+=(j&1? -1:1)*((c[k][j]*c[m-k][i-j])%mod)*t[k])%=mod;

		(((ans[i]*=ipw[m])%=mod)*=pw[cnt])%=mod;

	}

}

int main()

{

	scanf("%d%d",&n,&m),init();

	for(int i=pw[0]=1;i<=n;++i)scanf("%lld",&x),ins(x),pw[i]=(pw[i-1]<<1)%mod;

	for(int i=ipw[0]=1;i<=m;++i)ipw[i]=(ipw[i-1]*((mod+1)>>1))%mod;

	if(cnt<=26)solve1();

	else solve2();

	for(int i=0;i<=m;++i)printf("%lld ",((ans[i]+mod)*pw[n-cnt])%mod);

	return 0;

}