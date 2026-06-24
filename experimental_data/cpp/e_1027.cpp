#include<bits/stdc++.h>
using namespace std;

void doRoutine() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(322179);
#ifdef LOCAL
    freopen("/root/alg/clion_main/input.txt", "rt", stdin);
    freopen("/root/alg/clion_main/output.txt", "wt", stdout);
#endif
}

#define DBG(VAR) cerr << #VAR << ": " << VAR << endl

#define all(x) x.begin(), x.end()
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define vc vector

#ifndef LOCAL
#define cerr if(0) cerr
#define DBG(...) (true)
#endif

#define D double
#define int long long

// ----------------------------- CODE NOW ------------------------

const int MOD = 998244353;

const int MAXN = 505;
int cnt[MAXN]; // cnt[x] is amount of segments of length n that have <= x cons. eq. elements
int n, k;

int dp[MAXN];
int pref[MAXN];

void init() {
    for (int i = 0; i < MAXN; ++i) {
        dp[i] = pref[i] = 0;
    }
}

int fpow(int a, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 1) {
        return (fpow(a, n - 1) * a) % MOD;
    }
    else {
        return fpow((a * a) % MOD, n / 2);
    }
}

int rev(int x) {
    return fpow(x, MOD - 2);
}

int divide(int a, int b) {
    return a * rev(b) % MOD;
}

signed main() {
    doRoutine();

    cin >> n >> k;
    for (int x = 1; x <= n; ++x) {
        dp[0] = 1, pref[1] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = (pref[i] - pref[max(0ll, i - x)] + MOD) % MOD;
            pref[i + 1] = (pref[i] + dp[i]) % MOD;
        }
        cnt[x] = dp[n] * 2 % MOD;
    }

    int ans = 0;
    for (int x = 1; x <= min(n, k); ++x) {
        int line = (cnt[x] - cnt[x - 1] + MOD) % MOD;
        int h = divide(cnt[min((k - 1) / x, n)], 2ll);
        ans += (line * h) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}