/*****************************************************************

 *                   BISMILLAHIR RAHMANIR RAHIM                  *

 *          Raihat Zaman Neloy                                   *

 *          JU-CSE-21                                            *

 *          raihatneloy                                          *

 *****************************************************************/



#include<bits/stdc++.h>



//#include<algorithm>

//#include<cstdio>

//#include<sstream>

//#include<cstdlib>

//#include<cctype>

//#include<cmath>

//#includ<set>

//#include<queue>

//#include<stack>

//#include<list>

//#include<iostream>

//#include<fstream>

//#include<numeric>

//#include<string>

//#include<vector>

//#include<cstring>

//#include<map>

//#include<iterator>

//#include<deque>

//#include<climits>

//#include<complex>



#define S scanf

#define P printf



#define LL long long int

#define ULL unsigned long long int

#define D double



#define SQR(n)      (n*n)

#define PI          2.0*acos(0.0)



#define all(a) a.begin(),a.end()

#define X  first

#define Y  second

#define MP make_pair

#define NL P("\n")



#define open       freopen("input.txt","r",stdin)

#define close      freopen ("output.txt","w",stdout)

#define S1(a)      scanf("%d",&a)

#define S2(a,b)    scanf("%d%d",&a,&b)

#define S3(a,b,c)  scanf("%d%d%d",&a,&b,&c)

#define SL1(a)     scanf("%lld",&a)

#define SL2(a,b)   scanf("%lld%lld",&a,&b)

#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

#define CHR        getchar()

#define PB(x)      push_back(x)

#define pb         push_back

#define PP         pop_back()

#define PF(x)      push_front(x)

#define PPF(x)     pop_front()

#define PS(x)      push(x)

#define sz()       size()

#define UB         upper_bound

#define LB         lower_bound

#define mxe(a,n)   (*max_element(a,a+n))

#define mne(a,n)   (*min_element(a,a+n))

#define SUM(a,n)   (accumulate(a,a+n,0))

#define countbit(x) __builtin_popcount(x)

#define DBG(n)      P("Done %d\n",n);



// I/O

#define I(X)                       scanf("%d", &(X))

#define II(X, Y)                   scanf("%d%d", &(X), &(Y))

#define III(X, Y, Z)               scanf("%d%d%d", &(X), &(Y), &(Z))

#define DI(X) int (X);             scanf("%d", &X)

#define DII(X, Y) int X, Y;        scanf("%d%d", &X, &Y)

#define DIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)



#define ILL(X)          scanf("%lld", &(X))

#define DILL(X) LL (X); scanf("%lld", &X)



// LOOP

#define repv(i,a) for(int i=0;i<(int)a.size();i++)

#define revv(i,a) for(int i=((int)a.size())-1;i>=0;i--)

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define rev(i,a,b) for(int i=a;i>=b;i--)



#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)



#define MEM(a,val) memset(a,val,sizeof(a));

#define SET(a)     memset(a,-1,sizeof a)

#define CLR(a)     memset(a,0,sizeof a)

#define CMPL       cerr<< "Compilation Process Finished\n";cerr<< "----------------------------\n"



using namespace std;



template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}

template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}

template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}

template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}

template <typename T> T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}

template <typename T> T Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}

template <typename T> T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}

template <typename T> T DIFF(T a,T b) { T d = a-b;if(d<0)return -d;else return d;}

template <typename T> T ABS(T a) {if(a<0)return -a;else return a;}

template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

template <typename T> T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}

template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}

template <typename T> LL isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }



int    Set(int N,int pos){ return N=N | (1<<pos);}

int  Reset(int N,int pos){return N= N & ~(1<<pos);}

bool Check(int N,int pos){return (bool)(N & (1<<pos));}

template< class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i)); }



double DEG(double x) { return (180.0*x)/(PI);}

double RAD(double x) { return (x*(double)PI)/(180.0);}



#define VI  vector< int >

#define VII vector< VI >

#define VLL vector< LL >

#define PII pair< int , int >

#define PLL pair< LL , LL >

#define VPI vector< PII >



///         0123456789

#define MX  1007

#define MOD 1000000007

#define INF (1<<30)-1+(1<<30)

#define eps 1e-9



#define base ((1<<l)-1)

#define lft (idx<<1)

#define rgt (lft|1)

#define mid ((l+r)>>1)



/// Hashing Bases & MOD

///           0123456789

#define Base1 10000019ULL

#define Base2 10000079ULL

#define Base3 10000103ULL

#define MOD1  1000000007ULL

#define MOD2  1000000009ULL

#define MOD3  1000000021ULL

#define LOGX  17



template <class T >

struct Vector{

    T* ar;

    int sz;

    int cap;



    Vector(){

        cap = 1;

        sz = 0;

        ar = (T*)malloc(cap*sizeof(T));

    }



    Vector(int n){

        cap = n;

        sz = n;

        ar = (T*)calloc(cap,sizeof(T));

    }



    void push_back(T x){

        if (sz == cap){

            cap <<= 1;// cap + ((cap+1)>>1);



            ar = (T*)realloc(ar,cap*sizeof(T));

        }



        ar[sz++] = x;

    }



    void clear(){

        sz = 0;

    }



    void sort(int l,int r){

        std::sort(ar+l,ar+r+1);

    }



    T& operator[] (int idx){

        return ar[idx];

    }



    int size(){ return sz; }

};



struct Edge{

    int u,v,w,i;



    Edge(){}

    Edge(int _u,int _v,int _w,int _i){

        u = _u;

        v = _v;

        w = _w;

        i = _i;

    }



    bool operator<(const Edge& p)const{

        return w<p.w;

    }

};



int par[MX],color[MX],nxt[MX],start[MX],siz[MX];

Vector< Edge> e;



void Init(int n){

    for (int i=0;i<=n;i++){

        start[i] = par[i] = i;

        color[i] = 0;

        nxt[i] = -1;

        siz[i] = 1;

    }

}



int main(){

    DIII(n,m,q);

    e = Vector< Edge > (m+2);



    int u,v,w;



    for (int i=1;i<=m;i++){

        u = in<int>();

        v = in<int>();

        w = in<int>();

        e[i] = Edge(u,v,w,i);

    }



    e.sort(1,m);



    while(q--){

        DII(l,r);



        Init(n);

        int res = -1;



        for (int i=m;i;i--){

            if (e[i].i < l || e[i].i > r)   continue;



            int u = par[ e[i].u ], v = par[ e[i].v ], w = e[i].w;



            if (u != v){

                if (siz[u] < siz[v])

                    swap(u,v);



                int f = ( color[e[i].u]==color[e[i].v] );

                int tail;



                for(int j=start[v];j!=-1;j=nxt[j]){

                    color[j] ^= f;

                    par[j] = u;

                    tail = j;

                }

                nxt[tail] = start[u];

                start[u] = start[v];

                siz[u] += siz[v];

            }



            else if (color[ e[i].u ] == color[ e[i].v ]){

                res = max( res,w );

                break;

            }

        }



        P("%d\n",res);

    }

return 0;

}