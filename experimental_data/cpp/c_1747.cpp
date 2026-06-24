#include<bits/stdc++.h>

#define ll long long

#define endl "\n"

using namespace std;

 

 

void solve(){

    ll n;   cin>>n;

    vector<ll>a(n);

    ll mn= INT_MAX;

    for(auto &i : a){

        cin>>i;

        mn= min(i, mn);

    }

    if(a[0]==mn) cout<<"Bob"<<endl;

    else cout<<"Alice"<<endl;

}

 

int32_t main(){

    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;

    cin >> t;

    while(t--) solve();

}