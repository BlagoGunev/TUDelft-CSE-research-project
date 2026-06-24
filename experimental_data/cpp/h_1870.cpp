#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long 
#define vi vector < int > 
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define me(a, x) memset(a, x, sizeof(a)) 
#define int long long 
using namespace std;
const int N = 1 << 20;

#define INF 1000000001
int q; 
int pts[N];
vi e[N];

ll val[N];

namespace lsq { // https://www.cnblogs.com/lsq147/p/17029129.html

int n, m;
const int maxn=200005,maxm=400005;
struct Val{
	int u,v,w;
	Val(int u=0,int v=0,int w=0):
		u(u),v(v),w(w){}
	Val operator += (const int o){
		this->w=this->w+o;return *this;
	}
	bool operator < (const Val o)const{
		return w<o.w;
	}
};
struct Node{
	int l,r,dis,laz;Val v;
	Node(int l=0,int r=0,int dis=0,int laz=0,Val v=Val()):
		l(l),r(r),dis(dis),laz(laz),v(v){}
}P[maxm];
int tot;
void push(int x,int laz){
	P[x].laz+=laz;
	P[x].v+=laz;
}
void pushdown(int x){
	if(!P[x].laz)return;
	push(P[x].l,P[x].laz);
	push(P[x].r,P[x].laz);
	P[x].laz=0;
}
void pushup(int x){
	if(P[P[x].l].dis<P[P[x].r].dis)
		std::swap(P[x].l,P[x].r);
	P[x].dis=P[P[x].r].dis+1;
}
int newnode(Val v){
	P[++tot]=Node(0,0,1,0,v);
	return tot;
}
void merge(int&x,int l,int r){
	if(!l||!r)return x=l|r,void();
	pushdown(l);pushdown(r);
	if(P[r].v<P[l].v)l^=r^=l^=r;
	x=l;merge(P[x].r,P[l].r,r);
	return pushup(x);
}
void pop(int&x){
	pushdown(x);
	merge(x,P[x].l,P[x].r);
}
int rt[maxn*2];
int fa[maxn*2];
int vis[maxn*2],cnt;
int st[maxn],tp;
int rn;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int val[maxn*2];
int son[maxn*2],bro[maxn*2],pa[maxn*2];
void ade(int u,int v){
//	printf("ade %d %d %lld\n",u,v,val[v]);
	bro[v]=son[u],son[u]=v;pa[v]=u;
}
void dfs(int u){
	if(vis[u]&&vis[u]<cnt)return void();
	if(vis[u]==cnt){
		++rn;
		while(st[tp+1]!=u){
			fa[st[tp]]=rn;ade(rn,st[tp]);
			merge(rt[rn],rt[rn],rt[st[tp]]);
			--tp;
		}
		u=rn;
	}
	vis[u]=cnt,st[++tp]=u;
	while(rt[u]&&find(P[rt[u]].v.v)==u)pop(rt[u]);
	if(!rt[u])return val[u]=INF,ade(0,u);
	Val tmp=P[rt[u]].v;val[u]=tmp.w;
	pop(rt[u]);push(rt[u],-tmp.w);
	dfs(find(tmp.v));
	if(find(u)==u)ade(0,u);
	return;
}
const int mod=998244353;
int iac[maxn],fac[maxn];
int getans(int u){
	int sz=(son[u]==0);
	for(int v=son[u];v;v=bro[v]){
		e[u].emplace_back(v);
		int o=getans(v);
		sz+=o;
	}
	return sz;
}
void solve(void){
	cin >> n >> m >> q;
	rn=n;
	fac[0]=fac[1]=iac[0]=iac[1]=1;
	for(int i=2;i<=n;++i)
		iac[i]=1ll*(mod-mod/i)*iac[mod%i]%mod;
	for(int i=2;i<=n;++i)
		fac[i]=1ll*fac[i-1]*i%mod,iac[i]=1ll*iac[i-1]*iac[i]%mod;
	for(int i=1;i<=n*2;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin >> u >> v >> w;
		merge(rt[u],rt[u],newnode(Val(u,v,w)));
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			++cnt;dfs(i);tp=0;
		}
	}
	getans(0);
}
int Main(){
	solve();
	return 0;
}

}

int siz[N], dfn[N], en[N], mp[N], dep[N], hv[N], top[N], idt;
int fa[N], total;
 
void dfs1(int x) {
	siz[x] = 1;
	for(auto &v : e[x]) if(v != fa[x]) {
		fa[v] = x, dep[v] = dep[x] + 1, dfs1(v);
		siz[x] += siz[v];
		if(siz[v] > siz[hv[x]]) 
			hv[x] = v;
	}
}
 
void dfs2(int x) {
	dfn[x] = ++idt;
	mp[idt] = x;
	if(hv[x]) {
		top[hv[x]] = top[x];
		dfs2(hv[x]);
	}
	for(auto&v : e[x]) if(v != fa[x] && v != hv[x]) {
		top[v] = v, dfs2(v);
	}
	en[x] = idt;
}

void dfs(int x) {
	total = max(total, x);
	for(auto &v : e[x]) {
		fa[v] = x;
		dfs(v); 
	}
}

int mn[N], tag[N];
ll sum[N][2];
void adt(int x, int w) {
	tag[x] += w;
	mn[x] += w; 
}
void upd(int x) {
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
	sum[x][0] = sum[x][1] = 0;
	L(o, 0, 1) {
		if(mn[x * 2] == mn[x]) sum[x][o] += sum[x * 2][o];
		if(mn[x * 2 + 1] == mn[x]) sum[x][o] += sum[x * 2 + 1][o];
	}
}
void push(int x) {
	if(tag[x]) adt(x * 2, tag[x]), adt(x * 2 + 1, tag[x]), tag[x] = 0;
}
 
void add(int x, int L, int R, int l, int r, int w) {
	if(l <= L && R <= r) {
		adt(x, w);
		return ;
	}
	push(x);
	int mid = (L + R) >> 1;
	if(l <= mid) add(x * 2, L, mid, l, r, w);
	if(r > mid) add(x * 2 + 1, mid + 1, R, l, r, w);
	upd(x);
}
 
void build(int x, int L, int R) {
	if(L == R) {
		sum[x][0] = val[L];
		sum[x][1] = val[L] == INF;
		return ;
	}
	int mid = (L + R) >> 1;
	build(x * 2, L, mid);
	build(x * 2 + 1, mid + 1, R);
	upd(x);
}

int vis[N];

int cnt[N];
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	lsq :: Main();
	dfs(0);
	++total;
	dfs1(0);
	dfs2(0);
	L(i, 1, total) {
		val[i] = lsq :: val[mp[i]];
	}
	fa[0] = -1;
	
	build(1, 1, total);
	int scnt = 0;
	while(q--) {
		string s;
		cin >> s;
		int pos;
		cin >> pos;
		int add = 0;
		if(s == "+") {
			add = 1;
			vis[pos] = 1;
		} else {
			add = -1;
			vis[pos] = 0;
		}
		scnt += add;
		for(int x = pos; x != -1; x = fa[top[x]]) {
			::add(1, 1, total, dfn[top[x]], dfn[x], add);
//			L(i, dfn[top[x]], dfn[x]) {
//				cnt[i] += add;
//			}
		}
		
//		if(scnt == 0) {
//			cout << -1 << '\n';
//		}
		
		if(mn[1] > 0) {
			cout << 0 << '\n';
		} else if(sum[1][1]) {
			cout << -1 << '\n';
		} else {
			cout << ::sum[1][0] << "\n";
		}
	}
	return 0;
}