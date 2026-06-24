#pragma GCC optimize ("O3")

#pragma GCC target ("sse4")

#pragma GCC optimize("Ofast,unroll-loops")

#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")



#include <bits/stdc++.h>

#define f first

#define s second

#define pb push_back

#define all(x) (x).begin(), (x).end()

#define sz(x) ((int) (x).size())

using namespace std;



using ll = long long;

using ld = long double;

using pii = pair<int, int>;

using vi = vector<int>;

using vp = vector <pii>;

using vl = vector<ll>;



const int inf = INT_MAX;

const ll linf = LLONG_MAX;



ll spf[200005];



void solve() {

    int n, q;

    scanf("%d %d", &n, &q);

    vi rel_divs = {1};

    int x = n;

    while(x > 1) {

        int p = spf[x];

        rel_divs.pb(n / p);

        while(x % p == 0)

            x /= p;

    }

    vi pref;

    for(int d : rel_divs) {

        if(pref.empty()) pref.pb(0);

        else pref.pb(pref.back());

        pref.back() += d;

    }

    vl sums;

    vi a(n);

    for(int &x : a) scanf("%d", &x);

    vector <priority_queue<pair<ll, int>>> best(sz(rel_divs));

    ll ans = 0;

    for(int j = 0; j < sz(rel_divs); j++) {

        int d = rel_divs[j];

        for(int p = 0; p < d; p++) {

            ll sum = 0;

            for(int j = p; j < n; j += d) {

                sum += a[j];

            }

            best[j].push({sum, sz(sums)});

            sums.pb(sum);

            ans = max(ans, sum * d);

        }

    }

    printf("%lld\n", ans);

    while(q--) {

        int p, x;

        scanf("%d %d", &p, &x);

        p--;

        ans = 0;

        int delta = x - a[p];

        for(int j = 0; j < sz(rel_divs); j++) {

            int d = rel_divs[j];

            int r = (pref[j] - d) + p % d;

            sums[r] += delta;

            if(delta != 0)

                best[j].push({sums[r], r});

            while(true) {

                auto [ss, idx] = best[j].top();

                if(ss != sums[idx]) best[j].pop();

                else break;

            }

            ans = max(ans, best[j].top().f * d);

        }

        a[p] = x;

        printf("%lld\n", ans);

    }

}



int main() {

    for(ll i = 2; i <= 200000; i++) {

        if(!spf[i]) {

            spf[i] = i;

            for(ll j = i * i; j <= 200000; j += i) {

                if(!spf[j])

                    spf[j] = i;

            }

        }

    }

    int tc;

    scanf("%d", &tc);

    while(tc--) {

        solve();

    }

    return 0;

}