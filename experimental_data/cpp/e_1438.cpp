#include <bits/stdc++.h>

using namespace std;



#define int long long



const int N = 200010;



int n, a[N];



int get (int x) {

    for (int j = 1ll << 31; j >= 0; j >>= 1 )

        if (x & j) return j << 1;

    return -1;

}



void solve () {

    cin >> n;

    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    set<pair<int, int>> S;

    for (int l = 1; l + 2 <= n; l ++ ) {

        int s = a[l + 1], mx = get(a[l]);

        for (int r = l + 2; r <= n; r ++ ) {

            if ((a[l] ^ a[r]) == s) S.insert({l, r});

            if ((s += a[r]) > mx) break;

        }

    }

    for (int r = n; r - 2 >= 1; r -- ) {

        int s = a[r - 1], mx = get(a[r]);

        for (int l = r - 2; l >= 1; l -- ) {

            if ((a[l] ^ a[r]) == s) S.insert({l, r});

            if ((s += a[l]) > mx) break;

        }

    }

    cout << S.size() << endl;

}



signed main () {

    cin.tie(nullptr); ios::sync_with_stdio(false);

//    int t; cin >> t; while( t -- )

        solve();

    return 0;

}