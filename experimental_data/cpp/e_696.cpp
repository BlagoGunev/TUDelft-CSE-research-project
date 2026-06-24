//by yjz

#include<bits/stdc++.h>

using namespace std;

#define FF first

#define SS second

#define PB push_back 

#define MP make_pair

typedef long long ll;

const ll INF=1<<28;

const ll LINF=1ll<<61;

//My own input/output stream

#define geti(x) x=getnum()

#define getii(x,y) geti(x),geti(y)

#define getiii(x,y,z) getii(x,y),geti(z)

#define puti(x) putnum(x),putsp()

#define putii(x,y) puti(x),putnum(y),putsp()

#define putiii(x,y,z) putii(x,y),putnum(z),putsp()

#define putsi(x) putnum(x),putendl()

#define putsii(x,y) puti(x),putnum(y),putendl()

#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()

inline ll getnum()

{

	register ll r=0;register bool ng=0;register char c;c=getchar();

	while(c!='-'&&(c<'0'||c>'9'))c=getchar();

	if(c=='-')ng=1,c=getchar();

	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();

	if(ng)r=-r;return r;

}

template <class T> inline void putnum(T x)

{

	if(x<0)putchar('-'),x=-x;

	register short a[20]={},sz=0;

	while(x>0)a[sz++]=x%10,x/=10;

	if(sz==0)putchar('0');

	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);

}

inline void putsp(){putchar(' ');}

inline void putendl(){putchar('\n');}

inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}

pair<ll,int> init_a[100111];

struct SGT

{

	struct node

	{

		int l,r;

		ll dlt,v;

		pair<ll,int>mn;

	}a[400111];

	#define ls p<<1

	#define rs p<<1|1

	void build(int l,int r,int p=1)

	{

		a[p].l=l;a[p].r=r;

		a[p].dlt=0;

		if(l==r)

		{

			a[p].mn=init_a[l];

			a[p].v=0;

			return;

		}

		int m=l+r>>1;

		build(l,m,ls);

		build(m+1,r,rs);

		a[p].mn=min(a[ls].mn,a[rs].mn);

	}

	void push_down(int p)

	{

		if(a[p].dlt!=0&&a[p].l<a[p].r)

		{

			a[ls].dlt+=a[p].dlt;

			a[rs].dlt+=a[p].dlt;

			a[ls].mn.FF+=a[p].dlt;

			a[rs].mn.FF+=a[p].dlt;

			a[ls].v+=a[p].dlt;

			a[rs].v+=a[p].dlt;

			a[p].dlt=0;

		}

	}

	void add(int x,int y,int v,int p=1)

	{

//		if(p==1)cout<<"add:"<<x<<","<<y<<" "<<v<<endl;

		push_down(p);

		int l=a[p].l,r=a[p].r;

		if(x<=l&&r<=y)

		{

			a[p].mn.FF+=v;

			a[p].dlt+=v;

			a[p].v+=v;

			return;

		}

		int m=l+r>>1;

		if(x<=m)add(x,y,v,ls);

		if(m<y)add(x,y,v,rs);

		a[p].mn=min(a[ls].mn,a[rs].mn);

	}

	pair<ll,int> query(int x,int y,int p=1)

	{

//		if(p==1)cout<<"query:"<<x<<","<<y<<endl;

		push_down(p);

		int l=a[p].l,r=a[p].r;

		if(x<=l&&r<=y)return a[p].mn;

		int m=l+r>>1;

		if(x<=m&&m<y)return min(query(x,y,ls),query(x,y,rs));

		else if(x<=m)return query(x,y,ls);

		else return query(x,y,rs);

	}

	void change(int x,int id,int p=1)

	{

//		if(p==1)cout<<"change:"<<x<<" "<<id<<endl;

		push_down(p);

		int l=a[p].l,r=a[p].r;

		if(l==r)

		{

			if(id>0)a[p].mn.FF=a[p].v+id;

			else a[p].mn.FF=LINF;

			return;

		}

		int m=l+r>>1;

		if(x<=m)change(x,id,ls);

		else change(x,id,rs);

		a[p].mn=min(a[ls].mn,a[rs].mn);

	}

}menma;

int dfn[100111],dfnr[100111],dfntot;

int n,m,q;

int top[100111],fa[100111],lv[100111],son[100111],sz[100111];

int head[100111],nxt[200111],to[200111],etot;

void dfs(int x,int pre)

{

	fa[x]=pre;

	sz[x]=1;

	for(int i=head[x];i;i=nxt[i])

	{

		if(to[i]==pre)continue;

		lv[to[i]]=lv[x]+1;

		dfs(to[i],x);

		sz[x]+=sz[to[i]];

	}

}

void dfs2(int x)

{

	dfntot++;

	dfn[x]=dfntot;

	int mx=-1;

	for(int i=head[x];i;i=nxt[i])

	{

		if(to[i]==fa[x])continue;

		if(sz[to[i]]>mx)

		{

			mx=sz[to[i]];

			son[x]=to[i];

		}

	}

	if(mx!=-1)

	{

		top[son[x]]=top[x];

		dfs2(son[x]);

	}

	for(int i=head[x];i;i=nxt[i])

	{

		if(to[i]==fa[x]||to[i]==son[x])continue;

		top[to[i]]=to[i];

		dfs2(to[i]);

	}

	dfnr[x]=dfntot;

}

int fg[100111],nxtg[100111];

pair<ll,int> getmn(int x,int y)

{

	pair<ll,int> mn=MP(LINF,LINF);

	while(true)

	{

		if(top[x]==top[y])

		{

			if(lv[x]<lv[y])swap(x,y);

			mn=min(mn,menma.query(dfn[y],dfn[x]));

			return mn;

		}

		if(lv[top[x]]<lv[top[y]])swap(x,y);

		mn=min(mn,menma.query(dfn[top[x]],dfn[x]));

		x=fa[top[x]];

	}

}

vector<int>vans;

int tid[100111];

int main()

{

	getiii(n,m,q);

	for(int i=1;i<n;i++)

	{

		int x,y;

		getii(x,y);

		nxt[++etot]=head[x];

		head[x]=etot;

		to[etot]=y;

		nxt[++etot]=head[y];

		head[y]=etot;

		to[etot]=x;

	}

	lv[1]=1;

	dfs(1,-1);

	top[1]=1;

	dfs2(1);

	for(int i=1;i<=m;i++)geti(tid[i]);

	for(int i=m;i>=1;i--)

	{

		int x=tid[i];

		nxtg[i]=fg[x];

		fg[x]=i;

	}

	for(int i=1;i<=n;i++)

	{

		if(fg[i]>0)init_a[dfn[i]]=MP(fg[i],i);

		else init_a[dfn[i]]=MP(LINF,i);

	}

//	for(int i=1;i<=n;i++)cout<<init_a[i].FF<<","<<init_a[i].SS<<" ";

	menma.build(1,n);

	for(int i=1;i<=q;i++)

	{

		int cmd,x,y,k;

		geti(cmd);

		if(cmd==1)

		{

			getiii(x,y,k);

			vans.clear();

			while(k>0)

			{

				pair<ll,int> mn=getmn(x,y);

//				cout<<"mn="<<mn.FF<<","<<mn.SS<<endl;

				if(mn.FF>(1ll<<60))break;

				else

				{

					vans.PB(fg[mn.SS]);

					fg[mn.SS]=nxtg[fg[mn.SS]];

					if(fg[mn.SS]>0)menma.change(dfn[mn.SS],fg[mn.SS]);

					else menma.change(dfn[mn.SS],-1);

					k--;

				}

			}

			puti(vans.size());

			for(int j=0;j<vans.size();j++)puti(vans[j]);

			puts("");

		}

		else

		{

			getii(x,k);

			menma.add(dfn[x],dfnr[x],k);

		}

	}

	return 0;

}