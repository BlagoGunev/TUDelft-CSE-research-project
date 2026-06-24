#include "bits/stdc++.h"

using namespace std;

int main() {
    int T = 1;
//    cin >> T;
    while (T--) {
        vector<int> p(1e5 + 2);
        p[0] = 1;
        for (int i = 1; i < 1e5 + 2; i++) {
            p[i] = p[i - 1] * 2;
            p[i] %= (int) (1e9 + 7);
        }
        int t;
        cin >> t;
        vector<int> n(t), k(n);
        for (int i = 0; i < t; i++) {
            cin >> n[i];
        }
        for (int i = 0; i < t; i++) {
            cin >> k[i];
        }
        int i = 0;
        while (i < t) {
            cout << p[k[i]] << '\n';
            i++;
        }
    }
    return 0;
}