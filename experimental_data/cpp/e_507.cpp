#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<string>

#include<vector>

#include <ctime>

#include<queue>

#include<set>

#include<map>

#include<stack>

#include<iomanip>

#include<cmath>

#include<bitset>

#define mst(ss,b) memset((ss),(b),sizeof(ss))

///#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long ll;

typedef long double lb;

#define INF (1ll<<60)-1

#define Max 1e9

using namespace std;

int n,m;

struct edge{

    int v,next,w,f;

}e[200100];

int head[100100],tot=0,sum=0;

void Add(int u,int v,int w,int f){

    e[tot].v=v;

    e[tot].w=1;

    e[tot].f=f;

    e[tot].next=head[u];

    head[u]=tot++;

}

int dis[100100],num[100100],pre[100100],vis[200100],road[100100],cnt=0;

void print(int x){

    if(x==-1) return ;

    else print(pre[x]);

    road[cnt++]=x;

}

void BFS(int st){

    for(int i=1;i<=n;i++) dis[i]=Max;

    for(int i=1;i<=n;i++) num[i]=Max;

    mst(pre,-1);

    mst(vis,0);

    queue<int> qu;

    qu.push(st);

    dis[st]=0;

    num[st]=0;

    while(!qu.empty()){

        int u=qu.front();

        qu.pop();

        vis[u]=1;

        for(int i=head[u];i!=-1;i=e[i].next){

            int v=e[i].v;

            int w=e[i].w;

            int f=e[i].f;

            if(!vis[v] && dis[v]>dis[u]+w){

                dis[v]=dis[u]+w;

                num[v]=num[u]+f;

                qu.push(v);

                pre[v]=u;

            } else if(!vis[v] && dis[v]==dis[u]+w){

                if(num[v]<num[u]+f) {

                    num[v]=num[u]+f;

                    pre[v]=u;

                }

            }

        }

    }

    //for(int i=1;i<=n;i++) printf("%d\n",dis[i]);

    //for(int i=1;i<=n;i++) printf("%d\n",num[i]);

    printf("%d\n",dis[n]+sum-2*num[n]);

    print(n);

    mst(vis,0);

    ///for(int i=0;i<cnt;i++) cout<<road[i]<<" ";cout<<endl;

    for(int i=0;i<cnt-1;i++){

        int u=road[i];

        int v=road[i+1];

        for(int j=head[u];j!=-1;j=e[j].next){

            if(e[j].v==v) {

                if(e[j].f==0) e[j].f=e[j^1].f=2;

                else e[j].f=e[j^1].f=0;

                break;

            }

        }

    }

    for(int i=0;i<tot;i++){

        if(e[i].f==0) continue;

        printf("%d %d %d\n",e[i^1].v,e[i].v,e[i].f-1);

        i++;

    }

}

int main(){

    mst(head,-1);

    scanf("%d%d",&n,&m);

    sum=0;

    for(int i=1;i<=m;i++){

        int x,y,z;

        scanf("%d%d%d",&x,&y,&z);

        Add(x,y,1,z);

        Add(y,x,1,z);

        sum+=z;

    }

    BFS(1);

    return 0;

}