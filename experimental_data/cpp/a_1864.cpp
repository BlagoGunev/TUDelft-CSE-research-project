#include <bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
using grid = vector<vector<T>>;

using idata = vector<int>;
using igrid = grid<int>;
using bdata = vector<bool>;
using bgrid = vector<bdata>;

using di = pair<int, int>;
using vd = vector<di>;

template<typename T>
using graph = grid<T>;

template<typename A, typename B>
string to_string (pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template<typename T>
string to_string (T x) {
    string S = "[";
    bool first = true;
    for (const auto v : x) {
        if (!first) S += ", ";
        S += to_string(v);
        first = false;
    }
    S += "]";
    return S;
}
string to_string (string s) {
    return s;
}
string to_string (bool b) {
    return b ? "1" : "0";
}

const bool MULTITEST = true;

void solve () {
    int x, y, n;
    cin >> x >> y >> n;

    int del = 1;

    idata A(n);
    A[n - 1] = y;
    for (int i = n - 2; i >= 0; i --) {
        A[i] = A[i + 1] - del;
        del ++;
    }

    if (A[0] < x) {
        cout << "-1\n";
        return ;
    }

    A[0] = x;
    for (int u : A) cout << u << " ";
    cout << endl;
}

signed main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T = 1;
    if (MULTITEST) cin >> T;

    for (int t = 0; t < T; t ++)
        solve();
}