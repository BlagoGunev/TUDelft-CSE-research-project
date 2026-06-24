//Author: Ankush Bhagat (https://github.com/ankushbhagat124)

//RFIPITIDS

#include <bits/stdc++.h>

#define int unsigned long long

const int N = (int)(3e5 + 1);

const int mod = (int)(998244353);

using namespace std;



void init()

{

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif

}



int power( int x,

           int y, int p)

{

    int res = 1;



    x = x % p;



    while (y > 0)

    {

        if (y & 1ll)

            res = (res * x) % p;

        y = y >> 1ll;

        x = (x * x) % p;

    }

    return res;

}



int modInverse( int n,

                int p)

{

    return power(n, p - 2, p);

}



int nCrModPFermat( int n,

                   int r, int p)

{



    if (n < r)

        return 0;

    if (r == 0)

        return 1;



    int fac[n + 1];

    fac[0] = 1;

    for (int i = 1; i <= n; i++)

        fac[i] = (fac[i - 1] * i) % p;



    return (fac[n] * modInverse(fac[r], p) % p

            * modInverse(fac[n - r], p) % p)

           % p;

}



signed main()

{

    init();

    ios_base::sync_with_stdio(0);

    cin.tie(0); cout.tie(0);

    /*

    Ans = mC(n-1) * (n-2) * (2^(n-3))

    */



    int n, m;

    cin >> n >> m;



    if (n > 2)

        cout << (nCrModPFermat(m, n - 1, mod) * (n - 2) % mod * power((int)2, n - 3, mod)) % mod;

    else

        cout << 0;

    cout << endl;

}