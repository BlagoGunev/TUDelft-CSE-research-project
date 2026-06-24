#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> pii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pii> vpii;
typedef long long int ll;
typedef unsigned long long int ull;

#define mi 1000000007
#define rep(i,a,b) for(i=a;i<b;i++)
#define repv(i,a,b) for(i=b-1;i>=a;i--)
#define pr(arr,n) rep(i,0,n) cout<<arr[i]<<" "; cout<<endl;
#define pr1(arr,n) rep(i,1,n+1) cout<<arr[i]<<" "; cout<<endl;
#define inf INT_MAX
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define SET(a,b) memset(a,b,sizeof(a))
#define MAX 500005
#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

int mult(int x,int y)
{
  ll ans,x1=(ll)x,y1=(ll)y;
  ans=(x1*y1)%mi;
  return (int)ans;
}
int gcd(int a,int b) { return b==0 ? a : gcd (b,a%b);}
int lcm(int a,int b) { return a*(b/gcd(a,b));}

ll pow1(ll a,ll b)
{
  ll ans=1;
  while(b>0)
    {
      if(b&1) ans=(ans*a)%mi;	
      a=(a*a)%mi; b>>=1;
    }	
  return ans;
}
int mina(int arr[],int n)
{
  int x=arr[0],i,pos=0;
  rep(i,1,n){ if(arr[i]<x) { x=arr[i]; pos=i; } }
  return x;
}
int maxa(int arr[],int n)
{
  int x=arr[0],i,pos=0;
  rep(i,1,n){ if(arr[i]>x) { x=arr[i]; pos=i; } }
  return x;
}
ll ans=0,f[20],n,k,S,a[26];
map<ll,ll> cnt[26];
void dfs1(int ind,int m,ll s)
{
  if(m>k || s>S)
    return;
  if(ind==n/2)
    {
      cnt[m][s]++;
      return;
    }
  dfs1(ind+1,m,s);
  dfs1(ind+1,m,s+a[ind]);
  if(a[ind]<19)
    dfs1(ind+1,m+1,s+f[a[ind]]);
}
void dfs2(int ind,int m,ll s)
{
  if(m>k || s>S)
    return;
  if(ind==n)
    {
      int i;
      for(i=0;i+m<=k;i++)
	if(cnt[i].count(S-s))
	  ans+=cnt[i][S-s];
      return;
    }
  dfs2(ind+1,m,s);
  dfs2(ind+1,m,s+a[ind]);
  if(a[ind]<19)
    dfs2(ind+1,m+1,s+f[a[ind]]);
}
int main()
{
  ll i,j;
  sll(n); sll(k); sll(S);
  f[0]=1;
  rep(i,1,19)
    f[i]=f[i-1]*i;
  rep(i,0,n)
    sll(a[i]);
  sort(a,a+n);
  dfs1(0,0,0);
  dfs2(n/2,0,0);
  lldout(ans);
  return 0;
}