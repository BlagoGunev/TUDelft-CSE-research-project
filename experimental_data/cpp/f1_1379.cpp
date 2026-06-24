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

#define all(a) a.begin(), a.end()

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



double GetTime() { return clock() / (double) CLOCKS_PER_SEC; }



/// Actual code starts here

const int N = 200005;





set<int> up[N], dw[N];

int n, m, q;



pair<int, int> get_seg(int layer) {

    int l = 0, r = m / 2;

    if (!up[layer].empty()) relaxmi(r, *up[layer].begin() - 1);

    if (!dw[layer].empty()) relaxma(l, *dw[layer].rbegin());

    return {l, r};

}



struct bebra {

    int li, ri;

    bool res;

};

bebra tr[4 * N];



bebra Merge(bebra a, bebra b) {

    bebra res = {0, m / 2, true};

    res.res &= a.res;

    res.res &= b.res;

    res.res &= (a.ri >= b.li);

    res.ri = min(a.ri, b.ri);

    res.li = max(a.li, b.li);

    return res;

}



void build(int v = 0, int L = 1, int R = N) {

    if (R - L == 1) {

        tr[v] = {0, m / 2, true};

        return;

    }

    int M = (L + R) / 2;

    build(v * 2 + 1, L, M);

    build(v * 2 + 2, M, R);

    tr[v] = Merge(tr[v * 2 + 1], tr[v * 2 + 2]);

}



void upd(int p, int li, int ri, int v = 0, int L = 1, int R = N) {

    if (R - L == 1) {

        tr[v] = {li, ri, li <= ri};

        return;

    }

    int M = (L + R) / 2;

    if (p < M) {

        upd(p, li, ri, v * 2 + 1, L, M);

    } else {

        upd(p, li, ri, v * 2 + 2, M, R);

    }

    tr[v] = Merge(tr[v * 2 + 1], tr[v * 2 + 2]);

}



void solve() {

    cin >> n >> m >> q;

    n *= 2, m *= 2;

    build();

    for (int _ = 0; _ < q; _++) {

        int x, y;

        cin >> x >> y;

        int layer = (x + 1) / 2;

        y = (y + 1) / 2;

        if (x % 2 == 0) {

            if (dw[layer].count(y)) {

                dw[layer].erase(y);

            } else {

                dw[layer].insert(y);

            }

        } else {

            if (up[layer].count(y)) {

                up[layer].erase(y);

            } else {

                up[layer].insert(y);

            }

        }

        pair<int, int> now = get_seg(layer);

        upd(layer, now.ff, now.ss);

        if (tr[0].res) {

            cout << "YES\n";

        } else {

            cout << "NO\n";

        }

    }

}



signed main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    int tt = 1;

    //cin >> tt;

    while (tt--)

        solve();

}