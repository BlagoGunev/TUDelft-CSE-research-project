#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<cmath>
using namespace std;
#define in() freopen(".in","r",stdin)
#define out() freopen(".out","w",stdout)
#define I inline
#define R register
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define lb(x) (x&-x)
#define EL putchar(10)
#define SP putchar(32)
#define m(a) memset(a,0,sizeof(a))
#define gc() getchar()
typedef long long ll;
const int inf=2147483647;
const int ine=-2147483647;
//char ss[1<<17],*A=ss,*B=ss;I char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;}
template <typename _Tp> I void _(_Tp &x);
template <typename _Tq> I void wr(_Tq x);
I int mx(int a,int b){return a>b?a:b;}I int mn(int a,int b){return a<b?a:b;}
ll n,a[200010];
int main(){
    //in();out();
    _(n);
    R ll b;
    _(b);
    a[1]=0,a[n]=b;
    for(R int i=2;i<<1<=n;++i){
        R ll b;
        _(b);
        a[i]=a[i-1];
        R ll t=b-a[i];
        if(t>a[n-i+2])
            a[i]+=t-a[n-i+2],a[n-i+1]=a[n-i+2];
        else
            a[n-i+1]=t;
    }
    for(R int i=1;i<=n;++i) wr(a[i]),SP;
    return 0;
}
template <typename _Tp>
    I void _(_Tp &x){
        _Tp w=1;char c=0;x=0;
        while (c^45&&(c<48||c>57)) c=gc();
        if (c==45) w=-1, c=gc();
        while(c>=48&&c<=57) x=(x<<1)+(x<<3)+(c^48),c=gc();
        x*=w;
    }
template <typename _Tq>
    I void wr(_Tq x){
        if(x<0)
            putchar(45),x=-x;
        if(x<10){
            putchar(x+48);
            return;
        }
        wr(x/10);
        putchar(x%10+48);
    }