#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
namespace EMT{
	typedef long long ll;typedef double db;
	#define pf printf
	#define F(i,a,b) for(int i=a;i<=b;i++)
	#define D(i,a,b) for(int i=a;i>=b;i--)
	inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}
	inline void file(){freopen("in.in","r",stdin);freopen("my.out","w",stdout);}
	inline int max(int a,int b){return a>b?a:b;}inline int min(int a,int b){return a<b?a:b;}
	inline void pi(int x){pf("%d ",x);}inline void pn(){pf("\n");}
	const int N=2e5+10;
	int n,a[N],plc[N],L[N],R[N];
	struct seg{
		int lz[N<<2],mx[N<<2];
		inline void up(int p){
			mx[p]=max(mx[p<<1],mx[p<<1|1])+lz[p];
		}
		inline void build(int p,int l,int r){
			lz[p]=0;
			if(l==r){mx[p]=l-(l&1);return;}
			int mid=(l+r)>>1;
			build(p<<1,l,mid),build(p<<1|1,mid+1,r);
			up(p);
		}
		inline void change(int p,int l,int r,int ql,int qr,int v){
			if(l>=ql&&r<=qr){lz[p]+=v;mx[p]+=v;return;}
			int mid=(l+r)>>1;
			if(qr<=mid)change(p<<1,l,mid,ql,qr,v);
			else if(ql>mid)change(p<<1|1,mid+1,r,ql,qr,v);
			else change(p<<1,l,mid,ql,mid,v),change(p<<1|1,mid+1,r,mid+1,qr,v);
			up(p);
		}
		inline int ask(int p,int l,int r,int ql,int qr){
			if(l>=ql&&r<=qr)return mx[p];
			int mid=(l+r)>>1;
			if(qr<=mid)return ask(p<<1,l,mid,ql,qr)+lz[p];
			if(ql>mid)return ask(p<<1|1,mid+1,r,ql,qr)+lz[p];
			return max(ask(p<<1,l,mid,ql,mid),ask(p<<1|1,mid+1,r,mid+1,qr))+lz[p];
		}
	}segm;
	inline short main(){
		int T=read();
		while(T--){
			n=read();
			F(i,1,n)plc[read()]=i;
			L[n+1]=n+1;
			D(i,n,1)L[i]=min(L[i+1],plc[i]);
			F(i,1,n)R[i]=max(R[i-1],plc[i]);
			segm.build(1,1,n);
			int ans=0;
			for(int i=1;i<n;i++){
				segm.change(1,1,n,plc[i],plc[i],plc[i]&1?1:-1);
				if(plc[i]>1)segm.change(1,1,n,1,plc[i]-1,1);
				if(plc[i]<n)segm.change(1,1,n,plc[i]+1,n,-1);
				if(L[i+1]<=R[i])ans=max(ans,segm.ask(1,1,n,L[i+1],R[i]));
			}pi(ans);pn();
		}
		return 0;
	}
}
signed main(){return EMT::main();}