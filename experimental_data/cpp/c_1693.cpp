#include <iostream>
#include <limits>
#include <array>
#include <queue>
#include <set>

using namespace std;
typedef long long LL;
const int maxn=200001;
const int inf=numeric_limits<int>::max();
struct edge{
    edge* nxt;
    int to;
    edge(int v,edge* nxt):
        nxt(nxt),to(v){}
};
array <edge* ,maxn > head;
//array <set <int> ,maxn > mp;
array <int ,maxn > indeg,dis;
array <bool ,maxn > vis;

void addEdge(int u,int v)
{
    head[u]=new edge(v,head[u]);
    return;
}
struct node{
    int dis;
    int id;
    node(int a,int b):
        dis(a),id(b){}
    friend bool operator<(const node a,const node b)
    {
        return a.dis > b.dis; 
    }
};
priority_queue <node> q;
void dijkstra(int st)
{
    q.push(node(0,st));
    dis[st]=0;
    while(q.empty()==false){
        node tmp=q.top();
        q.pop();
        int u=tmp.id;
        if(tmp.dis!=dis[u])continue;
        vis[u]=true;
        for(edge* i=head[u];i;i=i->nxt){
            int v=i->to;
            indeg[v]--;
            if(!vis[v] && dis[v]>dis[u]+indeg[v]+1){
                dis[v]=dis[u]+indeg[v]+1;
                q.push(node(dis[v],v));
            }
        }
    }
    return;
}
int main()
{
    //freopen("test.in","r",stdin);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++){
        cin>>x>>y;
        addEdge(y,x);
        indeg[x]++;
    }
    dis.fill(inf);
    dijkstra(n);
    cout<<dis[1]<<endl;
    return 0;
}