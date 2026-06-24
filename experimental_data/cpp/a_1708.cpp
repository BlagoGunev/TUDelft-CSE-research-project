#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define fi first

#define se second



const ll mod = 1000000007;

const ll INF = 10000000000;



bool cek(vector<ll> v){

    for(int i = 1; i < v.size(); i++){

        if(v[i] != 0) return false;

    }

    return true;

}



void solve() {

    ll n; cin >> n;

    vector<ll> v(n);

    for(int i = 0; i < n; i++){

        cin >> v[i];

    }

    for(int i = 1; i < n; i++){

        if(v[i] % v[0] != 0){

            cout << "NO\n";

            return;

        }

    }

    cout << "YES\n";

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    ll t; cin >> t;

    while(t--){

        solve();

    }

    // solve();

    return 0;

}