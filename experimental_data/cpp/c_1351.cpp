#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        set<tuple<int, int, int, int>> h;
        int x = 0, y = 0, z = 0;
        for (auto &it : s) {
            int nx = x, ny = y;
            if (it == 'N') ny++;
            if (it == 'S') ny--;
            if (it == 'E') nx++;
            if (it == 'W') nx--;
            if (h.count({x, y, nx, ny})) {
                z += 1;
            } else {
                z += 5;
                h.insert({x, y, nx, ny});
                h.insert({nx, ny, x, y});
            }
            x = nx;
            y = ny;
        }
        cout << z << endl;
    }
    return 0;
}