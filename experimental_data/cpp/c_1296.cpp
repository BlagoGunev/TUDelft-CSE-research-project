#include <bits/stdc++.h>



using namespace std;



using ll = long long;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

using vi = vector<int>;

using vb = vector<bool>;

using vll = vector<ll>;

using vs = vector<string>;

#define ALL(v) v.begin(), v.end()

#define SORT(v) sort(ALL(v))

#define SZ(v) int(v.size())



#ifdef DLOCAL

#include <local.h>

#else

#define deb(...);

#endif



void solve() {

    int n; cin >> n;

    string s; cin >> s;

    pii pos = make_pair(0, 0);

    map<pii, int> m;



    int turn = 1;

    pii ans = make_pair(0, INT32_MAX);

    for (int i = 0; i < n; ++i) {

        m[pos] = turn;

        if (s[i] == 'U') pos.first++;

        else if (s[i] == 'D') pos.first--;

        else if (s[i] == 'R') pos.second++;

        else if (s[i] == 'L') pos.second--;



        auto it = m.find(pos);



        deb(pos)

        if (it != m.end()) {

            deb(it->second, turn);



            if (turn - it->second < ans.second - ans.first) {

                ans.first = it->second;

                ans.second = turn;

            }

            

            it->second = turn;

        }



        ++turn;

    }



    if (ans.second == INT32_MAX) {

        cout << "-1\n";

    }

    else {

        cout << ans.first << " " << ans.second << "\n";

    }

}



int main() {

    ios::sync_with_stdio(0); cin.tie(0);



    //ifstream cin ("puzzle_name.in");

    //ofstream cout ("puzzle_name.out");



    int t; cin >> t;

    while (t--)

    {

        solve();

    }



    return 0;

}