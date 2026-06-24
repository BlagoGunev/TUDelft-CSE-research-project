// بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيمِ
// Written by Ilia Rahbar

// #pragma GCC optimize ("O3,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target ("abm,bmi,bmi2,tbm,avx2")

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define ai(x) array <int, x>
#define F first 
#define S second

const int MOD = 1e9 + 7, N = 1e6 + 100;

int t, n, h, a[N], m, p, s;

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> t;

    while (t--)
    {
        cin >> n >> h;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a+n);

        m = a[n-1] + a[n-2];

        p = h / m;

        s = (h % m > 0) + (h % m > a[n-1]);

        cout << p * 2 + s << "\n";
    }
}