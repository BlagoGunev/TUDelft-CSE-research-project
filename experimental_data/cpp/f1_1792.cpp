#include<iostream>

#include<algorithm>

#include<cstdio>

#include<cmath>

#include<cstring>

#include<map>

#include<stack>

#include<queue>

#include<ctime>

#include<vector>

#include<set>

using namespace std;

const int mod=998244353;

int f[5000+5],g[5000+5],c[5000+5][5000+5];

int main()

{

    int n,i,j;

    scanf("%d",&n);

    for (i=0;i<=n;i++)

        c[i][0]=1;

    for (i=1;i<=n;i++)

        for (j=1;j<=i;j++)

            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;

    f[1]=1;g[1]=1;

    for(i=2;i<=n;i++)

    {

        for(j=1;j<i;j++)

            f[i]=(f[i]+1ll*g[i-j]*c[i-1][j-1]%mod*f[j])%mod;

        g[i]=f[i]*2%mod;

    }

    printf("%d\n",(g[n]+mod-2)%mod);

    return 0;

}