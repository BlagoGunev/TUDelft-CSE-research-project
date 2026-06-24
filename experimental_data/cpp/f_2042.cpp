// 线段树区间加区间求和 线段树二分左右>=给定sum的第一个位置
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int N = 7;
typedef array<array<ll, N>, N> Matrix;
Matrix ZERO, INF;
void gmax(ll &x, ll y) {
    if (y > x) x = y;
}
void write(Matrix c) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cout << c[x][y] << " \n"[y == N - 1];
        }
    }
}
Matrix operator+(Matrix a, Matrix b) {
    Matrix c = INF;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = j; k < N; k++) gmax(c[i][k], a[i][j] + b[j][k]);
        }
    }
    return c;
}

const int maxn = 2e5 + 10;
struct Node {
    int l, r;
    Matrix res;
};
struct SegmentTree {
    Node a[maxn * 4];
    void pushup(int i) {
        if (a[i].l == a[i].r) return;
        a[i].res = a[i * 2].res + a[i * 2 + 1].res;
    }
    void build(int i, int l, int r) {
        a[i].l = l, a[i].r = r;
        if (l >= r) return;
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
    }
    void update(int i, int x, const Matrix &w) {
        if (a[i].r < x || a[i].l > x) return;
        if (a[i].l >= x && a[i].r <= x) {
            a[i].res = w;
            return;
        }
        update(i * 2, x, w);
        update(i * 2 + 1, x, w);
        pushup(i);
    }
    Matrix query(int i, int l, int r) {
        if (a[i].l >= l && a[i].r <= r) {
            return a[i].res;
        }
        if (r <= a[i * 2].r) return query(i * 2, l, r);
        if (l >= a[i * 2 + 1].l) return query(i * 2 + 1, l, r);
        return query(i * 2, l, r) + query(i * 2 + 1, l, r);
    }
};
SegmentTree tri;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ZERO[i][j] = 0;
                INF[i][j] = -inf;
            }
        }
    }
    auto getMatrix = [&](int i) {
        Matrix c = INF;
        c[0][0] = 0;
        c[0][1] = a[i] + b[i];
        c[0][2] = a[i] + b[i] * 2;
        c[1][2] = a[i] + b[i];
        c[1][1] = a[i];
        c[2][3] = 0;
        c[3][3] = 0;
        c[2][4] = a[i] + b[i];
        c[2][5] = a[i] + b[i] * 2;
        c[3][4] = a[i] + b[i];
        c[3][5] = a[i] + b[i] * 2;
        c[4][4] = a[i];
        c[4][5] = a[i] + b[i];
        c[5][6] = 0;
        c[6][6] = 0;
        return c;
    };
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    tri.build(1, 1, n);
    for (int i = 1; i <= n; i++) tri.update(1, i, getMatrix(i));
    // for (int i = 1; i <= n; i++) {
    //     for (int j = i; j <= n; j++) {
    //         cout << "i=" << i << " j=" << j << endl;
    //         Matrix c = tri.query(1, i, j);
    //         write(c);
    //     }
    // }
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, x;
            cin >> i >> x;
            a[i] = x;
            tri.update(1, i, getMatrix(i));
        }
        if (op == 2) {
            int i, x;
            cin >> i >> x;
            b[i] = x;
            tri.update(1, i, getMatrix(i));
        }
        if (op == 3) {
            int l, r;
            cin >> l >> r;
            Matrix ans = tri.query(1, l, r);
            cout << max(ans[0][6], ans[0][5]) << "\n";
        }
    }
}