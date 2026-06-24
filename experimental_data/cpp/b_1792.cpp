#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using ld = long double;

using vl = vector<ll>;

using vvl = vector<vl>;

using pll = pair<ll,ll>;

using vpll = vector<pll>;

using vb = vector<bool>;

using vs = vector<string>; //

const ll oo = 0x3f3f3f3f3f3f3f3fLL;

const ld eps = 1e-9;

#define sz(c) ll((c).size())

#define all(c) begin(c),end(c)

#define mp make_pair

#define pb push_back

#define eb emplace_back

#define xx first

#define yy second

#define FOR(i,a,b) for (ll i=(a); i<(b); i++)

#define FORD(i,a,b) for (ll i=ll(b)-1; i>=(a); i--)

#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })



void solve(){

    vl a(4);

    ll n = 0;

    for(ll &x : a){

        cin >> x;

        n += x;

    }





    ll m = a[0];



    ll ans = m;

    if(m == 0){

        cout << 1 << "\n";

        return;

    }



    if(a[1] <= a[2]){

        ans += 2 * a[1];

        a[2] -= a[1];

    }else{

        ans += 2 * a[2];

        a[2] = a[1] - a[2];

    }

    ans += min(a[2], m);

    m -= min(a[2], m);



    ans += min(m, a[3]);



    if(ans == n)

        cout << n << "\n";

    else

        cout << ans + 1 << "\n";

}



int main() {

    cin.sync_with_stdio(0);

    cin.tie(0);



    ll tc; cin >> tc;

    while(tc--)

        solve();

}