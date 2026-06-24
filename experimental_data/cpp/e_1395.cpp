#include <bits/stdc++.h>

#define FOR(i,x,n) 	for(int i=x; i<n; i++)
#define F0R(i,n) 	FOR(i,0,n)
#define ROF(i,x,n) 	for(int i=n-1; i>=x; i--)
#define R0F(i,n) 	ROF(i,0,n)

#define WTF 		cout << "WTF" << endl

#define IOS 		ios::sync_with_stdio(false); cin.tie(0)
#define F 			first
#define S	 		second
#define pb 			push_back

#define ALL(x) 		x.begin(), x.end()
#define RALL(x) 	x.rbegin(), x.rend()

using namespace std;
typedef long long 		LL;

typedef pair<int, int> 	PII;
typedef pair<LL, LL> 	PLL;

typedef vector<int> 	VI;
typedef vector<LL> 		VLL;
typedef vector<PII> 	VPII;
typedef vector<PLL> 	VPLL;

const int N = 2e5 + 7;
const int K = 10 + 2;
const int ALPHA = 27;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int LOG = 22;

int n, m, k, ans;
int ok[K][K][K][K];
bool usable[K][K];
bitset<N> fix[K][K];
VPII adj[N];
VI keep;

void init() {
    cin >> n >> m >> k;

    F0R(i, m) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].pb({v, w});
    }

    F0R(i, n) sort(ALL(adj[i]), [](const PII &a, const PII &b) {return a.S < b.S;});
}

inline void makeBit(int deg, int id) {
    usable[deg][id] = 1;

    F0R(now, n) if (adj[now].size() == deg) {
        int on = adj[now][id].F;
        if (fix[deg][id][on] == 1) {
            usable[deg][id] = 0;
            return;
        }

        fix[deg][id][on] = 1;
    }
    
    return;
}

inline void check(const int &a, const int &b, const int &c, const int &d) {
    bitset<N> tmp = fix[a][b] & fix[c][d];
    ok[a][b][c][d] = (!tmp.any());
}

void backTrack(int now) {
    if (now == k + 1) {
        ans++;
        return;
    }

    F0R(i, now) {
        bool possible = 1;
        FOR(j, 1, now) if (!ok[j][ keep[j] ][now][i]) possible = 0;
        if (!usable[now][i]) possible = 0;
        if (possible) {
            keep.pb(i);
            backTrack(now + 1);
            keep.pop_back();
        }
    }

    return;
}

int main() {
    IOS;
    
    init();
    FOR(i, 1, k + 1) F0R(j, i) makeBit(i, j);
    FOR(i, 1, k + 1) F0R(j, i) FOR(p, 1, k + 1) F0R(q, p) check(i, j, p, q);

    keep.pb(0);
    backTrack(1);
    cout << ans;
}