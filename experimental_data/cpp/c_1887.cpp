#include <bits/stdc++.h>
#define int long long

using namespace std;

struct oper{
    int l, r, x;
};

struct event{
    int x, t, i;
    bool operator<(const event& a) {
        return x < a.x || (x == a.x && t < a.t);
    }
};

void solve() {
    int n; cin >> n;
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int q;
    cin >> q;
    vector <oper> op(q);
    for (int i = 0; i < q; ++i) {
        cin >> op[i].l >> op[i].r >> op[i].x;
        op[i].l--; op[i].r--;
    }
    vector <int> can(q + 1, 1);
    int cnt = q + 1;
    while (cnt > 1) {
        int pr = -1;
        for (int i = 0; i <= q; ++i) {
            if (can[i]) {
                if (pr == -1) {
                    pr = i;
                } else {
                    vector <event> ev;
                    for (int j = pr; j < i; ++j) {
                        ev.push_back({op[j].l, -1, j});
                        ev.push_back({op[j].r + 1, 1, j});
                    }
                    sort(ev.begin(), ev.end());
                    int delt = 0;
                    set <int> open;
                    for (int j = 0; j < ev.size(); ++j) {
                        if (ev[j].t == -1) {
                            open.insert(ev[j].i);
                            delt += op[ev[j].i].x;
                        } else {
                            open.erase(ev[j].i);
                            delt -= op[ev[j].i].x;
                        }
                        if (j + 1 == ev.size() || ev[j + 1].x > ev[j].x) {
                            if (delt > 0) {
                                if (can[i]) {
                                    cnt--;
                                }
                                can[i] = 0;
                                break;
                            } else if (delt < 0) {
                                if (can[pr]) {
                                    cnt--;
                                }
                                can[pr] = 0;
                                break;
                            }
                        }
                    }
                    if (can[pr] && can[i]) {
                        can[pr] = 0;
                        cnt--;
                    }
                    pr = i;
                }
            }
        }
    }

    vector <int> dt(n + 1, 0);
    int ind = 1;
    while (!can[ind - 1]) {
        dt[op[ind - 1].l] += op[ind - 1].x;
        dt[op[ind - 1].r + 1] -= op[ind - 1].x;
        ind++;
    }
    int delt = 0;
    for (int i = 0; i < n; ++i) {
        delt += dt[i];
        b[i] += delt;
        cout << b[i] << " ";
    }
    cout << "\n";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}