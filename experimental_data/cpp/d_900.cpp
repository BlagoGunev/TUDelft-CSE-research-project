#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
typedef long long LL;

template <class T> inline T bigmod(T p,T e,T M)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

LL x,y,ans;
vector<LL> v;

void call(int pos,LL num,LL taken)
{
    if(pos==v.size())
    {
        if(num==1)return;
        if(taken%2)ans-=bigmod(2LL,(y/num)-1,MOD);
        else ans+=bigmod(2LL,(y/num)-1,MOD);
        while(ans<0)ans+=MOD;
        ans%=MOD;
        return;
    }
    call(pos+1,num,taken);
    call(pos+1,num*v[pos],taken+1);
}

int main()
{
    cin>>x>>y;
    if(y%x)
    {
        cout<<0<<"\n";
        return 0;
    }
    y/=x;
    if(y==1)
    {
        cout<<1<<"\n";
        return 0;
    }
    LL n=y;
    for(int i=2;i<=sqrt(y);i++)
    {
        if(n%i)continue;
        v.push_back(i);
        while(n%i==0)n/=i;
    }
    if(n!=1)v.push_back(n);
    ans=bigmod(2LL,y-1,MOD);
    call(0,1,0);
    printf("%lld\n",ans);
    return 0;
}