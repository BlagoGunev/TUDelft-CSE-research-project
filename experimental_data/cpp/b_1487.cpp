// Author: Kritik09

#include<bits/stdc++.h>

using namespace std;

#ifdef KritikPC

#include "debug.h"

#else

#define deb(...)

#endif



/*



*/

void solve(){

    int n;cin>>n;

    int k;cin>>k;

    k--;

    k+=(n%2)*k/(n/2);

    cout << (k%n)+1 << '\n';

}



int32_t main(){

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int ttc=1;

    cin>>ttc;

    while(ttc--){

        solve();

    }

}