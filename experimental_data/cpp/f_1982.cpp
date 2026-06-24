#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
const char nl = '\n';
const char sp = ' ';
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const string OUT[2]{ "NO", "YES" };
const string out[2]{ "No", "Yes" };
#define all(a) a.begin(), a.end()
#define OK() cerr << "OK until line " << __LINE__ << nl
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ifstream fin(".in");
ofstream fout(".out");

auto start_time = chrono::high_resolution_clock::now();

double getTime() {
    auto end_time = chrono::high_resolution_clock::now();
    return chrono::duration<double>(end_time - start_time).count();
}

template<typename T>
int rand(T a, T b) { return uniform_int_distribution<T>(a, b)(rng); }

template<typename T1, typename T2>
bool ckmax(T1& a, T2 b) { return a < b ? a = b, true : false; }

template<typename T1, typename T2>
bool ckmin(T1& a, T2 b) { return a > b ? a = b, true : false; }

struct info {
    int mn, mx;
    friend info merge(info a, info b) {
        return info{ min(a.mn, b.mn), max(a.mx, b.mx) };
    }
};

const int nmax = 5e5;
int n, q;
int a[nmax + 5];
info t[4 * nmax + 5];
set<int> bad;

void build(int node, int l, int r) {
    if (l == r) {
        t[node] = info{ a[l], a[l] };
        return;
    }
    int mid = (l + r) / 2;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    t[node] = merge(t[node << 1], t[node << 1 | 1]);
}

void update(int node, int l, int r, int i, int x) {
    if (l == r) {
        t[node] = info{ x, x };
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid) {
        update(node << 1, l, mid, i, x);
    }
    else {
        update(node << 1 | 1, mid + 1, r, i, x);
    }
    t[node] = merge(t[node << 1], t[node << 1 | 1]);
}

info get(int node, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) {
        return info{ inf, -inf };
    }
    if (ql <= l && r <= qr) {
        return t[node];
    }
    int mid = (l + r) / 2;
    return merge(get(node << 1, l, mid, ql, qr), get(node << 1 | 1, mid + 1, r, ql, qr));
}

// prima pozitie > x
int find_pref(int pref, int x) {
    if (pref < 1) {
        return 1;
    }
    if (a[pref] <= x) {
        return pref + 1;
    }
    int st = 1, dr = pref, j;
    while (st <= dr) {
        int mid = (st + dr) / 2;
        if (a[mid] > x) {
            j = mid, dr = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    return j;
}

// ultima pozitie < x
int find_suff(int suff, int x) {
    if (suff > n) {
        return n;
    }
    if (a[suff] >= x) {
        return suff - 1;
    }
    int st = suff, dr = n, j;
    while (st <= dr) {
        int mid = (st + dr) / 2;
        if (a[mid] < x) {
            j = mid, st = mid + 1;
        }
        else {
            dr = mid - 1;
        }
    }
    return j;
}

void query() {
    if (bad.empty()) {
        cout << -1 << sp << -1 << nl;
        return;
    }
    int l = *bad.begin() - 1, r = *bad.rbegin();
    info aux = get(1, 1, n, l, r);
    cout << find_pref(l - 1, aux.mn) << sp << find_suff(r + 1, aux.mx) << nl;
}

void update() {
    int i, x;
    cin >> i >> x;
    if (i - 1 >= 1 && a[i] < a[i - 1]) {
        bad.erase(i);
    }
    if (i + 1 <= n && a[i + 1] < a[i]) {
        bad.erase(i + 1);
    }
    a[i] = x;
    if (i - 1 >= 1 && a[i] < a[i - 1]) {
        bad.insert(i);
    }
    if (i + 1 <= n && a[i + 1] < a[i]) {
        bad.insert(i + 1);
    }
    update(1, 1, n, i, x);
}

void testcase() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        if (a[i - 1] > a[i]) {
            bad.insert(i);
        }
    }
    build(1, 1, n);
    cin >> q;
    query();
    while (q--) {
        update();
        query();
    }
    bad.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; ++t) {
#ifdef _DEBUG
        cerr << "=== Subtask " << t << " ===" << nl;
#endif
        testcase();
#ifdef _DEBUG
        cerr << nl;
#endif
    }
}