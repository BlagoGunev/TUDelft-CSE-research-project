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



ll match(vl &a, vl&b){

    ll m = 1;

    while (m < sz(a) && a[m] == b[m])

        m++;

    return m - 1;

}



void solve(){

    ll n, m;

    cin >> n >> m;

    vvl perm(n, vl(m + 1)), inv(n, vl(m + 1));

    FOR(i, 0, n) FOR(j, 1, m + 1){

        cin >> perm[i][j];

        inv[i][perm[i][j]] = j;

    }

    sort(all(inv));

    FOR(i, 0, n){

        auto it = lower_bound(all(inv), perm[i]);

        ll ans = 0;

        if(it != inv.end())

            ans = match(*it, perm[i]);



        if(it != inv.begin()){

            it--;

            ans = max(ans, match(*it, perm[i]));

        }



        cout << ans << " ";

    }

    cout << endl;

}



int main() {

    cin.sync_with_stdio(0);

    cin.tie(0);



    ll tc; cin >> tc;

    while(tc--)

        solve();

}