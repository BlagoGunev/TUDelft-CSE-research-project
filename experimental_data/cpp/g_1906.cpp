#include <iostream>
#include <vector>

using namespace std;

int pref(int x, int y) {
    if (x == 0 || y == 0) {
        return 0;
    }
    if (x <= y) {
        return pref(x, y % x) ^ ((y / x) % 2);
    } else {
        return pref(x % y, y) ^ ((x / y) % 2);
    }
}

int dp(int x, int y) {
    return pref(x, y) ^ pref(x - 1, y) ^ pref(x, y - 1) ^ pref(x - 1, y - 1);
}

int main() {
    int n;
    cin >> n;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        result ^= dp(r, c);
    }
    if (result) {
        cout << "FIRST" << endl;
    } else {
        cout << "SECOND" << endl;
    }
    return 0;
}