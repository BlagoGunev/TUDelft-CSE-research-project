#include <bits/stdc++.h>

#pragma GCC optimize ("unroll-loops")

#pragma GCC optimize ("O3")

#define ll long long

#define st string

#define ull unsigned ll

#define pii pair <int, int>

#define pll pair <ll, ll>

#define pb push_back

#define ins insert

#define F first

#define S second

#define int ll

using namespace std;

int32_t main () {

    //freopen ("points.in", "r", stdin);

    //freopen ("points.out", "w", stdout);

    ios_base::sync_with_stdio();

    cin.tie(0);

    cout.tie(0);

    int t;

    cin >> t;

    while (t --) {

        int n, m;

        cin >> n >> m;

        int kol = 0;

        if (n % 2 == 0) kol += 2;

        else kol ++;

        if (m % 2 == 0) kol += 2;

        else kol ++;

        kol %= 2;

        if (kol == 0) {

            cout << "Tonya";

        }

        else cout << "Burenka";

        cout << "\n";

    }

    return 0;

}