#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define lb(v, x) (lower_bound(all(v), (x)) - (v).begin())
#define MAX(x, y) ((x) = max((x), (y)))
#define MIN(x, y) ((x) = min((x), (y)))
#define pi array<int, 2>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> way(n);
        for(int i = 1; i < n; ++i){
            int x, y; cin >> x >> y; --x, --y;
            way[x].push_back(y), way[y].push_back(x);
        }

        string s; cin >> s;
        array<int, 4> cnt = {0, 0, 0, 0};
        for(int i = 1; i < n; ++i){
            if(sz(way[i]) == 1){
                if(s[i] == '?') ++cnt[2];
                else ++cnt[s[i] - '0'];
            }
            else if(s[i] == '?') ++cnt[3];
        }

        if(s[0] != '?'){
            cout << cnt[s[0] - '0' ^ 1] + (cnt[2] + 1) / 2 << '\n';
        }
        else{
            if(cnt[0] < cnt[1]) swap(cnt[0], cnt[1]);
            if(cnt[0] > cnt[1] || cnt[3] % 2 == 0) cout << cnt[0] + cnt[2] / 2 << '\n';
            else cout << cnt[0] + (cnt[2] + 1) / 2 << '\n';
        }
    }

    return 0;
}