#include <bits/stdc++.h>

using namespace std;

using ll = long long int;



// a/b = a mod b

// a = bq+r

// r = q = a/b;

// a = q(b+1)

// a is muliple of b+1



void solve(){

    ll x,y;cin>>x>>y;

    ll ans = 0;

    for(ll i=1;i*i<=x;i++){

        ll add = min(y,x/i-1)-i;

        if(add>0)ans += add;

    }

    cout << ans << "\n" ;

}



int main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);

	ll t = 1;

	cin>>t;

	while (t--){

		solve();

	}

	return 0;

}