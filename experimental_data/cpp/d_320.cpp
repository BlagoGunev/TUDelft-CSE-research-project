#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;
const double pi = M_PI, eps = 1e-12;
#define gc(c) c = getchar()
#define gs(c) ((c < '0' || c > '9') && c != '-')
#define gf(c) if(c == '-') f = -f, c = getchar()
#define getint(A) ({ A w = 0, f = 1; char gc(c); while(gs(c)) gc(c); gf(c); while(!gs(c)) w = w*10+c-'0', gc(c); w*f; })
#define read(x) x = getint(int)
#define read64(x) x = getint(int64)
#define REP(i, l ,r) for(int i = l; i <= r; i ++)
#define DEP(i, r, l) for(int i = r; i >= l; i --)
#define foredge(d) for(int j = la[d], k; k = to[j], j; j = nx[j])
#define zabs(x) ( (x > 0)? x: -(x) )

//    ===================================================
//    ||    Delayyy's Little Mods    =u=   Ver 6.23    ||
//    ===================================================

const int Sn = 100010;
#define del(d) die[d] = 1, rr[ll[d]] = rr[d], ll[rr[d]] = ll[d]

int n, a[Sn], b[Sn], die[Sn];
int ll[Sn], rr[Sn];
int S[Sn], p, Ans;
int T[Sn], q;
int K[Sn], o;

int main()
{
//     freopen("oj.in" , "r", stdin);
//     freopen("oj.out", "w", stdout);
     read(n);
     REP(i, 1, n) read(a[i]);
     REP(i, 1, n) ll[i] = i-1, rr[i] = i+1;
     REP(i, 1, n-1) if(a[i] > a[i+1]) S[++p] = i;
     a[n+1] = (int) 1e9;

     p = n;
     REP(i, 1, p) S[i] = i;

     for( ; ; ) {
	  q = o = 0;
	  REP(i, 1, p)
	       if(a[S[i]] > a[rr[S[i]]]) T[++q] = S[i], K[++o] = rr[S[i]];
	  if(!q) break; else Ans ++;
	  
	  DEP(i, o, 1) del(K[i]);
	  p = 0;
	  REP(i, 1, q) if(!die[T[i]]) S[++p] = T[i];
     }
     
     printf("%d\n", Ans);
     return 0;
}