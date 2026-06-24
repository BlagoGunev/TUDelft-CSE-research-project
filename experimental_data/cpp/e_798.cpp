#include<bits/stdc++.h>
using namespace std;
#define ll int
#define lson (u<<1)
#define rson (u<<1|1)
const ll N=500007;
ll n,m,a[N],ans[N],id[N];
pair<ll,ll> val[N<<2];
void build(int u,int l,int r){
	if (l==r){
		val[u]=make_pair((id[l]?id[l]:1e9),l);return;
	}
	int mid=l+r>>1;
	build(lson,l,mid);build(rson,mid+1,r);
	val[u]=max(val[lson],val[rson]);
}
void modify(int u,int l,int r,int x){
	if (l==r){
		val[u]=make_pair(0,-1);return;
	}
	int mid=l+r>>1;
	if (x<=mid) modify(lson,l,mid,x);
	else modify(rson,mid+1,r,x);
	val[u]=max(val[lson],val[rson]);
}
pair<int,int> query(int u,int l,int r,int L,int R){
	if (L<=l&&r<=R) return val[u];
	int mid=l+r>>1;
	if (R<=mid) return query(lson,l,mid,L,R);
	if (L>mid) return query(rson,mid+1,r,L,R);
	return max(query(lson,l,mid,L,R),query(rson,mid+1,r,L,R));
}
void dfs(int u){
//	cout<<u<<endl;
	modify(1,1,n,u);
	if (id[u]&&ans[id[u]]==0) dfs(id[u]);
	if (a[u]>1) while(1){
		auto p=query(1,1,n,1,a[u]-1);
		if (p.first<=u) break;
		dfs(p.second);
	}
	ans[u]=++m;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		if (~a[i]) id[a[i]]=i;
		else a[i]=n+1;
	}
	build(1,1,n);
	for (int i=1;i<=n;++i) if (!ans[i]) dfs(i);
	for (int i=1;i<=n;++i) cout<<ans[i]<<' ';cout<<endl;
	return 0;
}