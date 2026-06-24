#include <bits/stdc++.h>

using namespace std;



#define ll long long

#define err() cout << "==================" << endl;

#define err1(a) cout << #a << " " << a << endl;

#define err2(a, b) cout << #a << " " << a << " " << #b << " " << b << endl;

#define err3(a, b, c) cout << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << endl;

const ll mod = 998244353;



void solve(int testCase) {

    ll i = 1, j, n, k;

    cin >> n >> k;

    vector<ll> dp1(n + 1, 0), dp2(n + 1, 0), ans(n + 1, 0);

    dp1[0] = 1;

    ans[0] = 1;

    for (i = 1; k * i + ((i * (i - 1)) / 2) <= n; i++) {

        for (j = 0; j <= n; j++) {

            if (j - (k + i - 1) >= 0) {

                dp1[j] = (dp1[j] + dp1[j - (k + i - 1)]) % mod;

                dp2[j] = dp1[j - (k + i - 1)] % mod;

            }

        }

        for (j = 0; j <= n; j++) {

            ans[j] = (ans[j] + dp2[j]) % mod;

            dp1[j] = dp2[j] % mod;

            dp2[j] = 0;

        }

    }

    for (i = 1; i <= n; i++) cout << ans[i] % mod << " ";

    cout << endl;

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    ll t = 1;

    // cin >> t;

    for (int testCase = 1; testCase <= t; testCase++)

        solve(testCase);

    return 0;

}