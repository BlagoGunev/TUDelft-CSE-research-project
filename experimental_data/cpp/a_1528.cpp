#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef __int128 ll;
typedef unsigned int uint;
typedef unsigned long long ull;
//typedef double db;
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

#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Flush FastIO::Fflush()

const int N=111111;
const int M=222222;
const int MOD=1e9+7;
const ll llINF=2e18;
const double pi=acos(-1);

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

/*void pr128(__int128 x)
{
    if(x<0) putchar('-'),x=-x;
    if(x<10) return putchar('0'+x),void();
    pr128(x/10),putchar('0'+(x%10));
}*/

ll dp[N][2];
int a[N][2],head[N],vet[M],nxt[M],n,tot;

void predo()
{
}

void add(int a,int b)
{
    nxt[++tot]=head[a];
    vet[tot]=b;
    head[a]=tot;
}

void init()
{
    n=read();
    rep(i,1,n) a[i][0]=read(),a[i][1]=read();
    rep(i,1,n) head[i]=0;
    tot=0;
    rep(i,1,n-1)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
}

void dfs(int u,int fa)
{
    dp[u][0]=dp[u][1]=0;
    int e=head[u];
    while(e)
    {
        int v=vet[e];
        if(v!=fa)
        {
            dfs(v,u);
            dp[u][0]+=max(dp[v][0]+abs(a[u][0]-a[v][0]),dp[v][1]+abs(a[u][0]-a[v][1]));
            dp[u][1]+=max(dp[v][0]+abs(a[u][1]-a[v][0]),dp[v][1]+abs(a[u][1]-a[v][1]));
        }
        e=nxt[e];
    }
}

void solve()
{
    dfs(1,0);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}

int main()
{
   //freopen("1.in","r",stdin);
   //freopen("1.out","w",stdout);
   predo();
   int cas=read();
   //int cas=1;
   while(cas--)
   {
       //printf("Case #%d: ",v);
       init();
       solve();
   }
   return 0;
}