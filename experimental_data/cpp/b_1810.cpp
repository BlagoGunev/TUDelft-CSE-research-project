#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <algorithm>
#include <array>
#include <set>
#include <deque>
#include <cmath>
#include <map>
#include <bitset>
#include <list>
#include <fstream>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

const int INF = 1e9 + 7;
const ld EPS = 1e-9;

void solve() {
    int n;
    cin >> n;
    if (!(n & 1)) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    while (n > 1) {
        if ((n / 2) & 1) {
            n = n / 2;
            ans.push_back(2);
        } else {
            n = n / 2 + 1;
            ans.push_back(1);
        }
    }
    cout << ans.size() << '\n';
    reverse(all(ans));
    for (auto i : ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}