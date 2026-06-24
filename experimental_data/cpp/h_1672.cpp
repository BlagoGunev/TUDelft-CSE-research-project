#include<map>

#include<ctime>

#include<cmath>

#include<queue>

#include<bitset>

#include<cstdio>

#include<vector>

#include<random>

#include<cstdlib>

#include<cstring>

#include<iostream>

#include<algorithm>

#define ll long long

using namespace std;

#define I inline ll

#define her1 20090115

#define IV inline void

#define cht 998244353

#define ld long double

#define Aestas16 392699

#define ull unsigned long long

#define mem(x,val)memset(x,val,sizeof x)

#define D(i,j,n)for(register int i=j;i>=n;i--)

#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)

#define F(i,j,n)for(register int i=j;i<=n;i++)

#define DL(i,j,n)for(register ll i=j;i>=n;i--)

#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)

#define FL(i,j,n)for(register ll i=j;i<=n;i++)

//#define D(i,j,n)for(int i=j;i>=n;i--)

//#define E(i,now)for(int i=first[now];i;i=e[i].nxt)

//#define F(i,j,n)for(int i=j;i<=n;i++)

//#define DL(i,j,n)for(ll i=j;i>=n;i--)

//#define EL(i,now)for(ll i=first[now];i;i=e[i].nxt)

//#define FL(i,j,n)for(ll i=j;i<=n;i++)

ll read(){

	ll ans=0,f=1;

	char c=getchar();

	while(c<'0'||c>'9'){

		if(c=='-')f=-1;

		c=getchar();

	}

	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();

	return ans*f;

}

mt19937 rnd(her1);

const int maxn = 1e6+5;

ll n,q,sum0[maxn],sum1[maxn];char s[maxn];

int main(){

	n=read();q=read();scanf("%s",s+1);

	F(i,2,n)sum0[i]=sum0[i-1]+(s[i]=='0'&&s[i-1]=='0');

	F(i,2,n)sum1[i]=sum1[i-1]+(s[i]=='1'&&s[i-1]=='1');

	while(q--){ll x=read(),y=read();printf("%lld\n",max(sum0[y]-sum0[x],sum1[y]-sum1[x])+1);}

	return 0;

}