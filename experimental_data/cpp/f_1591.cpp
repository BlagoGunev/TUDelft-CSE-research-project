#include<bits/stdc++.h>



using namespace std;



typedef long long ll;



const ll MOD = 998244353;



ll quickPow(ll n, ll p, ll k = MOD)

{

    ll ans = 1;

    ll base = n;



    while (p)

    {

        //最后一位为1

        if (p & 1)

        {

            ans *= base;

            ans %= k;

        }

        //去掉一位数

        base *= base;

        base %= k;

        p >>= 1;

    }



    return ans;

}



ll inv(ll x)

{

    return quickPow(x, MOD - 2);

}



ll n;

ll a[200005];

ll tp, s[200005] = {1}, q[200005], f[200005] = {-1};



void solve()

{



    cin >> n;

    for (int i = 1; i <= n; i++)

    {

        cin >> a[i];

    }





    ll res = 1;



    for (int i = 1; i <= n; i++)

    {

        while (tp && a[q[tp]] > a[i])

            tp--;

        int cnt = f[i - 1];

        if (q[tp])

            cnt = (cnt - f[q[tp] - 1] + MOD) % MOD;

        if (i & 1)

            cnt = MOD - cnt;



        s[i] = 1ll * a[i] * cnt % MOD;



        if (q[tp])

        {

            if ((i - q[tp]) & 1)

                s[i] = (s[i] - s[q[tp]] + MOD) % MOD;

            else

                s[i] = (s[i] + s[q[tp]]) % MOD;

        }

        q[++tp] = i;

        if (i & 1)

            f[i] = (f[i - 1] + s[i]) % MOD;

        else

            f[i] = (f[i - 1] - s[i] + MOD) % MOD;

        //      printf("%d %d %d\n", i, s[i], f[i]);

    }

    cout << s[n];

}



signed main()

{

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);



#ifndef ONLINE_JUDGE

    

    freopen("/Users/pengxuedian/Desktop/program_contest_cpp/input.txt", "r", stdin);

    freopen("/Users/pengxuedian/Desktop/program_contest_cpp/output.txt", "w", stdout);

    

#endif// ONLINE_JUDGE



    solve();



    return 0;

}