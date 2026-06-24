#include<bits/stdc++.h>
#define N 500005
#define LL long long
#define mod 1000000007
#define pr pair<int,int>
#define mp(x,y) make_pair(x,y)
using namespace std;

LL read(){
	char c=getchar();
	LL t=0,f=1;
	while(c>'9'||c<'0') f=(c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9') t=t*10+c-'0',c=getchar();
	return t*f;
}

int n,r;
LL a[N],K,ad[N],dc[N],inf;

bool check(LL v){
	LL tmp=0,used=0;
	memset(dc,0,sizeof dc);
	for(int i=1;i<=n;i++){
		if(a[i]+tmp<v){
			LL dt=v-a[i]-tmp;
			if((used+=dt)>K) return 0;
			tmp+=dt,dc[min(n,i+(r<<1))]+=dt;
		}
		tmp-=dc[i];
	}
	return 1;
}

int main(){
	n=read(),r=read(),K=read();
	for(int i=1;i<=n;i++) inf+=(a[i]=read()),ad[max(i-r,1)]+=a[i],dc[min(i+r,n)]+=a[i],a[i]=0;
	LL L=0,R=inf+K,mid,ans=0,tmp=0;
	for(int i=1;i<=n;i++) tmp+=ad[i],a[i]=tmp,tmp-=dc[i];
	while(L<=R) (check(mid=(L+R)>>1))?(L=(ans=mid)+1):(R=mid-1);
	printf("%lld\n",ans);
}