#include <bits/stdc++.h>

using namespace std;
long long a[505];
vector<int> V1[505];
vector<int> V2[505];
vector<int> G1[505];
vector<int> G2[505];
void dfs1(int n,int p=-1){

    if(p!=-1)
        G1[p].push_back(n);
    for(int i=0;i<V1[n].size();++i){
        if(V1[n][i]==p) continue;
        dfs1(V1[n][i],n);
    }

}
void dfs2(int n,int p=-1){
    if(p!=-1)
        G2[n].push_back(p);
    for(int i=0;i<V2[n].size();++i){
            if(V2[n][i]==p) continue;
        dfs2(V2[n][i],n);
    }
}
const int MAX=4000;
int k1[505];
int k2[505];
bool done[MAX];
int used[MAX];
typedef long long Tc;
typedef long long Tf;

struct Edge {
   int from, to, next;
   Tf cap, flow;
   Tc cost;
   Edge(int from, int to, int next, Tf cap, Tc cost) {
      this->from = from;
      this->to = to;
      this->next = next;
      this->cap = cap;
      this->cost = cost;
      this->flow = 0;
   }
};

struct MinCostFlow {
   typedef pair <Tc, int> Pti;
   Tf infF=(numeric_limits<Tf>::max() / 4);
   Tc infC=(numeric_limits<Tc>::max() / 4);
   int n;
   int S, T, ne[MAX];
   Tc d[MAX], pi[MAX];
   vector < Edge > E;

   void init(int _n) {
      n=_n;
      memset(ne, -1, n * sizeof(int));
      fill(pi, pi+n, 0);
      E.clear();
   }
   void addEdge(int u, int v, Tf cap = 1, Tc cost = 0) {
      E.push_back(Edge(u, v, ne[u], cap, cost));
      ne[u] = (int)E.size()-1;
      E.push_back(Edge(v, u, ne[v], 0, -cost));
      ne[v] = (int)E.size()-1;
   }

   // djkstra
   bool djkstra() {
      memset(used, -1, n*sizeof(int));
      memset(done, 0, n*sizeof(bool));
      fill(d, d+n, infC);
      priority_queue < Pti, vector <Pti>, greater <Pti> > q;
      q.push(make_pair(0, S));
      d[S] = 0;

      while(!q.empty()) {
         int u = q.top().second, v;
         q.pop();
         if(done[u]) continue;
         done[u] = true;

         for(int i = ne[u]; i != -1; i = E[i].next) {
            v = E[i].to;
            Tc pot = d[u] + pi[u] - pi[v];
            if(E[i].cap > E[i].flow && pot + E[i].cost < d[v]) {
               d[v] = pot + E[i].cost;
               used[v] = i;
               q.push(make_pair(d[v], v));
            }
         }
      }
      for(int i = 0; i < n; i++) pi[i] = min(pi[i] + d[i], infC);

      return d[T] != infC;
   }

    // belmanford
    bool belmanford() {
      memset(used, -1, n*sizeof(int));
      memset(done, 0, n*sizeof(bool));
      fill(d, d+n, infC);
      queue<int> q;
      q.push(S);
      d[S] = 0;

      while(!q.empty()) {
         int u = q.front(), v;
         q.pop();
         done[u] = 0;

         for(int i = ne[u]; i != -1; i = E[i].next) {
            v = E[i].to;
            Tc pot = d[u] + pi[u] - pi[v];
            if(E[i].cap > E[i].flow && pot + E[i].cost < d[v]) {
               d[v] = pot + E[i].cost;
               used[v] = i;
               if(done[v]==0)
               {
                   q.push(v);
                   done[v]=1;
               }
            }
         }
      }
      for(int i = 0; i < n; i++) pi[i] = min(pi[i] + d[i], infC);

      return d[T] != infC;
   }


   pair <Tf, Tc> maxFlow(int src, int snk) {
      S = src, T = snk;
      Tf flow = 0;
      Tc cost = 0;

      while(belmanford()) {
         // get blocking flow
         snk = T;
         Tf bflow = infF;
         while(snk != S) {
            bflow = min(bflow, E[ used[snk] ].cap - E[ used[snk] ].flow);
            snk = E[ used[snk] ].from;
         }
         // augment path
         snk = T;
         while(snk != S) {
            E[ used[snk] ].flow += bflow;
            E[ used[snk] ^ 1 ].flow -= bflow;
            cost += E[ used[snk] ].cost * bflow;
            snk = E[ used[snk] ].from;
         }
         flow += bflow;
      }
      return make_pair(flow, cost);
   }
};
long long ma=100000000000;
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=1;i<n;++i){
        int a,b;scanf("%d %d",&a,&b);
        V1[a].push_back(b);
        V1[b].push_back(a);

    }
    for(int i=1;i<n;++i){
        int a,b;scanf("%d %d",&a,&b);
        V2[a].push_back(b);
        V2[b].push_back(a);
    }
    dfs1(x);dfs2(y);

    int q1;cin >> q1;
    for(int i=1;i<=q1;++i){
        int k,x;scanf("%d %d",&k,&x);
        k1[k]=x;
    }
    int q2;cin >> q2;
    for(int i=1;i<=q2;++i){
        int k,x;scanf("%d %d",&k,&x);
        k2[k]=x;
    }
    MinCostFlow mcmf;
    mcmf.init(4*n+5);
    mcmf.addEdge(0,2*x-1,n,0);
    mcmf.addEdge(2*n+2*y,4*n+1,n,0);
    long long sum=0;
    for(int i=1;i<=n;++i){
        if(k1[i]){

            mcmf.addEdge(2*i-1,2*i,k1[i],-ma);
            sum+=k1[i];
        }
        else{
            mcmf.addEdge(2*i-1,2*i,n,0);
        }
        if(k2[i]){

            mcmf.addEdge(2*n+2*i-1,2*n+2*i,k2[i],-ma);
            sum+=k2[i];
        }
        else{
            mcmf.addEdge(2*n+2*i-1,2*n+2*i,n,0);
        }
        mcmf.addEdge(2*i,2*n+2*i-1,1,-a[i]);
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<G1[i].size();++j){
            mcmf.addEdge(2*i,2*G1[i][j]-1,n,0);
        }
    }
     for(int i=1;i<=n;++i){
        for(int j=0;j<G2[i].size();++j){
            mcmf.addEdge(2*i+2*n,2*n+2*G2[i][j]-1,n,0);
        }
    }
    auto ans=mcmf.maxFlow(0,4*n+1);
   // cout << ans.first << " " << ans.second+ma*sum <<  endl;
    //for(long long int j=0;j<=sum;++j) cout << j << " " << ans.second+j*ma << endl;
    ans.second+=ma*sum;
    if(ans.second>0 || ans.first!=k1[x] || ans.first!=k2[y]){
        cout << "-1" << endl;
    }
    else{
        cout << -ans.second << endl;
    }





    return 0;
}