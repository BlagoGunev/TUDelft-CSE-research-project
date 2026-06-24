#include<vector>
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
	inline ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}
	inline void file(){freopen("in.in","r",stdin);freopen("my.out","w",stdout);}
	inline int max(int a,int b){return a>b?a:b;}inline ll min(ll a,ll b){return a<b?a:b;}
	inline void pi(int x){pf("%d ",x);}inline void pn(){pf("\n");}
	const int N=2e5+10,B=500;
	int n,m,c[N],r[N],bel[N],T,L[B],R[B],a[N];ll ans,val[N],cf[N];
	struct dp{ll rest;int time;friend bool operator <(dp a,dp b){return a.time<b.time;}};
	std::vector<dp>now,nxt;
	inline short main(){
		n=read();
		F(i,1,n)c[i]=read(),r[i]=min(c[i],read()),bel[i]=(i-1)/B+1;
		F(i,1,bel[n])L[i]=R[i-1]+1,R[i]=min(n,i*B);
		m=read();
		while(m--){
			int t=read();ll h=read();T=max(T,t);
			nxt.push_back({h,t});
		}
		F(b,1,bel[n]){
			if(!nxt.size())break;
			bool lz=0;ll sum=0;
			now.swap(nxt);nxt.clear();
			memset(cf,0,sizeof(ll)*(T+1));
			F(i,L[b],R[b]){
				cf[1]+=r[i];
				int rest=c[i]%r[i];
				if(c[i]/r[i]<T)
					cf[c[i]/r[i]+1]-=r[i],
					cf[c[i]/r[i]+1]+=rest,
					cf[c[i]/r[i]+2]-=rest;
				sum+=(a[i]=c[i]);
			}
			F(i,1,T)cf[i]+=cf[i-1],val[i]=val[i-1]+cf[i];
			ll lst=0;
			for(int t=0;t<now.size();t++){
				auto w=now[t];
				if(w.rest<=sum){
					if(lz){
						F(i,L[b],R[b])a[i]=min(c[i],1ll*r[i]*(w.time-now[t-1].time));
						lz=0;
					}
					F(i,L[b],R[b]){
						ll v=min(w.rest,a[i]);
						w.rest-=v,a[i]-=v;
						if(!w.rest)break;
					}
					if(t+1!=now.size()){
						sum=0;
						F(i,L[b],R[b])a[i]=min(c[i],a[i]+1ll*r[i]*(now[t+1].time-w.time)),sum+=a[i];
					}
				}else{
					w.rest-=sum;lz=1;
					if(t+1!=now.size())sum=val[now[t+1].time-w.time];
					nxt.push_back(w);
				}
			}
		}now.swap(nxt);
		ll ans=0;
		for(auto w:now)ans+=w.rest;
		std::cout<<ans;
		return 0;
	}
}
signed main(){return EMT::main();}