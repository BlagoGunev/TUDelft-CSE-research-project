#include <bits/stdc++.h>
#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <cstring>

#define ll long long

using namespace std;

ll a,b,w,x,c;

int main()

{

    while (scanf("%lld%lld%lld%lld%lld",&a,&b,&w,&x,&c)!=EOF)

    {

        ll ans=0;

        if (c>a)

        ans=ceil(((c-a)*x-b)*1.0/(1.0*(w-x)))+c-a;

        printf("%lld\n",ans);

    }

    return 0;

}