#include<bits/stdc++.h>

#define int long long

#define p pair<int, int>

#define endl '\n'

const int INF = 1000000001;



using namespace std;



vector<p> ans;



void make_deg(int l, int r) {

    if (r-l == 1) {

        return;

    }

    int m = (l+r)/2;

    make_deg(l, m), make_deg(m, r);

    for (int q = l; q < m; q++) {

        ans.push_back({q, q+m-l});

    }

}



signed main(){

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    int n, C = 14;

    cin >> n;

    vector<vector<int>> deg;

    for (int q = C-1; q > -1; q--) {

        if ((n >> q) & 1) {

            deg.emplace_back();

            for (int q1 = n-(1 << q); q1 < n; q1++) {

                deg.back().push_back(q1);

            }

            make_deg(n-(1 << q), n);

            n -= (1 << q);

        }

    }

    int w = deg.size();

    while (w > 2) {

        int w1 = deg[w-1].size(), w2 = deg[w-2].size();

        while (w1 < w2) {

            for (int q = 0; q < w1; q++) {

                ans.push_back({deg[w-1][q], deg[0].back()});

                deg[w-1].push_back(deg[0].back());

                deg[0].pop_back();

            }

            w1 *= 2;

        }

        for (int q = 0; q < w1; q++) {

            ans.push_back({deg[w-2][q], deg[w-1][q]});

            deg[w-2].push_back(deg[w-1][q]);

        }

        deg.pop_back(), w--;

    }

    cout << ans.size() << endl;

    for (p q : ans) {

        cout << q.first+1 << ' ' << q.second+1 << endl;

    }

    return 0;

}