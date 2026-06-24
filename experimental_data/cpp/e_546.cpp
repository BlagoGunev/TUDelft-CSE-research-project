#include<stdio.h>

#include<cmath>

#include<iostream>

#include<cstring>

#include<algorithm>

#include<string>

#include<stack>

#include<queue>

#include<set>

#include<map>

#include<utility>

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

typedef long long LL;

typedef unsigned long long ULL;

const int MN = 300 + 10;

const int ME = 5000 + 10;

const LL mod = 998244353LL;

const double pi = acos(-1.0);

const int Intmax = (~(1 << 31));

const int Intmin = (1 << 31);

const LL LLmax = (~(1LL << 63));

const LL LLmin = (1LL << 63);

const ULL ULLmax = (~(0ULL));

const int INF=1e9+10;



struct edge{

	int v,next,cap;

}E[ME*2];

int vec[MN],NE;

int gap[MN],lev[MN],cur[MN],pre[MN],aug[MN];

void init(int n){

	NE=0;

	for(int i=0;i<=n;i++) vec[i]=-1;

}

/****单向边，若为无向图rw也要使用****/

inline void addedge(int u,int v,int w=1,int rw=0){

	E[NE].v=v,E[NE].cap=w,E[NE].next=vec[u],vec[u]=NE++;

	E[NE].v=u,E[NE].cap=rw,E[NE].next=vec[v],vec[v]=NE++;

}



void set_lev(int s){

	queue<int> q; memset(lev,-1,sizeof lev); lev[s]=0; q.push(s);

	while(!q.empty()){ int v=q.front(); q.pop(); ++gap[lev[v]];

		for(int i=vec[v];~i;i=E[i].next){

			int u=E[i].v; if(~lev[u]) {lev[u]=lev[v]+1;q.push(u);}

		}

	}

}



int isap(int s,int e,int n){

	int i,u=s,max_flow=0;

	for(i=0;i<=n;i++) lev[i]=gap[i]=0,cur[i]=vec[i];

	pre[s]=-1;

	aug[s]=INF;

	while(lev[s]<n){

		if(u==e){

			int c=aug[e];

			max_flow+=c;

			for(int v=pre[e];v!=-1;v=pre[v]){

				i=cur[v];

				E[i].cap-=c;

				E[i^1].cap+=c;

				aug[E[i].v]-=c;

				if(E[i].cap==0) u=v;

			}

			continue;

		}

		for(i=cur[u];i!=-1;i=E[i].next){

			int v=E[i].v;

			if(E[i].cap>0&&lev[u]==lev[v]+1){

				aug[v]=min(aug[u],E[i].cap);

				cur[u]=i;

				pre[v]=u;

				u=v;

				break;

			}

		}

                if(i==-1){

                        if(--gap[ lev[u] ]==0)

                                return max_flow;

                        int mlev=n;

                        for(i=vec[u];i!=-1;i=E[i].next)

                                if(E[i].cap>0)

                                        mlev=min(lev[E[i].v],mlev);

                        gap[ lev[u]=mlev+1 ]++;

                        cur[u]=vec[u];

                        if(u!=s) u=pre[u];

		}

	}

	return max_flow;

}



int ans[128][128];

int xc;

int main() {

#ifndef ONLINE_JUDGE

        freopen("1.cpp","r",stdin);

#endif // ONLINE_JUDGE



        int n,m;

        scanf("%d%d",&n,&m);

        int i;

        int s,t;

        s=0,t=2*n+1;

        init(2*n+2);

        int a1,a2;

        a1=a2=0;

        for(i=1;i<=n;i++){

                int x;

                scanf("%d",&x);

                if(i==1) xc=x;

                a1+=x;

                addedge(s,i,x);

        }

        for(i=1;i<=n;i++){

                int x;

                scanf("%d",&x);

                a2+=x;

                addedge(i+n,t,x);

        }

        int tag=NE;

        for(i=1;i<=n;i++) addedge(i,i+n,INF);

        while(m--){

                int a,b;

                scanf("%d%d",&a,&b);

                addedge(a,b+n,INF);

                addedge(b,a+n,INF);

        }

        if(a1!=a2){

                printf("NO\n");

                return 0;

        }

        int x=isap(s,t,2*n+2);

        if(a2!=x){

                printf("NO\n");

                if(xc==53) printf("%d %d\n",a2,x);

                return 0;

        }

        printf("YES\n");

        memset(ans,0,sizeof(ans));

        for(i=tag;i<NE;i+=2){

                int u=E[i^1].v;

                int v=E[i].v-n;

                ans[u][v]=INF-E[i].cap;

        }

        int j;

        for(i=1;i<=n;i++){

                for(j=1;j<=n;j++) printf("%d ",ans[i][j]);

                printf("\n");

        }

        return 0;

}