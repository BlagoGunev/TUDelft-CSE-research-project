#include <bits/stdc++.h>

using namespace std;



using i64 = long long;



const int mod = 998244353;



#define x first

#define y second

string yes = "YES\n";

string no = "NO\n";



void solve() {

    int n, k;

    cin >> n >> k;

    vector<int> a(n), p(n);

    vector<bool> st(n);

    for (int i = 0; i < n; i++) {

        cin >> a[i];

        p[i] = i;

    }

    for (int i = 0; i < n; i++) {

        if (a[i] == 0) {

            if (i < n - k) {

                p[i + k] = k;

            }

        }

        else if (a[i] == -1) {

            continue;

        }

        else {

            if (i < n - k) {

                p[i + k] = 0;

            } else {

                cout << 0 << '\n';

                return;

            }

        }

    }

    i64 ans = 1;

    // for (int i = 0; i < n; i++) {

    //     cout << p[i] << ' ';

    // }

    // cout << '\n';

    for (int i = 0; i < n; i++) {

        ans = ans * (p[i] + 1) % mod;

    }

    cout << ans << '\n';



}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);



    int t;

    cin >> t;

    while (t--) {

        solve();

    }

}