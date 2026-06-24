#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

template <typename T> inline void read(T &F) {

    int R = 1; F = 0; char CH = getchar();

    for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;

    for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;

    F *= R;

}

inline void file(string str) {

    freopen((str + ".in").c_str(), "r", stdin);

    freopen((str + ".out").c_str(), "w", stdout);

}

const int N = 5e3 + 10, B = 256, M = 1e5 + 10;

vector<pair<int, int> > R; int cnt, id[N], n, q, ans[M];

struct Info {

    int v[B + 10], len, g[B + 10][B + 10];

    void init(int x) {

        len = 1; v[1] = g[1][1] = x;

    }

    pair<int, int> calc(int l, int r) {

        const int ll = lower_bound(v + 1, v + len + 1, l) - v;

        const int rr = upper_bound(v + 1, v + len + 1, r) - v - 1;

        return make_pair(ll, rr);

    }

    friend Info operator + (Info &&A, Info &&B) {

        Info C; C.len = A.len + B.len;

        for(int i = 1; i <= A.len; i++) C.v[i] = A.v[i];

        for(int i = 1; i <= B.len; i++) C.v[A.len + i] = B.v[i];

        sort(C.v + 1, C.v + C.len + 1);

        for(int i = 1; i <= C.len; i++)

            for(int j = i; j <= C.len; j++) {

                auto x = A.calc(C.v[i], C.v[j]), y = B.calc(C.v[i], C.v[j]);

                if(x.first > x.second) {

                    C.g[i][j] = B.g[y.first][y.second]; continue;

                }

                if(y.first > y.second) {

                    C.g[i][j] = A.g[x.first][x.second]; continue;

                }

                R.emplace_back(A.g[x.first][x.second], B.g[y.first][y.second]);

                C.g[i][j] = ++cnt;

            }

        return C;

    }

}G[B];

Info build(int l, int r) {

    if(l == r) {

        Info T; T.init(id[l]); return T;

    }

    int mid = (l + r) >> 1;

    return build(l, mid) + build(mid + 1, r);

}

int solve(int l, int r) {

    int x = 0;

    for(int i = 1; i <= (n - 1) / B + 1; i++) {

        auto j = G[i].calc(l, r);

        if(j.first > j.second) continue;

        if(!x) x = G[i].g[j.first][j.second];

        else R.emplace_back(x, G[i].g[j.first][j.second]), x = ++cnt;

    }

    return x;

}

int main() {

    //file("");

    read(n), read(q); cnt = n;

    for(int i = 1; i <= n; i++) {

        int x; read(x); id[x] = i;

    }

    for(int i = 1; i <= n; i += B)

        G[(i - 1) / B + 1] = build(i, min(i + B - 1, n));

    for(int i = 1; i <= q; i++) {

        int l, r; read(l), read(r);

        ans[i] = solve(l, r);

    }

    cout << cnt << '\n';

    for(auto i : R) cout << i.first << ' ' << i.second << '\n';

    for(int i = 1; i <= q; i++)

        cout << ans[i] << ' ';

    puts("");

    #ifdef _MagicDuck

        fprintf(stderr, "# Time: %.3lf s", (double)clock() / CLOCKS_PER_SEC);

    #endif

    return 0;

}