#include <bits/stdc++.h>

using namespace std;



void solve(){

    int n,k,sum=0;

    cin >> n >> k;

    vector<int> a(n),b(n);

    for(auto &it:a) cin >> it;

    for(auto &it:b) cin >> it;

    sort(a.begin(),a.end());

    sort(b.rbegin(),b.rend());

    for(int i=0;i<n;i++){

        if(b[i]>a[i] && i<k) sum += b[i];

        else sum += a[i];

    }

    cout << sum << endl;

}



int main(){

    int t;

    cin >> t;

    while(t--){

        solve();

    }

}