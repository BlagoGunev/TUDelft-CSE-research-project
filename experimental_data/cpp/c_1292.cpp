#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforr(i, a, b) for(int i = (int)(b-1); i >= (a); i--)
#define dforn(i, n) dforr(i, 0, n)
#define db(v) cerr << #v << " = " << v << endl
#define pb push_back
#define sz(x) ((int)x.size())
#define fst first
#define snd second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
const int MAXN = 3050;

int n;
vector<int> g[MAXN];

int P[MAXN], S[MAXN];
int init_dfs(int p){
    int ans = 1;
    for(int q : g[p])if(q != P[p]){
        P[q] = p;
        ans += init_dfs(q);
    }
    return S[p] = ans;
}

ll DP[MAXN][MAXN];
vector<int> path;
void solve_in(int i, int j){
//    printf("Resolvemos (%d, %d)\n", path[i], path[j]);
    int ti = path[i], tj = path[j];
    ll Pi = n - S[path[i+1]];
    ll Pj = S[path[j]];
    ll ac = max(DP[path[i+1]][tj], DP[ti][path[j-1]]);
//    db(Pi); db(Pj); db(ac);
    DP[ti][tj] = DP[tj][ti] = Pi*Pj + ac;
}
void dank_dfs(int p){
    path.pb(p);
    dforn(j, sz(path)-1) solve_in(j, sz(path)-1);

    for(int q : g[p])if(q != P[p]){
        dank_dfs(q);
    }
    path.pop_back();
}

void ItsShowTime(){
    forn(i, n){
        forn(j, n)printf("%3lld ", DP[i][j]);
        puts("");
    }
    puts("");
}

ll solve_dp(int i, int j){
    if(DP[i][j] > -1)return DP[i][j];

    ll act = S[i]*S[j];
    ll ac = max(solve_dp(P[i], j), solve_dp(i, P[j]));
    return DP[i][j] = DP[j][i] = act + ac;
}

int main(){
//	freopen("input.txt", "r", stdin);
	while(scanf("%d", &n) >= 1){
        forn(i, MAXN)g[i].clear();
        forn(i, n-1){
            int u, v;
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].pb(v); g[v].pb(u);
        }
        P[0] = -1; init_dfs(0);
//        printf("P:"); forn(i, n)printf(" %d", P[i]); puts("");
//        printf("S:"); forn(i, n)printf(" %d", S[i]); puts("");
        forn(i, MAXN)forn(j, MAXN)DP[i][j] = -1;
        forn(i, MAXN)DP[i][i] = 0;
//        ItsShowTime();
        dank_dfs(0);
//        ItsShowTime();
        forn(i, n)forn(j, n)if(DP[i][j] == -1)
            solve_dp(i, j);
//        ItsShowTime();
        ll ans = 0;
        forn(i, n)forn(j, n) ans = max(ans, DP[i][j]);
        printf("%lld\n", ans);
	}
	return 0;
}