#include <bits/stdc++.h>



using namespace std;



long long gcd(long long a, long long b) {

    if (b == 0) return a;

    return gcd(b, a % b);

}



const int N = 5e5 + 1;



vector<int> a(2 * N, 0), b(2 * N, 0);



void solve() {

    string s; cin >> s;

    s = '$' + s;

    int n = s.size();

    int p = N;

    for (int i = 1; i <= n; i++) {

        if (s[i] == '1') {

            b[p]++;

            p++;

        } else {

            a[p]++;

            p--;

        }

    }

    p = N;

    for (int i = 1; i < n; i++) {

        if (a[p] && (!b[p] || b[p - 1] >= 1)) {

            cout << '0';

            a[p]--;

            p--;

        } else {

            cout << '1';

            b[p]--;

            p++;

        }

    } cout << "\n";

    for (int i = N - n; i <= N + n; i++) {

        a[i] = 0;

        b[i] = 0;

    }

}



signed main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T; cin >> T;

    while (T--) {

        solve();

    }

}