// a.cpp by Skyly
#include <algorithm>
#include <iostream>
using namespace std;


typedef long long int64;

int main() {
    int64 x, y, m;
    cin >> x >> y >> m;
    if (x < y) swap(x, y);
    int64 ans = 0;
    if (x >= m || y >= m) {
        cout << 0 << endl;
        return 0;
    }
    if (x > 0LL && y < 0LL) {
        ans = (-y) / x; 
        y += ans * x;
    }
    while (x < m && y < m) {
        if (x < y) swap(x, y);
        if (x <= 0LL && y <= 0LL) break;
        y = x + y;
        ans++;
    }
    cout << ((x >= m || y >= m) ? ans : -1LL) << endl;


    return 0;
}