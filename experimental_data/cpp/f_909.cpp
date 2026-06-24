#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define INF 0x3f3f3f3f3f3f3f3fLL

#define MOD 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-8

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



template<typename T> inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}

template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}

template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}

template<typename T> inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}

template<typename T> inline void println(T x) {print(x), putchar('\n');}

template<typename T> inline void printsp(T x) {print(x), putchar(' ');}

template<class T, class T1> inline void print(T x, T1 y) {printsp(x), println(y);}

template<class T, class T1, class T2> inline void print(T x, T1 y, T2 z) {printsp(x), printsp(y), println(z);}



int power(int a, int b, int m, int ans=1) {

 for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;

 return ans;

}



#define NN 100100

int p[NN];

VI v[30];



int main() {

#ifndef ONLINE_JUDGE

 freopen("in.in", "r", stdin);

 freopen("out.out", "w", stdout);

#endif

 

 int n;

 gn(n);

 

 if(n==1) return puts("NO\nNO"), 0;

 

 if(n%2==0){

  puts("YES");

  int nn=n;

  while(nn){

   int m=1;

   while(m*2<=nn) m*=2;

   int k=nn-m+1;

   for(int i=m-k; i<m+k; i++) p[i]=nn--;

  }

  for(int i=1; i<=n; i++) printsp(p[i]);

  puts("");

 }

 else puts("NO");

 

 if(n<=5 || bpt(n)==1) puts("NO");

 else {

  puts("YES");

  p[1]=5, p[5]=1;

  p[2]=3, p[3]=2;

  for(int i=4; i<=n; i++){

   if(i==5) continue;

   v[31-bclz(i)].pb(i);

  }

  for(int i=0; i<30; i++){

   if(v[i].empty()) continue;

   v[i].pb(v[i][0]);

   for(int j=1; j<v[i].size(); j++) p[v[i][j]]=v[i][j-1];

  }

  for(int i=1; i<=n; i++) printsp(p[i]);

  puts("");

 }

 

 return 0;

}