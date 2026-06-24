#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll sum1(ll l,ll r)
{
    l--;
    return r*(r+1)/2-l*(l+1)/2;
}
inline ll sum2(ll l,ll r)
{
    l--;
    return r*(r+1)*(r+r+1)/6-l*(l+1)*(l+l+1)/6;
}
inline ll calc(ll x)
{
    if (!x)return 0;
    ll sum=0;
    for (int i=1,j=1;;i++,j*=10)
    {
        ll l=j,r=j*10-1;if (r>x)r=x;
        sum+=i*((x+1)*(r-l+1)-sum1(l,r));
        if (r==x)break;
    }
    return sum;
}
inline ll calc2(ll x)
{
    if (!x)return 0;
    ll sum=0;
    for (int i=1,j=1;;i++,j*=10)
    {
        ll l=j,r=j*10-1;if (r>x)r=x;
        sum+=i*(r-l+1);
        if (r==x)break;
    }
    return sum;
}
inline void work()
{
    ll x;scanf("%lld",&x);
    ll l=1,r=1e9,s=1;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if (calc(mid)>=x)s=mid,r=mid-1;
        else l=mid+1;
    }
    x-=calc(s-1);
    l=1,r=s;ll t=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (calc2(mid)>=x)t=mid,r=mid-1;
        else l=mid+1;
    }
    x-=calc2(t-1);
    char S[20]={0};
    int Len=0;
    while (t)
    {
        S[++Len]=t%10+'0';
        t/=10;
    }
    printf("%c\n",S[Len-x+1]);
}
int main()
{
    int T;scanf("%d",&T);
    while (T--)work();
    return 0;
}