#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define CH (ch=getchar())
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,V)     for(__typeof(*V.begin()) i:  V)
#define For(i,a,b)   for(int i=(int)a;i<=(int)b;i++)
#define Rep(i,a,b)   for(int i=(int)a;i< (int)b;i++)
#define Forn(i,a,b)  for(int i=(int)a;i>=(int)b;i--)
#define pend(x)      ((x)=='\n'||(x)=='\r'||(x)=='\t'||(x)==' ')
using namespace std;
typedef double  db;
typedef long long ll;
const int N=200005;
const int mo=1000000007;
const int inf=(int)1e9;
const ll Inf=(ll)1e10;

inline int IN(){
 char ch;CH; int f=0,x=0;
 for(;pend(ch);CH); if(ch=='-')f=1,CH;
 for(;!pend(ch);CH) x=x*10+ch-'0';
 return (f)?(-x):(x);
}

int Pow(int x,int y,int p){
 int A=1;
 for(;y;y>>=1,x=(ll)x*x%p) if(y&1) A=(ll)A*x%p;
 return A;
}

int n,k,x;
ll a[N],pre[N],suf[N];

int main(){
 cin>>n>>k>>x;
 ll gtw=1;
 For(i,1,k) gtw*=x;
 For(i,1,n) a[i]=IN();
 For(i,1,n) pre[i]=pre[i-1]|a[i];
 Forn(i,n,1) suf[i]=suf[i+1]|a[i];
 ll ans=0;
 For(i,1,n){
  ll now=pre[i-1]|suf[i+1]|(a[i]*gtw);
  ans=max(ans,now);
 }
 cout<<ans<<endl;
 return 0;
}