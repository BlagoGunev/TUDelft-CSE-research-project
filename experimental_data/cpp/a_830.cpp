#include <bits/stdc++.h>
#define ll long long
#define EPS 1e-9
using namespace std;

const int MAX = 2222;

int n, k, p;

int a[MAX], b[MAX];

bool used[MAX];

bool can(int m) {
    memset(used, 0, sizeof used);
    int id = 0, dd = 0;
    bool f = false;
    for (; dd < n && a[dd] <= p; ++dd) {
        while (id < k && (used[id] || abs(a[dd] - b[id]) + abs(b[id] - p) > m)) {
            ++id;
        }
        if (id == k) {
            if (a[dd] != p)
                return false;
            else
                f = true;
        } else
            used[id] = true;
    }
    id = k - 1;
    for (dd = n - 1; dd >= 0 && a[dd] > p - f; --dd) {
        while (id >= 0 && (used[id] || abs(a[dd] - b[id]) + abs(b[id] - p) > m)) {
            --id;
        }
        if (id == -1) {
            return false;
        }
        used[id] = true;
    }
    return true;
}

int bin(int l, int r) {
    while (r - l > 1) {
        int mid = ((ll)l + r) / 2;
        if (can(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main() {
#ifdef LOCAL
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + k);
    cout << bin(-1, 2e9 + 10);
    return 0;
}