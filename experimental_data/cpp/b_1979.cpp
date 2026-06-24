#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long

using namespace std;

const int N = 2e5, mod = 998244353, INF = INT_MAX; //// !!!!!!!

void solve() {
    int x, y;
    cin >> x >> y;
    int z = x ^ y;
    for(int i = 0;;i++) {
        if((1 << i) & z) {
            cout << (1 << i) << "\n";
            return;
        }
    }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
}