#include<bits/stdc++.h>

using namespace std;



#define ll long long int



ll modinv(ll x,ll y,ll m)

{

    ll res = 1;

    x = x % m;

    while (y > 0) 

    {

        if (y & 1)

        {

            res = (res * x) % m;

        }

        y = y >> 1;

        x = (x * x) % m;

    }

    return res%m;

}



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll T=1;

    cin>>T;

    ll m = 998244353;

    vector<ll> fact(61,1);

    for(ll i=1;i<=60;i++)

    {

        fact[i] = fact[i-1]*i;

        fact[i] = fact[i]%m;

    }

    while(T--)

    {

        ll n;

        cin>>n;

        vector<ll> ans = {1,0,1};

        vector<ll> temp = ans;

        for(ll i = 4;i<=n;i=i+2)

        {

            ans[0] = ((fact[i-1] * modinv(fact[i/2],m-2,m)%m * modinv(fact[i-1-i/2],m-2,m)%m)%m + temp[1]%m)%m;

            ans[1] = ((fact[i-2] * modinv(fact[i/2],m-2,m)%m * modinv(fact[i-2-i/2],m-2,m)%m)%m + temp[0]%m)%m;

            ans[2] = 1;

            temp = ans;

        }

        cout<<ans[0]%m<<" "<<ans[1]%m<<" "<<ans[2]%m<<endl;

    }

}