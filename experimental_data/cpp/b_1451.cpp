#include<bits/stdc++.h>

using namespace std;



#define endl '\n'



int32_t main () {

    ios_base::sync_with_stdio(0); cin.tie(0);



    int t; cin >> t;

    while (t--) {

        int n, q; cin >> n >> q;

        string str; cin >> str;



        while (q--) {

            int l, r; cin >> l >> r;

            

            l--, r--;

            bool ok = false;

            for (int i = 0; i < l; i++) {

                if (str[i] == str[l]) {

                    ok = true;

                    break;

                }

            }



            for (int i = r + 1; i < n and !ok; i++) {

                if (str[i] == str[r]) {

                    ok = true;

                    break;

                }

            }



            if (ok) cout << "YES" << endl;

            else cout << "NO" << endl;

        }

    }



    return 0;

}