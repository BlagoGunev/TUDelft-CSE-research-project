#include <bits/stdc++.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327
#endif // M_PI
#define endl "\n"
#define S struct
#define X first
#define Y second
#define V vector
#ifndef __linux__
#define LLD "%I64d"
#else
#define LLD "%ll""d"
#endif
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int __i = 0; __i < (n); ++__i) cin >> a[__i];
#define GETM(a, n, m) for (int __i = 0; __i < (n); ++__i) for (int __j = 0; __j < m; ++__j) cin >> a[__i][__j];
#define PRINTM(a, n, m) for (int __i = 0; __i < (n); ++__i) { for (int __j = 0; __j < m; ++__j) cout << a[__i][__j] << " ";  cout << endl; };
#define PRINT(a, n) for (int __i = 0; __i < (n); ++__i) cout << a[__i] << " ";
#define IT(a) a.begin(), a.end()
#define SQR(x) (x) * (x)
#define CASE(a, s) cout << "Case #" << a << ": " << s << endl;
#define DEB(a) cout << #a << " = " << (a) << endl; cout.flush();
#define DEBA(a) for (auto __i: a) cout << __i << " "; cout << endl; cout.flush();
#define IFDEB(b, a) if (b) { cout << #a << " = " << (a) << endl; cout.flush(); }
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair <int, int> PII;
typedef pair <LL, LL> PLL;
const int MOD = 1000000007;
S Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;
S FAIL { FAIL () { cout << "CHANGE!!!" << endl;}};

bool next(vector <int> &v, int m)
{
    int j = v.size() - 1;
    ++v[j];
    while (j > 0 && v[j] == m) {
        v[j] = 0;
        --j;
        ++v[j];
    }
    if (v[j] == m) {
        return false;
    }
    return true;
}

int go(const vector <int> &v, int m)
{
    vector <int> used(m);
    FOR (i, 0, v.size()) {
        int place = v[i] / 2;
        int dir = v[i] % 2;
        int ok = 0;
        if (dir == 0) {
            FOR (i, place, m) {
                if (!used[i]) {
                    used[i] = 1;
                    ok = 1;
                    break;
                }
            }
        } else {
            FORR (i, place, -1) {
                if (!used[i]) {
                    used[i] = 1;
                    ok = 1;
                    break;
                }
            }
        }
        if (!ok) {
            return 0;
        }
    }
    //FOR (i, 0, v.size()) {
    //    cout << v[i] / 2 << (v[i] % 2 ? "B" : "F") << " ";
    //}
    //cout << endl;
    return 1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    swap(n, m);
    LL d = m - n;
    LL res = 2 * (d + 1);
    FOR (i, 0, n - 1) {
        res *= 2;
        res %= MOD;
    }
    FOR (i, 0, n - 1) {
        res *= (n + d + 1);
        res %= MOD;
    }
    cout << res;
/*    int n, m;
    cin >> n >> m;
    vector <int> v(n);
    int res = 0;
    do {
        res += go(v, m);
    } while (next(v, 2 * m));*/
//    cout << res;
}