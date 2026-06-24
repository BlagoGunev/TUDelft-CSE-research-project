#include"bits/stdc++.h"
using namespace std;
#pragma GCC optimize(2)
#define int long long
const int maxn = 300010;
const int lgn = 20;
const int mo = 998244353;
const int mo2 = 1e9+7;
int n,m,TIdx,fa[maxn][lgn+1],dep[maxn];
int a[maxn],A[maxn],b[maxn];
vector<int>e[maxn];
int rt[maxn],Rd[maxn],Dr[maxn];
mt19937 rnd(time(0));
struct Node{
	int sum,ls,rs;
	int Hs,Hs2;
}tr[maxn*lgn];
void pushup(int x){
	tr[x].sum=tr[tr[x].ls].sum+tr[tr[x].rs].sum;
	tr[x].Hs=(tr[tr[x].ls].Hs+tr[tr[x].rs].Hs)%mo;
	tr[x].Hs2=(tr[tr[x].ls].Hs2+tr[tr[x].rs].Hs2)%mo2;
}
void upd(int x,int p){
	tr[x].Hs=1ll*tr[x].sum*Rd[p]%mo;
	tr[x].Hs2=1ll*tr[x].sum*Rd[p]%mo2;
}
int Insert(int x,int l,int r,int p){
	tr[++TIdx]=tr[x],x=TIdx;
	if(l==r){
		tr[x].sum+=1;
		upd(x,p);
	}else{
		int mid=(l+r)>>1;
		if(p<=mid)tr[x].ls=Insert(tr[x].ls,l,mid,p);
		else tr[x].rs=Insert(tr[x].rs,mid+1,r,p);
		pushup(x);
	}
	return x;
}
int k;
vector<int>vec;
void query(int xl,int xr,int Td,int Tu,int xl_,int xr_,int Td_,int Tu_,int l,int r){
	if(k==0)return;
	int R=(tr[xl].Hs+tr[xr].Hs-tr[Td].Hs-tr[Tu].Hs+2*mo)%mo;
	int R2=(tr[xl].Hs2+tr[xr].Hs2-tr[Td].Hs2-tr[Tu].Hs2+2*mo2)%mo2;
	int R_=(tr[xl_].Hs+tr[xr_].Hs-tr[Td_].Hs-tr[Tu_].Hs+2*mo)%mo;
	int R2_=(tr[xl_].Hs2+tr[xr_].Hs2-tr[Td_].Hs2-tr[Tu_].Hs2+2*mo2)%mo2;
	if(R==R_&&R2_==R2)return;
	if(l==r){vec.push_back(A[l]),k--;return;}
	int mid=(l+r)>>1;
	query(tr[xl].ls,tr[xr].ls,tr[Td].ls,tr[Tu].ls,tr[xl_].ls,tr[xr_].ls,tr[Td_].ls,tr[Tu_].ls,l,mid);
	query(tr[xl].rs,tr[xr].rs,tr[Td].rs,tr[Tu].rs,tr[xl_].rs,tr[xr_].rs,tr[Td_].rs,tr[Tu_].rs,mid+1,r);
}
void dfs(int p,int Fa){
	rt[p]=Insert(rt[Fa],1,n,b[p]);
	fa[p][0]=Fa,dep[p]=dep[Fa]+1;
	for(int i=1;i<=lgn;i++)
		fa[p][i]=fa[fa[p][i-1]][i-1];
	for(int i=0;i<e[p].size();i++){
		int to=e[p][i];
		if(to==Fa)continue;
		dfs(to,p);
	}
}
int Lca(int u,int v){
	if(u==v)return u;
	if(dep[u]>dep[v])swap(u,v);
	for(int i=lgn;i>=0;i--)
		if(dep[fa[v][i]]>=dep[u])
			v=fa[v][i];
	if(u==v)return u;
	for(int i=lgn;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],A[i]=a[i];
	sort(A+1,A+n+1);
	int Top=unique(A+1,A+n+1)-A-1;
	for(int i=1;i<=n;i++)b[i]=lower_bound(A+1,A+Top+1,a[i])-A;
	for(int i=1;i<=Top;i++)Rd[i]=rnd()%mo,Dr[i]=rnd()%mo;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cin>>m;
	dfs(1,0);
	for(int i=1,u,v,u_,v_;i<=m;i++){
		cin>>u>>v>>u_>>v_>>k;
		int Lc=Lca(u,v),Lc_=Lca(u_,v_);
		vec.clear();
		query(rt[u],rt[v],rt[Lc],rt[fa[Lc][0]],rt[u_],rt[v_],rt[Lc_],rt[fa[Lc_][0]],1,n);
		cout<<vec.size()<<' ';
		for(auto To:vec)cout<<To<<' ';
		cout<<'\n';
	}
}