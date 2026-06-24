#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define tc        \
    long long _t; \
    cin >> _t;    \
    while (_t--)
typedef long long ll;
#define int long long

// type name short forms
#define vvll vector<vector<long long>>
#define vll vector<long long>
#define pll pair<long long, long long>

#define loop(_k) for (int _q = 0; _q < _k; _q++)
#define arrinp(_a, _n)                      \
    _a.resize(_n);                          \
    for (long long _l = 0; _l < _n; _l++) { \
        cin >> _a[_l];                      \
    }

#define debug(x) cerr << (#x) << " " << (x) << endl

#define mod (ll)(1e9 + 7)

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, M;
    cin >> N >> M;
    vector<pll> R(10, {-1, -1});
    vector<pll> B(10, {-1, -1});
    vector<pll> RG;
    vector<pll> BG;
    pll Q = {(N + 1) / 2, (M + 1) / 2};
    pll q_holder = {0, 0};
    ll fin_r = 0, fin_b = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            string s;
            cin >> s;
            if (s == "..") continue;
            if (s[0] == '.' && s[1] == 'Q') {
                Q.first = i;
                Q.second = j;
            } else if (s[0] == 'R') {
                if (s[1] == 'G')
                    RG.push_back({i, j});
                else
                    R[s[1] - '0'] = {i, j};
            } else if (s[0] == 'B') {
                if (s[1] == 'G')
                    BG.push_back({i, j});
                else
                    B[s[1] - '0'] = {i, j};
            }
        }
    }
    ll T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string p, a;
        cin >> p >> a;
        if (p[0] == 'R') {
            if (a[0] == 'C') {
                cin >> a;
                if (a == ".Q") {
                    q_holder = {1, p[1] - '0'};
                    continue;
                }
                break;
            } else if (a[0] == 'T') {
                Q = pll(R[p[1] - '0']);
                for (int l = 0; l < BG.size(); l++) {
                    if (Q == BG[l]) {
                        cout << t << " RED GOAL" << endl;
                        fin_r++;
                        break;
                    }
                }
                for (int l = 0; l < RG.size(); l++) {
                    if (Q == RG[l]) {
                        cout << t << " BLUE GOAL" << endl;
                        fin_b++;
                        break;
                    }
                }
            } else if (a[0] == 'U') {
                R[p[1] - '0'].first--;
            } else if (a[0] == 'D') {
                R[p[1] - '0'].first++;
            } else if (a[0] == 'L') {
                R[p[1] - '0'].second--;
            } else if (a[0] == 'R') {
                R[p[1] - '0'].second++;
            }

        } else if (p[0] == 'B') {
            if (a[0] == 'C') {
                cin >> a;
                if (a == ".Q") {
                    q_holder = {2, p[1] - '0'};
                    continue;
                }
                break;
            } else if (a[0] == 'T') {
                Q = pll(B[p[1] - '0']);
                for (int l = 0; l < RG.size(); l++) {
                    if (Q == RG[l]) {
                        cout << t << " BLUE GOAL" << endl;
                        fin_b++;
                        break;
                    }
                }
                for (int l = 0; l < BG.size(); l++) {
                    if (Q == BG[l]) {
                        cout << t << " RED GOAL" << endl;
                        fin_r++;
                        break;
                    }
                }
            } else if (a[0] == 'U') {
                B[p[1] - '0'].first--;
            } else if (a[0] == 'D') {
                B[p[1] - '0'].first++;
            } else if (a[0] == 'L') {
                B[p[1] - '0'].second--;
            } else if (a[0] == 'R') {
                B[p[1] - '0'].second++;
            }
        }
    }
    cout << "FINAL SCORE: " << fin_r << ' ' << fin_b << endl;
}