#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

//const int mod = 998244353;

#define PII pair<long long, long long>

#define x first

#define y second

#define pi 3.14159265359

int qpow(int a, int b)

{

    int res = 1;

    while (b != 0)

    {

        if (b & 1)res = res * a % mod;

        a = a * a % mod;

        b >>= 1;

    }

    return res;

}

int _qpow(int a, int b)

{

    int res = 1;

    while (b != 0)

    {

        if (b & 1)res = res * a;

        a = a * a;

        b >>= 1;

    }

    return res;

}



int inv(int a)

{

    return qpow(a, mod - 2);

}



int exgcd(int ai, int bi, int& xi, int& yi)

{

    if (bi == 0)

    {

        xi = 1, yi = 0;

        return ai;

    }

    int d = exgcd(bi, ai % bi, yi, xi);

    yi -= ai / bi * xi;

    return d;

}

int gcd(int a, int b)

{

    return b == 0 ? a : gcd(b, a % b);

}

/*----------------------------------------------------------------------*/







void solve()

{

    int n;

    cin >> n;

    if (n % 2 == 0)

    {

        for (int i = 0; i < n / 2; i++)cout << "1";

        cout << "\n";

        return;

    }

    cout << "7";

    for (int i = 0; i < (n - 3) / 2; i++)cout << "1";

    cout << "\n";

}



signed main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int tt = 1;

    cin >> tt;

    while (tt--)solve();

    return 0;

}