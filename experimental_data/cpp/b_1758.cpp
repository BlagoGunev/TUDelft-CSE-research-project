#include<bits/stdc++.h>

using namespace std;

void solve() {

    int n, x = 1;

    cin >> n;

    if(!(n & 1)) {

        n -= 2, x = 2;

        cout << 3 << ' ' << 1 << ' ';

    }

    while(n--) cout << x << ' ';

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