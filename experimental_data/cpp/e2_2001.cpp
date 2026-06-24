#include <bits/stdc++.h>
#define pb push_back
#define sz(a) ((int)a.size())
#define re return
#define all(a) a.begin(), a.end()
#define rept(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, a) rept(i, 0, a)
#define vi vector<int>
#define pii pair<int, int>
#define F first
#define S second
#define de(x) cout << #x << "=" << x << "\n";
#define int long long
#define il inline
#define db double
#define ld long db
using namespace std;
const int INF = 1000000000000000000;
template <typename T>
inline void Mx(T &a, T b) { a = max(a, b); }
template <typename T>
inline void Mi(T &a, T b) { a = min(a, b); }
void FILEIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
const int N = 505;
int n, k, p;
int f[N][N], g[N][N], h[N];
int ff[N][N], gg[N][N], hh[N];
void run()
{
    cin >> n >> k >> p;
    rep(i, k + 1) rep(j, k + 2) f[i][j] = ff[i][j] = g[i][j] = gg[i][j] = 0;
    rep(i, k + 1) h[i] = hh[i] = 0;
    rep(i, k + 1) rep(j, k + 2) f[i][j] = g[i][j] = 1;
    rep(i, k + 1) h[i] = 1;
    rep(i, n - 1)
    {
        rep(j, k + 1) rep(l, k + 1) if (j + l <= k)
        {
            if (j < l)
            {
                (ff[j + l][l + 1] += h[j] * (f[l][k + 1] - f[l][j + 1])) %= p;
                (ff[j + l][l + 1] += g[j][k + 1] * g[l][j]) %= p;
            }
            if (j > l)
            {
                (ff[j + l][j + 1] += (f[j][k + 1] - f[j][l + 1]) * h[l]) %= p;
                (ff[j + l][j + 1] += g[j][l] * g[l][k + 1]) %= p;
            }
            if (j < l)
                (gg[j + l][l + 1] += h[j] * g[l][k + 1]) %= p;
            if (j > l)
                (gg[j + l][j + 1] += g[j][k + 1] * h[l]) %= p;
            (hh[j + l] += h[j] * h[l]) %= p;
        }
        rep(j, k) rep(l, k + 2)(ff[j + 1][l] += ff[j][l]) %= p;
        rep(j, k + 1) rep(l, k + 1)(ff[j][l + 1] += ff[j][l]) %= p;
        rep(j, k) rep(l, k + 2)(gg[j + 1][l] += gg[j][l]) %= p;
        rep(j, k + 1) rep(l, k + 1)(gg[j][l + 1] += gg[j][l]) %= p;
        rep(j, k)(hh[j + 1] += hh[j]) %= p;
        rep(j, k + 1) rep(l, k + 2) f[j][l] = ff[j][l], ff[j][l] = 0;
        rep(j, k + 1) rep(l, k + 2) g[j][l] = gg[j][l], gg[j][l] = 0;
        rep(j, k + 1) h[j] = hh[j], hh[j] = 0;
        //		rep(j,k+1)rep(l,k+2)if(f[j][l])cout<<"f "<<i+2<<" "<<j<<" "<<l-1<<" "<<f[j][l]<<"\n";
        //		rep(j,k+1)rep(l,k+2)if(g[j][l])cout<<"g "<<i+2<<" "<<j<<" "<<l-1<<" "<<g[j][l]<<"\n";
        //		rep(j,k+1)if(h[j])cout<<"h "<<i+2<<" "<<j<<" "<<h[j]<<"\n";
    }
    cout << (f[k][k + 1] % p + p) % p << "\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        run();
    re 0;
}