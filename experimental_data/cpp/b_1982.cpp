#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DerrickLo{
	#define N 200005
	class Segment_Tree{
	public:
		struct tree{
			int l,r,sum,maxx,minx,flag;
		}tr[N*4];
		void pushup(int u){
			tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
			tr[u].maxx=max(tr[u<<1].maxx,tr[u<<1|1].maxx);
			tr[u].minx=min(tr[u<<1].minx,tr[u<<1|1].minx);
		}
		void pushdown(int u){
			if(tr[u].flag){
				tr[u<<1].sum+=tr[u].flag*(tr[u<<1].r-tr[u<<1].l+1),tr[u<<1].maxx+=tr[u].flag,tr[u<<1].minx+=tr[u].flag,tr[u<<1].flag+=tr[u].flag;
				tr[u<<1|1].sum+=tr[u].flag*(tr[u<<1|1].r-tr[u<<1|1].l+1),tr[u<<1|1].maxx+=tr[u].flag,tr[u<<1|1].minx+=tr[u].flag,tr[u<<1|1].flag+=tr[u].flag;
				tr[u].flag=0;
			}
		}
		void build(int u,int l,int r){
			if(l==r){
				tr[u]={l,r,0,0,0,0};
				return;
			}
			tr[u]={l,r};
			int mid=l+r>>1;
			build(u<<1,l,mid),build(u<<1|1,mid+1,r);
			pushup(u);
		}
		void change(int u,int l,int r,int k){
			if(l>r)return;
			if(tr[u].l>=l&&tr[u].r<=r){
				tr[u].sum+=k*(tr[u].r-tr[u].l+1);
				tr[u].maxx+=k,tr[u].minx+=k;
				tr[u].flag+=k;
				return;
			}
			pushdown(u);
			int mid=tr[u].l+tr[u].r>>1;
			if(l<=mid)change(u<<1,l,r,k);
			if(r>mid)change(u<<1|1,l,r,k);
			pushup(u);
		}
		int query_sum(int u,int l,int r){
			if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
			pushdown(u);
			int mid=tr[u].l+tr[u].r>>1,res=0;
			if(l<=mid)res+=query_sum(u<<1,l,r);
			if(r>mid)res+=query_sum(u<<1|1,l,r);
			return res;
		}
		int query_max(int u,int l,int r){
			if(tr[u].l>=l&&tr[u].r<=r)return tr[u].maxx;
			pushdown(u);
			int mid=tr[u].l+tr[u].r>>1,res=-1e18;
			if(l<=mid)res=max(res,query_max(u<<1,l,r));
			if(r>mid)res=max(res,query_max(u<<1|1,l,r));
			return res;
		}
		int query_min(int u,int l,int r){
			if(tr[u].l>=l&&tr[u].r<=r)return tr[u].minx;;
			pushdown(u);
			int mid=tr[u].l+tr[u].r>>1,res=1e18;
			if(l<=mid)res=min(res,query_min(u<<1,l,r));
			if(r>mid)res=min(res,query_min(u<<1|1,l,r));
			return res;
		}
	}sgt;
	class Hash{
	public:
		#define base1 1931
		#define base2 3119
		#define mod1 998244353
		#define mod2 1000000007
		int hs1[N],hs2[N],hs3[N],hs4[N],pw1[N],pw2[N];
		void init(int n,string&s){
			pw1[0]=pw2[0]=1,hs3[n+1]=hs4[n+1]=0;
			for(int i=1;i<=n;i++)pw1[i]=pw1[i-1]*base1%mod1;
			for(int i=1;i<=n;i++)pw2[i]=pw2[i-1]*base2%mod2;
			for(int i=1;i<=n;i++)hs1[i]=hs1[i-1]*base1+s[i],hs1[i]%=mod1;
			for(int i=1;i<=n;i++)hs2[i]=hs2[i-1]*base2+s[i],hs2[i]%=mod2;
			for(int i=n;i;i--)hs3[i]=hs3[i+1]*base1+s[i],hs3[i]%=mod1;
			for(int i=n;i;i--)hs4[i]=hs4[i+1]*base2+s[i],hs4[i]%=mod2;
		}
		int qry1(int l,int r){
			return ((hs1[r]-hs1[l-1]*pw1[r-l+1]%mod1)+mod1)%mod1;
		}
		int qry2(int l,int r){
			return (hs2[r]-hs2[l-1]*pw2[r-l+1]%mod2+mod2)%mod2;
		}
		int uqry1(int l,int r){
			return(hs3[l]-hs3[r+1]*pw1[r-l+1]%mod1+mod1)%mod1;
		}
		int uqry2(int l,int r){
			return(hs4[l]-hs4[r+1]*pw2[r-l+1]%mod2+mod2)%mod2;
		}
		bool pal(int l,int r){
			return qry1(l,r)==uqry1(l,r)&&qry2(l,r)==uqry2(l,r);
		}
	}hs;
}
using namespace DerrickLo;
int t,x,y,k;
signed main(){
	cin>>t;
	while(t--){
		cin>>x>>y>>k;
		int cnt=0,flag=0;
		while(cnt<=k&&x>1){
			int nowp=x+y-x%y;
			if(nowp-x+cnt>k){
				flag=1,x+=k-cnt;
				break;
			}
			cnt+=nowp-x,x=nowp;
			while(x%y==0)x/=y;
		} 
		if(flag){cout<<x<<"\n";continue;}
		cout<<1+(k-cnt)%(y-1)<<"\n";
	}
}