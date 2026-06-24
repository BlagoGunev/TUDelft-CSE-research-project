#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>
#include <cassert>
#include <bitset>

using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ft(a) __typeof((a).begin())
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define bitcount(n) __builtin_popcountll(n)

typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int N = 300000 + 7;
const int M = 20;
const int inf = 1000000007;
const long long linf = 1e18 + 7;
const double pi = acos(-1);
const double eps = 1e-9;
const bool multipleTest = 0;



int a[M][M];
int limit;
ll sum[30];
int mn[30];

int cnt = 0;

int getK(int x) {
    int ans = 0;
    while (x) {
        ++ans;
        x >>= 1;
    }
    return ans;
}


map<int, int> st;

inline ll calc(int u0, int v0, int u1, int v1, int k, ll added) {
    if (added + 1 > limit)
        return 0;

    ll ans = 0;
    int len = 1 << k;
    if (u0 == 0 && v0 == 0 && u1 == (1 << k) - 1 && v1 == u1) {
        int r = min(limit - added, 1ll * (u1 + 1));
        ans = ((1ll * r * (r + 1) / 2) % inf) << k;
        ans = (ans + 1ll * r * (u1 + 1) % inf * added) % inf;
        st[k]++;
        return ans;
    }

    if (u1 - u0 + 1 == len) {
        int r = min(limit - added, 1ll * len);
        ans = (((1ll * r * (r + 1) / 2)) % inf) * (v1 - v0 + 1);
        ans = (ans + 1ll * r * (v1 - v0 + 1) % inf * added) % inf;
        return ans;
    }

    if (v1 - v0 + 1 == len) {
        int r = min(limit - added, 1ll * len);
        ans = (((1ll * r * (r + 1) / 2)) % inf) * (u1 - u0 + 1);
        ans = (ans + 1ll * r * (u1 - u0 + 1) % inf * added) % inf;
        return ans;
    }

    if (k < 1) {
        for (int i = u0; i <= u1; ++i) {
            for (int j = v0; j <= v1; ++j) {
                if (a[i][j] + added <= limit) {
                    ans += (a[i][j] + added);
//                    ans %= inf;
                }
            }
        }
        return ans % inf;
    }
    int tmp = 1 << (k - 1);
    while (k > 1 && tmp > max(u1, v1)) {
        --k;
        tmp >>= 1;
    }

    int x = tmp;
    int y = tmp;

    int ss = 1 << k;

    if (u0 < x && v0 < y)
        ans = (ans + calc(u0, v0, min(u1, x - 1), min(v1, y - 1), k - 1, added));
    if (u1 >= x && v1 >= y)
        ans = (ans + calc(max(x, u0) - x, max(y, v0) - y, u1 - x, v1 - y, k - 1, added));
    if (u0 < x && v1 >= y) {
        ans = (ans + calc(u0, max(y, v0) - y, min(x - 1, u1), v1 - y, k - 1, added + tmp));
    }
    if (u1 >= x && v0 < y) {
        ans = (ans + calc(max(u0, x) - x, v0, u1 - x, min(v1, y - 1), k - 1, added + tmp));
    }
    ans %= inf;
    return ans;
}

void solve() {

    a[0][0] = 1;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == 0 && j == 0) continue;
            set<int> list;
            for (int t = 0; t < i; ++t) list.insert(a[t][j]);
            for (int t = 0; t < j; ++t) list.insert(a[i][t]);
            int cur = 1;
            for (int x : list) {
                if (cur == x) ++cur;
                else break;
            }
            a[i][j] = cur;
        }
    }

//    for (int i = 0; i <= 20; ++i) {
//        for (int j = 0; j <= 20; ++j) cout << a[i][j] << ' ';
//        puts("");
//    }

    sum[0] = 1; mn[0] = 1;
    for (int i = 1; i <= 30; ++i) {
        ll added = 1 << (i - 1);
        sum[i] = (4ll * sum[i - 1] + 2ll * added) % inf;
    }

    int q;
    cin >> q;
    while (q-- > 0) {
        int u0, v0, u1, v1;
        scanf("%d%d%d%d%d", &u0, &v0, &u1, &v1, &limit);
        u0--; v0--; u1--; v1--;
//        cout << u0 << ' ' << v0 << ' ' << u1 << ' ' << v1 << '\n';

        cout << calc(u0, v0, u1, v1, 30, 0) << '\n';
//        cout << cnt << '\n';
//        forIt(it, st) {
//            cout << it->first << ' ' << it->second << '\n';
//        }
//        ll ans = 0;
//        rep(i, u0, u1 + 1) rep(j, v0, v1 + 1) if (a[i][j] <= limit) {
//                    ans = (ans + a[i][j]) % inf;
//                }
//        cout << ans << '\n';
    }


}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    for(int i = 0; i < Test; ++i) {
//        printf("Case #%d: ", i + 1);
        solve();
    }
#ifdef _LOCAL_
    cout<<"\n" << 1.0 * clock() / CLOCKS_PER_SEC;
#endif
}