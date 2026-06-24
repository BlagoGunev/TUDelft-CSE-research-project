#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ll,int> Pli;
typedef pair<ll,ll> Pll;
typedef vector<int> VI;
typedef vector<PII> VII;
//typedef pair<ll,ll>P;
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define per(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define REP(i,n) for(int i=0;i<n;++i)
#define lowbit(x) x&(-x)
#define Rand (rand()*(1<<16)+rand())
#define id(x) ((x)<=B?(x):m-n/(x)+1)
#define fors(i) for(auto i:e[x]) if(i!=p)
#define ls p<<1
#define rs p<<1|1

const int N=2222222,M=12222222;
      ll MOD=1e9+7;
      int intINF=int(1e9);
      ll llINF=ll(2e18);
      db eps=1e-8;
      int dx[4]={-1,1,0,0};
      int dy[4]={0,0,-1,1};
      long double pi=acos(-1.0L);
      ld s2=sqrt(2.0);

int read()
{
   int v=0,f=1;
   char c=getchar();
   while(c<48||57<c) {if(c=='-') f=-1; c=getchar();}
   while(48<=c&&c<=57) v=(v<<3)+v+v+c-48,c=getchar();
   return v*f;
}

ll readll()
{
   ll v=0,f=1;
   char c=getchar();
   while(c<48||57<c) {if(c=='-') f=-1; c=getchar();}
   while(48<=c&&c<=57) v=(v<<3)+v+v+c-48,c=getchar();
   return v*f;
}

inline char nc()
{
    static char buf[100000],*p1,*p2;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

int rd()
{
    int x=0; char ch=nc();
    while(ch<'0'||ch>'9') ch=nc();
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=nc();
    return x;
}

/*ll pw(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1) res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}

void pr128(__int128 x)
{
	if(x<0) putchar('-'),x=-x;
	if(x<10) return putchar('0'+x),void();
	pr128(x/10),putchar('0'+(x%10));
}*/

//std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void predo()
{
}

struct node
{
    ll x,y;
}a[N];

bool cmp(node a,node b)
{
    return a.x<b.x;
}

ll m,h,k;
int n;

void init()
{
    n=read(),h=readll(),m=readll(),k=readll();
    rep(i,1,n)
    {
        int x=read(),y=read();
        a[i]=(node){y%(m/2),i};
    }
    sort(a+1,a+n+1,cmp);
}

void solve()
{
    rep(i,1,n) a[i+n]=(node){a[i].x+m/2,a[i].y};
    int mn=intINF,l,r;
    int j=1;
    int ans=0;
    rep(i,1,n)
    {
        while(j<=i+n&&a[i].x>a[j].x-k) j++;
        int t=j-i-1;
        if(t<mn)
        {
            mn=t;
            l=i+1,r=j-1;
            ans=(a[i].x+k)%(m/2);
        }
    }
    printf("%d %d\n",mn,ans);
    rep(i,l,r) printf("%d ",a[i].y);
    printf("\n");
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    //int cas=read();
    int cas=1;
    predo();
    while(cas--)
    {
       init();
       solve();
    }
    return 0;
}