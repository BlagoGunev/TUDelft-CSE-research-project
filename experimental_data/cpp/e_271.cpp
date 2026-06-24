#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int g=0;
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        g=__gcd(x-1,g);
    }   
    while (g%2==0)
        g/=2;
    long long ans=0;
    for (long long k=1;k*k<=g;k++)
        if (g%k==0)
        {
            for (int i=k;i<m;i*=2)
                ans+=m-i;
            if (k*k!=g)
                for (int i=g/k;i<m;i*=2)
                    ans+=m-i;
        }
    printf("%lld\n",ans);
    return 0;
}