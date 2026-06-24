#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define fi first

#define se second

 

const ll mod = 1000000007;

const ll INF = 10000000000;

// ll a[200005];

void solve() {

    ll n,x,a,b,mx; cin >> n >> x;

    queue<pair<ll,ll>> q;

    string str;

    map<ll,ll> m;

    q.push({x,0});

    while(!q.empty()){

        a = q.front().fi;

        b = q.front().se;

        q.pop();

        str = to_string(a);

        if(str.size() == n){

            cout << b << "\n";

            return;

        } 

        mx = -1;

        ll p=0;

        for(int i = 0; i < str.size(); i++){

            if(str[i] - '0' != 0 && !m[a*(str[i] - '0')]){

                m[a*(str[i] - '0')] = 1; 

                q.push({a*(str[i] - '0'), b+1});

            }

        }

    }

    cout << "-1\n";

}

 

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    // ll t; cin >> t;

    // while(t--){

    //     solve();

    // }

    solve();

    return 0;

}