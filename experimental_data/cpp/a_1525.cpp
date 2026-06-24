#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;



int gcd(int a, int b) {

    return b ? gcd(b, a % b) : a;

}



void solve() {

    int k;

    cin >> k;

    int x = k, y = 100 - k;

    while (gcd(x, y) != 1) {

        int d = gcd(x, y);

        x /= d, y /= d;

    }

    cout << x + y << '\n';

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int T = 1;

    cin >> T;

    while (T--) {

        solve();

    }

    return 0;

}