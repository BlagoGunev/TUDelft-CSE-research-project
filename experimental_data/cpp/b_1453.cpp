#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define N 200005
#define M 100005
#else
#define fast 
#define N 105
#define M 105
#endif
#define forn(i, n) for(int i = 0; i < (n); i++)
#define forab(i, a, b) for(int i = (a); i <= (b); i++)
#define forba(i, b, a) for(int i = (b); i >= (a); i--)
#define INF 0x3f3f3f3f
#define mk(x) (1<<(x)) // be conscious if mask x exceeds int
#define sz(x) ((int)x.size())
#define upperdiv(a,b) (a/b + (a%b>0))
#define mp(a,b) make_pair(a, b)
#define endl '\n'
#define lowbit(x) (x&-x)

using namespace std;
typedef long long ll;
typedef double db;

template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

/** fast read **/
template <typename T>
inline void read(T &x) {
    x = 0; T fg = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') fg = -1;ch = getchar();}
    while (isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    x = fg * x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &... args) { read(x), read(args...); }
template <typename T>
inline void write(T x) {
    int len = 0; char c[21]; if (x < 0) putchar('-'), x = -x;
    do{++len; c[len] = x%10 + '0';} while (x /= 10);
    for (int i = len; i >= 1; i--) putchar(c[i]);
}
template <typename T, typename... Args>
inline void write(T x, Args ... args) { write(x), write(args...); }

ll a[N];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; read(n);
        for (int i = 1; i <= n; i++) {
            read(a[i]);
        }

        ll dis = max(abs(a[n] - a[n-1]), abs(a[2] - a[1]));
        ll ans = 0LL;
        for (int i = n-1; i >= 1; i--) {
            ll tmp = abs(a[i+1] - a[i]);
            ans += tmp;
            if (i-1 >= 1 && i+1 <= n) {
                ll tmpdis = abs(a[i+1] - a[i]) + abs(a[i] - a[i-1]) - abs(a[i+1] - a[i-1]);
                dis = max(dis, tmpdis);
            }
        }
        ans -= dis;
        cout << ans << endl;
    }
    return 0;
}
/*

*/