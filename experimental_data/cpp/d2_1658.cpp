#include <iostream>

#include <utility>

#include <vector>

#include <cmath>

#include <algorithm>

#include <unordered_set>

#include <set>

#include <queue>

#include <cmath>

#include <numeric>

#include <sstream>

#include <string>

#include <map>

#include <unordered_map>

#include <deque>

#include <iomanip>

#include <unordered_set>

#include <limits>

#include <list>

#include <bitset>

#include <random>

#include <cstring>

#include <cassert>

#include <chrono>

#include <array>



#define ff first

#define err(x) cerr << "["#x"]  " << (x) << "\n"

#define errv(x) {cerr << "["#x"]  ["; for (const auto& ___ : (x)) cerr << ___ << ", "; cerr << "]\n";}

#define errvn(x, n) {cerr << "["#x"]  ["; for (auto ___ = 0; ___ < (n); ++___) cerr << (x)[___] << ", "; cerr << "]\n";}

#define ss second

#define pb push_back

#define all(a) a.begin(),a.end()

typedef long long ll;

typedef long double ld;

using namespace std;

const int MOD = 1000000007;

mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());



template<typename T1, typename T2>

inline bool relaxmi(T1 &a, const T2 &b) {

    return a > b ? a = b, true : false;

}



template<typename T1, typename T2>

inline bool relaxma(T1 &a, const T2 &b) {

    return a < b ? a = b, true : false;

}



double GetTime() { return clock() / (double) CLOCKS_PER_SEC; };

/// Actual code starts here

const int N = (1 << 17), LG = 18;

int tr[N * LG][2];

int T = 1;



void add(int x) {

    int v = 0;

    for (int i = LG - 1; i >= 0; i--) {

        if (tr[v][1 & (x >> i)] == -1) tr[v][1 & (x >> i)] = T++;

        v = tr[v][1 & (x >> i)];

    }

}



int mx(int x) {

    int v = 0, res = 0;

    for (int i = LG - 1; i >= 0; i--) {

        if (1 & (x >> i)) {

            if (tr[v][0] != -1) v = tr[v][0], res += (1 << i);

            else v = tr[v][1];

        } else {

            if (tr[v][1] != -1) v = tr[v][1], res += (1 << i);

            else v = tr[v][0];

        }

    }

    return res;

}



int mn(int x) {

    int v = 0, res = 0;

    for (int i = LG - 1; i >= 0; i--) {

        if (1 & (x >> i)) {

            if (tr[v][1] != -1) v = tr[v][1];

            else v = tr[v][0], res += (1 << i);

        } else {

            if (tr[v][0] != -1) v = tr[v][0];

            else v = tr[v][1], res += (1 << i);

        }

    }

    return res;

}



void solve() {

    int l, r;

    cin >> l >> r;

    vector<int> v(r - l + 1);

    for (auto &i: v) cin >> i;

    int n = v.size();

    vector<int> candidat;

    for (int i = 0; i < n; i++) candidat.pb(v[i] ^ l);

    T = 1;

    for (int i = 0; i < n * LG + 5; i++)

        for (int j = 0; j < 2; j++)

            tr[i][j] = -1;

    for (auto i: v)

        add(i);

    for (auto i: candidat) {

        if (mx(i) == r && mn(i) == l) {

            cout << i << '\n';

            return;

        }

    }

    cout << "ABOBUS\n";

}



signed main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    int tt = 1;

    cin >> tt;

    while (tt--)

        solve();

}