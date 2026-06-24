#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define fst first

#define sec second

void solve(){

        ll n,m;cin >> n >> m;

        

        ll ct=0;

        for(int i=0;i<n;i++){

            int a,b,c,d;

            cin >> a >> b >> c >> d;

            if(b==c) ct++;

        }

        if(m&1) {

            cout << "NO" << endl;

            return;

        }

        if(ct>=1) cout << "YES" << endl;

        else cout << "NO" << endl;



}

int main(){

    ios::sync_with_stdio(0); cin.tie(0);

    ll t;cin >> t;

    while(t--){

        solve();

    }

    return 0;

}