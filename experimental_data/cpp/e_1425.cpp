#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int N=1e5+5;
const long long INF=(1LL<<60)-1;
int n,k;
long long ans,a[N],b[N],c[N],sum[N];
long long gg[N];

signed main(){
	read(n,k);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	if(k>1){
		for(int i=1;i<=n;i++) ans+=a[i];
		write(max(max(0ll,a[n]-b[n]),ans-*min_element(b+1,b+n)));
		return 0;
	}
	if(!k){
		for(int i=n;i;i--) a[i]+=a[i+1];
		for(int i=1;i<=n;i++) ans=max(ans,a[i]-b[i]);
		write(ans);
		return 0;
	}
	long long mn=INF;
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for (int i=n;i>=1;--i) gg[i]=max(gg[i+1],sum[n]-sum[i-1]-b[i]);
	for (int i=1;i<n;++i){
	  mn=min(mn,b[i]);
	  long long x=sum[i]-mn,y=gg[i+1];
	  ans=max(ans,max(x,0LL)+max(y,0LL));
	}
	for (int i=1;i<n;++i) ans=max(ans,gg[1]-a[i]);
	write(max(ans,0ll));
}