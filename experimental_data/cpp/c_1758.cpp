#include<bits/stdc++.h>

using namespace std;

void solve() {

    int n, x, y;

    cin >> n >> x;

    if(n % x) {

        cout << -1 << '\n';

        return;

    }

    int temp = n / x;

    int a[n + 7];

    for(int i = 1; i <= n; i++) a[i] = i;

    for(int i = x, j = 2; temp > 1; j++) {

        while(i <= n && temp % j == 0) {

            a[i] = i * j;

            i = i * j;

            temp /= j;

        }

    }

    a[1] = x, a[n] = 1;

    for(auto i = 1; i <= n; i++) cout << a[i] << ' ';

    cout << '\n';

}

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int t;

    cin >> t;

    while(t--) solve();

    return 0;

}