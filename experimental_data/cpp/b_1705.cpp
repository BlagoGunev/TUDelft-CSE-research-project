#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define loop(i, l, n) for(ll i = l; i < ll(n); i++)

#define bloop(i, n, l) for(ll i = n; i > ll(l); i--)

#define INF ll(1e18)

#define F first

#define S second

#define pll pair<ll, ll>

typedef long long ll;

typedef __int128_t fbl;



// ----------------- //





int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);



    //------------------//





    ll Misha; cin >> Misha;

    while(Misha--){

        ll n; cin >> n;

        vector<ll> a;

        bool can = false;

        loop(i, 0, n){

            ll x; cin >> x;

            if(i == n - 1) continue;

            if(!can && x) can = true;

            if(can) a.pb(x);

        }

        ll cnt = 0;

        for(auto x: a){

            cnt += (x ? x : 1);

        }

        cout << cnt << '\n';

    }

}