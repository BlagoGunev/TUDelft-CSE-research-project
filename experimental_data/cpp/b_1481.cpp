#include<bits/stdc++.h>

using namespace std;



void solve() {

    int n, k; cin >> n >> k;

    vector<int> h(n+1);

    for(int i = 1; i <= n; i ++) cin >> h[i];

    if(k > 1e4) {

        cout << -1 << "\n";

        return;

    }

    int pos;

    for(int i = 1; i <= k; i ++) {

        pos = -1;

        for(int j = 1; j < n; j ++) {

            if(h[j] < h[j+1]) {

                h[j] ++; pos = j; break;

            }

        }

    }

    cout << pos << "\n";

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;

    while(T--) solve();

    return 0;

}