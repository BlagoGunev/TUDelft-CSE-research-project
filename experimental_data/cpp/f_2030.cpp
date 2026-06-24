#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int maxd=20;
const int INF=1e9+10;

struct SGT{
	struct node{
		int l,r;
		set<int> s;
	}tr[maxn<<2];
	void build(int p,int l,int r){
		tr[p].l=l;tr[p].r=r;tr[p].s.clear();
		if(l==r) return ;
		int mid=(l+r)>>1;
		build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	}
	void insert(int p,int l,int r,int v){
		//printf("ins");
		tr[p].s.insert(v);
		if(l<=tr[p].l&&tr[p].r<=r) return ;
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid) insert(p<<1,l,r,v);
		if(mid<r) insert(p<<1|1,l,r,v);
	}
	int query(int p,int l,int r,int v){
		//printf("qry:%d %d %d|%d %d\n",p,l,r,tr[p].l,tr[p].r);
		if(r<l) return -INF;
		if(l<=tr[p].l&&tr[p].r<=r){
			set<int>::iterator it=tr[p].s.lower_bound(v);
			if(it==tr[p].s.begin()) return -INF;
			return *(--it);
		}
		int mid=(tr[p].l+tr[p].r)>>1;
		if(r<=mid) return query(p<<1,l,r,v);
		if(mid<l) return query(p<<1|1,l,r,v);
		return max(query(p<<1,l,r,v),query(p<<1|1,l,r,v));
	}
}tr;

int n,m;
int a[maxn],lst[maxn],f[maxn];
struct ST{
	int mx[maxn<<2][maxd+2];
	void prepare(){
		for(int i=1;i<=n;i++) mx[i][0]=f[i];
		for(int j=1;j<=__lg(n);j++){
			for(int i=1;i<=n;i++){
				mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int query_mx(int l,int r){
		if(r<l) return 0;
		int d=__lg(r-l+1);
		return max(mx[l][d],mx[r-(1<<d)+1][d]);
	}
}st;

void solve(){
	scanf("%d%d",&n,&m);
	tr.build(1,1,n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),lst[i]=0;
	for(int i=1;i<=n;i++){
		if(lst[a[i]]==0){
			tr.insert(1,i,i,lst[a[i]]);
			lst[a[i]]=i;f[i]=-INF;continue;
		}
		int l=lst[a[i]],r=i;
		f[i]=tr.query(1,l+1,r-1,l);
		tr.insert(1,i,i,lst[a[i]]);
		lst[a[i]]=i;
	}
	st.prepare();
	for(int i=1;i<=m;i++){
		int l,r;scanf("%d%d",&l,&r);
		if(st.query_mx(l,r)>=l) printf("NO\n");
		else printf("YES\n");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}