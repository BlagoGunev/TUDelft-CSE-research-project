#include <bits/stdc++.h>



typedef long long ll;

#define fast ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;



vector<vector<int>> g;

vector<int> value;





void sol() {

    int n, m;

    cin >> n >> m;

    int lcm = 720720;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            int x;

            cin >> x;

            if ((i + j)%2) {

                cout << lcm + x * x * x * x << ' ';

            } else

                cout << lcm << ' ';

        }

        cout << '\n';

    }

}



signed main() {

    fast;

    int t;

    t = 1;

    while (t--)

        sol();

    //map<int, vector<pair<int, int>>> fx;

    //for (int x = 1; x <= 1000; x++) {

    //    for (int y = 1; y <= 1000; y++) {

    //        if (x % y == x/y) {

    //            fx[x%y].push_back({x, y});

    //        }

    //    }

    //}

    //vector<pair<int, int>> st;

    //for (auto[u, v] : fx) {

    //    cout << "-------" << u << "-------\n";

    //    set<int> zx;

    //    st.push_back({v[0].first, v[0].second});

    //    for (auto [x, y] : v) {

    //        cout << x << ' ' << y << '\n';

    //    }

    //}

    //for (auto i : st) cout << i.first << ' ' << i.second << '\n';

}