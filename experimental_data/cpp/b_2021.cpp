#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;cin>>tt;
    while(tt--)
    {
        ll n,x;cin>>n>>x;
        ll a[n];
        map<ll,ll> m;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;
        }
        ll ans=0;
        for(ll i=0;i<=n;i++)
        {
            if(m.find(i)==m.end())
            {
                ans=i;
                break;
            }
            else if(m[i]>1)
            {
                m[x+i]+=m[i]-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}