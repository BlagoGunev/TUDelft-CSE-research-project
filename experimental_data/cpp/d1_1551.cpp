#include <bits/stdc++.h>

using namespace std;



void no() {

    cout << "NO\n";

}



void yes() {

    cout << "YES\n";

}



void solve() {

    int n, m, k;

    cin >> n >> m >> k;



    if (n & 1 && m & 1) {

        no();

        return;

    }



    if (n % 2 == 0 && m % 2 == 0) {

        if (k % 2 == 0 && k <= (n * m) / 2) yes();

        else no();

        return;

    }



    if (n % 2 == 0 && m & 1) {

        if (k % 2 == 0 && k <= (n * m - n) / 2) yes();

        else no();

        return;

    }



    if (n & 1 && m % 2 == 0) {

        if (k % 2 == (n * m / 2) % 2 && k >= (m / 2) && k <= (n * m) / 2) yes();

        else no();

        return;

    }

}

 

int main() {

    ios::sync_with_stdio(0);

    cin.tie(0), cout.tie(0);



    int t = 1;

    cin >> t;

    while (t--) {

        solve();

    }

}