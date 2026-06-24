#include <bits/stdc++.h>

using namespace std;



#define rep(i,a,n) for (int i=a;i<(int)n;i++)

#define per(i,a,n) for (int i=n;i-->(int)a;)



int read(){int r;scanf("%d",&r);return r;}



const int LOG = 18;

const int D = 21;

const int N = 200000+D;



int n;

vector<int> g[N+10];



int p[LOG][N+10]; // p[pwr][u];

int tin[N+10], tout[N+10];



void build(int v, int f,int &T) {

  tin[v] = T++;

  p[0][v] = f;

  rep(pw, 1, LOG) p[pw][v] = p[pw-1][p[pw-1][v]]; // 倍增

  for (int u: g[v]) if(u!=f) build(u, v, T);

  tout[v] = T; // [tin[v] ...... tout[v]] 都是v的子树

}



bool inside(int l, int v) { return tin[l] <= tin[v] && tout[v] <= tout[l]; }



int lca(int u, int v) {

  if (inside(u, v)) return u;

  if (inside(v, u)) return v;

  per(pw,0,LOG) if (!inside(p[pw][u], v)) u = p[pw][u];

  return p[0][u];

}



struct Fenwick {

  int n;

  vector<int> F;

  void init(int nn) { // 0-index support

    n = nn;

    F.assign(n, 0);

  }



  void add(int pos, int val) {

    for (; pos < n; pos |= pos + 1) F[pos] += val;

  }

  int sum(int pos) {

    int ans = 0;

    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) ans += F[pos];

    return ans;

  }

  int getSum(int l, int r) { return sum(r-1) - sum(l-1); }

};



struct DS {

  Fenwick f;

  void init(int n) { f.init(n); }

  // x in path [v...l)

  //    tin[l]..tin[x]..tin[u]..tout[u]..tout[x]..tout[l]

  // x not in path [v...l)

  //    tin[x]..tin[l]..tin[u]..tout[u]..tout[l]..tout[x]

  //    tin[l]..tin[u]..tin[x]..tout[x]..tout[u]..tout[l]

  //    tin[l]..tin[x]..tout[x]..tin[u]..tout[u]..tout[l]

  //    tin[l]..tin[u]..tout[u]..tin[x]..tout[x]..tout[l]

  void addPath(int v, int l, int k) {

    f.add(tin[v], +k);

    f.add(tin[l], -k);

  }

  int getVertex(int v) { return f.getSum(tin[v], tout[v]); }

};



DS t[D]; // t[distance] => fenwick



int main() {

  n=read();

  rep(i,0,n-1) {

    int u=read()-1;

    int v=read()-1;

    g[u].push_back(v);

    g[v].push_back(u);

  }



  // n+d-1 -> ... -> n+2->n+1->n->n-1, 从n-1 向上构建 d个点, 减少if判断, 统一同样操作

  rep(i,0,D) g[n+i].push_back(n+i-1);

  int root=n+D-1; // 新建的点



  int T=0;

  build(root, root, T);

  rep(i, 0, D) t[i].init(root + 1);



  int m=read();

  while(m--){

    int op=read();

    if (op == 1) {

      int v=read()-1;

      int ans = 0;

      rep(i,0,D){

        ans += t[i].getVertex(v);

        v = p[0][v];

      }

      printf("%d\n",ans);

    } else { // op == 2;

      int u=read()-1;

      int v=read()-1;

      int k=read();

      int d=read();

      int l = lca(u, v);



      if (u != l) t[d].addPath(u, l, k);

      if (v != l) t[d].addPath(v, l, k);



      rep(i,0,d+1){ // l 向上

        t[d-i].addPath(l,p[0][l],k);

        if (d-i-1 >= 0) t[d-i-1].addPath(l,p[0][l],k);

        l=p[0][l];

      }

    }

  }

  return 0;

}