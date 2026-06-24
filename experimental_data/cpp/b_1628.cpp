#include <bits/stdc++.h>



#pragma comment(linker, "/stack:200000000")

#pragma GCC optimize("Ofast")

#pragma GCC target_tbl("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")



using namespace std;



#define int long long

#define ll long long

#define ld long double

#define all(a) a.begin(), a.end()

#define rall(a) a.rbegin(), a.rend()



#define sz(v) ((int)(v).size())

const double pi = 3.1415926535897932384626433832795;



const long long mod = 1e9 + 7;

const long long inf = 99999999999999999;

const long long nmax = 3e5 + 5;



string sub(string &s, int l, int r) {

    string res = "";

    for (; l <= r; l++)

        res += s[l];

    return res;

}



void runtimeerror() {



    int n;

    cin >> n;

    vector <string> arr(n);

    for (int i = 0; i < n; i++)

        cin >> arr[i];



    unordered_map<string, int> p;



    for (int i = n - 1; i > -1; i--) {

        string s = arr[i];



        if (p[s] == 0) p[s] = i + 1;



        reverse(all(s));



        if (sz(s) == 1) {

            cout << "YES" << '\n';

            return;

        }



        if (sz(s) == 2) {

            bool flag = false;



            if (s[0] == s[1]) {

                cout << "YES" << '\n';

                return;

            }



            if (p[sub(s, 0, 1)] > i + 1)

                flag = true;



            int ind = p[sub(s, 1, 1)];

            if (ind > i + 1 || flag) {

                cout << "YES" << '\n';

                return;

            }



            string t = 'a' + s;

            for (char c = 'b'; c <= 'z' + 1; c++){

                if (p[t] > i + 1) flag = true;

                t[0] = c;

            }

            if (flag) {

                cout << "YES" << '\n';

                return;

            }

        }



        if (sz(s) == 3) {

            bool flag = false;



            if (s[0] == s[2]) {

                cout << "YES" << '\n';

                return;

            }



            if (p[sub(s, 0, 2)] > i + 1)

                flag = true;



            int ind = p[sub(s, 2, 2)];

            int ind2 = p[sub(s, 1, 1)];



            int ind4 = p[sub(s, 1, 2)];



            if ((ind > i + 1 && ind2 > ind) || (ind4 > i + 1) || flag) {

                cout << "YES" << '\n';

                return;

            }

        }



    }

    cout << "NO" << '\n';



//    for (auto x : p)

//        cout << x.first << ' ' << x.second << '\n';

//    cout << '\n';



}



signed main() {



    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);



    ll t = 1;

    cin >> t;

    while (t--) {

        runtimeerror();

    }



    //i`m stupid man

}