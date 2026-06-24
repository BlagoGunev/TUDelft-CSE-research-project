#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll arr[110];
int main()
{
    ll w,h;
    sc2(w,h);

    ll ans=w;

    memset(arr,0,sizeof arr);
    for(ll i=1;i<=2;i++)
    {
        ll a,b;
        sc2(a,b);
        arr[b]=a;
    }
    for(ll i=h;i>0;i--)
    {
        ans+=i;
        ans-=arr[i];
        if(ans<0)
            ans=0;
    }
    printf("%lld\n",ans);



    return 0;
}