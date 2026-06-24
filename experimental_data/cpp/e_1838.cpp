#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int maxn = 2e5+10,mod = 1e9+7;
int a[maxn];

/*
k^m-

j=0...n-1
(k-1)^(m-j)*C(m,j)
*/


LL ksm(LL a,LL k,LL mod)
{
    LL ans = 1;
    while(k)
    {
        if(k&1) ans = ans * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return ans;
}

LL inv(LL a,LL p)
{
    return ksm(a,p-2,p);
}

int main()
{
    int cs;cin>>cs;
    while(cs--)
    {
        LL n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        LL ans = ksm(k,m,mod),C = 1;
        for(LL j=0;j<n;j++)
        {
            if(j) C = C*(m-j+1)%mod*inv(j,mod)%mod;
            ans -= ksm(k-1,m-j,mod)*C%mod;
            ans %= mod;
        }
        cout<<(ans+mod)%mod<<endl;
    }
    return 0;
}