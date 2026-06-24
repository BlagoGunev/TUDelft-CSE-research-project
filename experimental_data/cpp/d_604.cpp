#include<stdio.h>

#include<algorithm>

#include<iostream>

#include<string.h>

#include<queue>

#include<stack>

#include<math.h>

#include<map>

#include<vector>

using namespace std;

typedef long long LL;

const int mod = 1e9+7;

LL quick(LL n,LL m);

int main(void)

{

    LL n,m;

    while(scanf("%lld %lld",&n,&m)!=EOF)

    {

        if(m == 0)

        {

            printf("%lld\n",quick(n,n-1));

        }

        else if(m == 1)

        {

            printf("%lld\n",quick(n,n));

        }

        else

        {   LL sum = 1;LL i;

            for( i = 1;i <= n;i++)

            {

                  sum = sum*m%n;

                  if(sum==1)

                    break;

            }

            printf("%lld\n",quick(n,(n-1)/i));

        }

    }

    return 0;

}

LL quick(LL n,LL m)

{

    LL ask = 1;

    n%=mod;

    while(m)

    {

        if(m&1)

            ask = ask*n%mod;

        n = n*n%mod;

        m>>=1;

    }

    return ask;

}