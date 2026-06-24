#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define MOD 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-9

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))

#define sgn(x) (((x)>eps)-((x)<-eps))

#define PQ priority_queue<pii, vector<pii>, greater<pii> >



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<class T>inline void printsp(T x) {print(x); putchar(' ');}

template<class T>inline void println(T x) {print(x); putchar('\n');}

template<class T, class U>inline void print(T x, U y) {printsp(x); println(y);}

template<class T, class U, class V>inline void print(T x, U y, V z) {printsp(x); printsp(y); println(z);}



int power(int a, int b, int m, int ans=1) {

 for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;

 return ans;

}



#define NN 200200

VI adj[NN];



pii dfs(int u, int d, int pa=-1) {

 pii x=pii(d, u);

 for (int i=0; i<adj[u].size(); i++) if (adj[u][i]!=pa) smax(x, dfs(adj[u][i], d+1, u));

 return x;

}



INT ans;

vector<pii> res;

int vst[NN], pre[NN];



void solve(int u, pii d, int pa=-1) {

 for (int i=0; i<adj[u].size(); i++) {

  int v=adj[u][i];

  if (v==pa || vst[v]) continue;

  res.pb(pii(d.x, v)); ans+=d.y+1;

  solve(v, pii(d.x, d.y+1), u);

 }

}



int main() {

#ifndef ONLINE_JUDGE

 freopen("in.in", "r", stdin);

 freopen("out.out", "w", stdout);

#endif



 int n, u, v;

 gn(n);

 if (n==2) {

  puts("1");

  puts("1 2 2");

  return 0;

 }

 for (int i=1; i<n; i++) {

  gn(u, v);

  if (u>v) swap(u, v);

  adj[u].pb(v);

  adj[v].pb(u);

 }

 pii a=dfs(1, 0);

 pii b=dfs(a.y, 0);

 a=dfs(b.y, 0);

 queue<int> q;

 q.push(a.y); vst[a.y]=1;

 while (!q.empty()) {

  u=q.front(); q.pop();

  for (int i=0; i<adj[u].size(); i++) {

   v=adj[u][i];

   if (vst[v]) continue;

   vst[v]=vst[u]+1; q.push(v);

   pre[v]=u;

  }

 }

 for (int i=b.y; i!=a.y; i=pre[i]) vst[i]=-vst[i]; vst[a.y]=-1;

 for (int i=1; i<=n; i++) vst[i]<0?vst[i]=-vst[i]:vst[i]=0;

 for (int i=b.y; i!=a.y; i=pre[i]) {

  res.pb(pii(a.y, i)); ans+=vst[i]-vst[a.y];

 }

 reverse(res.begin(), res.end());

 for (int i=pre[b.y]; i!=a.y; i=pre[i]) {

  u=vst[b.y]-vst[i]; v=vst[i]-vst[a.y];

  solve(i, u>v?pii(b.y, u):pii(a.y, v));

 }

 println(ans);

 for (int i=res.size(); i--; ) print(res[i].x, res[i].y, res[i].y);



 return 0;

}