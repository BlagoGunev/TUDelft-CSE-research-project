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



///////////////////////////////////////////////////////



bool multiTest = 1;

void solve(int tt){



    ll s;

    cin >> s >> n >> k;



    if(s == k) {

        cout << "YES" << nl;

        return;

    }



    ll minn = n/k;

    minn *= k * 2;



    minn += n % k;



    cout << (s >= minn ? "NO" : "YES") << nl;







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