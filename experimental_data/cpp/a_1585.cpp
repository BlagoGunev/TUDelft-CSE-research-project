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

int t, n, x, p, s;

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> t;

    while (t--)
    {
        cin >> n;
            
        s = 1;

        for (int i = 0; i < n; i++)
        {
            cin >> x;

            if (s == -1)
                continue;

            if (x)
            {
                if (i > 0 && p)
                    s += 5;

                else
                    s++;
            }

            else
            {
                if (i > 0 && !p)
                    s = -1;
            }

            p = x;
        }

        cout << s << "\n";
    }
}