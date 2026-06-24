/*

if a vertex is good, then an added edge doesn't go across two subtrees

if w is good and the added edge is {u,v},
then dist(w,u)+dist(u,v)=dist(w,v) OR dist(w,v)+dist(v,u)=dist(w,u)
i.e. w is in the subtree of u or v
i.e. kick out everything that isn't in the subtree of u or v

*/

#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <set>

#define SEG1 262144
#define SEG2 524288

int t1,t2,t3;

int n,q;
std::vector<int> g[200005];
bool vis[200005];

int cnt=0;
int v1[200005];     // left side
int v2[200005];     // right side
std::set<int> child[200005];        // idx of child
std::set<int>::iterator it;
void dfs(int u)
{
    vis[u]=1;
    v1[u]=cnt;
    cnt++;
    for (int v:g[u]) {
        if (vis[v]) continue;
        child[u].insert(cnt);
        dfs(v);
    }
    child[u].insert(cnt);
    v2[u]=cnt-1;
}

std::set<std::pair<int,int> > added;

int seg1[SEG2];     // left side
int seg2[SEG2];     // right side
int segval[SEG2];   // lazy
int segmin[SEG2];   // min value in segment
int segcnt[SEG2];   // number of elements with min value

void seg(int u,int r1,int r2,int v)
{
    //if (u==1) printf("[%d %d] %d\n",r1,r2,v);
    // base case
    if (seg2[u]<r1 || r2<seg1[u]) return;
    if (r1<=seg1[u] && seg2[u]<=r2) {
        segval[u]+=v;
        segmin[u]+=v;
        return;
    }
    // recursive case, guaranteed that u<SEG1
    seg(u*2,r1,r2,v);
    seg(u*2+1,r1,r2,v);
    //printf("%d %d %d\n",u,segmin[u],segcnt[u]);
    if (segmin[u*2]<segmin[u*2+1]) {
        //printf("A ");
        segmin[u]=segmin[u*2]+segval[u];
        segcnt[u]=segcnt[u*2];
    }
    else if (segmin[u*2+1]<segmin[u*2]) {
        //printf("B ");
        segmin[u]=segmin[u*2+1]+segval[u];
        segcnt[u]=segcnt[u*2+1];
    }
    else {
        //printf("C ");
        segmin[u]=segmin[u*2]+segval[u];
        segcnt[u]=segcnt[u*2]+segcnt[u*2+1];
    }
    //printf("%d %d %d\n",u,segmin[u],segcnt[u]);
}

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    scanf("%d%d",&n,&q);
    for (int i=1; i<n; i++) {
        scanf("%d%d",&t1,&t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(1);
    //for (int i=1; i<=n; i++) printf("%d [%d %d]\n",i,v1[i],v2[i]);
    // set up segtrees
    for (int i=0; i<SEG1; i++) {
        seg1[SEG1+i]=seg2[SEG1+i]=i;
        if (i>=n) segmin[SEG1+i]=1;
        segcnt[SEG1+i]=1;
    }
    for (int i=SEG1-1; i; i--) {
        seg1[i]=seg1[i*2];
        seg2[i]=seg2[i*2+1];
        //segval[i]=0;
        segmin[i]=segmin[i*2];
        segcnt[i]=segcnt[i*2];
        if (segmin[i*2]==segmin[i*2+1]) segcnt[i]+=segcnt[i*2+1];
    }
    // do queries
    while (q--) {
        scanf("%d%d",&t1,&t2);
        if (v1[t1]>v1[t2]) std::swap(t1,t2);
        // guaranteed that v1[t1] < v1[t2]
        if (added.count({t1,t2})) {
            added.erase({t1,t2});
            t3=-1;
        }
        else {
            added.insert({t1,t2});
            t3=1;
        }
        if (v1[t2]<=v2[t1]) {
            // t2 is in subtree of t1
            // get child of t1 that contains t2
            it=child[t1].upper_bound(v1[t2]);
            int t5=(*it);
            --it;
            int t4=(*it);       // :(
            seg(1,t4,t5-1,t3);  // :(
            seg(1,v1[t2],v2[t2],-t3);
        }
        else {
            // t1,t2 in separate subtrees
            seg(1,0,n-1,t3);
            seg(1,v1[t1],v2[t1],-t3);
            seg(1,v1[t2],v2[t2],-t3);
        }
        // get answer
        if (segmin[1]==0) printf("%d\n",segcnt[1]);
        else printf("0\n");
    }
}