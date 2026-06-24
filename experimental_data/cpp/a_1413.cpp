#include <bits/stdc++.h>



#define ll long long

#define ull unsigned long long

#define ld long double

#define ms multiset

#define endl "\n"

#define pb push_back

#define pf push_front

#define popf pop_front

#define popb pop_back

#define er erase

#define all(a) a.begin(), a.end()

#define fst first

#define sec second

#define fr front

#define bk back

#define rev reverse

#define mp make_pair

#define in insert

#define sp " "

#define debug(n) cout << #n << " = " << n << endl;



using namespace std;



ifstream fin("INPUT.TXT");

ofstream fout("OUTPUT.TXT");



// 0-9 (48-57); A-Z (65-90); a-z (97-122)





void solve() {



    int n;

    cin >> n;



    vector <int> a(n);



    for (int i = 0; i < n; i++) {

        cin >> a[i];

    }



    rev(all(a));



    for (int i = 0; i < n / 2; i++) {

        a[i] *= -1;

    }



    for (int i : a) {

        cout << i << sp;

    }

    cout << endl;



}





int main() {



    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);



    int t = 1;

    cin >> t;

    while (t--) {

        solve();

    }



}