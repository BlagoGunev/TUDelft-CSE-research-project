#include <bits/stdc++.h>
#define pb push_back
#define cmin(a, b) (a > b ? a = b : a)
#define cmax(a, b) (a < b ? a = b : a)
#define lop(i, s, t) for(int i = s;i < (t);++i)
#define rep(i, s, t) for(int i = s;i <= (t);++i)
#define dec(i, s, t) for(int i = s;i >= (t);--i)
using namespace std;

#define Pr(f,...) //printf(f, ##__VA_ARGS__), fflush(stdout)

const int P=1e9+7,I=P-P/2;

int add(int a,int b) { 
 a+=b;
 return (a>=P)?a-P:a;
}

int mul(int a,int b){
 return (int)(1ll*a*b%P);
}

const int N=5e3+5;
int n,c[N],a[N],f[N][N],g[N+N],ans[N+N];
int main(int argc,char *argv[]){
#ifndef ONLINE_JUDGE
    freopen("dat.in","r",stdin); 
    freopen("my.out","w",stdout); 
#endif
    scanf("%d",&n);
    c[1]=1;
    rep(i,1,n-1){
     scanf("%d",a+i);
     c[i+1]=mul(c[i],a[i]);
    }
    dec(i,n,1){
     f[i][0]=1;
     rep(j,1,n-i)f[i][j]=mul(a[i],f[i+1][j-1]);
    }
    rep(i,1,n)rep(j,1,n-i){
     ans[j]=add(ans[j],mul(c[i],f[i][j]));
    }
    rep(i,2,n){
     dec(i,n*2-2,2)g[i]=g[i-1]; 
     g[1]=1;
     rep(j,0,n-i){
      g[j+2]=add(g[j+2],mul(a[i-1]-1,f[i][j]));
     }
     rep(j,1,2*n-2)ans[j]=add(ans[j],mul(c[i],g[j]));
    }
    rep(i,1,n*2-2)ans[i]=mul(ans[i],I);
    rep(i,1,2*n-2)printf("%d ",ans[i]);
    return 0; 
}