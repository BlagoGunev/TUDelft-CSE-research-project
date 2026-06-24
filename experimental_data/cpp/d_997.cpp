#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;

const ll MOD = 998244353;

ll pw(ll a, ll b = MOD - 2) {
    if (!b) {
        return 1;
    }

    ll v = pw(a, b / 2);
    v = (v *v) % MOD;
    if (b & 1) {
        v = (v * a) % MOD;
    }

    return v;
}

const int MAXN = 5002;
ll fact[MAXN];
ll rfact[MAXN];

ll cnk(ll a, ll b) {
    return fact[a] * rfact[b] % MOD * rfact[a - b] % MOD;
}

ll coff(int x) {
    return 1 - 2 * (x & 1);
}

ll norm(ll x) {
    x %= MOD;
    if (x < 0) {
        x += MOD;
    }

    return x;
}

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    rfact[MAXN - 1] = pw(fact[MAXN - 1]);
    for (int i = MAXN - 1; i > 0; --i) {
        rfact[i - 1] = rfact[i] * i % MOD;
    }
}

int k2;

int a[2 * MAXN], b[2 * MAXN];
ll s[MAXN][100];
ll f[MAXN][100];
ll fe[2 * MAXN][100];

struct Tree {
    int n;
    int m;
    int m2;

    ll sum[100];


    vector<pair<int, int>> e[MAXN];

    Tree(int n)
        : n(n), m(n - 1) {
        m2 = 2 * m;
        memset(f, 0, sizeof(f));
        memset(fe, 0, sizeof(fe));
        memset(sum, 0, sizeof(sum));
        memset(s, 0, sizeof(s));
        read();
    }

    void read() {
        for (int i = 0; i < m; ++i) {
            cin >> a[2 * i] >> b[2 * i];
            a[2 * i + 1] = b[2 * i];
            b[2 * i + 1] = a[2 * i];
            e[a[2 * i]].emplace_back(b[2 * i], 2 * i);
            e[a[2 * i + 1]].emplace_back(b[2 * i + 1], 2 * i + 1);
        }
        
        for (int i = 1; i <= n; ++i) {
            f[i][0] = 1;
        }

        for (int i = 0; i < m2; ++i) {
            fe[i][0] = 1;
        }


        for (int i = 1; i <= k2; ++i) {
            for (int j = 0; j < m2; ++j) {
                s[a[j]][i - 1] = norm(s[a[j]][i - 1] + fe[j][i - 1]);
            }

            for (int j = 1; j <= n; ++j) {
                for (int l = 0; l < i; ++l) {
                    int r = i - l - 1;
                    f[j][i] = norm(f[j][i] + f[j][l] * s[j][r]);
                }
            }

            for (int j = 0; j < m2; ++j) {
                for (int l = 0; l < i; ++l) {
                    int r = i - l - 1;
                    fe[j][i] = norm(fe[j][i] + fe[j][l] * (s[b[j]][r] - fe[j ^ 1][r]));
                }
            }

            
        }

        for (int i = 0; i <= k2; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i] += f[j][i];
                sum[i] %= MOD;
            }
        }
    }
};

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    precalc();
    int n1, n2, k;
    cin >> n1 >> n2 >> k;
    if (k % 2) {
        cout << 0 << "\n";
        return 0;
    }

    k2 = k / 2;
    Tree a(n1), b(n2);
    ll ans = 0;
    for (int i = 0; i <= k2; ++i) {
        ll val = a.sum[i] * b.sum[k2 - i] % MOD;
        val = val * cnk(k, 2 * i) % MOD;
        ans = (ans + val) % MOD;
    }

    ans = norm(ans);

    cout << ans << "\n";
}