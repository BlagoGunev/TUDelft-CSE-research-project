#include <bits/stdc++.h>
#define N 600011
#define pii pair<int,int>
#define s1 first
#define s2 second
using namespace std;
int n,m,ka,ks,T,a[N],b[N],s[N],col[N];
vector<int> vv,vs,vcol;
vector<int> vp[N],vps[N];
int typ[N];
bool can[N];int res[N];
int mx[N],mn[N];
namespace sgt
{
	int tag[N*4];pii mx[N*4];
	void pushup(int x){mx[x]=max(mx[x<<1],mx[x<<1|1]);}
	void apply(int x,int p){tag[x]+=p;mx[x].s1+=p;}
	void pushdown(int x){if(tag[x])apply(x<<1,tag[x]),apply(x<<1|1,tag[x]),tag[x]=0;}
	void build(int L,int R,int x)
	{//printf("build([%d,%d],%d)\n",L,R,x);
		tag[x]=0;
		if(L==R){mx[x]=pii(can[L],L);return;}
		build(L,L+R>>1,x<<1);build((L+R>>1)+1,R,x<<1|1);pushup(x);//printf("mx[%d]:{%d,%d}\n",x,mx[x].s1,mx[x].s2);
	}
	pii query(int l,int r,int L,int R,int x)
	{//printf("query([%d,%d],[%d,%d],%d):{%d,%d}\n",l,r,L,R,x,mx[x].s1,mx[x].s2);
		if(l>r)return pii(0,0);
		if(l<=L&&R<=r)return mx[x];pushdown(x);pii ans(0,0);
		if(l<=L+R>>1)ans=max(ans,query(l,r,L,L+R>>1,x<<1));if(r>L+R>>1)ans=max(ans,query(l,r,(L+R>>1)+1,R,x<<1|1));return ans;
	}
	void add(int l,int r,int p,int L,int R,int x)
	{//printf("add([%d,%d],%d,[%d,%d],%d):{%d,%d}\n",l,r,p,L,R,x,mx[x].s1,mx[x].s2);
		if(l>r)return;
		if(l<=L&&R<=r){apply(x,p);return;}pushdown(x);
		if(l<=L+R>>1)add(l,r,p,L,L+R>>1,x<<1);if(r>L+R>>1)add(l,r,p,(L+R>>1)+1,R,x<<1|1);pushup(x);
	}
}
vector<pii> vans;
namespace check
{
	int val[N],mx[N],mn[N];
	void check()
	{
		for(int i=1;i<=m;++i)mx[i]=-1e9,mn[i]=1e9;
		for(int i=1;i<=n;++i)val[i]=0;
		for(pii x:vans)
		{
			for(int i=1;i<=n;++i)
			{
				if((vs[s[i]-1]==x.s2?vv[b[i]-1]:vv[a[i]-1])>=x.s1)++val[i];
			}
		}
		for(int i=1;i<=n;++i)mx[col[i]]=max(mx[col[i]],val[i]),mn[col[i]]=min(mn[col[i]],val[i]);
		for(int i=1;i<=m;++i)
		{
			for(int j=i+1;j<=m;++j)assert(mn[i]>mx[j]);
		}
	}
}
int main()
{
//	freopen("E.in","r",stdin);freopen("E.out","w",stdout);
	scanf("%d",&T);while(T--)
	{
		scanf("%d%d",&n,&m);//printf("n:%d m:%d\n",n,m);
		vv.clear();vs.clear();
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",a+i,b+i,s+i);//printf("%d %d %d\n",a[i],b[i],s[i]);
			vv.push_back(a[i]);
			vv.push_back(b[i]);
			vs.push_back(s[i]);
		}
		sort(vv.begin(),vv.end());vv.resize(unique(vv.begin(),vv.end())-vv.begin());
		sort(vs.begin(),vs.end());vs.resize(unique(vs.begin(),vs.end())-vs.begin());
		vcol.clear();
		int tt=1e9,pt=vs.size()-1;
		while(vcol.size()<=5*n)
		{
			while(~pt&&vs[pt]>tt)--pt;
			if(~pt&&vs[pt]==tt)--tt;
			else vcol.push_back(tt),--tt;
		}
		for(int i=1;i<=n;++i)
		{
			a[i]=lower_bound(vv.begin(),vv.end(),a[i])-vv.begin()+1;
			b[i]=lower_bound(vv.begin(),vv.end(),b[i])-vv.begin()+1;
			s[i]=lower_bound(vs.begin(),vs.end(),s[i])-vs.begin()+1;
		}
		ka=vv.size();ks=vs.size();
		// for(int i=1;i<=n;++i)printf("{a:%d,b:%d,s:%d} ",a[i],b[i],s[i]);putchar(10);
		for(int i=1;i<=m;++i)
		{
			int k;scanf("%d",&k);
			for(int j=1;j<=k;++j){int x;scanf("%d",&x);col[x]=i;}
		}
		// printf("col:");for(int i=1;i<=n;++i)printf("%d ",col[i]);putchar(10);
		for(int i=1;i<=n;++i)typ[i]=-1;
		for(int i=1;i<=ka;++i)vp[i].clear(),can[i]=1;
		for(int i=1;i<=ks;++i)vps[i].clear();
		for(int i=1;i<=n;++i)vp[a[i]].push_back(i),vps[s[i]].push_back(i);
		mn[0]=m+1;
		for(int i=1;i<=ka;++i)
		{
			mn[i]=mn[i-1];
			for(int x:vp[i])mn[i]=min(mn[i],col[x]);
		}
		mx[ka+1]=0;
		for(int i=ka;i;--i)
		{
			mx[i]=mx[i+1];
			for(int x:vp[i])mx[i]=max(mx[i],col[x]);
		}
		bool ok=1;
		for(int i=1;i<=ka;++i)if(mn[i-1]<mx[i])can[i]=0;
		for(int i=1;i<=ka;++i)
		{
			// printf("i:%d mn:%d mx:%d\n",i,mn[i],mx[i]);
			for(int x:vp[i])
			{
				// printf("x:%d col:%d\n",x,col[x]);
				if(mn[i]<col[x])
				{
					if(typ[x]==1){ok=0;break;}
					typ[x]=0;
				}
				if(col[x]<mx[i])
				{
					if(typ[x]==0){ok=0;break;}
					typ[x]=1;
				}
			}
			if(!ok)break;
		}
		// printf("first typ:");for(int i=1;i<=n;++i)printf("%d ",typ[i]);putchar(10);
		if(!ok){printf("-1\n");continue;}
		int tmx=0;
		for(int i=1;i<=ka;++i)
		{
			int cmx=0;
			for(int x:vp[i])cmx=max(cmx,col[x]);
			if(can[i])tmx=cmx;
			else tmx=max(tmx,cmx);
			for(int x:vp[i])
			{
				if(tmx>col[x])
				{
					if(typ[x]==0){ok=0;break;}
					typ[x]=1;
				}
			}
			if(!ok)break;
		}
		int tmn=m+1;can[ka+1]=0;
		for(int i=ka;i;--i)
		{
			int cmn=m+1;
			for(int x:vp[i])cmn=min(cmn,col[x]);
			if(can[i+1])tmn=cmn;
			else tmn=min(tmn,cmn);
			// printf("i:%d tmn:%d\n",i,tmn);
			for(int x:vp[i])
			{
				// printf("x:%d col:%d\n",x,col[x]);
				if(tmn<col[x])
				{
					if(typ[x]==1){ok=0;break;}
					typ[x]=0;
				}
			}
			if(!ok)break;
		}
		// printf("typ:");for(int i=1;i<=n;++i)printf("%d ",typ[i]);putchar(10);
		// printf("can:");for(int i=1;i<=n;++i)printf("%d ",can[i]);putchar(10);
		sgt::build(1,ka,1);
		for(int i=1;i<=ks;++i)
		{
			int L=1,R=ka;
			for(int x:vps[i])
			{
				if(typ[x]==1)
				{
					L=max(L,a[x]+1);
					R=min(R,b[x]);
				}
				else if(!typ[x])sgt::add(a[x]+1,b[x],-1,1,ka,1);
			}
			// printf("color i:%d [%d,%d]\n",i,L,R);
			if(L<=R)
			{
				auto tt=sgt::query(L,R,1,ka,1);
				// printf("tt:{%d,%d}\n",tt.s1,tt.s2);
				if(tt.s1)res[i]=tt.s2;
				else ok=0;
			}
			else ok=0;
			if(!ok)break;
			for(int x:vps[i])if(!typ[x])sgt::add(a[x]+1,b[x],1,1,ka,1);
		}
		// printf("res:");for(int i=1;i<=n;++i)printf("%d ",res[i]);putchar(10);
		if(!ok){printf("-1\n");continue;}
		vans.clear();
		for(int i=1;i<=ka;++i)if(can[i])
		{
			vans.push_back({vv[i-1],vcol.back()}),vcol.pop_back();
			vans.push_back({vv[i-1],vcol.back()}),vcol.pop_back();
		}
		for(int i=1;i<=ks;++i)vans.push_back({vv[res[i]-1],vs[i-1]});
		printf("%d\n",(int)vans.size());
		for(pii x:vans)printf("%d %d\n",x.s1,x.s2);
	//	check::check();
	}
	fclose(stdin);fclose(stdout);return 0;
}