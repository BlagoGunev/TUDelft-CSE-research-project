// LUOGU_RID: 98203182
#include<bits/stdc++.h>

#define ll long long

#define int long long

#define fir first

#define sec second

#define pii pair<int,int>

#define yes cout<<"Yes\n";

#define no cout<<"No\n";

using namespace std;



const int maxn=200005;

const int inf=0x3f3f3f3f3f3f3f3f;



struct Val {

	int v,cnt;

	Val operator + (const Val &rhs) const {

		Val t;

		t.v=min(v,rhs.v);

		t.cnt=(v==t.v)*cnt+(rhs.v==t.v)*rhs.cnt;

		return t;

	}

};

struct Tag {

	int add;

	Tag operator + (const Tag &rhs) const {

		return {add+rhs.add};

	}

};

struct ST {

	struct Node {

		int l,r;

	} a[maxn*4];

	Val val[maxn*4];

	Tag tag[maxn*4];

	void pushup(int x) {

		val[x]=val[x*2]+val[x*2+1];

	}

	void spread(int x,Tag t) {

		val[x].v+=t.add;

		tag[x]=tag[x]+t;

	}

	void pushdown(int x) {

		spread(x*2,tag[x]);

		spread(x*2+1,tag[x]);

		tag[x]={};

	}

	void build(int l,int r,int k=1) {

		a[k]={l,r};

		tag[k]={};

		if(l==r) {

			val[k]={0,1};

			return ;

		}

		int mid=(l+r)>>1;

		build(l,mid,k*2);

		build(mid+1,r,k*2+1);

		pushup(k);

	}

	void update(int l,int r,Tag t,int k=1) {

		if(a[k].r<l||a[k].l>r) {

			return ;

		}

		if(l<=a[k].l&&a[k].r<=r) {

			spread(k,t);

			return ;

		}

		pushdown(k);

		update(l,r,t,k*2);

		update(l,r,t,k*2+1);

		pushup(k);

	}

	void change(int x,Val v,int k=1) {

		if(a[k].l==a[k].r) {

			val[k]=v;

			return ;

		}

		pushdown(k);

		int mid=(a[k].l+a[k].r)>>1;

		change(x,v,k*2+(x>mid));

		pushup(k); 

	}

	Val ask(int l,int r,int k=1) {

		if(a[k].r<l||a[k].l>r) {

			return {inf,0};

		}

		if(l<=a[k].l&&a[k].r<=r) {

			return val[k];

		}

		pushdown(k);

		return ask(l,r,k*2)+ask(l,r,k*2+1);

	} 

} seg;

struct Node {

	int l,r,v;

};



int cnt;

int f[maxn];

int rd[maxn];

int fir[maxn];

int lst[maxn];

vector<int> graph[maxn];

vector<vector<char>> c;

vector<Node> t[maxn]; 



void dfs(int x) {

	fir[x]=++cnt;

	for(int to:graph[x]) {

		dfs(to);

	}

	lst[x]=cnt;

}



signed main() {

	ios::sync_with_stdio(false);

	cin.tie(0),cout.tie(0);

	int n,m;

	cin>>n>>m;

	c.resize(n+1,vector<char>(m+1));

	for(int i=1;i<=n;i++) {

		for(int j=1;j<=m;j++) {

			cin>>c[i][j];

		}

	}

	auto id=[&](int i,int j) {

		return (i-1)*m+j;

	};

	auto add=[&](int a,int b,int c,int d) {

		if(c<1||c>n||d<1||d>m) {

			return ;

		}

		int x=id(a,b),y=id(c,d); 

		rd[x]++;

		graph[y].push_back(x);

	};

	for(int i=1;i<=n;i++) {

		for(int j=1;j<=m;j++) {

			if(c[i][j]=='U') {

				add(i,j,i+2,j);

				add(i+1,j,i-1,j);

			} else if(c[i][j]=='L') {

				add(i,j,i,j+2);

				add(i,j+1,i,j-1);

			}

		}

	}

	for(int i=1;i<=n*m;i++) {

		if(!rd[i]) {

			dfs(i);

		}

	} 

	for(int i=1;i<=n;i++) {

		for(int j=1;j<=m;j++) {

			int x=0,y=0;

			if(c[i][j]=='U') {

				x=id(i,j),y=id(i+1,j);

			} else if(c[i][j]=='L') {

				x=id(i,j),y=id(i,j+1);

			}

			if(x&&y) {

				if((i+j)&1) {

					swap(x,y);

				}

				t[fir[x]].push_back({fir[y],lst[y],1});

				t[lst[x]+1].push_back({fir[y],lst[y],-1});

			} 

		}

	}

	seg.build(1,n*m);

	int ans=0;

	for(int i=1;i<=n*m;i++) {

		for(Node p:t[i]) {

			seg.update(p.l,p.r,{p.v});

		}

		Val t=seg.ask(1,n*m);

		ans+=n*m;

		if(!t.v) {

			ans-=t.cnt;

		}

	}

	cout<<ans<<"\n";

//	queue<int> q;

//	for(int i=1;i<=n*m;i++) {

//		f[i]=1;

//		if(!rd[i]) {

//			q.push(i);

//		}

//	}

//	while(q.size()) {

//		int x=q.front();

//		q.pop();

//		for(int to:graph[x]) {

//			f[to]+=f[x];

//			rd[to]--;

//			if(!rd[to]) {

//				q.push(to);

//			}

//		}

//	}

//	int ans=0;

//	for(int i=1;i<=n;i++) {

//		for(int j=1;j<=m;j++) {

//			if(c[i][j]=='U') {

//				ans+=f[id(i,j)]*f[id(i+1,j)];

//			} else if(c[i][j]=='L') {

//				ans+=f[id(i,j)]*f[id(i,j+1)];

//			}

//		}

//	}

//	cout<<ans<<"\n";

}