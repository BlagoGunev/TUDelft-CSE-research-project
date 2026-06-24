#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=400005,mo=1e9+7;
int a[maxn],s[maxn],cnt[maxn],d[maxn];
int num[maxn],pos[maxn];
signed main(){
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	int sum=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]%=k,sum=(sum+a[i])%k;
	for(int i=1;i<=n;i++) a[i+n]=a[i];
	for(int i=n;i<2*n;i++){
		s[i]=(s[i-1]+a[i])%k;
		cnt[s[i]]++;
	}
	if(sum==0){
		for(int i=0;i<k;i++) cnt[i]=1ll*cnt[i]*m%mo;
	}else{
		num[0]=0;
		pos[0]=0;
		for(int i=sum,j=1;i;i=(i+sum)%k,j++){
			num[j]=i;
			pos[i]=j;
		}
		for(int i=0;i<k;i++){
			d[pos[i]]+=cnt[i];
			d[pos[i]+m]-=cnt[i];
		}
		for(int i=0;i<k+m;i++) d[i]=(d[i-1]+d[i])%mo;
		for(int i=0;i<k;i++) cnt[i]=0;
		for(int i=0;i<k+m;i++) cnt[num[i%k]]=(cnt[num[i%k]]+d[i])%mo;
	}
	int ans=1ll*cnt[0]*m%mo,now=0;
	int lans=ans;
	a[0]=a[n];
	for(int i=1;i<n;i++){
		cnt[(a[i-1]+now)%k]--;
		cnt[(a[i-1]+now+1ll*sum*m%k)%k]++;
		now=(now+a[i-1])%k;
		ans=(ans+1ll*cnt[now]*m%mo)%mo;
	}
	if(1ll*sum*m%k==0) ans-=(1ll*n*m%mo-1);
	ans=(ans%mo+mo)%mo;
	printf("%lld\n",ans);
}