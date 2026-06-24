//sorcerer_21
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define deb(...)  83
#endif
using ll=long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while (t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &ai: a) cin >> ai;

        const int MX = 2 * 100000 + 1;
        map<int, vector<int>> color_diff;
        vector<int> prev(MX, -1);

        for (int i = 0; i < n; i++) {
            color_diff[a[i]].push_back(i - prev[a[i]] - 1);
            prev[a[i]] = i;
        }
        for (auto& entry : color_diff) {
            entry.second.push_back(n - prev[entry.first] - 1);
            sort(entry.second.begin(), entry.second.end());
        }

        int res = INT_MAX;
        for (auto& entry : color_diff) {
            int x = max(entry.second.back() / 2, entry.second[entry.second.size() - 2]);
            res = min(res, x);
        }
        cout << res << endl;
    }
}