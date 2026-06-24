#include<bits/stdc++.h>

using namespace std;

const int M=5e5+5;

template<class T>void rd(T &a){

	a=0;char c;

	while(c=getchar(),!isdigit(c));

	do a=a*10+(c^48);

		while(c=getchar(),isdigit(c));

}

#define bug(x) cout<<#x<<"="<<x<<" "

#define debug(x) cout<<#x<<"="<<x<<endl

template<class T>void nt(T x){

	if(!x)return;

	nt(x/10),putchar(x%10+48);

}

template<class T>void pt(T x){

	if(!x)putchar(48);

	else nt(x);

}

struct Edge{

	int to,nxt;

}G[M<<1];

int tot_edge,head[M],n;

inline void add_edge(int from,int to){

	G[tot_edge]=(Edge){to,head[from]};

	head[from]=tot_edge++;

	G[tot_edge]=(Edge){from,head[to]};

	head[to]=tot_edge++;

}

struct Segment_Tree{

	int sum[M<<2],add[M<<2];

	inline void up(const int &p){

		sum[p]=sum[p<<1]+sum[p<<1|1];

	}

	inline void down(const int &p,const int &l,const int &r){

		if(!add[p])return;

		add[p<<1]=add[p],add[p<<1|1]=add[p];

		int mid=l+r>>1;

		sum[p<<1]=add[p]*(mid-l+1);

		sum[p<<1|1]=add[p]*(r-mid);

		add[p]=0;

	}

	void update(int l,int r,const int &x,int L=1,int R=n,int p=1){

		if(l==L&&r==R){

			add[p]=x,sum[p]=x*(R-L+1);

			return;

		}

		int mid=L+R>>1;

		down(p,L,R);

		if(r<=mid)update(l,r,x,L,mid,p<<1);

		else if(l>mid)update(l,r,x,mid+1,R,p<<1|1);

		else update(l,mid,x,L,mid,p<<1),update(mid+1,r,x,mid+1,R,p<<1|1);

		up(p);

	}

	int query(int l,int r,int L=1,int R=n,int p=1){

		if(l==L&&r==R)return sum[p];

		int mid=L+R>>1;

		down(p,L,R);

		if(r<=mid)return query(l,r,L,mid,p<<1);

		if(l>mid)return query(l,r,mid+1,R,p<<1|1);

		return query(l,mid,L,mid,p<<1)+query(mid+1,r,mid+1,R,p<<1|1);

	}

	bool col(int l,int r){

		int s=query(l,r);

		return s==r-l+1;

	}

}sgt;

int tid[M],uid[M],dfs_clock;

int anc[M],sz[M],hev[M],f[M];

void predfs(int v,int fa=0){

	sz[v]=1,f[v]=fa;

	for(int i=head[v];~i;i=G[i].nxt){

		int to=G[i].to;

		if(to==fa)continue;

		predfs(to,v);

		sz[v]+=sz[to];

		if(sz[to]>sz[hev[v]])

			hev[v]=to;

	}

}

void dfs(int v,int f=0,int ancestor=1){

	anc[v]=ancestor;

	tid[v]=++dfs_clock;

	if(hev[v])dfs(hev[v],v,ancestor);

	for(int i=head[v];~i;i=G[i].nxt){

		int to=G[i].to;

		if(to==f||to==hev[v])continue;

		dfs(to,v,to);

	}

	uid[v]=dfs_clock;

}

void modify(int x){

	for(;x;x=f[anc[x]])

		sgt.update(tid[anc[x]],tid[x],-1);

}

int main(){

	memset(head,-1,sizeof(head));

	cin>>n;

	for(int i=1,a,b;i<n;++i)

		rd(a),rd(b),add_edge(a,b);

	predfs(1);

	dfs(1);

	int q;cin>>q;

	for(int opt,x;q--;){

		rd(opt),rd(x);

		switch(opt){

			case(1):

				sgt.update(tid[x],uid[x],1);

				break;

			case(2):

				modify(x);

				break;

			case(3):

				pt(sgt.col(tid[x],uid[x])),putchar('\n');

				break;

		}

	}

	return 0;

}