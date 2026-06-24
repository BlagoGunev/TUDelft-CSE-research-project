#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define rep(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef double ld;
const int mod=998244353;
const int K=1000000;int iK;
const int N=33,M=2010,maxn=30;
int f[M][N],g[M][N],h[M][N];int R[M],tot,b[M],cnt;int cur;
int c[N][N],inv[N];int wl[M],wr[M],s[M];int a[M];

int power(int x,int y){
 int ret=1;
 for(;y;y>>=1,x=1ll*x*x%mod){
  if(y&1) ret=1ll*ret*x%mod;
 }
 return ret;
}

void integral(int id){
 int i,j;
 rep(i,1,cur) g[id][i]=1ll*f[id][i-1]*inv[i]%mod;
 g[id][0]=0;
 memset(h[id],0,sizeof(h[id]));
 rep(i,1,cur)  rep(j,0,i) h[id][j]=(h[id][j]+1ll*g[id][i]*c[i][j])%mod;
}

int eval(int a[],int x){
 int ret=0;int i,j;
 for(i=0,j=1;i<=cur;i++,j=1ll*j*x%mod) ret=(ret+1ll*j*a[i])%mod;
 return ret;
}

void work(){
 int l,r,i,j;
 memset(f[tot+1],0,sizeof(f[tot+1]));
 R[tot+1]=R[tot]+K;
 rep(i,1,tot+1) integral(i);
 rep(i,1,tot+1){
  wl[i]=eval(g[i],1ll*R[i-1]*iK%mod);
  wr[i]=eval(g[i],1ll*R[i]*iK%mod);
  s[i]=(wr[i]-wl[i]+mod)%mod;
 }
 rep(i,1,tot+1) (s[i]+=s[i-1])%=mod;
 cnt=0;
 rep(i,1,tot) b[++cnt]=R[i];
 rep(i,1,tot) b[++cnt]=R[i]+K;
 b[++cnt]=K;
 sort(b+1,b+1+cnt);cnt=unique(b+1,b+1+cnt)-b-1;
 l=r=0;
 rep(i,1,cnt){
  while(R[l]<b[i]-K) l++;
  while(R[r]<b[i]) r++;
  memset(f[i],0,sizeof(f[i]));
  f[i][0]=(1ll*s[r-1]-s[l]+wr[l]-wl[r]+mod+mod)%mod;
  rep(j,0,cur) f[i][j]=(f[i][j]+g[r][j])%mod;
  rep(j,0,cur) f[i][j]=(f[i][j]-h[l][j]+mod)%mod;
 }
 tot=cnt;
 rep(i,1,tot) R[i]=b[i];
 if(R[tot]<a[cur]) return;
 while(R[tot]>=a[cur]) tot--;
 R[++tot]=a[cur];
}

void calc(){
 int i;
 rep(i,1,tot) integral(i);
 rep(i,1,tot){
  wl[i]=eval(g[i],1ll*R[i-1]*iK%mod);
  wr[i]=eval(g[i],1ll*R[i]*iK%mod);
  s[i]=(wr[i]-wl[i]+mod)%mod;
 }
 rep(i,1,tot) (s[i]+=s[i-1])%=mod;
 printf("%d\n",s[tot]);
}

void init(){
 int i,j;
 iK=power(K,mod-2);
 inv[1]=1;rep(i,2,maxn) inv[i]=(-1ll*(mod/i)*inv[mod%i]%mod+mod)%mod;
 rep(i,0,maxn) for(c[i][0]=1,j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
 rep(i,0,maxn) rep(j,0,i) c[i][j]=(i-j&1)?mod-c[i][j]:c[i][j];
} 

int main(){
// freopen("a.in","r",stdin);
// freopen("a.out","w",stdout);
 int n,i;ld dx;int j;
 init();
 scanf("%d",&n);
 rep(i,1,n){
  scanf("%lf",&dx);
  a[i]=(int)(dx*(ld)K*10+0.5)/10;
  //cerr<<a[i]<<endl;
 }
 tot=1;f[tot][0]=1;R[tot]=min(K,a[1]);
 rep(cur,2,n) work(); 
 calc();
}