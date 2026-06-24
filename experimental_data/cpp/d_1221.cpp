/**
    *Makacha
**/
#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read (T &x) { bool b = 0; char c; while (!isdigit (c = getchar()) && c != '-');
if (c == '-') c = getchar(), b = 1; x = c - 48; while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - 48; if (b) x = -x; }
template <typename T> inline void wrip(T x) { if (x > 9) wrip(x / 10); putchar(x%10 + 48); }
template <typename T> inline void write(T x) { if (x < 0) putchar('-'), x = -x; wrip(x); }
void reads(string &s) { char c; while (!isalpha(c = getchar())); s = c; while (isalpha(c = getchar())) s += c; }

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef long double ld;
const ll inf = 2e18;
const int N = 3e5 + 11;
typedef pair <int, int> ii;
int n;
ll res, a[N], b[N], f[N][4];
priority_queue <ii, vector <ii>, greater<ii> > Heap;
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    #ifdef makacha
        freopen("m.inp", "r", stdin);
        freopen("m.out", "w", stdout);
    #endif // makacha
    int ntest;
    read(ntest);
    while (ntest--) {
        read(n);
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            read(b[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2; j++) {
                f[i][j] = inf;
                for (int k = 0; k <= 2; k++)
                    if (a[i] + j != a[i - 1] + k)
                        f[i][j] = min(f[i][j], f[i - 1][k] + b[i] * j);
            }
        }
        res = inf;
        for (int i = 0; i <= 2; i++)
            res = min(res, f[n][i]);
        write(res);
        putchar('\n');
    }
}