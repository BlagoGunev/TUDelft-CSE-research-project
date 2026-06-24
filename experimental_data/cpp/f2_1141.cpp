#include <bits/stdc++.h>

using namespace std;



const int N = 1505;

int sums[N];



void solve() {

    int n;

    cin >> n;

    for (int i = 1; i <= n; ++i) {

        cin >> sums[i];

        sums[i] += sums[i - 1];

    }

    

    unordered_map<int, vector<pair<int, int>>> pos;

    

    for (int i = 1; i <= n; ++i) {

        for (int j = i; j <= n; ++j) {

            pos[sums[j] - sums[i - 1]].emplace_back(i, j);

        }

    }

    

    int cnt = 0, val = 0;

    for (auto &[v, vec] : pos) {

        if (vec.size() < cnt) continue;

        sort(vec.begin(), vec.end(), [](auto &x, auto &y) { // se越靠前越好

            return x.second < y.second;

        });

        int last = -1, cur = 0;

        for (auto &[fi, se] : vec) {

            if (fi <= last) continue;

            ++cur;

            last = se;

        }

        if (cur > cnt) {

            cnt = cur;

            val = v;

        }

    }

    

    cout << cnt << '\n';

    int last = -1;

    for (auto &[fi, se] : pos[val]) {

        if (fi <= last) continue;

        cout << fi << ' ' << se << '\n';

        last = se;

    }

}



int main() {

    cin.tie(0)->sync_with_stdio(0);

    solve();

    return 0;

}