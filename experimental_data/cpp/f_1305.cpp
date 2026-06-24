#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int N = 2e5 + 5;

const int M = 1e6 + 5;

int n, prime[M], tot;

ll a[N];

mt19937_64 rnd(19260817);

bool vis[M];

inline void Euler()

{

    for (int i = 2; i <= M - 5; i++)

    {

        if (!vis[i])

            prime[++tot] = i;

        for (int j = 1; j <= tot && 1ll * i * prime[j] <= M - 5; j++)

        {

            vis[i * prime[j]] = true;

            if (!(i % prime[j]))

                break;

        }

    }

}

set<ll> s;

inline void solve(ll x)

{

    for (int i = 1; i <= tot && x > 1; i++)

        if (!(x % prime[i]))

        {

            s.insert(prime[i]);

            while (!(x % prime[i]))

                x /= prime[i];

        }

    if (x > 1)

        s.insert(x);

}

signed main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    Euler();

    cin >> n;

    for (int i = 1; i <= n; i++)

        cin >> a[i];

    for (int i = 1; i <= 50; i++)

    {

        int x = rnd() % n + 1;

        if (a[x] > 2)

            solve(a[x] - 1);

        solve(a[x]), solve(a[x] + 1);

    }

    int ans = n, cur;

    for (ll x : s)

    {

        cur = 0;

        for (int i = 1; i <= n; i++)

            cur += a[i] < x ? x - a[i] : min(a[i] % x, x - a[i] % x);

        ans = min(ans, cur);

    }

    cout << ans;

    return 0;

}