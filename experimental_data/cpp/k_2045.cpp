#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long cnt[200001],c[200001],pw2[200001],pw34[200001],f[200001],g[200001],val[200001],miu[200001];
bool npri[200001];
int pri[200000],pc=0;
void gen(long long n){
	long long i,j;
	npri[1]=1;
	miu[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!npri[i])
		{
			pri[pc]=i;
			miu[i]=-1;
			pc++;
		}
		for(j=0;j<pc&&i*pri[j]<=n;j++)
		{
			npri[i*pri[j]]=1;
			if(i%pri[j]==0)break;
			miu[i*pri[j]]=-miu[i]%mod;
		}
	}
}
long long gcd(long long a,long long b){
	return b>0?gcd(b,a%b):a;
}
long long solve(long long n){
	long long i,j,t,s,s2,a,b,lc,ans;
	s=0;
	for(i=1;i<=n;i++)s=(s+miu[i]*pw2[c[i]])%mod;
	for(i=1;i<=n;i++)val[i]=s;
	for(i=1;i<=n;i++)
	{
		for(j=1;i*j<=n;j++)
		{
			if(gcd(i,j)!=1)continue;
			for(t=1;i*j*t<=n;t++)
			{
				a=i*t;
				b=j*t;
				lc=i*j*t;
				if(miu[b]==0)continue;
				if(miu[b]==1)val[a]=(val[a]+pw2[c[b]]*(pw34[c[lc]]+mod-1))%mod;
				else
				{
					val[a]+=mod-pw2[c[b]]*(pw34[c[lc]]+mod-1)%mod;
					if(val[a]>=mod)val[a]-=mod;
				}
			}
		}
	}
	for(i=1;i<=n;i++)val[i]=(val[i]*pw2[c[i]])%mod;
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(miu[i]==0)continue;
		if(miu[i]==1)ans=(ans+val[i])%mod;
		else ans=(ans+mod-val[i])%mod;
	}
	for(i=1;i<=n;i++)val[i]=1;
	s=0;
	for(i=1;i<=n;i++)
	{
		if(miu[i]==0)continue;
		if(miu[i]==1)s=(s+val[i])%mod;
		else s=(s+mod-val[i])%mod;
	}
	for(i=1;i<=n;i++)val[i]=(pw2[c[i]]+mod-1)%mod;
	s2=0;
	for(i=1;i<=n;i++)
	{
		if(miu[i]==0)continue;
		if(miu[i]==1)s2=(s2+val[i])%mod;
		else s2=(s2+mod-val[i])%mod;
	}
	ans=(ans+mod-s2*s*2%mod+mod-s*s%mod)%mod;
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	long long n,i,j,a,ans;
	cin>>n;
	gen(n);
	for(i=0;i<n;i++)
	{
		cin>>a;
		cnt[a]++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i*2;j<=n;j+=i)cnt[i]+=cnt[j];
	}
	pw2[0]=1;
	pw34[0]=1;
	pw2[1]=2;
	pw34[1]=(mod-mod/2)*(mod-mod/2)%mod*3%mod;
	for(i=2;i<=n;i++)
	{
		pw2[i]=pw2[i-1]*pw2[1]%mod;
		pw34[i]=pw34[i-1]*pw34[1]%mod;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i)c[j/i]=cnt[j];
		ans=(ans+solve(n/i)*i)%mod;
	}
	cout<<ans<<'\n';
	return 0;
}