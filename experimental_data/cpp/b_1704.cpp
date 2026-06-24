#include<bits/stdc++.h>

#define ll           long long

#define ull          unsigned long long

#define pb           push_back

#define fastread()   (ios_base:: sync_with_stdio(false),cin.tie(NULL));

#define MOD          1e9+7

#define yes          cout<<"YES\n"

#define no           cout<<"NO\n"

#define vi           vector<int> v

#define vll          vector<ll> v

using namespace std;



void solve()

{

    ll n,m;

    cin>>n>>m;



    vector<ll> v(n);

    for(int i=0;i<n;i++)

    {

        cin>>v[i];

    }



    // ll l=v[0]-m;

    // ll r=v[0]+m;

    // ll count=0;



    // for(int i=1;i<n;i++)

    // {

    //     l=max(l,v[i]-m);

    //     r=min(r,v[i]+m);



    //     if(l>r)

    //     {

    //         count++;

    //     }



    //     l=v[i]-m;

    //     r=v[i]+m;

    // }



    // cout<<count<<'\n';



    ll mini=v[0];

    ll maxi=v[0];

    ll count=0;



    for(int i=1;i<n;i++)

    {

        mini=min(mini,v[i]);

        maxi=max(maxi,v[i]);



        if((maxi-mini)>2*m)

        {

            count++;

            maxi=v[i];

            mini=v[i];

        }

    }



    cout<<count<<'\n';

}

    

int main(){

    fastread();

    

    ll t;

    cin>>t;

    

    while(t--)

    {

    solve();

    }

    return 0;

}