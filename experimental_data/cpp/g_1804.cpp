#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll inf=1e18;
struct SegT{
	ll sm[1<<19],tg[1<<19],mn[1<<19],mx[1<<19],ct[1<<19];
	SegT(){fill(mn,mn+(1<<19),inf),fill(mx,mx+(1<<19),-inf);}
	void push(int i,ll w){
		if(!ct[i])return;
		sm[i]+=ct[i]*w,tg[i]+=w,mn[i]+=w,mx[i]+=w;
	}
	void pushup(int i){
		int ls=i<<1,rs=i<<1|1;
		sm[i]=sm[ls]+sm[rs],ct[i]=ct[ls]+ct[rs];
		mn[i]=min(mn[ls],mn[rs]),mx[i]=max(mx[ls],mx[rs]);
	}
	void pushdown(int i){
		push(i<<1,tg[i]),push(i<<1|1,tg[i]),tg[i]=0;
	}
	void upd0(int i,int l,int r,int p,int v){
		if(l==r){
			if(v)sm[i]=mn[i]=mx[i]=v,ct[i]=1;
			else sm[i]=ct[i]=0,mn[i]=inf,mx[i]=-inf;
			return;
		}
		int md=l+r>>1;pushdown(i);
		if(p<=md)upd0(i<<1,l,md,p,v);
		else upd0(i<<1|1,md+1,r,p,v);
		pushup(i);
	}
	void upd1(int i,int l,int r){
		if(!ct[i]||mn[i]+1>>1==mx[i]+1>>1){
			push(i,-(mn[i]+1>>1));return;
		}
		int md=l+r>>1;pushdown(i);
		upd1(i<<1,l,md),upd1(i<<1|1,md+1,r);
		pushup(i);
	}
}ds;
int n,B,C;ll ans;
vector<pair<int,pii> >vec;
int main(){
	scanf("%d%d",&n,&B);
	for(int i=1;i<=n;i++){
		int s,f,d;scanf("%d%d%d",&s,&f,&d);
		vec.push_back({s,{i,d}}),vec.push_back({f+1,{i,0}});
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		auto[s,p]=vec[i];auto[a,b]=p;
		ds.upd0(1,1,n,a,b),C+=b==0?-1:1;
		if(ds.ct[1]==0)continue;int t=vec[i+1].first;
		while(s<t&&ds.sm[1]>B)ds.upd1(1,1,n),++s;
		int X=-1,Y=-1,Z=-1;
		for(;s<t;){
			int T=(B-ds.sm[1])/C+1;
			if(s+T>=t){
				T=t-s;ll H=(ll)ds.sm[1]*T+((ll)C*T*(T-1)>>1);
				ans+=H;ds.push(1,T);break;
			}
			ll H=(ll)ds.sm[1]*T+((ll)C*T*(T-1)>>1);
			ans+=H,ds.push(1,T);
			s+=T+1,ds.upd1(1,1,n);
			if(X==ds.sm[1]&&Y==ds.mn[1]&&Z==ds.mx[1]){
				int w=(t-s)/(T+1);ans+=H*w;s+=(T+1)*w;
			}
			X=ds.sm[1],Y=ds.mn[1],Z=ds.mx[1];
		}
	}
	printf("%lld",ans);
}