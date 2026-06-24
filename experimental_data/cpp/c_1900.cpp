#include "bits/stdc++.h"
using namespace std;
void open_file(const string &file_name) {
    if (fopen((file_name + ".inp").c_str(), "r")) {
        freopen((file_name + ".inp").c_str(), "r", stdin);
        freopen((file_name + ".out").c_str(), "w", stdout);
    }
}
void init();
void solve();
bool multitest();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    clock_t TIME = clock();
    init();
    int TEST = 1;
    if (multitest()) cin >> TEST;
    while (TEST--) solve();
    cerr << "\nUsed: " << clock() - TIME << " ms\n\n";
}

bool multitest() {
    return 1;
}

int ac(int i, int op, string &s, vector<int> &l, vector<int> &r) {
    if (!l[i] && !r[i]) return op;

    int res = INT_MAX;

    if (l[i])
        res = min(res, ac(l[i], op + (s[i] != 'L'), s, l, r));
    
    if (r[i])
        res = min(res, ac(r[i], op + (s[i] != 'R'), s, l, r));

    return res;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = '$' + s;
    vector<int> l(n+1, 0), r(n+1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];

    cout << ac(1, 0, s, l, r) << "\n";
}

void init() {
}