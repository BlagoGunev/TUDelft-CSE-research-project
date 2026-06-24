#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define FOR(i, j, k) for (int i = j; i <= k; i++)

#define FORR(i, j, k) for (int i = j; i >= k; i--)

ll inf = 0x3f3f3f3f, linf = LLONG_MAX/2;

ll MOD = 1e9+7;



ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}



const int N = 1e7;

vector<ll> p(N+5), P;



void solve() {

    ll x, y; cin >> x >> y;

    ll d = y-x;

    if (d == 1) cout << -1 << '\n';

    else {

        ll ans = inf;

        while (d > 1) {

            int e = p[d];

            ans = min(ans, (e-x%e)%e);

            while (d%e == 0) d /= e;

        }

        // for (auto e : P) {

        //     if (e*e > d) break;

        //     if (d%e == 0) {

        //         ans = min(ans, (e-x%e)%e);

        //         while (d%e == 0) d /= e;

        //     }

        // }

        if (d > 1) ans = min(ans, (d-x%d)%d);

        cout << ans << '\n';

    }

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0); cout.tie(0);



    for (int i = 2; i <= N; i++) {

        if (!p[i]) {

            p[i] = i;

            P.push_back(i);

        }

        for (int x : P) {

            if (i*x > N) break;

            p[i*x] = x;

            if (i%x == 0) break;

        }

    }



    int _; cin >> _;

    while (_--) solve();

    return 0;

}



// x y

// x+k y+k

// x+k, y-x

// k >= p-x%p

// https://blog.csdn.net/m0_60593173/article/details/128305868