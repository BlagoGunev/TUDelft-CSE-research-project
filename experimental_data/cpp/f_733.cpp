#include<cstdio>

#include<algorithm>

using namespace std;

inline int read(){

	char c=getchar();int p=1,ret=0;

	while((c<'0')||(c>'9')){if(c=='-')p=-1;c=getchar();}

	while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();

	return ret*p;

}

struct Edge{

	int u,v,w,c,k;

}E[200005];

struct edge{

	int to,next,w;

}e[400005];

int n,m,S,last,cnt,p;

long long ans,re;

int fa[200005],head[200005],deep[200005];

int Fa[200005][20],w[200005][20];

inline bool cmp(Edge k1,Edge k2){return k1.w<k2.w;}

inline int find(int k){return fa[k]==k?k:fa[k]=find(fa[k]);}

void add(int u,int v,int w){e[++cnt]=(edge){v,head[u],w};head[u]=cnt;}

void dfs(int root){

	for(int i=head[root];i;i=e[i].next)if(e[i].to!=Fa[root][0]){

		Fa[e[i].to][0]=root;w[e[i].to][0]=e[i].w;deep[e[i].to]=deep[root]+1;

		dfs(e[i].to);

	}

}

inline int lca(int x,int y){

	if(deep[x]>deep[y])swap(x,y);

	for(int k=0;k<19;k++)if((deep[y]-deep[x])&(1<<k))y=Fa[y][k];

	if(x==y)return x;

	for(int k=19;k>=0;k--)if(Fa[x][k]!=Fa[y][k])x=Fa[x][k],y=Fa[y][k];

	return Fa[x][0];

}

inline int query(int x,int k){

	int ans=-2000000000;

	for(int i=0;i<=19;i++)if(k&(1<<i))ans=max(ans,w[x][i]),x=Fa[x][i];

	return ans;

}

int main(){

	n=read();m=read();

	for(int i=1;i<=m;i++)E[i].w=read(),E[i].k=i;

	for(int i=1;i<=m;i++)E[i].c=read();

	for(int i=1;i<=m;i++)E[i].u=read(),E[i].v=read();

	S=read();sort(E+1,E+1+m,cmp);

	for(int i=1;i<=n;i++)fa[i]=i;

	last=2000000000;

	for(int i=1;i<=m;i++){

		int U=find(E[i].u),V=find(E[i].v);

		if(U!=V){

			fa[U]=V;

			if(E[i].c<last)last=E[i].c;

			ans+=E[i].w;

			add(E[i].u,E[i].v,E[i].w);

			add(E[i].v,E[i].u,E[i].w);

		}

	}

	dfs(1);

	for(int i=1;i<=19;i++)

		for(int j=1;j<=n;j++)Fa[j][i]=Fa[Fa[j][i-1]][i-1],w[j][i]=max(w[j][i-1],w[Fa[j][i-1]][i-1]);

	re=ans-S/last;

	for(int i=1;i<=m;i++)if(E[i].c<last){

		int lc=lca(E[i].u,E[i].v),tmp=max(query(E[i].u,deep[E[i].u]-deep[lc]),query(E[i].v,deep[E[i].v]-deep[lc]));;

		if(re>ans+E[i].w-tmp-S/E[i].c)re=ans+E[i].w-tmp-S/E[i].c,p=i;

	}

	for(int i=1;i<=n;i++)fa[i]=i;

	printf("%I64d\n",re);

	if(p==0){

		for(int i=1;i<=m;i++){

			int U=find(E[i].u),V=find(E[i].v);

			if(U!=V){

				fa[U]=V;

				if(E[i].c==last){last=-1;printf("%d %d\n",E[i].k,E[i].w-S/E[i].c);}

				else printf("%d %d\n",E[i].k,E[i].w);

			}

		}

	}else{

		int U=find(E[p].u),V=find(E[p].v);

		fa[U]=V;

		for(int i=1;i<=m;i++){

			if(i==p){

				printf("%d %d\n",E[p].k,E[p].w-S/E[p].c);

				continue;

			}

			int U=find(E[i].u),V=find(E[i].v);

			if(U!=V){

				fa[U]=V;

				printf("%d %d\n",E[i].k,E[i].w);

			}

		}

	}

}