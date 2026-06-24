#include <bits/stdc++.h>

using namespace std;



#define ll long long



void solve() {

    int n, f = 0;

    cin >> n;

    vector<int> vc(n);

    for (int i = 0; i < n; i++) cin >> vc[i];



    for (int i = 0; i < n; i++) {

        int ans = 0;

        for (int j = 0; j < n; j++) {

            if (vc[i] != vc[j]) ans = ans ^ vc[j];

        }

        for (int j = 0; j < n; j++) {

            if (vc[j] == ans) {

                cout << ans << endl;

                return;

            }

        }

    }



    cout << vc[n - 1] << endl;

}



void T() {

    int t;

    cin >> t;

    while (t--) {

        solve();

    }

}

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    T();

    // solve();

    return 0;

}