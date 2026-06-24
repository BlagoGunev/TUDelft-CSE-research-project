#include<bits/stdc++.h>

using namespace std;



#define endl '\n'



int32_t main () {

    ios_base::sync_with_stdio(0); cin.tie(0);



    int t; cin >> t;

    while (t--) {

        int n; cin >> n;

        vector <int> a(n), b(n);

        for (auto &i : a) cin >> i;

        for (auto &i : b) cin >> i;

        sort(a.begin(), a.end());

        sort(b.begin(), b.end());



        bool found = false;

        for (int i = 0; i < n; i++) {

            int dif = b[i] - a[i];

            if (dif != 0 and dif != 1) {

                found = true;

                break;

            }

        }



        if (found) cout << "NO" << endl;

        else cout << "YES" << endl;

    }



    return 0;

}