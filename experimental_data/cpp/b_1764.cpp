#include<bits/stdc++.h>

#define ll long long

#define ld long double

#define fi first

#define se second

#define pii pair<int, int>

#define pll pair<long long, long long>

using namespace std;



void solve() {

    int n, mmax = 0, a, g = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> a;

        mmax = max(mmax, a);

        g = __gcd(g, a);

    }



    cout << mmax / g << "\n";

    return;

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int tt;

    cin >> tt;

    while(tt--) {

        solve();

    }



    return 0;

}