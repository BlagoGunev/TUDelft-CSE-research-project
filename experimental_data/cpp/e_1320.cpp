// LUOGU_RID: 97737920
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> Pair;

const int N=2e5+500,INF=1e9;

#define F first

#define S second

Pair f[N],g[N],pre[N],suf[N];

int dfn[N],ST[N<<1][19],Log[N<<1],dep[N],col[N],s[N],p[N],vis[N],vet[N],stk[N],que[N];

int n,m,k,q,u,v,L,top;

vector<int> G[N],Tr[N];

bool cmp(int i, int j){ return dfn[i]<dfn[j]; }

void dfs(int u, int f){

	ST[dfn[u]=++L][0]=u; dep[u]=dep[f]+1;

	for (int v:G[u])

		if (v!=f) dfs(v,u),ST[++L][0]=u;

}

inline int LCA(int u, int v){

	int l=dfn[u],r=dfn[v];

	if (l>r) swap(l,r);

	int k=Log[r-l+1],x=ST[l][k],y=ST[r-(1<<k)+1][k];

	return dep[x]<dep[y]?x:y;

}

inline int dist(int u, int v){ return dep[u]+dep[v]-dep[LCA(u,v)]*2; }

void dfs1(int u){

	for (int v:Tr[u]){

		dfs1(v); pre[v]=f[u]; int c=f[v].S;

		if (c) f[u]=min(f[u],make_pair((dist(p[c],u)+s[c]-1)/s[c],c));

	}

	Pair P={INF,0};

	for (int i=Tr[u].size()-1; ~i; i--){

		suf[Tr[u][i]]=P; int c=f[Tr[u][i]].S;

		if (c) P=min(P,make_pair((dist(p[c],u)+s[c]-1)/s[c],c));

	}

	if (col[u]) f[u]={0,col[u]};

}

void dfs2(int u){

	int c=g[u].S;

	if (c) f[u]=min(f[u],make_pair((dist(p[c],u)+s[c]-1)/s[c],c));

	for (int v:Tr[u]){

		if (col[u]) g[v]={0,col[u]};

		else {

			g[v]=min(pre[v],suf[v]); int c=g[u].S;

			if (c) g[v]=min(g[v],make_pair((dist(p[c],u)+s[c]-1)/s[c],c));

		}

		dfs2(v);

	}

}

void Clear(int u){

	f[u]=g[u]=pre[u]=suf[u]={INF,0};

	col[u]=vis[u]=0;

	for (int v:Tr[u]) Clear(v);

	Tr[u].clear();

}

inline void Add(int u, int v){ Tr[u].push_back(v); }

char buf[1<<24],*S=buf,obuf[1<<23],*Os=obuf;

#define gc() (*S++)

inline int read(){

	char ch=gc(); int num=0;

	while (!isdigit(ch)) ch=gc();

	while (isdigit(ch)) num=num*10+ch-'0',ch=gc();

	return num;

}

inline void Pc(char ch){ *Os++=ch; }

void P(int x){ if (x>9) P(x/10); Pc(x%10+'0'); }

int main(){

	fread(buf,1,1<<24,stdin);

	n=read(); Log[0]=-1;

	for (int i=1; i<n; i++){

		u=read(),v=read();

		G[u].push_back(v),G[v].push_back(u);

	}

	dfs(1,0);

	for (int i=1; i<=L; i++) Log[i]=Log[i>>1]+1;

	for (int i=L; i>=1; i--)

		for (int j=1; i+(1<<j)-1<=L; j++){

			int x=ST[i][j-1],y=ST[i+(1<<(j-1))][j-1];

			ST[i][j]=dep[x]<dep[y]?x:y;

		}

	for (int i=1; i<=n; i++) f[i]=g[i]=pre[i]=suf[i]={INF,0};

	for (q=read(); q; q--){

		m=read(),k=read(); int len=0;

		for (int i=1; i<=m; i++){

			p[i]=read(),s[i]=read(); col[p[i]]=i;

			if (!vis[p[i]]) vis[p[i]]=1,vet[++len]=p[i];

		}

		for (int i=1; i<=k; i++){

			que[i]=read();

			if (!vis[que[i]]) vis[que[i]]=1,vet[++len]=que[i];

		}

		sort(vet+1,vet+1+len,cmp); stk[top=1]=1;

		for (int i=1; i<=len; i++){

			if (vet[i]==1) continue;

			while (LCA(stk[top],vet[i])!=stk[top])

				if (LCA(stk[top-1],vet[i])==stk[top-1]){

					int u=LCA(stk[top],vet[i]); Add(u,stk[top--]);

					if (u!=stk[top]) stk[++top]=u;

				} else Add(stk[top-1],stk[top]),top--;

			stk[++top]=vet[i];

		}

		for (int i=1; i<top; i++) Add(stk[i],stk[i+1]);

		dfs1(1); dfs2(1);

		for (int i=1; i<=k; i++) P(f[que[i]].S),Pc(' ');

		Clear(1); Pc('\n');

	}

	fwrite(obuf,1,Os-obuf,stdout);

}