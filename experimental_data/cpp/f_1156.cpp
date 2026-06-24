#include<bits/stdc++.h>
using namespace std;
#define N 5011
#define LL long long
#define mp make_pair
#define MOD 998244353
LL n,cnt,a[N],f[N][N],s[N],inv[N];
pair<LL,LL>b[N];
LL qow(LL x,LL y){return y?(y&1?x*qow(x,y-1)%MOD:qow(x*x%MOD,y/2)):1;}
int main()
{
	for(LL i=1;i<N;i++)
	  inv[i]=qow(i,MOD-2);
	scanf("%I64d",&n);
	for(LL i=1;i<=n;i++)
	  scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for(LL i=1;i<=n;i++)
	  if(a[i]==a[i-1])b[cnt].second++;
	  else b[++cnt]=mp(a[i],1);
	for(LL i=1;i<=cnt;i++)
	  s[i]=s[i-1]+b[i].second;
	for(LL i=cnt;i>=1;i--)
	  for(LL j=1;j<=s[i-1]+1;j++)
	    {
	    f[i][j]=f[i+1][j+1];
	    f[i][j]+=b[i].second-1;
	    (f[i][j]*=inv[n-j])%=MOD;
	    f[i][j]=(b[i].second*f[i][j]+f[i+1][j])%MOD;
		}
	printf("%I64d\n",f[1][1]*inv[n]%MOD);
}