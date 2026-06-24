#include<cstdio>

#include<algorithm>

 

#define MAXN 110000

using namespace std;

 

int n,m,cnt;

 

int ans[MAXN];

int clock;

 

int l[MAXN];

int r[MAXN];

int id[MAXN];

long long val[MAXN];

 

int dfn[MAXN];

int low[MAXN];

 

int f[MAXN];

 

struct Node

{

    int id;

    int v;

    Node * next;

};

Node edge[MAXN*2];

Node * ecnt = edge;

Node * adj[MAXN];

 

void set(int a,int b,int id)

{

    Node * p = ++ecnt; p->id = id;

    p ->v = b;p->next = adj[a];adj[a] = p;

    p = ++ecnt; p->id = id;

    p->v = a;p->next = adj[b];adj[b] = p;

}

 

bool cmp(int a,int b)

{

    return val[a]<val[b];

}

 

int find(int a)

{

    return f[a]==a?a:f[a]=find(f[a]);

}

 

int dfs(int u,int fa)

{

    int lowu = dfn[u] = ++clock;

    for(Node * p = adj[u];p;p=p->next) {

        if(!dfn[p->v]) {

            int lowv = dfs(p->v,p->id);

            lowu = min(lowv,lowu);

            if(lowv>dfn[u]) ans[p->id] = 2;

        }

        else if(dfn[u]>dfn[p->v]&&p->id!=fa) {

            lowu = min(dfn[p->v],lowu);

        }

    }

    return lowu;

}



void delet(int x,int y)

{

	dfn[x] = 0;

	dfn[y] = 0;

	adj[x] = 0;

	adj[y] = 0;

}



int main()

{

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++) {

        cnt++;

        scanf("%d%d%I64d",&l[cnt],&r[cnt],&val[cnt]);

        id[cnt] = cnt;

    }

    sort(id+1,id+1+cnt,cmp);

    for(int i=1;i<=n;i++) f[i] = i;

    int j;

    for(int i=1;i<=cnt;i=j) {

        j = i+1;

		ecnt = edge;

        while(j<=cnt+1&&val[id[j]]==val[id[i]]) j++;

        for(int k=i;k<j;k++) {

            int x = find(l[id[k]]);

            int y = find(r[id[k]]);

            if(x==y) {

                ans[id[k]] = -1;

                continue;

            }

            set(x,y,id[k]);

            ans[id[k]] = 1;

        }

        for(int k=i;k<j;k++) {

            int x = find(l[id[k]]);

            int y = find(r[id[k]]);

            if(x!=y&&!dfn[x]) {

                dfs(x,-1);

            }

        }

        for(int k=i;k<j;k++) {

            int x = find(l[id[k]]);

            int y = find(r[id[k]]);

			if(x!=y) {

				f[x] = y;

				delet(x,y);

			}

		}

    }

    for(int i=1;i<=m;i++) {

        if(ans[i]==-1) printf("none\n");

        if(ans[i]==1) printf("at least one\n");

        if(ans[i]==2) printf("any\n");

    }

}