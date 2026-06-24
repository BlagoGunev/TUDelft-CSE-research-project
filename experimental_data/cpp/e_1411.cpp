#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

typedef vector<long long> vll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<double, double> pdd;

const double PI = acos(-1);

const ll mod7 = 1e9 + 7;

const ll mod9 = 998244353;

const ll INF = 2 * 1024 * 1024 * 1023;

const char nl = '\n';

#define forn(i, n) for (int i = 0; i < int(n); i++)

#define all(v) v.begin(),v.end()



#pragma GCC optimize("O2")

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

 

ll l, r, k, n, m, p, q, u, v, w, x, y, z;

string s, t;

 

////////////////////  LIBRARY CODE ////////////////////



///////////////////////////////////////////////////////b



bool multiTest = 0;

void solve(int tt){



    cin >> n >> m;



    string s;

    cin >> s;



    vll pow2(26, 1);

    forn(i, 25) pow2[i+1] = pow2[i] * 2;



    m -= pow2[s[n-1]-'a'];

    m += pow2[s[n-2] - 'a'];



    vll cnt(26, 0);

    ll tot = 0;

    forn(i, n-2) {

        cnt[s[i]-'a']++;

        tot += pow2[s[i]-'a'];

    }



    ll needed = tot - m;



    if(needed % 2 || needed < 0) {

        cout << "No" << nl;

        return;

    }



    needed /= 2;



    for(int i = 25; i > -1; i--) {

        ll cur = needed / pow2[i];

        cur = min(cur, cnt[i]);

        needed -= cur * pow2[i];

    }



    if(needed) cout << "No" << nl;

    else cout << "Yes" << nl;





}



int main() {



    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);



    #ifdef yangster

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    // #else 

    // freopen("cowpatibility.in", "r", stdin);

    // freopen("cowpatibility.out", "w", stdout);

    #endif



    int t = 1;

    if (multiTest) cin >> t;

    for (int ii = 0; ii < t; ii++) {

        solve(ii + 1);

    }

}