#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
 
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
 
#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
 
using namespace std;

void solve() {
    int a[2], b[2];
    REP(i, 2) cin >> a[i];
    REP(i, 2) cin >> b[i];
    int res = 0;
    REP(i, 2) REP(j, 2) {
        int x = 0, y = 0;
        if (a[i] > b[j]) ++x;
        else if (a[i] < b[j]) ++y;
        if (a[1 - i] > b[1 - j]) ++x;
        else if (a[1 - i] < b[1 - j]) ++y;
        if (x > y) ++res;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}