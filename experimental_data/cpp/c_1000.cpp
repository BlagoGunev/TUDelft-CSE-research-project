#include <algorithm>
#include <cstdio>
using std::sort;
typedef long long lint;
inline char gc()
{
    static char now[1<<16],*s,*t;
    if(s==t) {t=(s=now)+fread(now,1,1<<16,stdin); if(s==t) return EOF;}
    return *s++;
}
inline lint read()
{
    lint x=0; char ch=gc();
    while(ch<'0'||'9'<ch) ch=gc();
    while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=gc();
    return x;
}
const int N=2e5+10;
int n;
struct rec{lint x; int f;} a[N<<1];
bool cmpX(rec x,rec y) {return x.x<y.x;}
lint cnt[N];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i*2-1].x=read(),a[i*2-1].f=1;
        a[i*2].x=read()+1,a[i*2].f=-1;
    }
    sort(a+1,a+n+n+1,cmpX);
    for(int i=1,t=0;i<=n+n-1;i++)
    {
        t+=a[i].f;
        cnt[t]+=a[i+1].x-a[i].x;
    }
    for(int i=1;i<=n;i++) printf("%lld ",cnt[i]);
    return 0;
}