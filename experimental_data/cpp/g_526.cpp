#include <cmath>

#include <ctime>

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cassert>

#include <algorithm>

#include <iostream>

#include <vector>

#include <queue>

#include <map>

#include <set>

#define pb push_back

#define pq priority_queue

#define lowbit(x) ((x)&(-(x)))

#define debug(x) cout<<#x<<" = "<<x<<endl

#define rep(i,a,b) for(int i=a,_b=b;i<_b;++i)

#define per(i,a,b) for(int i=(b)-1,_a=a;i>=_a;--i)

using namespace std;

typedef long long ll;

typedef double db;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;

typedef pair<ll,int> pli;

inline void rd(int&res){

    res=0;char c;

    while(c=getchar(),c<48);

    do res=res*10+(c^48);

    while(c=getchar(),c>47);

}

void print(int x){

    if(!x) return;

    print(x/10);

    putchar(x%10^48);

}

inline void pt(int x){

    if(!x) putchar('0');

    else print(x);

    putchar('\n');

}

const int M=100005;

struct Edge{

    int to,v,nxt;

    Edge(int a=0,int c=0,int b=0):to(a),v(c),nxt(b){}

}edge[M<<1];

int etot;

int head[M];

inline void add_edge(int a,int b,int c){

    edge[etot]=Edge(b,c,head[a]);

    head[a]=etot++;

}

const int S=18;

const int INF=0x7fffffff;

int n,cmp_val[M];

bool cmp(int a,int b){

    return cmp_val[a]>cmp_val[b];

}

struct Solver{

    int rt,cnt;

    int dis[M],dep[M],fa[S][M],val[M],s[M],L[M];//170W

    void rec(int x,int f,int pf){

        cmp_val[x]=val[x]=dis[x]-dis[pf];

        int mx=0;

        for(int i=head[x];~i;i=edge[i].nxt){

            int to=edge[i].to;

            if(to==f) continue;

            if(L[to]==L[x]) rec(to,x,pf);

            else rec(to,x,x);

        }

    }

    void dfs(int x,int f){

        int k=x;

        fa[0][x]=f;

        L[x]=x;

        for(int i=head[x];~i;i=edge[i].nxt){

            int to=edge[i].to;

            if(to==f) continue;

            dis[to]=dis[x]+edge[i].v;

            dfs(to,x);

            if(dis[L[to]]>dis[L[x]]) L[x]=L[to];

        }

        if(L[x]==x) s[++cnt]=x;

    }

    int up(int x,int step){

        rep(i,0,S) if(step&(1<<i)) x=fa[i][x];

        return x;

    }

    int LCA(int a,int b){

        if(dep[a]<dep[b]) swap(a,b);

        a=up(a,dep[a]-dep[b]);

        if(a!=b){

            per(i,0,S) if(fa[i][a]!=fa[i][b]) a=fa[i][a],b=fa[i][b];

            a=fa[0][a];

        }

        return a;

    }

    int id[M],pos[M],sum[M];

    void init(){

        dfs(rt,0);

        rec(rt,0,rt);

        rep(i,1,S) rep(j,1,n+1) fa[i][j]=fa[i-1][fa[i-1][j]];

        sort(s+1,s+cnt+1,cmp);

//      puts("SUM");

//      rep(i,1,n+1) printf("%d ",val[i]);

//      puts("");

        rep(i,1,cnt+1) sum[i]=sum[i-1]+val[s[i]],id[s[i]]=i;

//      puts("");

    }

    int solve(int a,int b){

        if(b>=cnt) return sum[cnt];

        if(b>=id[L[a]]) return sum[b];

        int u=L[a];

        per(i,0,S) if(fa[i][a]&&id[L[fa[i][a]]]>b) a=fa[i][a];

        a=fa[0][a];

        return sum[b]-min(dis[L[a]]-dis[a],val[s[b]])+dis[u]-dis[a];

    }

}A,B;

int mx,id;

void dfs(int x,int f,int len){

    if(len>mx){

        mx=len;

        id=x;

    }

    for(int i=head[x];~i;i=edge[i].nxt){

        int to=edge[i].to;

        if(to==f) continue;

        dfs(to,x,len+edge[i].v);

    }

}

int main(){

    int q;

    scanf("%d%d",&n,&q);

    memset(head,-1,sizeof(head));

    rep(i,1,n){

        int a,b,c;

        rd(a);rd(b);rd(c);

        add_edge(a,b,c);

        add_edge(b,a,c);

    }

    mx=-1;dfs(1,0,0);

    A.rt=id;

    mx=-1;dfs(id,0,0);

    B.rt=id;

    A.init();

    B.init();

    int ans=0;

    rep(i,0,q){

        int a,b;

        rd(a);rd(b);

        a=((a+ans-1)%n)+1;

        b=((b+ans-1)%n)+1;

        b=b*2-1;

        ans=max(A.solve(a,b),B.solve(a,b));

        printf("%d\n",ans);

    }

    return 0;

}