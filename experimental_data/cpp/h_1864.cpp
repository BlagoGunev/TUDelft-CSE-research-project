#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#define int long long
const int MOD = 998244353;
int n, k;
long long power(int x, int p)
{
    if (p < 0)
        return power(power(x, MOD - 2), -p);
    int answer = 1;
    x %= MOD;
    while (p)
    {
        if (p & 1)
            answer = answer * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return answer;
}
void Delta()
{
    cin >> n;
    k = power(2, MOD - 2);
    int l = n, r = max(1ll, (n - 1) * 2), n0 = 0, s;
    vector<int> Q;
    while (l > 1)
    {
        vector<int> P;
        l = (l + 1) / 2;
        r /= 2;
        s = n0;
        for (int i = 0, t = k - 1; i < (int)Q.size(); ++i)
        {
            s = (s + Q[i] * power(power(k, -(1ll << i)), r + 1)) % MOD;
            t = t * t % MOD;
        }
        P.push_back(((power(k, r + 1) * s - power(k, r)) % MOD + MOD) % MOD);
        for (int i = 0; i < (int)Q.size(); ++i)
        {
            P[0] += power(power(k, 1 - (1ll << (i + 1))) - 1, MOD - 2) * Q[i] % MOD * power(power(k, 1 - (1ll << (i + 1))), r + 1) % MOD * k % MOD;
            P.push_back(((MOD - Q[i] * k % MOD * power(power(k, 1 - (1ll << (i + 1))) - 1, MOD - 2) % MOD) % MOD + MOD) % MOD);
        }
        P[0] += (MOD - n0) * power(k, r + 1) % MOD;
        for (int &i : P)
            i %= MOD;
        Q = P;
        n0 += 2;
    }
    s = n0;
    for (int i = 0, t = k - 1; i < (int)Q.size(); ++i)
    {
        s = (s + Q[i] * power(power(k, -(1ll << i)), 1)) % MOD;
        t = t * t % MOD;
    }
    cout << s << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        Delta();
}