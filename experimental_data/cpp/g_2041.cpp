#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define mp make_pair
#define pbc push_back
#define all(v) begin(v),end(v)
#define vin(v) for (auto &el : v) cin >> el

mt19937 rnd(179);

template<typename T1, typename T2>
inline void chkmin(T1 &x, const T2 &y) {
    if (y < x) {
        x = y;
    }
}


template<typename T1, typename T2>
inline void chkmax(T1 &x, const T2 &y) {
    if (y > x) {
        x = y;
    }
}

vector <int> fup, tin, used;
vector <int> is_p;
int cur_time = 0;

void dfs(int v, bool is_root, vector <vector <int>>& g) {
    used[v] = 1;
    tin[v] = fup[v] = cur_time++;
    bool flex = false;
    int cn = 0;

    for (int i : g[v]) {
        if (used[i]) {
            fup[v] = min(fup[v], tin[i]);
        } else {
            cn++;
            dfs(i, false, g);
            fup[v] = min(fup[v], fup[i]);
            if (fup[i] >= tin[v]) flex = true;
        }
    }

    if (is_root) {
        if (cn > 1) is_p[v] = 1;
    } else {
        if (flex) is_p[v] = 1;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector <array <int, 3>> all_q(q);
    vector <int> poses;
    for (int i = 0; i < q; ++i) {
        cin >> all_q[i][0] >> all_q[i][1] >> all_q[i][2]; --all_q[i][1]; --all_q[i][2]; --all_q[i][0];
        poses.push_back(max(0, all_q[i][0] - 1));
        poses.push_back(max(0, all_q[i][0] - 2));
        poses.push_back(all_q[i][0]);
        poses.push_back(min(all_q[i][0] + 1, n - 1));
        poses.push_back(min(all_q[i][0] + 2, n - 1));
    }

    sort(all(poses));
    poses.resize(unique(all(poses)) - poses.begin());
    int ln = poses.size();
    vector <vector <pair<int, int>>> events(ln);
    for (int i = 0; i < q; ++i) {
        int x = lower_bound(all(poses), all_q[i][0]) - poses.begin();
        int l = all_q[i][1];
        int r = all_q[i][2];
        events[x].emplace_back(l, 1);
        events[x].emplace_back(r + 1, -1);
    }

    vector <vector <pair <int, int>>> segs(ln);

    for (int i = 0; i < ln; ++i) {
        sort(all(events[i]));
        int cur_bal = 0;

        if (events[i].empty()) {
            segs[i].emplace_back(0,n - 1);
            // interesting_points[i].push_back(n - 1);
            continue;
        }

        if (events[i][0].first > 0) {
            segs[i].emplace_back(0, events[i][0].first - 1);
            // interesting_points[i].push_back(0);
            // interesting_points[i].push_back(events[i].first - 1);
        }

        for (int j = 0; j + 1 < events[i].size(); ++j) {
            cur_bal += events[i][j].second;

            if (cur_bal == 0 && events[i][j + 1].first != events[i][j].first) {
                segs[i].emplace_back(events[i][j].first, events[i][j + 1].first - 1);
                // interesting_points[i].push_back(events[i][j].first);
                // interesting_points[i].push_back(events[i][j + 1].first - 1);
            }
        }

        if (events[i].back().first < n) {
            segs[i].emplace_back(events[i].back().first, n - 1);
            // interesting_points[i].push_back(events[i].back().first);
            // interesting_points[i].push_back(n - 1);
        }
    }
    
    vector <vector <int>> points(ln);

    auto check_point = [&](int x, int y) {
        auto it = lower_bound(all(segs[x]), make_pair(y + 1, 0));
        if (it == segs[x].begin()) return false;
        it = prev(it);
        if (it->first <= y && it->second >= y) return true;
        return false;
    };

    for (int i = 0; i < ln; ++i) {
        for (int ind : vector <int>{i - 1, i, i + 1}) {
            if (ind < 0 || ind >= ln) continue;

            for (auto seg : segs[ind]) {
                if (check_point(i, seg.first)) points[i].push_back(seg.first);
                if (check_point(i, seg.second)) points[i].push_back(seg.second);
            }
        }
    }

    vector <vector <pair <int, int>>> wpoints(ln);

    for (int i = 0; i < ln; ++i) {
        sort(all(points[i]));
        points[i].resize(unique(all(points[i])) - points[i].begin());

        for (int j = 0; j < points[i].size(); ++j) {
            wpoints[i].emplace_back(points[i][j], 1);

            if (j + 1 < points[i].size() && points[i][j] + 1 != points[i][j + 1]) {
                int y = points[i][j] + 1;
                if (check_point(i, y)) {
                    wpoints[i].emplace_back(y, points[i][j + 1] - points[i][j] - 1);
                }
            }
        }
    }

    map <pair <int, int>, int> ind;
    int cur_ind = 0;
    for (int i = 0; i < ln; ++i) {
        for (auto j : wpoints[i]) {
            ind[{i, j.first}] = cur_ind++;
        }
    }
    vector <vector <int>> g(cur_ind);

    for (int i = 0; i < ln; ++i) {
        for (int j = 0; j + 1 < wpoints[i].size(); ++j) {
            if (wpoints[i][j + 1].first == wpoints[i][j].first + 1 || check_point(i, wpoints[i][j].first + 1)) {
            int i1 = ind[{i, wpoints[i][j].first}];
            int i2 = ind[{i, wpoints[i][j + 1].first}];
            g[i1].push_back(i2);
            g[i2].push_back(i1);
            }
        }

        for (auto j : wpoints[i]) {
            int mind = ind[{i, j.first}];
            if (i && ind.count({i - 1, j.first})) {
                int i1 = ind[{i - 1, j.first}];
                g[mind].push_back(i1);
                g[i1].push_back(mind);
            }
            if (i < ln - 1 && ind.count({i + 1, j.first})) {
                int i1 = ind[{i + 1, j.first}];
                g[mind].push_back(i1);
                g[i1].push_back(mind);
            }
        }
    }

    cur_time = 0;
    fup.assign(cur_ind, 0);
    tin.assign(cur_ind, 0);
    used.assign(cur_ind, 0);
    is_p.assign(cur_ind, 0);

    for (int i = 0; i < cur_ind; ++i) {
        if (!used[i]) {
            dfs(i, true, g);
        }
    }

    ll answer = 0;

    for (int i = 0; i < ln; ++i) {
        for (auto j : wpoints[i]) {
            if (is_p[ind[{i, j.first}]]) {
                answer += j.second;
            }
        }
    }

    cout << answer << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}