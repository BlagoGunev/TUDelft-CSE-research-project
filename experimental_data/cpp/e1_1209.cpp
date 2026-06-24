//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
//#define QWE "startup"
#define mp make_pair
#define pb push_back
#define sz(a) ((ll)a.size())
#define cina(a, n) {a.resize(n); for (auto &i_i: a) cin >> i_i;}
//#define couta(a) {for (auto i_i: a) cout << ((i_i == INF)? -1:i_i) << ' '; cout << '\n';}
#define couta(a) {for (auto i_i: a) cout << i_i << ' '; cout << "\n";}
#define cerra(a) {for (auto i_i: a) cerr << i_i << ' '; cerr << "\n";}
//#define res(_v, _size, _val) _v.resize(_size, _val);
//#define resc(_v, _size, _val) _v.clear(); _v.resize(_size, _val);
#define all(_a) (_a).begin(), (_a).end()
#define X first
#define Y second
#define int ll

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef int ll;
typedef long double ld;
typedef pair<int, int> par;
typedef vector<int>::iterator vit;

par operator +(const par &a, const par &b)
{
    return make_pair(a.first + b.first, a.second + b.second);
}
par operator -(const par &a, const par &b)
{
    return make_pair(a.first - b.first, a.second - b.second);
}
par operator *(const par &a, const int &b)
{
    return make_pair(a.first * b, a.second * b);
}
ostream& operator <<(ostream& os, const par &p)
{
    os << p.first << ' ' << p.second;
    return os;
}

const ld PI = acos(-1);
const int INF = (ll)(1e18) + 9;
//const int INF = 1024 * 1024 * 1024;
const ld EPS = 1e-15;
const ld SEPS = 1e-6;
//const ll M = 1e9 + 7;
//const ll M = 998244353ll;
//const int M = 1e + 7;
///const int N = 128 * 1024;
const int NN = 80050;
const int N = 1024 * 256;
//const int N = 4;
//const int N = 1024 * 16;
const int K = 4096;
const int L = 26;
//sconst int NN = 12 * 3600;
//const int N = 8;
const ull INTF = (ll)INT_MAX * INT_MAX;
const int LET = 26;
const int MUL = 1000;
const int F = 4;

int n, m;
vector <par> tr;
vector <vector <int>> a;

bool cmp(const par &a, const par &b)
{
    return a.X > b.X;
}

int rec(int c, vector <int> &z)
{
    if (c < min(n, 4ll))
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            z.pb(i);
            ans = max(ans, rec(c + 1, z));
            z.pop_back();
        }
        return ans;
    }
    int rez = 0;
    for (int j = 0; j < n; j++)//line
    {
        int mx = 0;
        for (int k = 0; k < min(n, m); k++)//column
            mx = max(mx, a[(z[k] + j) % n][tr[k].Y]);
        rez += mx;
    }
    return rez;
}

signed main()
{
    double start = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(13);
    //cout << fixed << setprecision(2);
    cerr << setprecision(10);
    srand(14313);
#ifdef MAKS
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
}
#else
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(QWE".in", "r", stdin);
    //freopen(QWE".out", "w", stdout);

}
#endif // MAKS

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        a.clear();
        tr.clear();
        tr.resize(m);
        a.resize(n, vector <int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                tr[j] = max(tr[j], make_pair(a[i][j], j));
            }
        }
        sort(all(tr), cmp);
        vector <int> vec;
        int ans = rec(0, vec);
        cout << ans << '\n';
    }

#ifdef MAKS
    cerr << endl << "Time " << (clock() - start)  * 1000.0 / CLOCKS_PER_SEC << "ms\n";
#endif // MAKS
    return 0;
}