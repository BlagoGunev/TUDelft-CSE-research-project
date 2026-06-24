#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;

template<class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree(int n, Info v = Info()) {
        build(vector<Info>(n, v));
    }
    SegmentTree(vector<Info> init) {
        build(init);
    }
    void build(vector<Info> init) {
        n = init.size();
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int x, int lx, int rx) {
            if (rx - lx == 1) {
                info[x] = init[lx];
                return;
            }
            int mid = (lx + rx) / 2;
            build(2 * x + 1, lx, mid);
            build(2 * x + 2, mid, rx);
            pull(x);
        };
        build(0, 0, n);
    }
    void pull(int x) {
        info[x] = info[2 * x + 1] + info[2 * x + 2];
    }
    void modify(int i, Info v) {
        modify(i, v, 0, 0, n);
    }
    void modify(int i, Info v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            info[x] = info[x] + v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            modify(i, v, 2 * x + 1, lx, mid);
        } else {
            modify(i, v, 2 * x + 2, mid, rx);
        }
        pull(x);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(l, r, 0, 0, n);
    }
    Info rangeQuery(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return Info();
        }
        if (l <= lx && rx <= r) {
            return info[x];
        }
        int mid = (lx + rx) / 2;
        return rangeQuery(l, r, 2 * x + 1, lx, mid) + rangeQuery(l, r, 2 * x + 2, mid, rx);
    }
};
int const inf = 1e4;
struct Info {
    short min;
    Info() : min(inf) {}
    Info(int min) : min(min) {}
};
Info operator+(Info a, Info b) {
    return Info(min(a.min, b.min));
}

void solve() {
    int n = 1e4, a = 1e3, b = 1e3;
    cin >> n >> a >> b;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = 1e3;
        cin >> v[i];
    }
    
    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + v[i];
    }
    
    int mn = *min_element(pre.begin(), pre.end());
    for (int i = 0; i <= n; ++i) {
        pre[i] -= mn;
    }
    
    vector<int> compress{0, int(1e7)};
    for (int i = 0; i <= n; ++i) {
        compress.push_back(pre[i]);
    }
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    auto upperMapping = [&](int x) {
        return lower_bound(compress.begin(), compress.end(), x) - compress.begin();
    };
    auto lowerMapping = [&](int x) {
        return upper_bound(compress.begin(), compress.end(), x) - compress.begin() - 1;
    };
    
    int const N = 1e7 + 1;
    int d = max(a, b);
    short dp[10001][1001][2][2] {};
    for (int i = 0; i <= d; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[n][i][0][j] = i;
            dp[n][i][1][j] = (j == 0 ? 0 : a);
        }
    }
    SegmentTree<Info> seg(compress.size());
    seg.modify(pre[n], Info(n));
    vector<int> preMin(N + 1), sufMin(N + 1), best(N, n);
    
    auto getDp = [&](int i, int A, int B) {
        int idx = n;
        if (pre[i] - (a - A) >= 0) {
            idx = min(idx, preMin[pre[i] - (a - A)]);
        }
        if (pre[i] + A < N) {
            idx = min(idx, sufMin[pre[i] + A]);
        }
        if (pre[i] + (b - B) < N) {
            idx = min(idx, sufMin[pre[i] + (b - B)]);
        }
        if (pre[i] - B >= 0) {
            idx = min(idx, preMin[pre[i] - B]);
        }
        A -= pre[idx] - pre[i];
        B += pre[idx] - pre[i];
        if (A > a) {
            int x = A - a;
            A -= x;
            B += x;
        } 
        if (A < 0) {
            int x = abs(A);
            A += x;
            B -= x;
        }
        if (B > b) {
            int x = B - b;
            B -= x;
            A += x;
        }
        if (B < 0) {
            int x = abs(B);
            B += x;
            A -= x;
        }
        int nvalue = B;
        int nplace = 1;
        int nother = (A == a);
        if (A != 0 && A != a) {
            nvalue = A;
            nplace = 0;
            nother = (B == b);
        }       
        return dp[idx][nvalue][nplace][nother];
    };
    
    for (int i = n - 1; i >= 0; --i) {
        int upper = min(N - 1, pre[i] + d);
        int lower = max(0, pre[i] - d);
        preMin[lower] = seg.rangeQuery(0, lowerMapping(lower)).min;
        for (int j = lower; j < pre[i]; ++j) {
            preMin[j + 1] = min(preMin[j], best[j]);
        }
        sufMin[upper] = seg.rangeQuery(upperMapping(upper), N).min;
        for (int j = upper - 1; j >= pre[i]; --j) {
            sufMin[j] = min(sufMin[j + 1], best[j]);
        }
        for (int value = 0; value <= d; ++value) {
            for (int place = 0; place < 2; ++place) {
                for (int other = 0; other < 2; ++other) {
                    int A = (place == 0 ? value : (other == 0 ? 0 : a));
                    int B = (place == 1 ? value : (other == 0 ? 0 : b));
                    if (A <= a && B <= b) {
                        dp[i][value][place][other] = getDp(i, A, B);
                    }
                }
            }
        }
        seg.modify(lowerMapping(pre[i]), Info(i));
        best[pre[i]] = min(best[pre[i]], i);
        if (i == 0) {
            for (int A = 0; A <= a; ++A) {
                for (int B = 0; B <= b; ++B) {
                    cout << getDp(i, A, B) << " \n"[B == b];            
                }
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
  
    int t = 1;
    //cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}