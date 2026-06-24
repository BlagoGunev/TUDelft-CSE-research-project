#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define RVC(i, S) for (int i = 0; i < S.size(); ++i)
#define mp make_pair
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> VI;

const int N = 50005, INF = 0x3f3f3f3f;
int n, m, K, idx, xi[N], yi[N], dist[N];
VI tx[N], ty[N];
map<int, int> rk[N];
VI to[N], wi[N];

void addedge(int x, int y, int w){
	to[x].pb(y);
	wi[x].pb(w);
}

void biedge(int x, int y, int w){
	addedge(x, y, w);
	addedge(y, x, w);
}

queue<int> q;
int inq[N];

void spfa(int S){
	memset(dist, 0x3f, sizeof dist);
	dist[S] = 0;
	inq[S] = 1; q.push(S);
	while (!q.empty()){
		int h = q.front(); q.pop(); inq[h] = 0;
		RVC(i, to[h]){
			if (dist[h] + wi[h][i] < dist[to[h][i]]){
				dist[to[h][i]] = dist[h] + wi[h][i];
				if (!inq[to[h][i]]){
					q.push(to[h][i]);
					inq[to[h][i]] = 1;
				}
			}
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 1, K){
		int x, y;
		scanf("%d%d", &x, &y);
		tx[x].pb(y);
		ty[y].pb(x);
	}
	REP(i, 1, n) xi[i] = ++idx;
	REP(i, 1, m) yi[i] = ++idx;
	REP(x, 1, n){
		sort(tx[x].begin(), tx[x].end());
		RVC(j, tx[x])
			rk[x][tx[x][j]] = ++idx;
		for (int j = 0; j + 1 < tx[x].size(); ++j)
			if (tx[x][j] + 1 == tx[x][j + 1]){
				biedge(rk[x][tx[x][j]], 
					   rk[x][tx[x][j + 1]], 0);
			}
		RVC(j, tx[x]){
			int y = tx[x][j];
			addedge(rk[x][y], xi[x], 1);
			addedge(xi[x], rk[x][y], 0);
			if (x - 1 > 0){
				addedge(rk[x][y], xi[x - 1], 1);
				addedge(xi[x - 1], rk[x][y], 0);
			}
			if (x + 1 <= n){
				addedge(rk[x][y], xi[x + 1], 1);
				addedge(xi[x + 1], rk[x][y], 0);
			}
		}
	}
	REP(y, 1, m){
		sort(ty[y].begin(), ty[y].end());
		for (int j = 0; j + 1 < ty[y].size(); ++j){
			if (ty[y][j] + 1 == ty[y][j + 1]){
				biedge(rk[ty[y][j]][y], 
					   rk[ty[y][j + 1]][y], 0);
			}
		}
		RVC(j, ty[y]){
			int x = ty[y][j];
			addedge(rk[x][y], yi[y], 1);
			addedge(yi[y], rk[x][y], 0);
			if (y - 1 > 0){
				addedge(rk[x][y], yi[y - 1], 1);
				addedge(yi[y - 1], rk[x][y], 0);
			}
			if (y + 1 <= m){
				addedge(rk[x][y], yi[y + 1], 1);
				addedge(yi[y + 1], rk[x][y], 0);
			}
		}
	}
	spfa(rk[1][1]);
	RVC(i, tx[n]) dist[rk[n][m]] = min(dist[rk[n][m]], dist[rk[n][tx[n][i]]] + 1);
	RVC(i, ty[m]) dist[rk[n][m]] = min(dist[rk[n][m]], dist[rk[ty[m][i]][m]] + 1);
	// cerr << dist[rk[n - 1][m - 1]] << endl;
	dist[rk[n][m]] = min(dist[rk[n][m]], dist[xi[n]]);
	dist[rk[n][m]] = min(dist[rk[n][m]], dist[yi[m]]);
	if (dist[rk[n][m]] >= INF) puts("-1");
	else printf("%d\n", dist[rk[n][m]]);
	return 0;
}