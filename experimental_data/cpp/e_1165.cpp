#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
ll a[200005];
ll b[200005];
int main()
{
    string s,s1;
    ll maxi;
    ll mini,t,i,k,m,sum;
    ll n;
    bool flag;
    while( scanf("%lld",&n)!=EOF)
    {
     for(i=1;i<=n;i++)
     {
         scanf("%lld",&a[i]);
         a[i]*=(i)*(n-i+1);
     }
     for(i=1;i<=n;i++)
        scanf("%lld",&b[i]);
     sort(a+1,a+n+1,greater<ll>());
     sort(b+1,b+1+n,less<ll>());
     sum=0;
     for(i=1;i<=n;i++)
     {
         sum=(sum+((a[i]%998244353)*(b[i]%998244353))%998244353)%998244353;
     }
     printf("%lld\n",sum);
    }
    return 0;
}