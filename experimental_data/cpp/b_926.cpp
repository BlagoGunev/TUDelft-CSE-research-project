// luogu-judger-enable-o2
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define Rep(i,a,b) for(register int i=(a),i##end=(b);i<=i##end;++i)
#define Repe(i,a,b) for(register int i=(a),i##end=(b);i>=i##end;--i)
#define For(i,a,b) for(i=(a),i<=(b);++i)
#define Forward(i,a,b) for(i=(a),i>=(b);--i)
template<typename T>inline void read(T &x)
{
    T f=1;x=0;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+(c^48);
    x*=f;
}
using namespace std;
void file()
{
#ifndef ONLINE_JUDGE
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
#endif
}
const int MAXN=1e5+7;
static int a[MAXN],n;
inline void init()
{
 read(n);Rep(i,1,n)read(a[i]);
 sort(a+1,a+n+1);
}
static int ans;
inline void solve()
{
 Rep(i,2,n)ans=__gcd(ans,a[i]-a[i-1]);
 printf("%d\n",(a[n]-a[1])/ans-n+1);
}
int main()
{
    file();
    init();
    solve();
    return 0;
}