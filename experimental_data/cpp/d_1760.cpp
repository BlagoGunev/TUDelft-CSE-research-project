#include <algorithm>

#include <iostream>

#include <iomanip>

#include <cmath>

#include <vector>

#include <set>

#include <map>

#include <string>

#include <cassert>

#include <numeric>

using namespace std;



#define int long long

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



const long long INF = 1e18 + 7;

const double EPS = 1e-6;

const int N = 310;

const int MOD = 1e9 + 7;



int dx[] = {-1, 0, 1, 0};

int dy[] = {0, 1, 0, -1};



void solve() {

    int n;

    cin >> n;

    vector<int> a;

    for (int i = 0 ; i < n; ++i) {

        int x;

        cin >> x;

        if (a.size() == 0 || a.back() != x) {

            a.emplace_back(x);

        }

    }

    n = a.size();

    int cnt = 0;

    if (n == 1) {

        cout << "YES\n";

        return;

    }

    if (a[0] < a[1]) {

        ++cnt;

        if (n == 2) {

            cout << "YES\n";

            return;

        }

    }

    if (a[n - 2] > a[n - 1]) {

        ++cnt;

    }

    for (int i = 1; i < n - 1; ++i) {

        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {

            ++cnt;

        }

    }

    cout << (cnt == 1? "YES\n": "NO\n");

}



int32_t main() {

    IOS;



    int t;

    cin >> t;

    while (t--) {

        solve();

    }

    return 0;

}