#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ptc putchar
#define pb push_back
#define rer(i, l, r, a) R(i, l, r) read(a[i])
#define R(i, l, r) for (int i = l; i <= r; ++i)
#define debug puts("--------------------------------------------")
typedef long long ll;
typedef pair<int, int> PII;
namespace ZeroTwo 
{
    template <typename T>
    il void read(T &x) 
    { 
    x = 0; T f = 1; char ch;
    while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar(); x *= f;
    }
    template <typename T, typename ...L>
    il void read(T &x, L &...y) {read(x); read(y...);}
    template <typename T>
    il void write(T x) 
    {
        if (x < 0) ptc('-'), x = -x;
        if (x > 9) write(x / 10);
        ptc(x % 10 + '0');
    }
    template <typename T, typename ...L>
    il void write(T &x, L &...y) {write(x), ptc(' '); write(y...);}
}
using namespace ZeroTwo;
const int N = 2e5 + 5; 
int n, m, sx, sy, tx, ty;
string op;
void solve()
{
    cin >> n >> m >> sx >> sy >> tx >> ty >> op;
    if (sx == tx && sy == ty) return cout << 0 << endl, void();
    int d = 0, f = 1;
    if (op == "DR") d = -1, f = -1;
    else if (op == "DL") d = 1, f = -1;
    else if (op == "UL") d = -1, f = 1;
    else d = 1, f = 1;
    map <PII, int> vis;
    vis[{sx, sy}] = 1;
    int lx = 0, ly = 0;
    int a = d, b = f;
    if (sx == 1 && sy == 1) d = -1, f = -1;
    if (sx == 1 && sy == m) d = 1, f = -1;
    if (sx == n && sy == 1) d = 1, f = 1;
    if (sx == n && sy == m) d = -1, f = 1;
    int g = 0;
    if (a != d || b != f) ++g;
    R(p, 1, INT_MAX)
    {
        // cout << p << ' ' << sx << ' ' << sy << endl;
        int ex, ey;
        if (d == 1)
        {
            if (f == -1)
            {
                int t = min(sy - 1, n - sx);
                ex = sx + t, ey = sy - t;
            }
            else
            {
                int t = min(m - sy, sx - 1);
                ex = sx - t; ey = sy + t;
            }
        }
        else
        {
            if (f == -1)
            {
                int t = min(m - sy, n - sx);
                ex = sx + t, ey = sy + t;
            }
            else
            {
                int t = min(sx - 1, sy - 1); 
                ex = sx - t, ey = sy - t;
            }
        }
        // cout << p << ' ' << ex << ' ' << ey << ' ' << tx << ' ' << ty << ' ' << sx << ' ' << sy << endl;
        if (vis[{ex, ey}] >= 2) return puts("-1"), void();
        if (ex != sx && ey != sy)
        {
            if ((ex - tx) * (ty - sy) == (ey - ty) * (tx - sx) && (ex >= tx && tx >= sx || ex <= tx && tx <= sx) && (ey >= ty && ty >= sy || ey <= ty && ty <= sy)) return cout << p - 1 + g << endl, void();
            vis[{ex, ey}] += 1;
        }
        else
        {
            if (ex == lx && ey == ly) return puts("-1"), void();
        }
        lx = sx, ly = sy;
        sx = ex, sy = ey;
        if ((sx == 1 && sy == 1 || sx == 1 && sy == m || sx == n && sy == 1 || sx == n && sy == m)) f = -f;
        else 
        {
            // cout << f << ' ' <<d <<endl;
            d = -d;
            // if ((sx == 1 && sy == 1 || sx == 1 && sy == m || sx == n && sy == 1 || sx == n && sy == m)) d = -d;
            if (f < 0 && d == -1 && sx == n) f = -f;
            if (f > 0 && d == 1 && sx == 1) f = -f;   
            if (f < 0 && d == 1 && sx == n) f = - f;
            if (f > 0 && d == -1 && sx == 1) f = -f; 
            // cout << f << ' ' << d << endl;
        }
    }
}
signed main() 
{
    int T = 1; 
    read(T); 
    while (T--) solve();
    return 0;
}