#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    cout << 1 << " " << n << " ";
    int len = 0;
    int f = 0;
    while (f < s.size() && s[f] == '1') {
        f += 1;
    }
    len = max<int>(1, n - f);
    string mx(n, '0');
    int lx = 1, rx = n;
    for (int k = len - 1; k < n; ++k) {
        string now = s.substr(k - len + 1, len);
        string res(s);
        for (int i = 0; i < now.size(); ++i) {
            if (now.rbegin()[i] == '1') {
                res.rbegin()[i] ^= '0' ^ '1';
            }
        }
        if (mx < res) {
            mx = res;
            lx = k - len + 2, rx = k + 1;
        }
    }
    cout << lx << " " << rx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    cin >> test;

    while (test--) {
        solve();
    }

    return 0;
}