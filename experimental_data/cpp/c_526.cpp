#include <bits/stdc++.h>
#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<cmath>

using namespace std;

typedef long long ll;

ll n,c1,c2,v1,v2;

int main()

{

    while(~scanf("%lld%lld%lld%lld%lld",&n,&c1,&c2,&v1,&v2))

    {

        ll ans=0;

        if(v1<v2)

        {

            swap(v1,v2);

            swap(c1,c2);

        }

        if(v1>=sqrt(n))

        {

            for(int i=0;i<=n/v1;i++)

            {

                ans=max(ans,i*c1+(n-i*v1)/v2*c2);

            }

            printf("%lld\n",ans);

            continue;

        }

        double x=c1*1.0/v1;

        double y=c2*1.0/v2;

        if(x>y)

        {

            swap(v1,v2);

            swap(c1,c2);

        }

        for(int i=0;i<=v2&&i*v1<=n;i++)

        {

            ans=max(ans,i*c1+(n-i*v1)/v2*c2);

        }

        printf("%lld\n",ans);

    }

    return 0;

}