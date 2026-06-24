#include<bits/stdc++.h>

using namespace std;



void solve() {

    int n; cin >> n;

    vector<pair<int, int>> ans;

    while(n > 2) {

        int s = ceil(sqrt(n));

        for(int i = s + 1; i < n; i ++) {

            ans.emplace_back(i, i + 1);

        }

        ans.emplace_back(n, s);

        ans.emplace_back(n, s);

        n = s;

    }

    cout << ans.size() << " \n";

    for(auto t : ans) cout << t.first << " " << t.second << "\n";

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;

    while(T--) solve();

    return 0;

}