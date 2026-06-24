#include <bits/stdc++.h>

using namespace std;

 

#define endl '\n'

#define ff first

#define ss second

#define all(a) a.begin(), a.end()

#define rall(a) a.rbegin(), a.rend()



typedef long long ll;

typedef long double ld;



const ll INF = 1e18 + 1;

const ll N = 2 * 1e5 + 1;

const ll MOD = 1e9 + 7;



void solve(){

    ll n; cin >> n;

    vector <string> a(n);

    set <string> st;

    for (auto &x: a) cin >> x, st.insert(x);



    string ans = "";

    for (int i = 0; i < n; i++){

        string s1;

        string s2 = a[i];

        bool f = false;

        for (int j = 0; j < a[i].size(); j++){

            s1 += s2[0];

            s2.erase(s2.begin());

            f = f || (st.count(s1) && st.count(s2));

        }



        ans += (char) (f + '0');

    }



    cout << ans << endl;

}



int main(){

    #ifdef LOCAL

        freopen("TASK.in", "r", stdin);

        freopen("TASK.out", "w", stdout);

    #else



    #endif // LOCAL

    ios::sync_with_stdio(0);

    cin.tie(0);

    int t; cin >> t;

    while (t--)solve();

    return 0;

}