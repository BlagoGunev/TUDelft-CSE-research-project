#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define f first
#define s second
#define ever (;;)
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define debug(x) cout << #x << " : " << x << '\n'
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define debugV(x) cout << #x << " : "; for (auto y : (x)) cout << y << " "; cout << endl;

const int INF = 1e9 + 7;
const ll INFLL = 1e16 + 7;
const ld EPS = 1e-9;
const int MAXN = 2e5 + 7;

mt19937 myRand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 myRand64(chrono::steady_clock::now().time_since_epoch().count());

struct Edge {
    int to, num;
};

int color[MAXN];
vector<Edge> g[MAXN];
int ans;

void dfs(int v, int par = -1, int inCol = -1) {
    int curCol = 1;
    for (Edge& i : g[v]) {
        if (i.to == par)
            continue;
        if (curCol == inCol)
            curCol++;
        if (curCol > ans)
            curCol = ans;
        color[i.num] = curCol;
        dfs(i.to, v, curCol);
        curCol++;
    }
}

signed main(void) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, a, b;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        a--, b--;
        g[a].pb({b, i});
        g[b].pb({a, i});
    }
    vector<pii> deg(n);
    for (int i = 0; i < n; ++i)
        deg.pb(mp(sz(g[i]), i));
    sort(deg.rbegin(), deg.rend());
    ans = deg[k].f;
    cout << ans << '\n';
    dfs(deg[0].s);
    for (int i = 0; i < n - 1; ++i)
        cout << color[i] << ' ';
}