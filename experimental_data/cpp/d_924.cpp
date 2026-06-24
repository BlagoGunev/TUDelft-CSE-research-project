#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define N 100010
inline char gc(){
 static char buf[1<<16],*S,*T;
 if(S==T){T=(S=buf)+fread(buf,1,1<<16,stdin);if(T==S) return EOF;}
 return *S++;
}
inline ll read(){
 ll x=0,f=1;char ch=gc();
 while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}
 while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc();
 return x*f;
}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,W,m,c[N];ll ans=0;
struct frac{
 int a,b;
 frac(int _a,int _b){int g=gcd(_a,_b);a=_a/g;b=_b/g;}
 frac(){}
 friend bool operator<(frac a,frac b){
  return (ll)a.a*b.b<(ll)b.a*a.b;
 }friend bool operator==(frac a,frac b){
  return a.a==b.a&&a.b==b.b;
 }
}aa[N];
struct hhh{
 frac x,y;int pos;
 friend bool operator<(hhh a,hhh b){
  return a.x==b.x?a.pos>b.pos:a.x<b.x;
 }
}a[N];
inline void add(int x,int val){for(;x<=m;x+=x&-x) c[x]+=val;}
inline int ask(int x){int res=0;for(;x;x-=x&-x) res+=c[x];return res;}
int main(){
// freopen("a.in","r",stdin);
 n=read();W=read();
 for(int i=1;i<=n;++i){
  int x=read(),v=read();
  a[i].x=frac(abs(x),abs(v+W));a[i].y=frac(abs(x),abs(v-W));aa[i]=a[i].y;
 }sort(aa+1,aa+n+1);m=unique(aa+1,aa+n+1)-aa-1;
 for(int i=1;i<=n;++i) a[i].pos=lower_bound(aa+1,aa+m+1,a[i].y)-aa;
 sort(a+1,a+n+1);
 for(int i=1;i<=n;++i){
  ans+=ask(m-a[i].pos+1);add(m-a[i].pos+1,1);
 }printf("%I64d\n",ans);
 return 0;
}