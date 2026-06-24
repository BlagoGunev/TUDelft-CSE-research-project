/**

 *  - Meet Brahmbhatt

 *  - Hard work always pays off

**/

#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

#define ff first

#define ss second

#define int long long

#define sz(x) (int)(x).size()



const long long INF = 4e18;

const int32_t M = 1e9 + 7;

const int32_t MM = 998244353;

const int32_t N = 5e6 + 10;

void solve() {

    int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {

        cin >> a[i];

    }



    int last = -1;

    vector<vector<int>> ID(N);

    for (int i = 0; i < n; i++) {

        ID[a[i]].push_back(i);

        int S = (int)ID[a[i]].size();

        if (S == 2) {

            if (last == -1) {

                last = a[i];

            } else {

                cout << "YES" << endl;

                cout << ID[last][0] + 1 << " " << ID[a[i]][0] + 1 << " " << ID[last][1] + 1 << " " << ID[a[i]][1] + 1 << endl;

                return;

            }

        } else if (S == 4) {

            cout << "YES" << endl;

            for (auto& x : ID[a[i]]) {

                cout << x + 1 << " ";

            }

            return;

        }

    }



    vector<pair<int, int>> v(N, { -1, -1});

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            int S = a[i] + a[j];

            if (v[S].ff == v[S].ss) {

                v[S] = {i, j};

            } else {

                if (set<int>({v[S].ff, v[S].ss, i, j}).size() == 4) {

                    cout << "YES" << endl;

                    cout << v[S].ff + 1 << " ";

                    cout << v[S].ss + 1 << " ";

                    cout << i + 1 << " ";

                    cout << j + 1 << " ";

                    return;

                }

            }

        }

    }

    cout << "NO" << endl;

}



signed main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(9);

    int tt = 1;

    // cin >> tt;

    while (tt--) solve();

    return 0;

}