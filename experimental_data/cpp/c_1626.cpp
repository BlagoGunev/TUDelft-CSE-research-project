#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iterator>
#include <fstream>
#include <math.h>

#include <vector>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <list>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

#include <random>
#include <ctime>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef long double ld;

#define FOR(i, from, to) for (int i = from; i < to; i++)
#define ROF(i, from, to) for (int i = from; i > to; i--)

const double PI = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int INFS = 1000000001;
const ll LLINF = 9223372036854775807;
const ll M = 998244353;
const double EPS = 1e-8;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> k(n), h(n);
        FOR(i, 0, n) {
            cin >> k[i];
        }
        FOR(i, 0, n) {
            cin >> h[i];
        }
        int ans = 0, lst = h[n - 1], cr = h[n - 1];
        set<int> curr = {};
        curr.insert(h[n - 1]);
        ROF(i, n - 2, -1) {
            cr -= k[i + 1] - k[i];
            if (cr <= 0) {
                ans += (lst * (lst + 1)) / 2;
                lst = h[i];
                cr = h[i];
            } else {
                if (h[i] > cr) {
                    lst += h[i] - cr;
                    cr = h[i];
                }
            }
        }
        ans += (lst * (lst + 1)) / 2;
        cout << ans << "\n";
    }

    return 0;
}