#include<map>

#include<set>

#include<queue>

#include<deque>

#include<cmath>

#include<ctime>

#include<bitset>

#include<vector>

#include<cstdio>

#include<string>

#include<cassert>

#include<cstdlib>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<unordered_map>

using namespace std;

typedef long long ll;

typedef unsigned int uint;

typedef unsigned long long ull;

#define pc putchar

#define sp pc(' ')

#define en pc('\n')

#define gc getchar()

#define lb lower_bound

#define ub upper_bound

#define eb emplace_back

#define fs fflush(stdout)

#define ump unordered_map

#define pq priority_queue

#define clz __builtin_clz

#define ctz __builtin_ctz

#define sz(x) (int)x.size()

#define np next_permutation

#define clzl __builtin_clzll

#define par __builtin_parity

#define ctzl __builtin_ctzll

#define ppc __builtin_popcount

#define parl __builtin_parityll

#define all(x) x.begin(),x.end()

#define ppcl __builtin_popcountll

#define fpi(x) freopen(x,"r",stdin)

#define fpo(x) freopen(x,"w",stdout)

#define ms(x,y) memset(x,y,sizeof(x))

#define dbg(x) cerr<<"In Line "<<__LINE__<<' '<<#x<<'='<<x<<'\n'

template<class T> inline T &re(T &x){

	x=0;int f=1;char ch=gc;

	while(ch<48||ch>57){if(ch==45) f=-f;ch=gc;}

	while(ch>47&&ch<58) x=(x<<1)+(x<<3)+(ch^48),ch=gc;

	return x*=f;

}

template<class T> inline void pr(T x){

	static char buf[40];static int cnt=0;

	if(x<0) pc(45),x=-x;

	do buf[++cnt]=x%10^48;while(x/=10);

	do pc(buf[cnt--]);while(cnt);

}

#define mod 1000000007

#define inf 0x3f3f3f3f

int dp[405][205],mul[405],inv[405],fac[205],ans[205],C[405][405];

inline int rmod(int x){return x-mod+(x-mod>>31&mod);}

int main(){

	int n=re(n),k=re(k),i,j,l;

	mul[0]=inv[1]=fac[0]=ans[0]=dp[0][0]=1;

	for(i=0;i<=k<<1;i++){C[i][0]=1;for(j=1;j<=i;j++) C[i][j]=rmod(C[i-1][j-1]+C[i-1][j]);}

	for(i=2;i<=k<<1;i++) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;

	for(i=1;i<=k<<1;i++) mul[i]=(n-i+1ll)*mul[i-1]%mod*inv[i]%mod;

	for(i=1;i<=k;i++) fac[i]=(ll)fac[i-1]*i%mod;

	for(i=1;i<=k;i++) for(j=0;j<i;j++) for(l=0;l<=j<<1;l++) dp[l+i-j+1][i]=(dp[l+i-j+1][i]+(ll)fac[i-j]*dp[l][j]%mod*C[l+i-j][i-j])%mod; 

	for(i=1;i<=k;i++) for(j=i+1;j<=i<<1;j++) ans[i]=(ans[i]+(ll)dp[j][i]*mul[j])%mod;

	for(i=1;i<=k;i++){int sum=0;for(j=i;j>-1;j-=2) sum=rmod(sum+ans[j]);pr(sum),sp;}

	return 0;

}