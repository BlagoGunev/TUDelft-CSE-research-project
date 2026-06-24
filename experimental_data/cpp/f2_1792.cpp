#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=5e4+10,mod = 998244353;

int C[N],f[N];

void solve()

{

    int n;

    scanf("%lld",&n);

   

    f[1]=C[0]=1;

    for(int i=2;i<=n;i++)

    {

        for(int j=i-1;j>=1;j--)C[j]=(C[j-1]+C[j])%mod;

        for(int j=1;j<i-1;j++)

            f[i]+=C[j-1]*f[j]%mod*f[i-j]*2%mod;

        f[i]=(f[i]+C[i-2]*f[i-1])%mod;

    }

    printf("%lld\n",(2*f[n]-2+mod)%mod);

}

signed main()

{

    int T=1;

    while(T--)

    {

        solve();

    }

    return 0;

}