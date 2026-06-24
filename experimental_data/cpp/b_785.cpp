#include <bits/stdc++.h>
//#include <ext/hash_map>
//using namespace __gnu_cxx;
typedef long long LL;
typedef unsigned long long ULL;
#define RDI(x) scanf("%d",&x)
#define RDI_2(x,y) scanf("%d%d",&x,&y)
#define RDD(x) scanf("%lf",&x)
#define RDD_2(x,y) scanf("%lf%lf",&x,&y)
#define RDL(x) scanf("%I64d",&x)
#define RDL_2(x,y) scanf("%I64d%I64d",&x,&y)
#define RDS(x) scanf("%s",x)
#define RDS_2(x,y) scanf("%s%s",x,y)
#define PUTI(x) printf("%d",x)
#define PUTL(x) printf("%I64d",x)
#define PUTF(x) printf("%f",x)
#define PUTC(x) putchar(x)
#define LINE putchar('\n')
#define SPACE putchar(' ')
#define REP(i,x) for(int i=0;i<int(x);++i)
#define REP_1(i,x) for(int i=1;i<=int(x);++i)
#define FOR_EDGE(i,x) for(int i=head[x];~i;i=edge[i].next)
#define FOR_EDGE2(x,i,y) for(int i=head[x][y];~i;i=edge[i].next)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);++i)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);--i)
#define DWN(i,x) for(int i=int(x-1);i>=0;--i)
#define DWN_1(i,x) for(int i=int(x);i>0;--i)
#define FIL(x,v) memset(x,v,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ALL(x) x.begin(),x.end()
#define p_queue priority_queue
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define x first
#define y second
#define mp(x,y) make_pair(x,y)
#define check(x) printf("%s=%d\n",#x,x)
using namespace std;
template<typename T>
T gcd(T a, T b){ return b == 0 ? a : gcd(b, a%b); }
template<typename T>
T lcm(T a, T b){ return a / gcd(a, b)*b; }
template<typename T>
T ext_gcd(T a, T b, T& x, T& y)
{
    if(b==0){x=1,y=0;return a;}
    T d=ext_gcd(b,a%b,y,x);
    y-=x*(a/b);
    return d;
}
template<typename T>
T inverse(T a, T n)  
{  
    T x,y;  
    T t=ext_gcd(a,n,x,y);
    if(t!=1)return -1;
    return x<0?x+n:x;
}
template<typename T>
T Q_mul(T a,T b,T Mod)
{
    T ret;
    for(ret=0;b;b>>=1,a=(a+a)%Mod)if(b&1)ret=(ret+a)%Mod;
    return ret;
}
template<typename T>
T quick_pow_mod(T a, T b,T Mod)
{
    T ret;
    for(ret=1;b;b>>=1,(a*=a)%=Mod)if(b&1)(ret*=a)%=Mod;
    return ret;
}
template<typename T>
T quick_pow(T a, T b)
{
    T ret;
    for(ret=1;b;b>>=1,a*=a)if(b&1)ret*=a;
    return ret;
}
double combination(int n, int r)
{
    if (r<n - r) return combination(n, n - r);
    double s = 1.0;
    REP_1(i, n - r) s *= (r + i), s /= i;
    return s;
}
template<typename T>
inline void read(T& v)
{
    T ret=0,sgnv=1;
    char p;
    while(!isdigit(p=getchar()))if(p=='-')sgnv=-1;
    do ret=(ret<<3)+(ret<<1)+p-'0';while(isdigit(p=getchar()));
    v=sgnv*ret;
}
//const double eps=1e-8;
//inline int sgn(double x){ return (x>-eps)-(x<eps); }
//const LL mod=1000000007;
//const double INF = 1e9;
//const LL INF = numeric_limits<LL>::max();
//const int INF = 0x7f7f7f7f;
//const int INFCELL = 0x7f;
//const int NINFCELL = 0x80;
//const int NINF = 0x80808080;
#define MAX 100000+5
int main()
{
    //freopen("test.in","r",stdin);
    int n,l,r,L,R,x,y;
    read(n),read(l),read(r);
    REP_1(i,n-1)read(x),read(y),r=min(r,y),l=max(l,x);
    read(n),read(L),read(R);
    REP_1(i,n-1)read(x),read(y),R=min(R,y),L=max(L,x);
    PUTI(max(max(0,L-r),max(0,l-R)));
    return 0;
}