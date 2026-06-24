#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;
template<class _T>inline void read(_T &_a)
{
    bool f=0; char _c=getchar(); _a=0;
    while(_c<'0'||_c>'9'){ if(_c=='-') f=1; _c=getchar(); }
    while(_c>='0'&&_c<='9'){ _a=(_a<<3)+(_a<<1)-'0'+_c; _c=getchar(); }
    if(f) _a=-_a;
}

const int MAXN=200005;
long long T,n,a[MAXN],ans,tmp;

int main()
{
    for(read(T);T;--T)
    {
        read(n);
        ans=0;
        a[n+1]=0;
        for (register int i=1;i<=n;++i) read(a[i]);
        bool flag=(a[1]>0);
        tmp=a[1];
        for (register long long i=2;i<=n+1;++i)
        {
            if(flag)
            {
                if(a[i]>0)
                {
                    tmp=max(tmp,a[i]);
                } else {
                    flag=!flag;
                    ans+=tmp;
                    tmp=a[i];
                }
            } else {
                if(a[i]<0)
                {
                    tmp=max(tmp,a[i]);
                } else {
                    flag=!flag;
                    ans+=tmp;
                    tmp=a[i];
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}