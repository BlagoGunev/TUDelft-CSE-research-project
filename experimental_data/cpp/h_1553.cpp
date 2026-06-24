#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define meow(args...) fprintf(stderr,args)
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,k,U;
int f[524288],mn[524288],mx[524288];
signed main(){
#ifdef LOCAL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
#endif
	n=read(),k=read();U=1<<k;
	for(int i=0;i<U;i++) f[i]=inf,mn[i]=inf,mx[i]=-inf;
	for(int i=1,x;i<=n;i++) x=read(),mn[x]=mx[x]=0;
	for(int i=0;i<k;i++) for(int y=0,x,mnx,mny,mxx,mxy;y<U;y++) if((y>>i)&1){
		x=y^(1<<i);f[x]=f[y]=min(f[x],f[y]);
		f[x]=min(f[x],mn[y]-mx[x]+(1<<i));
		f[y]=min(f[y],mn[x]-mx[y]+(1<<i));
		mnx=mn[x],mny=mn[y],mxx=mx[x],mxy=mx[y];
		mn[x]=min(mnx,mny+(1<<i));
		mn[y]=min(mny,mnx+(1<<i));
		mx[x]=max(mxx,mxy+(1<<i));
		mx[y]=max(mxy,mxx+(1<<i));
	}
	for(int i=0;i<U;i++) printf("%lld ",f[i]);
	return 0;
}