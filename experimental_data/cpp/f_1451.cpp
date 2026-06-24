#include <bits/stdc++.h>

#define mem(a,b) memset(a,b,sizeof(a))

#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef __int128 lll;

typedef pair<int,int> Pair;

const int inf=2139062143;

static char buf[1000000],*p1=buf,*p2=buf,obuf[1000000],*p3=obuf;

#define gc() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++

#define getchar gc

inline void qread(){}template<class T1,class ...T2>

inline void qread(T1 &a,T2&... b)

{

    register T1 x=0;register bool f=false;char ch=getchar();

    while(ch<'0') f|=(ch=='-'),ch=getchar();

    while(ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();

    x=(f?-x:x);a=x;qread(b...);

}

template<class T> T qmax(T x,T y){return x>y?x:y;}

template<class T,class ...Arg> T qmax(T x,T y,Arg ...arg){return qmax(x>y?x:y,arg...);}

template<class T> T qmin(T x,T y){return x<y?x:y;}

template<class T,class ...Arg> T qmin(T x,T y,Arg ...arg){return qmin(x<y?x:y,arg...);}

template<class T> T randint(T l,T r){static mt19937 eng(time(0));uniform_int_distribution<T>dis(l,r);return dis(eng);}

const int MAXN=107;

int T,n,m,a[MAXN][MAXN],sum[MAXN*MAXN];

int main()

{

    qread(T);int i,j;

    while(T--)

    {

        mem(sum,0);

        qread(n,m);for(i=0;i<n;i++) for(j=0;j<m;j++) qread(a[i][j]),sum[i+j]^=a[i][j];

        for(i=0;i<=n+m-2;i++) if(sum[i]) goto label;

        printf("Jeel\n");continue;

        label:;printf("Ashish\n");

    }

    return 0;

}