#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#    pragma GCC optimize(2)
#endif
#define ll long long
#define db double
#define INF 0x3f3f3f
#define LNF 0x3f3f3f3f3f
#define ms(a, b) memset(a, b, sizeof(a))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b / gcd(a, b))
using namespace std;
const int maxn = 1e6 + 100;
const int MOD = 1e9 + 7;
const int N = 2e3 + 1;

int n;
int a[maxn];
int b[maxn];

inline void solve()
{
    cin >> n;
    int t = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] << 1 | 1;
    }

    cout<<"0 ";
    for (int i = 2; i <= n; i++) {
        int x = (a[i] | a[i - 1]) - a[i];
        a[i] ^= x;
        cout << x << " ";
    }
    cout << endl;
}

signed main(void)
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    double st = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();

#ifndef ONLINE_JUDGE
    cerr << "TIME: " << clock() - st << "ms" << endl;
#endif
    return 0;
}