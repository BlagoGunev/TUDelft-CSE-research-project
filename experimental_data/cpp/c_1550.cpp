#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
using namespace std;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
const int N=2e5+5;
int n,a[N];
bool check(int a,int b,int c){
    if(a<=b&&b<=c)return 0;
    if(a>=b&&b>=c)return 0;
    return 1;
}
bool check4(int a,int b,int c,int d){
    if(!check(a,b,c)||!check(b,c,d)||!check(a,c,d)||!check(a,b,d))return 0;
    return 1;
}
inline void solve(){
    n=read();
    rep(i,1,n)a[i]=read();
    ll ans=2*n-1;
    rep(i,1,n-2){
        if(check(a[i],a[i+1],a[i+2]))ans++;
    }
    rep(i,1,n-3){
        if(check4(a[i],a[i+1],a[i+2],a[i+3]))ans++;
    }
    printf("%lld\n",ans);
}
int main(){
    int T=read();
    while(T--)solve();
    return 0;
}