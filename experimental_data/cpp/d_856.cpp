#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=201000;

int n,m;
int head[maxn],nxt[maxn],list[maxn],tot;
vector<int> u[maxn],v[maxn],bu[maxn];
int fa[maxn],dep[maxn],son[maxn],top[maxn],size[maxn];
int dfn[maxn],tim;
long long sum[maxn],dp[maxn];

void add(int a,int b){
	tot++;
	nxt[tot]=head[a];
	head[a]=tot;
	list[tot]=b;
	return;
}

int dfs(int p,int f){
	size[p]=1;
	fa[p]=f;
	dep[p]=dep[f]+1;
	for (int i=head[p];i;i=nxt[i]){
		size[p]+=dfs(list[i],p);
		if (size[list[i]]>size[son[p]]) son[p]=list[i];
	}
	return size[p];
}

void dfs2(int p){
	dfn[p]=++tim;
	if (son[p]){
		top[son[p]]=top[p];
		dfs2(son[p]);
	}
	for (int i=head[p];i;i=nxt[i]) if (list[i]!=son[p]){
		top[list[i]]=list[i];
		dfs2(list[i]);
	}
	return;
}

inline int getlca(int a,int b){
	while(top[a]!=top[b]){
		if (dep[top[a]]>dep[top[b]]) swap(a,b);
		b=fa[top[b]];
	}
	if (dep[a]<dep[b]) return a;
	else return b;
}

inline void inc(int a,int b){
	while(a<=n){
		sum[a]+=b;
		a+=a&(-a);
	}
	return;
}

inline long long ask(int a){
	long long ret=0;
	while(a){
		ret+=sum[a];
		a-=a&(-a);
	}
	return ret;
}

inline long long ask(int a,int b){return ask(b)-ask(a-1);}

inline long long get(int a,int b){
	long long ret=0;
	while(top[a]!=top[b]){
		ret+=ask(dfn[top[a]],dfn[a]);
		ret+=dp[son[a]];
		ret-=dp[top[a]];
		a=fa[top[a]];
	}
	ret+=ask(dfn[b],dfn[a]);
	ret+=dp[son[a]];
	return ret;
}

void dfs3(int p){
	long long S=0;
	for (int i=head[p];i;i=nxt[i]){
		dfs3(list[i]);
		S+=dp[list[i]];
	}
	inc(dfn[p],S-dp[son[p]]);
	dp[p]=S;
	for (int i=0;i<u[p].size();++i){
		if (u[p][i]==p){
			dp[p]=max(dp[p],bu[p][i]+get(v[p][i],p));
		}
		else{
			dp[p]=max(dp[p],bu[p][i]+get(v[p][i],p)+get(u[p][i],p)-S);
		}
	}
	return;
}

int main(){
	int a,b,c;
	scanf("%d%d",&n,&m);
	for (int i=2;i<=n;++i){
		scanf("%d",&a);
		add(a,i);
	}
	dfs(1,1);
	top[1]=1;
	dfs2(1);
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",&a,&b,&c);
		if (dep[a]>dep[b]) swap(a,b);
		int lca=getlca(a,b);
		u[lca].push_back(a);
		v[lca].push_back(b);
		bu[lca].push_back(c);
	}
	dfs3(1);
	printf("%lld\n",dp[1]);
	return 0;
}