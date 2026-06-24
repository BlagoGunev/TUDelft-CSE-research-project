#include <bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof b)
#define lb(x) ((x)&(-(x)))
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define dalao 1000000007
#define inf 0x3f3f3f3f
#define N 200010
using namespace std;
typedef long long ll;
int n,Q,siz,ty[N],a[N],tmp[N],x[N],num,dfn[N],out[N],no[N],o[N],tim,cnt[N][2],dep[N],f[N][17];
ll tot,ans[N];
vector<int>G[N];
struct query{int l,r,blo,no,flag,x;bool operator <(const query& b)const{return blo<b.blo||(blo==b.blo&&r<b.r);}}q[N];
inline void dfs(int x,int p){
//	cout<<x<<" ";
	dfn[x]=++tim,no[tim]=x;
	bool flag=0;
	for(auto y:G[x])if(y^p)flag=1,f[y][0]=x,dep[y]=dep[x]+1,dfs(y,x);
//	cout<<x<<" ";
	out[x]=++tim,no[tim]=x;
}
inline int lca(int x,int y){
	if(x==y)return x;
	if(dep[x]<dep[y])swap(x,y);
	if(dep[x]^dep[y])for(int j=16;~j;j--)if(dep[f[x][j]]>=dep[y])x=f[x][j];
	if(x==y)return x;
	for(int j=16;~j;j--)if(f[x][j]^f[y][j])x=f[x][j],y=f[y][j];
	return f[x][0];
}
int main(){
	scanf("%d",&n),siz=sqrt(n<<1);
	for(int i=1;i<=n;i++)scanf("%d",&ty[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),x[i]=a[i];
	sort(x+1,x+1+n),num=unique(x+1,x+1+n)-x-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(x+1,x+1+num,a[i])-x;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	f[1][0]=1,dfs(1,0);
//	puts("");
	for(int j=1;j<17;j++)for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=tim;i++)tmp[i]=a[no[i]];mcpy(a,tmp);
	for(int i=1;i<=tim;i++)tmp[i]=ty[no[i]];mcpy(ty,tmp);
	cin>>Q;
	for(int i=1;i<=Q;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		if(dfn[q[i].l]>dfn[q[i].r])swap(q[i].l,q[i].r);
		int x=lca(q[i].l,q[i].r);
		if(x==q[i].l)q[i].l=dfn[q[i].l],q[i].r=dfn[q[i].r],q[i].flag=0;
		else q[i].flag=1,q[i].x=x,q[i].l=out[q[i].l],q[i].r=dfn[q[i].r];
		q[i].blo=q[i].l/siz,q[i].no=i;
	}
	sort(q+1,q+1+Q);
	int l=1,r=0,L,R;
//	for(int i=1;i<=n;i++)val[i]=1;
	for(int i=1;i<=Q;i++){
		L=q[i].l,R=q[i].r;
		while(l<L)
			if(o[no[l]]==1)tot-=cnt[a[l]][ty[l]^1],cnt[a[l]][ty[l]]--,o[no[l]]--,l++;
			else tot+=cnt[a[l]][ty[l]^1],cnt[a[l]][ty[l]]++,o[no[l]]--,l++;
		while(l>L){
			l--;
			if(!o[no[l]])tot+=cnt[a[l]][ty[l]^1],cnt[a[l]][ty[l]]++,o[no[l]]++;
			else tot-=cnt[a[l]][ty[l]^1],cnt[a[l]][ty[l]]--,o[no[l]]++;
		}
		while(r<R){
			r++;
			if(!o[no[r]])tot+=cnt[a[r]][ty[r]^1],cnt[a[r]][ty[r]]++,o[no[r]]++;
			else tot-=cnt[a[r]][ty[r]^1],cnt[a[r]][ty[r]]--,o[no[r]]++;
		}
		while(r>R)
			if(o[no[r]]==1)tot-=cnt[a[r]][ty[r]^1],cnt[a[r]][ty[r]]--,o[no[r]]--,r--;
			else tot+=cnt[a[r]][ty[r]^1],cnt[a[r]][ty[r]]++,o[no[r]]--,r--;
		if(q[i].flag)ans[q[i].no]=tot+cnt[a[dfn[q[i].x]]][ty[dfn[q[i].x]]^1];
		else ans[q[i].no]=tot;
//		printf("%d %d\n",l,r);for(int i=1;i<=num;i++)for(int j=0;j<2;j++)printf("%d %d %d\n",i,j,cnt[i][j]);
	}
	for(int i=1;i<=Q;i++)printf("%I64d\n",ans[i]);
	return 0;
}