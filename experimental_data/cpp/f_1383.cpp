#pragma GCC target("avx")

#pragma GCC optimize("Ofast")

#pragma GCC optimize("inline")

#pragma GCC optimize("-fgcse")

#pragma GCC optimize("-fgcse-lm")

#pragma GCC optimize("-fipa-sra")

#pragma GCC optimize("-ftree-pre")

#pragma GCC optimize("-ftree-vrp")

#pragma GCC optimize("-fpeephole2")

#pragma GCC optimize("-ffast-math")

#pragma GCC optimize("-fsched-spec")

#pragma GCC optimize("unroll-loops")

#pragma GCC optimize("-falign-jumps")

#pragma GCC optimize("-falign-loops")

#pragma GCC optimize("-falign-labels")

#pragma GCC optimize("-fdevirtualize")

#pragma GCC optimize("-fcaller-saves")

#pragma GCC optimize("-fcrossjumping")

#pragma GCC optimize("-fthread-jumps")

#pragma GCC optimize("-funroll-loops")

#pragma GCC optimize("-fwhole-program")

#pragma GCC optimize("-freorder-blocks")

#pragma GCC optimize("-fschedule-insns")

#pragma GCC optimize("inline-functions")

#pragma GCC optimize("-ftree-tail-merge")

#pragma GCC optimize("-fschedule-insns2")

#pragma GCC optimize("-fstrict-aliasing")

#pragma GCC optimize("-fstrict-overflow")

#pragma GCC optimize("-falign-functions")

#pragma GCC optimize("-fcse-skip-blocks")

#pragma GCC optimize("-fcse-follow-jumps")

#pragma GCC optimize("-fsched-interblock")

#pragma GCC optimize("-fpartial-inlining")

#pragma GCC optimize("no-stack-protector")

#pragma GCC optimize("-freorder-functions")

#pragma GCC optimize("-findirect-inlining")

#pragma GCC optimize("-fhoist-adjacent-loads")

#pragma GCC optimize("-frerun-cse-after-loop")

#pragma GCC optimize("inline-small-functions")

#pragma GCC optimize("-finline-small-functions")

#pragma GCC optimize("-ftree-switch-conversion")

#pragma GCC optimize("-foptimize-sibling-calls")

#pragma GCC optimize("-fexpensive-optimizations")

#pragma GCC optimize("-funsafe-loop-optimizations")

#pragma GCC optimize("inline-functions-called-once")

#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<iostream>

#include<cstdio>

#include<cstring>

#include<queue>

#include<vector>

#define N 10005

#define M 10005

#define re register

using namespace std;

char buf[1<<23],*p1=buf,*p2=buf;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

inline int read(){

    int s=0,w=1;char ch=getchar();

    while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}

    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();

    return s*w;

}

const int INF=(1LL<<31)-1;

struct edge{

	int v,w,nxt;

}e[M<<1];

int s,t,tot,head[N],dep[N],now[N],flow[N],pre[N],pe[N];

bool vis[N];

inline void add(int u,int v,int w){

	e[++tot]=(edge){v,w,head[u]};

	head[u]=tot;

	e[++tot]=(edge){u,0,head[v]};

	head[v]=tot;

	return;

}

inline void inits(int ss,int tt){

	s=ss,t=tt;

	tot=1;

	memset(head,0,sizeof(head));

}

inline int Bfs(){

	static int q[N];

	int l=1,r=0;

	q[++r]=s;

	memset(vis,0,sizeof(vis));

	vis[s]=1;

	while(l<=r){

		int f=q[l++];

		for(int i=head[f];i;i=e[i].nxt){

			if(!vis[e[i].v]&&e[i].w){

				pre[e[i].v]=f;

				q[++r]=e[i].v;

				vis[e[i].v]=1;

				flow[e[i].v]=e[i].w;

				pe[e[i].v]=i;

			}

			if(vis[t]) break;

		}

		if(vis[t]) break;

	}

	if(!vis[t]) return 0;

	int res=INF;

	for(int i=t;i!=s;i=pre[i]) res=min(res,flow[i]);

	for(int i=t;i!=s;i=pre[i]) e[pe[i]].w-=res,e[pe[i]^1].w+=res;

	return res;

}

inline int FF(){

	int ans=0,num;

	while(num=Bfs()) ans+=num;

	return ans;

}

inline bool bfs(){

	memset(dep,0,sizeof(dep));

	queue<int> q;

	q.push(s);

	dep[s]=1;

	now[s]=head[s];

	while(!q.empty()){

		int f=q.front();

		q.pop();

		for(int i=head[f];i;i=e[i].nxt){

			int v=e[i].v;

			if(!dep[v]&&e[i].w){

				dep[v]=dep[f]+1;

				now[v]=head[v];

				q.push(v);

				if(v==t) return 1;

			}

		}

	}

	return 0;

}

int dfs0(int x,int flow){

	if(x==t){

		return flow;

	}

	int tot=0;

	for(int i=now[x];i&&flow;i=e[i].nxt){

		now[x]=i;

		int v=e[i].v;

		if(!e[i].w||dep[v]!=dep[x]+1) continue;

		int num;

		if(num=dfs0(v,min(flow,e[i].w))){

			e[i].w-=num;

			e[i^1].w+=num;

			tot+=num;

			flow-=num;

		}else dep[v]=0;

	}

	return tot;

}

inline int dinic(){

	int ans=0;

	while(bfs()) ans+=dfs0(s,INF);

	return ans;

}

int n,m,k,q,hh,fl[1<<10],kot=-1,ke[20],w[20],cnt[1<<10],fa[1<<10],hb[1<<10];

edge cy[1<<10][M<<1];

int main(){

	int highbit=0;

	for(re int i=1;i<(1<<10);i++){

		if(i>=(1<<highbit+1)) highbit++;

		fa[i]=i^(1<<highbit);

		hb[i]=highbit;

	}

	n=read(),m=read(),k=read(),q=read();

	hh=1<<k;

	inits(1,n);

	for(re int i=1;i<=m;i++){

		int u,v,w;

		u=read(),v=read(),w=read();

		if(!w&&kot!=k-1) ke[++kot]=tot+1;

		add(u,v,w);

	}

	fl[0]=dinic();

	for(re int i=1;i<=tot;i++) cy[0][i]=e[i];

	for(re int i=1;i<hh;i++){

		for(re int j=1;j<=tot;j++) e[j]=cy[fa[i]][j];

		e[ke[hb[i]]].w=25;

		fl[i]=FF()+fl[fa[i]];

		for(re int j=1;j<=tot;j++) cy[i][j]=e[j];

	}

	while(q--){

		for(re int i=0;i<k;i++) w[i]=read();

		int ans=1<<30;

		for(re int i=0;i<hh;i++){

			if(i) cnt[i]=cnt[fa[i]]+w[hb[i]];

			ans=min(ans,cnt[i]+fl[(hh-1)^i]);

		}

		printf("%d\n",ans);

	}

}