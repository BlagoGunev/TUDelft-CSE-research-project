#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define endl '\n' 



void solve()

{   

    ll n , k ; cin >> n >> k;

    ll ans=0;vector <ll> v;

    for(int i=0;i<n;i++){

        ll x; cin>> x;

        ans+=(x/k);

        v.push_back(x%k);

    }

    sort(v.begin(),v.end());

    ll l=0 ; ll r=n-1;

    while(l<r){

        if(v[l]  + v[r] >=k){

            ans++;l++;r--;

        }

        else{

            l++;

        }

    }

    cout<<ans;

}

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t=1;

    cin>>t;

    while(t--)

    {

        solve();

        cout << endl;

    }

}