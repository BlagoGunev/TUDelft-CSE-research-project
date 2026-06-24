#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int64_t> b(7);
    for(int i = 0; i < 7; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(i == j) continue;
            for(int k = 0; k < 7; k++) {
                if(j == k || k == i) continue;
                int64_t a1 = b[i], a2 = b[j], a3 = b[k];
                vector<int64_t> xd = {a1, a2, a3, a1+a2, a1+a3, a2+a3, a1+a2+a3};
                sort(xd.begin(), xd.end());
                if(xd == b) {
                    cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
                    return;
                } 
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}