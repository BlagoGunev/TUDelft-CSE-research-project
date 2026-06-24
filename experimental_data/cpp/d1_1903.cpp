#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,q;
ll a[100009],b[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)
     cin>>b[i];
    while(q--)
    {
        for(int i=0;i<n;i++)a[i]=b[i];
        ll k;
        cin>>k;
        ll ans=0;
        for(ll u=60;u>=0;u--)
        {
            ll r=0;
            for(int i=0;i<n;i++)
            {
                if((a[i]&(1ll<<u)))continue;
                r+=(1ll<<u)-a[i];
                if(r>k)r=k+1;
            }


                for(int i=0;i<n;i++)
                    {if((a[i]&(1ll<<u))) {a[i]^=(1LL<<u);continue;}
                      if(r<=k)a[i]=0;}

            if(r<=k)
            {
                ans+=(1LL<<u);
                k-=r;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}