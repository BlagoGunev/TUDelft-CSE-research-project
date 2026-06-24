#include <iostream>
#define MOD 998244353

using namespace std;
typedef long long ll;

int T;
int n;
ll m;
int cnt;
int l[500005];
int r[500005];
ll val[500005];
int fix[500005];
ll fact[500005];
ll ifact[500005];
ll ans;

ll inv(ll x) {
    x %= MOD;
    ll res = 1;
    for (int i = 29; i >= 0; i--)
    {
        res = (res * res) % MOD;
        if ((MOD - 2) & (1 << i))
        {
            res = (res * x) % MOD;
        }
    }
    return res;
}

void dfs(int here) {
    if (l[here] != -1)
    {
        dfs(l[here]);
    }
    cnt++;
    fix[cnt] = val[here];
    if (r[here] != -1)
    {
        dfs(r[here]);
    }
}

void h(ll first, int second) {
    for (int i = 0; i < second; i++)
    {
        ans = (ans * (first + second - 1 - i)) % MOD;
    }
    ans = (ans * ifact[second]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    ifact[0] = 1;
    for (int i = 1; i <= 500000; i++)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
        ifact[i] = inv(fact[i]);
    }
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i] >> r[i] >> val[i];
        }
        cnt = 0;
        dfs(1);
        fix[n + 1] = m;
        ans = 1;
        ll last = 1;
        int p = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            if (fix[i] != -1)
            {
                h(fix[i] - last + 1, i - p - 1);
                p = i;
                last = fix[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}