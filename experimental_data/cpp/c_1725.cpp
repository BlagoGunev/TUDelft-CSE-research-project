#include <bits/stdc++.h>

#define ll long long

#define all(a) (a).begin(), (a).end()

#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

const int inf = 0x3f3f3f3f;

const ll INF = 0x3f3f3f3f3f3f3f3f;

const int N = 3e5 + 10;



ll mod = 998244353;

ll fac[N], invfac[N];

ll qpow(ll base, ll pow)

{

    // if(base == 0 && pow) return 0;

    ll ans = 1;

    while (pow)

    {

        if (pow & 1)

            ans = ans * base % mod;

        pow >>= 1;

        base = base * base % mod;

    }

    return ans;

}

void init()//不能忘记init

{

     fac[0] = invfac[0] = 1;

     for(int i = 1; i < N; i ++ ) 

         fac[i] = fac[i - 1] * i % mod;

     invfac[N - 1] = qpow(fac[N - 1], mod - 2);

     for(int i = N - 2; i >= 0; i -- ) 

         invfac[i] = invfac[i + 1] * (1 + i) % mod;

}

ll C(int n, int m)

{

    if (n < 0 || m < 0 || m > n)

        return 0;

    return fac[n] * invfac[m] % mod * invfac[n - m] % mod;

}



void solve()

{

    init();



    int n, m;

    cin >> n >> m;

    

    vector<ll> d(n);

    for(int i = 0; i < n; i++) cin >> d[i];

    

    vector<ll> pre = d;

    for(int i = 1; i < n; i++) pre[i] += pre[i - 1];

    

    int tot = 0;

    if(pre.back() % 2 == 0)

    {

        for(int i = 0; i < n; i++)

        {

            auto it = lower_bound(all(pre), pre[i] - pre.back() / 2);

            if(it != pre.end() && *it == pre[i] - pre.back() / 2) tot++;

        }

    }



    ll ans = 0;

    for(int i = 0; i <= min(tot, m); i++)

        ans = (ans + C(tot, i) * fac[m] % mod * invfac[m - i] % mod * qpow(C(m - i, 2) * 2 % mod, tot - i) % mod * qpow(m - i, n - 2 * tot) % mod) % mod;

    

    cout << ans << '\n';

}



signed main()

{

    IOS;

    int t = 1;

    // cin >> t;

    while (t--)

        solve();

    return 0;

}