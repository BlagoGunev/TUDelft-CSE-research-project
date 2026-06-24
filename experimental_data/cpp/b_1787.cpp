#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> f(int n) {
    vector<pair<int, int>> ans;
    for(int i = 2; i * i <= n; i++) {
        if(n % i)
            continue;

        int c = 0;
        while(n % i == 0) {
            n /= i;
            c++;
        }

        ans.push_back({i, c});
    }

    if(n > 1)
        ans.push_back({n, 1});

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(32, 1);
        for(auto [x, y]: f(n))
            for(int i = 0; i < y; i++)
                v[i] *= x;

        int ans = 0;
        for(int i: v)
            if(i > 1)
                ans += i;
        cout << ans << endl;
    }

    return 0;
}