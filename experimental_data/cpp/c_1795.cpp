#include <bits/stdc++.h>



using namespace std;

using ll = long long;

using ld = long double;

using vl = vector<ll>;

using vvl = vector<vl>;

using pll = pair<ll, ll>;

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

#define FOR(i, a, b) for (ll i=(a); i<(b); i++)

#define FORD(i, a, b) for (ll i=ll(b)-1; i>=(a); i--)

#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })



void solve() {

    ll n;

    cin >> n;

    vl a(n), b(n);

    for (ll &x: a)

        cin >> x;

    vl pref(n + 1);

    FOR(i, 0, n) {

        cin >> b[i];

        pref[i + 1] = pref[i] + b[i];

    }

    vl dr(n + 1);

    vl rem(n + 1);

    ll cur_cnt = 0;

    FOR(sort, 0, n) {

        auto it = upper_bound(all(pref), pref[sort] + a[sort]);

        ll last = it - pref.begin() - 1;

        dr[last] += a[sort] + pref[sort] - pref[last];

        rem[last] += 1;



        cur_cnt += 1;

        cur_cnt -= rem[sort];

        dr[sort] += cur_cnt * b[sort];

    }

    FOR(i, 0, n) {

        cout << dr[i] << " ";

    }

    cout << "\n";

}



int main() {

    cin.sync_with_stdio(0);

    cin.tie(0);



    ll tc;

    cin >> tc;

    while (tc--)

        solve();

}