#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define all(x) x.begin(), x.end()

const ll MOD = 998244353;
const ll MAXN = 1000000;
ll fact[MAXN+1];
ll rev_fact[MAXN+1];

ll bin_pow(ll x, ll d) {
    ll ans = 1LL;
    while(d) {
        if(d&1) ans = (ans*x)%MOD;
        d >>= 1;
        x = (x*x)%MOD;
    }
    return ans;
}

ll reverse(ll x) {
    return bin_pow(x, MOD-2LL);
}

void calc_fact() {
    fact[0] = 1LL;
    for(ll i = 0; i < MAXN; ++i) {
        fact[i+1] = (fact[i] * (i+1LL)) % MOD;
    }
    for(ll i = 0; i <= MAXN; ++i) {
        rev_fact[i] = reverse(fact[i]);
    }
}

ll cnk(ll n, ll k) {
    if(n < k || n < 0 || k < 0) return 0;
    else {
        return ((fact[n]*rev_fact[k])%MOD)*rev_fact[n-k]%MOD;
    }
}

struct Point {
    ll pos;
    char side;

    bool operator<(const Point& other) const {
        return (pos < other.pos || (pos == other.pos && side < other.side));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    cin >> test;
    calc_fact();
    while(test--) {
        ll n;
        cin >> n;
        vector<Point> points(2*n);
        ll left, right;
        for(int i = 0; i < n; ++i) {
            cin >> left >> right;
            points[2*i] = {left, 'L'};
            points[2*i+1] = {right, 'R'};
        }
        sort(all(points));

        vector<ll> dl(2*n, 0);
        vector<ll> dr(2*n, 0);
        vector<ll> cl(2*n, 0);
        vector<ll> cr(2*n, 0);
        vector<ll> cm(2*n, 0);
        for(int i = 1; i < 2*n; ++i) {
            cl[i] = cl[i-1];
            if(points[i-1].side == 'R') cl[i]++;
        }
        for(int i = 2*n-2; i >=0; i--) {
            cr[i] = cr[i+1];
            if(points[i+1].side == 'L') cr[i]++;
        }
        for(int i = 0; i < 2*n; ++i) {
            cm[i] = n-1LL-cl[i]-cr[i];
        }

        for(int i = 1; i < 2*n; ++i) {
            dl[i] = (dl[i-1] + (cl[i] * (points[i].pos - points[i-1].pos) % MOD))%MOD;
        }
        for(int i = 2*n-2; i >= 0; i--) {
            dr[i] = (dr[i+1] + (cr[i] * (points[i+1].pos - points[i].pos) % MOD))%MOD;
        }

        //checking
        // cout << "Points: ";
        // for(int i = 0; i < 2*n; ++i) {
        //     cout << points[i].p << ' ' << points[i].side << "; ";
        // }
        // cout << '\n';
        // cout << "l: ";
        // for(int i = 0; i < 2*n; ++i) {
        //     cout << cl[i] << ' ';
        // }
        // cout << '\n';
        // cout << "r: ";
        // for(int i = 0; i < 2*n; ++i) {
        //     cout << cr[i] << ' ';
        // }
        // cout << '\n';
        // cout << "m: ";
        // for(int i = 0; i < 2*n; ++i) {
        //     cout << cm[i] << ' ';
        // }
        // cout << '\n';
        // cout << "dl: ";
        // for(int i = 0; i < 2*n; ++i) {
        //     cout << dl[i] << ' ';
        // }
        // cout << '\n';
        // cout << "dr: ";
        // for(int i = 0; i < 2*n; ++i) {
        //     cout << dr[i] << ' ';
        // }
        // cout << '\n';

        ll ans = 0;
        for(int i = 0; i < 2*n; ++i) {
            if(points[i].side == 'R') {
                ans += ((dl[i] * cnk(cr[i]+cl[i]-1LL, cl[i]+1LL) % MOD) * bin_pow(2LL, cm[i]))%MOD;
                ans %= MOD;
                ans += ((dr[i] * cnk(cr[i]+cl[i]-1LL, cl[i]) % MOD) * bin_pow(2LL, cm[i]))%MOD;
                ans %= MOD;
            }
            else {
                ans += ((dl[i] * cnk(cl[i]+cr[i]-1LL, cl[i]) % MOD) * bin_pow(2LL, cm[i])) % MOD;
                ans %= MOD;
                ans += ((dr[i] * cnk(cl[i]+cr[i]-1LL, cr[i]) % MOD) * bin_pow(2LL, cm[i])) % MOD;
                ans %= MOD;
            }
        }
        cout << ans << '\n';
    }
}