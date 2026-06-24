#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair <int, int> pi;

ll bin_pow(ll a, ll x)
{
    ll res = 1;
    while (x)
    {
        if (x&1)
            res*=a;
        a*=a;
        x>>=1;
    }
    return res;
}
int main()
{
    ll n, l, r;
    cin >> n >> l >> r;
    ll len = r - l + 1;

    if (n == 1)
    {
        cout << len;
        return 0;
    }

    if (n == 2)
    {
        cout << len*(len - 1);
        return 0;
    }

    ll ans = 0, g, g1, low_k, top_k;
    if (n >= 30)
    {
        cout << 0;
        return 0;
    }
    for (ll q = 1; ;q++)
    {
        g = bin_pow(q, n - 1);
        if (g > r)
            break;
        low_k = (l + g - 1) / g;
        for (ll delta = 1; ; delta++)
        {
            g1 = bin_pow(q + delta, n - 1);
            if (__gcd(q + delta, q) != 1)
                continue;
            if (g1 > r)
                break;
            top_k = (r)/g1;
            ans += max(0LL, top_k - low_k + 1LL);
        }
    }
    cout << ans + ans << '\n';
}