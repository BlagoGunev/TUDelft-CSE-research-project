#include "bits/extc++.h"

using namespace std;

using ll = long long;

template <typename T, typename... U>
void dbgh(const T& t, const U&... u) {
    cerr << t;
    ((cerr << " | " << u), ...);
    cerr << endl;
}

#ifdef DEBUG
#define dbg(...)                                              \
    cerr << "L" << __LINE__ << " [" << #__VA_ARGS__ << "]: "; \
    dbgh(__VA_ARGS__)
#else
#define dbg(...)
#define cerr   \
    if (false) \
    cerr
#endif

#define sz(x) int(std::size(x))
#define int ll

#ifdef LOCAL
constexpr int maxn = 1e4;
#else
constexpr int maxn = 2e6 + 10;
#endif
int lpd[maxn];
bool comp[maxn];
int phi[maxn];

int phicalc(int x) {
    if (phi[x] != 0) {
        return phi[x];
    }
    vector<int> fac;
    int num = x;
    while (x > 1) {
        fac.push_back(lpd[x]);
        int div = lpd[x];
        while (x % div == 0) {
            x /= div;
        }
    }
    for (auto u : fac) {
        num /= u;
        num *= (u - 1);
    }
    return phi[x] = num;
}

int bpow(ll base, int exp, int mod) {
    ll ans = 1;
    while (exp) {
        if (exp & 1) {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return ans;
}

int inv(int x, int mod) {
    return bpow(x, phicalc(mod) - 1, mod);
}

int mod(int a, int b) {
    a %= b;
    if (a < 0) {
        a += b;
    }
    return a;
}
ll gcd(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    if (a == 0) {
        return b;
    }
    return gcd(a, b % a);
}

ll lcm(int a, int b) {
    return (ll(a) * b / gcd(a, b));
}

void solve() {
    ll n, k, w, h;
    string s;
    cin >> n >> k >> w >> h >> s;
    int x[n + 1], y[n + 1];
    x[0] = 0;
    y[0] = 0;
    for (int i = 1; i <= n; i++) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
        if (s[i - 1] == 'U') {
            y[i]++;
        }
        if (s[i - 1] == 'D') {
            y[i]--;
        }
        if (s[i - 1] == 'L') {
            x[i]--;
        }
        if (s[i - 1] == 'R') {
            x[i]++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        // find solutions to a:
        // a*x[n]+x[i] = 0 mod 2w
        // a*y[n]+y[i] = 0 mod 2h
        // a*x[n]=-x[i] mod 2w
        // a=-x[i]*x[n]^-1 mod 2w
        // no solution if gcd(x[n],2w) doesn't divide gcd(x[i],2w)
        ll wm = 2 * w, hm = 2 * h, xnm = mod(x[n], wm), ynm = mod(y[n], hm);
        ll nxi = mod(-x[i], wm), nyi = mod(-y[i], hm);
        dbg(i, xnm, nxi, wm, ynm, nyi, hm);
        if (gcd(xnm, wm) == 0) {
            if (gcd(nxi, wm)) {
                continue;
            }
        } else {
            if (gcd(nxi, wm) % gcd(xnm, wm) != 0) {
                continue;
            }
        }
        if (gcd(ynm, hm) == 0) {
            if (gcd(nyi, hm)) {
                continue;
            }
        } else {
            if (gcd(nyi, hm) % gcd(ynm, hm) != 0) {
                continue;
            }
        }
        if (ynm == 0 && xnm == 0) {
            dbg(i);
            ans += k;
            continue;
        }
        int gcdw = gcd(wm, xnm), gcdh = gcd(hm, ynm);
        // do a bunch of nonsense if it's 0
        if (gcdw == 0) {
            gcdw = 1;
        }
        if (gcdh == 0) {
            gcdh = 1;
        }
        xnm /= gcdw;
        ynm /= gcdh;
        nxi /= gcdw;
        nyi /= gcdh;
        wm /= gcdw;
        hm /= gcdh;
        nxi *= inv(xnm, wm);
        nyi *= inv(ynm, hm);
        nxi %= wm;
        nyi %= hm;
        // so now (if everything is right) should be
        // a = nxi mod wm
        // a = nyi mod hm
        // solve for a mod lcm(wm,hm)
        dbg(nxi, wm, nyi, hm, i);
        if (nxi % gcd(wm, hm) != nyi % gcd(wm, hm)) {
            continue;
        }
        // a=[smth]*wm+nxi = nyi mod hm
        // [smth]*wm=nyi-nxi mod hm
        ll gcdwh = gcd(hm, wm);
        if (gcdwh == 0) {
            dbg(i);
            ans += k;
            continue;
        }
        ll smth = mod(nyi - nxi, hm) / gcdwh * inv(wm / gcdwh, hm / gcdwh);
        ll a = ll(smth) * wm + nxi;
        a = mod(a, lcm(wm, hm));
        // so now (if everything is right) all solutions stuff=a%lcm(wm,hm)
        if (xnm == 0) {
            dbg(i, hm, nyi);
            ans += k / hm + (nyi < k % hm);
            continue;
        } else if (ynm == 0) {
            dbg(i);
            ans += k / wm + (nxi < k % wm);
            continue;
        }
        ans += k / lcm(wm, hm) + (a < k % lcm(wm, hm));
        dbg(ans, i);
        dbg(a, nxi, wm, nyi, hm);
    }
    cout << ans << "\n";
}

int32_t main() {
    cin.tie(nullptr);
    cin.exceptions(ios::failbit);
    ios_base::sync_with_stdio(false);
    for (int i = 2; i < maxn; i++) {
        if (comp[i]) {
            continue;
        }
        lpd[i] = i;
        for (int j = i * i; j < maxn; j += i) {
            if (!lpd[j]) {
                lpd[j] = i;
            }
            comp[j] = 1;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}