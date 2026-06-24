#include<cstdio>
typedef long long ll;
typedef long double ld;
ll read(){
    ll a=0;int op=1;char ch=getchar();
    while(ch<'0'||'9'<ch){if(ch=='-')op=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){a=(a<<3)+(a<<1)+(48^ch);ch=getchar();}
    return a*op;
}
const int N=1e5+10;
ll a[N];
int n,q;
ll k;
int main(){
    n=read();
    q=read();
    k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int l,r;
    for(int i=0;i<q;i++){
        l=read();
        r=read();
        printf("%lld\n",2*((a[r]-a[l]-1)-(r-l-1))+(a[l]-1)+(k-a[r]));
    }
    return 0;
}