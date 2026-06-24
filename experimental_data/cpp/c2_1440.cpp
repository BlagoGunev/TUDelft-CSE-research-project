#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define SZ(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> Pii;
typedef pair <ll, int> Pli;
typedef unsigned long long ull;
const double eps = 1e-8;
const int mod = (int)(1e9) + 7;
const int inf = 0x7fffffff;
const int N = 150;

char s[N][N];
int _, n, m;
vector<Pii> v;
void gao(int i, int j) {
    s[i][j] = (s[i][j] == '0' ? '1' : '0');
    v.pb(mp(i, j));
    // printf("%d %d\n", i, j);
}
// 1 0
// (1) 1
void LD(int i, int j) {
    gao(i, j);
    gao(i - 1, j);
    gao(i, j + 1);
}
// 0 1
// 1 (1)
void RD(int i, int j) {
    gao(i, j);
    gao(i - 1, j);
    gao(i, j - 1);
}
// (1) 1
// 1 0
void LU(int i, int j) {
    gao(i, j);
    gao(i + 1, j);
    gao(i, j + 1);
}
// 1 (1)
// 0 1
void RU(int i, int j) {
    gao(i, j);
    gao(i, j - 1);
    gao(i + 1, j);
}
// 0 0
// (1) 1
void DD(int i, int j) {
    LU(i - 1, j);
    RU(i - 1, j + 1);
}

int main() {

    // freopen("in.in", "r", stdin);
    for (scanf("%d", &_); _; --_) {
        v.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
        }
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i][j] == '1') {
                    if (j == 1) LD(i + 1, j);
                    else RD(i + 1, j);
                }
            }
        } 
        for (int j = 1; j < m - 1; ++j) {
            if (s[n - 1][j] == '1' && s[n][j] == '1') {
                LU(n - 1, j);
            } else if (s[n - 1][j] == '0' && s[n][j] == '1') {
                RD(n, j + 1);
            } else if (s[n - 1][j] == '1' && s[n][j] == '0') {
                RU(n - 1, j + 1);
            }
        }
        int cnt = ((s[n - 1][m] == '1') + (s[n - 1][m - 1] == '1') + (s[n][m - 1] == '1') + (s[n][m] == '1'));
        if (cnt == 1) {
            if (s[n - 1][m - 1] == '1') {
                LU(n - 1, m - 1);
                RU(n - 1, m);
                LD(n, m - 1);
            } else if (s[n - 1][m] == '1') {
                RU(n - 1, m);
                LU(n - 1, m - 1);
                RD(n, m);
            } else if (s[n][m - 1] == '1') {
                LD(n, m - 1);
                LU(n - 1, m - 1);
                RD(n, m);
            } else if (s[n][m] == '1') {
                RD(n, m);
                RU(n - 1, m);
                LD(n, m - 1);
            }
        } else if (cnt == 2) {
            if (s[n][m] == s[n - 1][m - 1] && s[n][m] == '1') {
                LU(n - 1, m - 1);
                RD(n, m);
            } else if (s[n - 1][m] == s[n][m - 1] && s[n][m - 1] == '1') {
                RU(n - 1, m);
                LD(n, m - 1);   
            } else if (s[n][m] == s[n][m - 1] && s[n][m] == '1') {
                RU(n - 1, m);
                LU(n - 1, m - 1);
            } else if (s[n][m] == s[n - 1][m] && s[n][m] == '1') {
                LU(n - 1, m - 1);
                LD(n, m - 1);
            } else if (s[n - 1][m - 1] == s[n][m - 1] && s[n][m - 1] == '1') {
                RU(n - 1, m);
                RD(n, m);
            } else if (s[n - 1][m - 1] == s[n - 1][m] && s[n - 1][m] == '1') {
                LD(n, m - 1);
                RD(n, m);
            }
        } else if (cnt == 3) {
            if (s[n][m] == '0') {
                LU(n - 1, m - 1);
            } else if (s[n - 1][m - 1] == '0') {
                RD(n, m);
            } else if (s[n][m - 1] == '0') {
                RU(n - 1, m);
            } else {
                LD(n, m - 1);
            }
        } else if (cnt == 4) {
            LU(n - 1, m - 1);
            RU(n - 1, m);
            LD(n, m - 1);
            RD(n, m);
        }
        // puts("--------");
        // for (int i = 1; i <= n; ++i) {
        //     printf("%s\n", s[i] + 1);
        // }
        // puts("--------");
        int si = SZ(v);
        printf("%d\n", si / 3);
        for (int i = 0; i < si; i += 3) {
            printf("%d %d %d %d %d %d\n", v[i].fir, v[i].sec, v[i + 1].fir, v[i + 1].sec, v[i + 2].fir, v[i + 2].sec);
        }
    }

    return 0;
}