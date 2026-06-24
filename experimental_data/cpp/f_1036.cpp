#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int prime[105],mul[105],flag[105],cnt;
LL sum[105][1005],n;int num[105];
map<LL,LL>G;
LL Pow(LL a,LL b,LL n){
	LL ret=1;
	while (b&&ret<=n){
		if (b&1){
			if (ret*1.*a>n) return 0;
			ret*=a;
		}
		b>>=1;
		if (!b) break;
		if (a*1.*a>n) return 0;
		a*=a;
	}
	return ret<=n?ret:0;
}
int main(){
	mul[0]=1; 
	for (int i=2;i<=100;i++){
		if (!flag[i]) prime[++cnt]=i,mul[i]=-1;
		for (int j=1;j<=cnt&&prime[j]*i<=100;j++){
			flag[prime[j]*i]=1;
			mul[prime[j]*i]=-mul[i];
			if (i%prime[j]==0) {mul[prime[j]*i]=0;break;}
		}
	}
	for (int i=6;i<=61;i++){
		int j=2;sum[i][1]=1;
		while (Pow(j,i,(LL)(1e18)))
			sum[i][j]=Pow(j,i,(LL)(1e18)),++j;
		num[i]=j-1;
	}
	int T=1;scanf("%d",&T);
	//freopen("dict.txt","w",stdout);
	while (T--){
		scanf("%lld",&n);
		if (G.find(n)!=G.end()){
			printf("%lld\n",G[n]);
			continue;
		}
		LL ans=n;
		for (int i=2;i<=5;i++){
			if ((1ll<<i)>n) break;
			LL now=pow(n,1./i);
			while (Pow(now+1,i,n)) ++now;
			while (!Pow(now,i,n)) --now;
			ans+=(now-1)*mul[i];
			//printf("%d %lld %lld %lld %lld\n",i,now,Pow(now-1,i,n),Pow(now,i,n),Pow(now+1,i,n));
		}
		for (int i=6;(1ll<<i)<=n;i++){
			int x=num[i]==2?1:upper_bound(sum[i]+1,sum[i]+num[i]+1,n)-sum[i]-1-1;
			//printf("%d %d\n",i,x);
			ans+=mul[i]*x;
		}
		printf("%lld\n",G[n]=ans-1);
	}
}