#include <iostream>

#include <bits/stdc++.h>

#define Kirlos ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

#define ll long long

#define pb(k) push_back(k)

#define fi first

#define se second

#define endl '\n'

#define mp(x,y) make_pair(x,y)

#define MOD 1000000007

#define all(x) x.begin(), x.end()



using namespace std;



void solve()

{

    ll n,m,d;

    cin>>n>>m>>d;

    ll arr[n],sum=0;

    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr,arr+n,greater());

    for(int i=0; i<min(d,n); i++) sum+=arr[i];

    if(sum>=m) cout<<"Infinity"<<endl;

    else

    {

        ll l=0,r=d+10,ans=-1;

        while(l<=r)

        {

            ll mid=(l+r)/2;

            ll cnt=0,sum=0,spare=d,ptr=0;

            while(ptr<=min(n-1,mid))

            {

                sum+=(arr[ptr]*(ceil((double)spare/(mid+1))));

                spare--;

                ptr++;

            }

            if(sum>=m)

            {

                ans=mid;

                l=mid+1;

            }

            else r=mid-1;

        }

        if(ans==-1) cout<<"Impossible"<<endl;

        else cout<<ans<<endl;

    }

}



int main()

{

    Kirlos

    ll t;

    //t=1;

    cin>>t;

    while(t--)

    {

        solve();

    }

    return 0;

}