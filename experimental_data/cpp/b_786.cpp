#include <bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define SZ(S) S.size()
#define vi vector<int>
#define pr pair<int,int>
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define FORD(i,b,a) for(int i=(int)(b);i>=(int)(a);--i)
#define ALL(S) S.begin(),S.end()

using namespace std;
typedef long long ll;

const int MAXN=300005;
const ll P=1e9+7;

template<typename T>
inline void read(T& x,char s=getchar()) {
	for(x=0;s>'9'||s<'0';) s=getchar();
	while(s<='9'&&s>='0') x=x*10+s-'0',s=getchar();
}

#define INF 4557430888798830399LL

struct edge{
	int s,t,cap,next;
}e[MAXN*35];

int head[MAXN*4],cnt;

void addedge(int s,int t,int cap) {
	e[cnt].s=s;e[cnt].t=t;e[cnt].cap=cap;e[cnt].next=head[s];head[s]=cnt++;
}

int n,m,s,opt,u,v,w,l,r;

priority_queue<pair<long long,int> ,vector<pair<long long,int> > ,greater<pair<long long,int> > > q;

long long dis[MAXN*4];

bool vis[MAXN*4];

namespace Tree {
	struct Node {int lch,rch;};
	int poolt,Root;
	Node tree[200010];
	int NewNode() {
		return ++poolt;
	}
	int build(int l,int r) {
		if (l==r) {
			addedge(l*2,l*2+1,0);
			addedge(l*2+1,l*2,0);
			return l;
		}
		int mid=(l+r)>>1;
		int node=NewNode();
		tree[node].lch=build(l,mid);
		addedge(tree[node].lch*2,node*2,0);
		addedge(node*2+1,tree[node].lch*2+1,0);
		tree[node].rch=build(mid+1,r);
		addedge(tree[node].rch*2,node*2,0);
		addedge(node*2+1,tree[node].rch*2+1,0);
		return node;
	}
	void init() {
		poolt=n;
		Root=build(1,n);
	}
	void A(int L,int R,int l,int r,int node,int tar,int w) {
		if (L<=l&&r<=R) {
			addedge(node*2,tar*2,w);
			return;
		}
		int mid=(l+r)>>1;
		if (L<=mid)
			A(L,R,l,mid,tree[node].lch,tar,w);
		if (R>mid)
			A(L,R,mid+1,r,tree[node].rch,tar,w);
	}
	void B(int L,int R,int l,int r,int node,int tar,int w) {
		if (L<=l&&r<=R) {
			addedge(tar*2+1,node*2+1,w);
			return;
		}
		int mid=(l+r)>>1;
		if (L<=mid)
			B(L,R,l,mid,tree[node].lch,tar,w);
		if (R>mid)
			B(L,R,mid+1,r,tree[node].rch,tar,w);
	}
}
void SPFA(int s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s*2]=0;
	memset(vis,0,sizeof(vis));
	q.push(make_pair(dis[s*2],s*2));
	while (!q.empty()) {
		pair<long long,int> tmp=q.top();
		q.pop();
		if (vis[tmp.y]) continue;
		vis[tmp.y]=1;
		for (int i=head[tmp.y];i!=-1;i=e[i].next)
			if (!vis[e[i].t]&&dis[tmp.y]+e[i].cap<dis[e[i].t]) {
				dis[e[i].t]=dis[tmp.y]+e[i].cap;
				q.push(make_pair(dis[e[i].t],e[i].t));
			}
	}
}
int main() {
	read(n),read(m),read(s);
	memset(head,0xff,sizeof(head));
	cnt=0;
	Tree::init();
	for (int i=1;i<=m;i++) {
		read(opt);
		if (opt==1) {
			read(u),read(v),read(w);
			Tree::B(v,v,1,n,Tree::Root,u,w);
		}
		if (opt==2) {
			read(v),read(l),read(r),read(w);
			Tree::B(l,r,1,n,Tree::Root,v,w);
		}
		if (opt==3) {
			read(v),read(l),read(r),read(w);
			Tree::A(l,r,1,n,Tree::Root,v,w); 
		}
	}
	SPFA(s);
	for (int i=1;i<=n;i++)
		printf("%I64d ",dis[i*2]==INF?-1:dis[i*2]);
	return 0;
}