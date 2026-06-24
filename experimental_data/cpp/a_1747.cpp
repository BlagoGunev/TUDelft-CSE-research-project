#include <bits/stdc++.h>



using namespace std;



const char nl = '\n';



typedef long long ll;



const int MOD = 1e9 + 7;



int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;

    while(tt--){

    ll n; cin >> n;

    ll ans = 0;

    for(int i = 0; i < n; i++){

        ll x; cin >> x;

        ans += x;

    }

    cout << abs(ans) << nl;

    }

}