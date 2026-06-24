#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>
#include<bitset>
#include<vector>
#include<functional>
#include<deque>
#include<cctype>
#include<climits>
#include<complex>
#include<bits/stdc++.h>
#include<ctime>

using namespace std;

typedef long long LL;
typedef double DB;
typedef pair<int,int> PII;
typedef pair<DB,DB> PDD;
typedef complex<DB> CP;
typedef vector<int> VI;

#define mmst(a,v) memset(a,v,sizeof(a))
#define mmcy(a,b) memcpy(a,b,sizeof(a))
#define fill(a,l,r,v) fill(a+l,a+r+1,v)
#define re(i,a,b)  for(i=(a);i<=(b);i++)
#define red(i,a,b) for(i=(a);i>=(b);i--)
#define rep(i,a,b) for(i=(a);i<(b);i++)
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define two(k) (1<<(k))
#define SZ(x) (int(x.size()))
#define all(x) (x).begin(),(x).end()
#define ire(i,v,x) for(i=0,v=i<SZ(x)?x[i]:0;i<SZ(x);v=x[++i])
#define ls (rt<<1)
#define rs (rt<<1|1)
#define MID ((l+r)>>1)
#define debug(...) fprintf(stderr, __VA_ARGS__)

template<class T>inline T sqr(T x){return x*x;}
template<class T>inline void upmin(T &t,T tmp){if(t>tmp)t=tmp;}
template<class T>inline void upmax(T &t,T tmp){if(t<tmp)t=tmp;}

inline int sgn(DB x){if(fabs(x)<1e-9)return 0;return(x>0)?1:-1;}
const DB Pi=acos(-1.0);

int gint()
  {
  int res=0;bool neg=0;char z;
  for(z=getchar();z!=EOF && z!='-' && !isdigit(z);z=getchar());
  if(z==EOF)return 0;
  if(z=='-'){neg=1;z=getchar();}
  for(;z!=EOF && isdigit(z);res=(res<<3)+(res<<1)+z-'0',z=getchar());
  return (neg)?-res:res;
 }
LL gll()
  {
   LL res=0;bool neg=0;char z;
  for(z=getchar();z!=EOF && z!='-' && !isdigit(z);z=getchar());
  if(z==EOF)return 0;
  if(z=='-'){neg=1;z=getchar();}
  for(;z!=EOF && isdigit(z);res=res*10+z-'0',z=getchar());
  return (neg)?-res:res;
 }

const int maxn=1100000;
const int MOD=1000000007;

int n;
int a[maxn];
int frac[maxn],rev[maxn];

int main(){
  //freopen("input.txt","r",stdin);
  int i,j,mx=0;
  n=gint();
  re(i,1,n)a[i]=gint(),upmax(mx,a[i]);
  sort(a+1,a+n+1);
  frac[0]=1;re(i,1,n)frac[i]=1LL*frac[i-1]*i%MOD;
  rev[n]=n;red(i,n-1,1)rev[i]=1LL*rev[i+1]*i%MOD;
  rev[n+1]=1;
  int ans=0;
  for(i=1;i<=n;i=j+1)
   {
    for(j=i;j+1<=n && a[i]==a[j+1];j++);
    if(a[i]==mx)break;
    (ans+=1LL*frac[n-i]*rev[n-i+2]%MOD*a[i]%MOD*(j-i+1)%MOD)%=MOD;
   }
  cout<<ans<<endl;
  return 0;
}