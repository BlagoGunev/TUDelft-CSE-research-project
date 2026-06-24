#include<bits/stdc++.h>
using namespace std;
bool shesadzlebelia(const vector<vector<int>>& a, const vector<vector<int>>& b, int n, int m) {
    vector<vector<int>> d(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = (b[i][j] - a[i][j] + 3) % 3;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (d[i][j] != 0) {
                int delta = d[i][j];
                d[i][j] = (d[i][j] - delta + 3) % 3;
                d[i + 1][j] = (d[i + 1][j] + delta) % 3;
                d[i][j + 1] = (d[i][j + 1] + delta) % 3;
                d[i + 1][j + 1] = (d[i + 1][j + 1] - delta + 3) % 3;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i][m - 1] != 0) return false;
    }
    for (int j = 0; j < m; j++) {
        if (d[n - 1][j] != 0) return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                a[i][j] = s[j] - '0';
            }
        }
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                b[i][j] = s[j] - '0';
            }
        }
        if (shesadzlebelia(a, b, n, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}