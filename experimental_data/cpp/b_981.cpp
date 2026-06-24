#include <algorithm>
#include <cstdio>
using namespace std;
inline char gc()
{
    static char now[1<<16],*s,*t;
    if(s==t) {t=(s=now)+fread(now,1,1<<16,stdin); if(s==t) return EOF;}
    return *s++;
}
inline int read()
{
    int x=0; char ch=gc();
    while(ch<'0'||'9'<ch) ch=gc();
    while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=gc();
    return x;
}
const int N=2e5+10;
int n,m,a[N],b[N],x[N],y[N];
int n0,map[N];
void discrete()
{
    for(int i=1;i<=n;i++) map[i]=a[i];
    for(int i=1;i<=m;i++) map[n+i]=b[i];
    sort(map+1,map+n+m+1); n0=unique(map+1,map+n+m+1)-map-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(map+1,map+n0+1,a[i])-map;
    for(int i=1;i<=m;i++) b[i]=lower_bound(map+1,map+n0+1,b[i])-map;
}
int res[N];
int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),x[i]=read();
    m=read();
    for(int i=1;i<=m;i++) b[i]=read(),y[i]=read();
    discrete();
    for(int i=1;i<=n;i++) res[a[i]]=x[i];
    for(int i=1;i<=m;i++) res[b[i]]=max(res[b[i]],y[i]);
    long long ans=0;
    for(int i=1;i<=n0;i++) ans+=res[i];
    printf("%lld\n",ans);
    return 0;
}