#include<bits/stdc++.h>

#define MP make_pair

#define fi first

#define se second

using namespace std;

typedef long long LL;

typedef pair<int, int> pii;

const int N = 103, mod = 998244353;

void qmo(int &x){x += x >> 31 & mod;}

pii operator - (const pii &a, const pii &b){return MP(a.fi - b.fi, a.se - b.se);}

LL operator * (const pii &a, const pii &b){return (LL)a.fi * b.se - (LL)a.se * b.fi;}

int n, rt, f[N], g[N], dp[N<<1], id[N][N], fir[N][N], lst[N][N], wei[N][N];

vector<int> E[N], sbt[N], wys[N][N];

bool has[N][N];

pii a[N];

void dfs0(int x, int fa){

    wys[rt][x] = wys[rt][fa];

    wys[rt][x].push_back(x);

    for(int v : E[x]) if(v != fa) dfs0(v, x);

}

void dfs(int x, int fa){

    for(auto it = E[x].begin();it != E[x].end();++ it)

        if(*it == fa){E[x].erase(it); break;}

    sbt[x].push_back(x); g[x] = 1;

    for(int v : E[x]){

        dfs(v, x); g[x] = (LL)g[x] * f[v] % mod;

        sbt[x].insert(sbt[x].end(), sbt[v].begin(), sbt[v].end());

    }

    sort(sbt[x].begin(), sbt[x].end(), [&](int u, int v){return a[u] < a[v];});

    f[x] = g[x];

    for(int v : E[x]){

        int tmp = g[v];

        for(int i : E[x]) if(i != v) tmp = (LL)tmp * f[i] % mod;

        qmo(f[x] += tmp - mod);

    }

    int num = 0;

    memset(id, 0, sizeof(id));

    for(int u : sbt[x])

        for(int v : E[u]){

            id[u][v] = ++num;

            id[v][u] = ++num;

        }

    vector<pii> edg;

    for(int u : sbt[x])

        for(int v : sbt[x]) if(wys[u][v].size() >= 3 && (a[v] - a[u]) * (a[x] - a[u]) >= 0){

            edg.emplace_back(u, v);

            int len = wys[u][v].size();

            fir[u][v] = id[wys[u][v][0]][wys[u][v][1]];

            lst[u][v] = id[wys[u][v].back()][wys[u][v][len-2]];

            wei[u][v] = 1;

            int now = wys[u][v][0], nxt = wys[u][v][1];

            has[u][v] = now == x;

            for(int son : E[now]) if(son != nxt && (a[son] - a[now]) * (a[nxt] - a[now]) >= 0) wei[u][v] = (LL)wei[u][v] * f[son] % mod;

            int lst = wys[u][v][len-2]; now = wys[u][v].back();

            has[u][v] |= now == x;

            for(int son : E[now]) if(son != lst && (a[lst] - a[now]) * (a[son] - a[now]) >= 0) wei[u][v] = (LL)wei[u][v] * f[son] % mod;

            for(int i = 1;i < len-1;++ i){

                lst = wys[u][v][i-1]; now = wys[u][v][i]; nxt = wys[u][v][i+1];

                has[u][v] |= now == x;

                for(int son : E[now]) if(son != lst && son != nxt && ((a[lst] - a[now]) * (a[nxt] - a[now]) <= 0) + ((a[son] - a[now]) * (a[lst] - a[now]) <= 0) + ((a[son] - a[now]) * (a[nxt] - a[now]) >= 0) >= 2)

                    wei[u][v] = (LL)wei[u][v] * f[son] % mod;

            }

			// printf("wei[%d][%d] = %d, has[%d][%d] = %d\n", u, v, wei[u][v], u, v, has[u][v]);

        }

    auto half = [&](const pii &u){

        return u.fi < 0 || u.fi == 0 && u.se < 0;

    };

    sort(edg.begin(), edg.end(), [&](const pii &u, const pii &v){

        pii A = a[u.se] - a[u.fi], B = a[v.se] - a[v.fi];

        int X = half(A), Y = half(B);

        return X == Y ? A * B > 0 : X < Y;

    });

    for(int i = 0;i < sbt[x].size();++ i)

        for(int j = i+1;j < sbt[x].size();++ j){

            int u = sbt[x][i], v = sbt[x][j];

            if(!id[u][v]) continue;

            memset(dp, 0, sizeof(dp));

            dp[id[u][v]] = 1;

            for(const pii &e : edg) if(!has[e.fi][e.se]){

                int S = fir[e.fi][e.se], T = lst[e.fi][e.se];

                dp[T] = (dp[T] + (LL)dp[S] * wei[e.fi][e.se]) % mod;

            }

			qmo(f[x] -= dp[id[u][v]]);

			memset(dp, 0, sizeof(dp));

			dp[id[u][v]] = 1;

			for(const pii &e : edg){

				int S = fir[e.fi][e.se], T = lst[e.fi][e.se];

				dp[T] = (dp[T] + (LL)dp[S] * wei[e.fi][e.se]) % mod;

			}

			qmo(f[x] += dp[id[u][v]] - mod);

        }

	// printf("f[%d] = %d, g[%d] = %d\n", x, f[x], x, g[x]);

}

int main(){

    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 1;i <= n;++ i) cin >> a[i].fi >> a[i].se;

    for(int i = 1, u, v;i < n;++ i){

        cin >> u >> v;

        E[u].push_back(v);

        E[v].push_back(u);

    }

    for(rt = 1;rt <= n;++ rt){

        dfs0(rt, 0);

        for(int i = 1;i <= n;++ i)

            for(int j : wys[rt][i]) if((a[i] - a[rt]) * (a[j] - a[rt]) < 0){

                wys[rt][i].clear(); break;

            }

    }

    dfs(1, 0); cout << f[1] << '\n';

}