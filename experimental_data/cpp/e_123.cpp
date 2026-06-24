#include<cstdio>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<iostream>
#include<iomanip>

#define SC(a) scanf("%d", &a)
#define SCC(a) scanf("%c", &a)
#define SC2(a, b) scanf("%d%d", &a, &b)
#define SC3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define PR(a) printf("%d\n", a)
#define FORE(a, b, c) for(int c=a; c<=(int) b; ++c)
#define FORD(a, b, c) for(int c=a; c>=(int) b; --c)
#define FORIT(cont_t, cont, it) for(cont_t::iterator it = cont.begin(); it != cont.end(); ++it) 

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define itr iterator

#define dbg if(0) 
#define prd dbg printf
#define koniec dbg {SCC(c);SCC(c);} return 0;

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef vector<vi> vivi;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;

const int nmax = 100003;
const ll inf = (ll) 1e10;

char c;
int n, x, y;
ll asum, bsum;
ld rev, atre[nmax], bdown[nmax], bup[nmax], ad[nmax], bd[nmax], out;
int a[nmax], b[nmax], vis[nmax], par[nmax];
vi ed[nmax];

void dfs(int v) {
  if(vis[v])
    return;
  vis[v] = 1;
  atre[v] = ad[v];
  FORIT(vi, ed[v], it)
    if(!vis[*it]) {
      dfs(*it);
      atre[v] += atre[*it];
    }
  dbg cout << "dfs " << v << " : " << atre[v] << endl;
}

void dfs2(int v) {
  if(vis[v])
    return;
  vis[v] = 1;
  bdown[v] = (ld) bd[v] * (atre[v] - ad[v]);
  FORIT(vi, ed[v], it)
    if(!vis[*it]) {
      dfs2(*it);
      bdown[v] += bdown[*it];
    }
}

void dfs3(int v, ld up) {
  if(vis[v])
    return;
  vis[v] = 1;
  bup[v] = up + bdown[v];
  vi sons;
  FORIT(vi, ed[v], it)
    if(!vis[*it])
      sons.pb(*it);
    else
      par[v] = *it;
      
  /*FORIT(vi, sons, it)
    bup[v] += bdown[*it];*/
  FORIT(vi, sons, it)
    dfs3(*it, bup[v] - bdown[*it] - bd[v] * atre[*it] + bd[*it] * (1 - atre[*it]));
}

int main() {
  SC(n);
  FORE(1, n-1, i) {
    SC2(x, y);
    ed[x].pb(y);
    ed[y].pb(x);
  }
  FORE(1, n, i) {
    SC2(a[i], b[i]);
    asum += a[i];
    bsum += b[i];
  }
  FORE(1, n, i) {
    ad[i] = (ld) a[i] / asum;
    bd[i] = (ld) b[i] / bsum;
    rev += ad[i] * bd[i];
  }
  dfs(1);
  FORE(1, n, i)
    vis[i] = 0;
  dfs2(1);
  FORE(1, n, i)
    vis[i] = 0;
  dfs3(1, 0);
  
  out = (n-1) * (1 - rev);
  FORE(1, n, i)
    dbg cout << i << ": " << atre[i] << " " << bdown[i] << " " << bup[i] << endl;
  FORE(2, n, i)
    //out -= bdown[i];
    out -= bup[par[i]] - bd[par[i]] * atre[i];
  cout << setprecision(15) << out;
  koniec
}