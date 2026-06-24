#include <bits/stdc++.h>

using namespace std;



#define pb push_back

#define mp make_pair



#define int long long

#define IOS ios_base::sync_with_stdio(0);cin.tie(0)



#define db cout << "Debug" << "\n";

#define dbg(x)  cout << #x << " = " << x << "\n"



const int N = 2e2 + 10;

const int INF = 1e9;



int n, m, memo[N][N];

string s, t;



string destroy(string s) {

    string ans;

    int B = 0;

    for(auto u : s) {

        if(u != 'B') {

            if(ans.back() == u) ans.pop_back();

            else ans += u;

        }

        else B ^= 1;

    }

    if(B) ans += "B";

    return ans;

}



void solve(){

    cin >> s >> t;

    n = s.size(), m = t.size();



    auto esq = destroy(s), dir = destroy(t);

    if(esq == dir) cout << "YES\n";

    else cout << "NO\n";

}



signed main() {

    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;

    for(int i = 1; i <= t; i++)

        solve();

}