#include<bits/stdc++.h>

using namespace std;const int N=1<<18,mod=998244353;

int n,m,a[18][N],l,r,S,k,tot,i,j,pw[18][N];char s[N];

int main(){

	for(scanf("%d%s%d",&n,s+1,&m),i=1;i<=n;++i)tot+=(s[i]=='?');

	for(i=1;i<18;++i)for(j=pw[i][0]=1;j<=tot;++j)pw[i][j]=pw[i][j-1]*1LL*i%mod;

	for(j=1;j<18;++j)for(i=2;i<=2*n;++i)for(l=i/2,S=0,k=tot;l;l--)

		if((r=i-l)>n)break;else if(s[l]=='?'&&s[r]=='?')a[j][S]=(a[j][S]+pw[j][k-=(l!=r)])%mod;

		else if(s[l]=='?'||s[r]=='?')S|=1<<(s[l]+s[r]-'?'-97),a[j][S]=(a[j][S]+pw[j][--k])%mod;

		else if(s[l]==s[r])a[j][S]=(a[j][S]+pw[j][k])%mod;else break;

	for(i=0;i<17;++i)for(j=0;j<(1<<17);++j)if(j>>i&1)for(k=1;k<18;++k)(a[k][j]+=a[k][j^(1<<i)])%=mod;

	for(;m--;printf("%d\n",a[i-1][k]))for(scanf("%s",s+1),k=0,i=1;s[i];++i)k|=1<<s[i]-'a';

}