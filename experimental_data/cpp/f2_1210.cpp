#ifndef HOME
#pragma GCC optimize "-O3"
#endif

#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

int mul(int x, int y) {
    return (1ll * x * y) % MOD;
}

void add(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int pw(int x, int y) {
    if (y == 0) {
        return 1;
    } else if (y % 2 == 0) {
        return pw(mul(x, x), y / 2);
    } else {
        return mul(x, pw(x, y - 1));
    }
}

int inv(int x) {
    return pw(x, MOD - 2);
}

int neg(int x) {
    return (MOD + 1 - x) % MOD;
}

const int MX = 10;

int n;
int p[MX][MX];
int pm[MX][1 << MX];

map<vector<int>, int> dp[MX];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
            p[i][j] = mul(p[i][j], inv(100));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            pm[i][j] = 1;
            for (int k = 0; k < n; k++) {
                if (j & (1 << k)) {
                    pm[i][j] = mul(pm[i][j], p[i][k]);
                } else {
                    pm[i][j] = mul(pm[i][j], neg(p[i][k]));
                }
            }
        }
    }

    vector<pair<vector<int>, int> > states;
    map<vector<int>, int> nextStates;
    vector<int> nmts;
    states.emplace_back(vector<int>({0}), 1);
    for (int pos = 0; pos < n; pos++) {
        nextStates.clear();
        for (int mask = 0; mask < (1 << n); mask++) {
            for (auto e : states) {
                vector<int> mts = e.first;
                int p = e.second;
                nmts.clear();
                for (int mt : mts) {
                    for (int v = 0; v < n; v++) {
                        if ((mask & (1 << v)) && !(mt & (1 << v))) {
                            nmts.push_back(mt | (1 << v));
                        }
                    }
                }
                sort(nmts.begin(), nmts.end());
                nmts.resize(unique(nmts.begin(), nmts.end()) - nmts.begin());
                if (!nmts.empty()) {
                    add(nextStates[nmts], mul(p, pm[pos][mask]));
                }
            }
        }
        states.clear();
        for (auto e : nextStates) {
            states.emplace_back(e);
        }
    }
    int ans = 0;
    for (auto e : states) {
        add(ans, e.second);
    }
    cout << ans << "\n";
    return 0;
}