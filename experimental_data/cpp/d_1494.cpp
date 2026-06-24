#include <bits/stdc++.h>

using namespace std;

template<typename T> inline bool upmin(T &x, T y) { return y < x ? x = y, 1 : 0; }
template<typename T> inline bool upmax(T &x, T y) { return x < y ? x = y, 1 : 0; }

#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define SIZE(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef long double lod;
typedef pair<int, int> PR;
typedef vector<int> VI;

const lod eps = 1e-11;
const lod pi = acos(-1);
const int oo = 1 << 30;
const ll loo = 1ll << 62;
const int mods = 998244353;
const int MAXN = 600005;
const int INF = 0x3f3f3f3f;//1061109567
/*--------------------------------------------------------------------*/
inline int read() {
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	return x * f;
}
vector<PR> Ans;
vector<int> e[MAXN];
struct Vnode{ int x, u, v; } V[MAXN];
int id[MAXN], c[MAXN], C[MAXN], f[MAXN], n, ID, num;
int find(int x) { return f[x] == x ? f[x] : f[x] = find(f[x]); }
void dfs(int x, int father) {
	if (x <= n) return;
	if (c[x] != c[father]) id[x] = ++ ID, C[ID] = c[x];
	else id[x] = id[father];
	for (auto v : e[x]) {
		if (v == father) continue;
		dfs(v, x);
	}
	for (auto v : e[x]) {
		if (v == father) continue;
		if (id[v] != id[x]) Ans.PB(MP(id[v], id[x]));
	}
}
signed main() {
	n = read();
	int edgenum = 0;
	for (int i = 1; i <= n ; ++ i)
		for (int j = 1; j <= n ; ++ j) {
			if (i == j) { c[i] = C[i] = read(); continue; }
			int x = read();
			if (i < j) V[++ edgenum] = (Vnode){x, i, j};
		}
	sort(V + 1, V + edgenum + 1, [&](Vnode a, Vnode b){ return a.x < b.x; });
	num = ID = n;
	for (int i = 1; i <= n ; ++ i) id[i] = i, f[i] = i;
	for (int i = 1; i <= edgenum ; ++ i) {
		int x = find(V[i].u), y = find(V[i].v);
		if (x == y) continue;
		c[++ num] = V[i].x, f[x] = f[y] = f[num] = num;
		e[num].PB(x), e[num].PB(y);
	} 
	dfs(num, 0);
	printf("%d\n", ID);
	for (int i = 1; i <= ID ; ++ i) printf("%d ", C[i]); puts("");
	printf("%d\n", id[num]);
	for (auto v : Ans) printf("%d %d\n", v.fi, v.se);
	return 0;
}