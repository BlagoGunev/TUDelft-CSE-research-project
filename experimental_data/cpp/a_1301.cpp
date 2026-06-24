#include <bits/stdc++.h>



#define ll long long

#define ld long double



using namespace std;



int main(){

    ll t = 1;

    cin >> t;

    while (t--) {

            bool flag = true;

        string a, b, c;

        cin >> a >> b >> c;

        for (int i = 0; i < a.size(); i++) {

            if (c[i] == a[i] or c[i] == b[i]) {

                continue;

            }

            else {

                flag = false;

                break;

            }

        }

        cout << (flag ? "YES\n" : "NO\n");

    }

    return 0;

}