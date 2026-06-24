#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
int n,a[200010],p[800010];
ll ans=0,dp[200010];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i)
    {
        dp[i]=a[i]+dp[p[a[i]-i+400000]];
        p[a[i]-i+400000]=i;
    }
    for(int i=1;i<=n;++i)
    {
        ans=max(ans,dp[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}