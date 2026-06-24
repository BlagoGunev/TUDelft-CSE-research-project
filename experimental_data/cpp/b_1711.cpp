#include <iostream>

#include <fstream>

#include <vector>

#include <set>

#include <map>

#include <cassert>

#include <string>

#include <random>

#include <algorithm>

#include <unordered_map>

#define int long long

//#define double long double

using namespace std;





signed main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);



    int t;

    cin >> t;

    

    int n, m;

    int x, y;



    for (int trs = 0; trs < t; ++trs) {

        cin >> n >> m;

        vector<pair<int, int>> un_pa(n);

        for (int i = 0; i < n; ++i) {

            cin >> x;

            un_pa[i].first = x;

        }

        vector<pair<int, int>> reb(m);

        for (int i = 0; i < m; ++i) {

            cin >> x >> y;

            x--;

            y--;

            reb[i] = { x, y };

            un_pa[x].second++;

            un_pa[y].second++;

        }

        if (m % 2 == 0) {

            cout << 0 << '\n';

        }

        else {

            int ma = 1e9;

            for (int i = 0; i < m; ++i) {

                if (un_pa[reb[i].first].second % 2 == 1) {

                    ma = min(ma, un_pa[reb[i].first].first);

                }

                if (un_pa[reb[i].second].second % 2 == 1) {

                    ma = min(ma, un_pa[reb[i].second].first);

                }

                if (un_pa[reb[i].second].second % 2 == 0 && un_pa[reb[i].first].second % 2 == 0) {

                    ma = min(ma, un_pa[reb[i].second].first + un_pa[reb[i].first].first);

                }

            }

            cout << ma << '\n';

        }

    }



}