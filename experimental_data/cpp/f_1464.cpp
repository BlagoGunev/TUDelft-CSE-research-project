#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2,fma")



#include<bits/stdc++.h>

#define itn int

#define ll long long

#define fi first

#define se second

#define pb push_back

using namespace std;



ll read(){

	ll a=0;bool b=0;char c=getchar();

	while(c>'9'||c<'0')b^=(c=='-'),c=getchar();

	while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();

	return b?-a:a;

}



const int N=200005;

int n,q;

struct edge{

	int v,nx;

}e[N*2];

struct pir{int a,b;};

int hd[N],dp[N],to[N][19],sz[N],dfn[N],dn,cnt,rdn[N];

void dfs(int u,int f){

	dp[u]=dp[f]+1, to[u][0]=f, sz[u]=1, dfn[u]=++dn, rdn[dn]=u;

	for(int i=1;i<19;i++)to[u][i]=to[to[u][i-1]][i-1];

	for(int j=hd[u];j;j=e[j].nx)if(e[j].v!=f){

		dfs(e[j].v,u);

		sz[u]+=sz[e[j].v];

	}

}

int lca(int u,int v){

	for(int i=18;i>=0;i--)if(dp[to[u][i]]>=dp[v])u=to[u][i];

	for(int i=18;i>=0;i--)if(dp[to[v][i]]>=dp[u])v=to[v][i];

	if(u==v)return v;

	for(int i=18;i>=0;i--)if(to[u][i]!=to[v][i])v=to[v][i],u=to[u][i];

	if(to[u][0]==v)return v;

	return to[v][0];

}

int up(int u,int d){

	for(int i=0;i<19;i++)if((d>>i)&1)u=to[u][i];

	return u;

}



int le(const pir &a){

	int l=lca(a.a,a.b);

	return dp[a.a]-dp[l]+dp[a.b]-dp[l];

}



bool operator<(const pir &a,const pir &b){

	return a.b==b.b?a.a<b.a:a.b>b.b;

}



pir mx(const pir &a,const pir &b){

	if(a.b==-1||a.a==-1)return b;

	if(b.b==-1||b.a==-1)return a;

	return le(a)<le(b)?b:a;

}





pir operator+(const pir &a,const pir &b){

	pir c=mx(a,b);

	c=mx(c,mx(pir{a.a,b.a},pir{a.a,b.b}));

	c=mx(c,mx(pir{a.b,b.a},pir{a.b,b.b}));

	return c;

}



const int NS=524290;



#define ls (p*2)

#define rs (p*2+1)

pir tr[NS];

int l[NS],r[NS],sr[N];

void build(int p,int x,int y){

	l[p]=x,r[p]=y,tr[p]=pir{-1,-1};

	if(x==y)return;

	build(ls,x,(x+y)/2);

	build(rs,(x+y)/2+1,y);

}

struct bit{

	int t[N];

	void add(int i,int k){for(;i<=n;i+=i&-i)t[i]+=k;}

	int find(int i){int a=0;for(;i;i-=i&-i)a+=t[i];return a;}

	int sum(int l,int r){return find(r)-find(l-1);}

}a;

void cg(int p,int x,int g){

	if(l[p]==r[p]){

		if(g)tr[p]=pir{rdn[x],rdn[x]};

		else tr[p]=pir{-1,-1};

		return;

	}

	if(x<=(l[p]+r[p])/2)cg(ls,x,g);

	else cg(rs,x,g);

	tr[p]=tr[ls]+tr[rs];

}



pir find(int p,int x,int y){

	if(x<=l[p]&&r[p]<=y)return tr[p];

	int m=(l[p]+r[p])/2;

	pir c=pir{-1,-1};

	if(x<=m)c=c+find(ls,x,y);

	if(m<y)c=c+find(rs,x,y);

	return c;

}



multiset<pir>s;



bool sol(int d){

	pir p=*s.begin();

	int u=p.a,v=up(u,d),k=up(v,d);

	int nu=a.sum(dfn[k],dfn[k]+sz[k]-1);

	if(nu!=s.size())return 0;

	pir o=find(1,dfn[k],dfn[k]+sz[k]-1);

	int x=max(le(pir{o.a,v}),le(pir{o.b,v}));

	return x<=d;

}



int main(){

	n=read(),q=read();

	for(int i=1;i<n;i++){

		int x=read(),y=read();

		e[++cnt]=edge{x,hd[y]},hd[y]=cnt;

		e[++cnt]=edge{y,hd[x]},hd[x]=cnt;

	}

	dfs(1,1);

	build(1,1,n);

	while(q--){

		int op=read(),x=read(),y,l;

		if(op==1){

			y=read(), l=lca(x,y);

			a.add(dfn[x],1), a.add(dfn[y],1), a.add(dfn[l],-1);

			s.insert(pir{l,dp[l]});

			if(++sr[l]==1)cg(1,dfn[l],1);

		}else if(op==2){

			y=read(), l=lca(x,y);

			a.add(dfn[x],-1), a.add(dfn[y],-1), a.add(dfn[l],1);

			s.erase(s.find(pir{l,dp[l]}));

			if(--sr[l]==0)cg(1,dfn[l],0);

		}else{

			puts(sol(x)?"Yes":"No");

		}

	}

	return 0;

}