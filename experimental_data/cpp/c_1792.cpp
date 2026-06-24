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

    ll n;

    cin >> n;

    vl a(n + 1);

    vl ainv(n + 1);

    FOR(i, 1, n + 1){

        cin >> a[i];

        ainv[a[i]] = i;

    }



    ll i = n / 2 + 1, j = (n + 1) / 2;

    while (j < n && ainv[i - 1] < ainv[i] && ainv[j + 1] > ainv[j]){

        i--; j++;

    }

    cout << (n - (j - i + 1)) / 2 << "\n";

}



int main() {

    cin.sync_with_stdio(0);

    cin.tie(0);



    ll tc; cin >> tc;

    while(tc--)

        solve();

}