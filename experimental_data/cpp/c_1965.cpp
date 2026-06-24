#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;

int n;
string s;

void Solve() {
    cin >> n >> s;
    int l = 0;
    int r = 0;
    int cc = 0;
    int dir = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            dir = -dir;
        }
        else {
            cc += dir;
            l = min(l, cc);
            r = max(r, cc);
        }
    }
    cout << r - l + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}