#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 100005
using namespace std;
struct edge{
    int v,w,n;
}e[MAXN*2];
vector<int> vec[MAXN];
int n,m,tu,tv,tw,ki,kx;
int first[MAXN],es;
//---spfa---
int d[MAXN];
bool inq[MAXN];
void spfa(int st,int totn){
    queue<int> q;
    for(int i=0;i<=totn;i++){
        d[i]=(i==st?0:INF);
        inq[i]=0;
    }
    q.push(st);
    while(!q.empty()){
        int u=q.front();q.pop();
         inq[u]=0;
         int dd=d[u];
         while(1){
            int pos=lower_bound(vec[u].begin(),vec[u].end(),dd)-vec[u].begin();
            if(pos==vec[u].size()||vec[u][pos]!=dd)break;
            dd++;
         }
        for(int i=first[u];i!=-1;i=e[i].n){
            int v=e[i].v;
            if(d[v]>dd+e[i].w){
                d[v]=dd+e[i].w;
                if(!inq[v]){
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
void addedge(int u,int v,int w){
    e[es].v=v,e[es].w=w;
    e[es].n=first[u],first[u]=es++;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(first,-1,sizeof first);es=0;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&tu,&tv,&tw);
        addedge(tu,tv,tw);
        addedge(tv,tu,tw);
    }
    for(int i=1;i<=n;i++){
        vec[i].clear();
        scanf("%d",&ki);
        for(int j=1;j<=ki;j++){
            scanf("%d",&tu);
            vec[i].push_back(tu);
        }
    }
    spfa(1,n);

    printf("%d\n",d[n]==INF?-1:d[n]);
    return 0;
}