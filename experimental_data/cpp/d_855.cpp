#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define fre(a,b) for(int a = adj[b]; ~a; a = ant[a])
#define cl(a,b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)

#define iter(a) __typeof((a).begin())
#define fore(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vii;

const int oo = 0x3f3f3f3f;

#define N 100009

vi adj[2][N];

int n;
int in, head[N+N];
int p[2][N], rep[2][N], b[2][N], e[2][N];

int top;

void dfs(int t, int u, int id) {
	rep[t][u] = id;
	b[t][u] = top++;
	
	int sz = adj[t][u].size();
	rp(i, sz) {
		int v = adj[t][u][i];
		dfs(t, v, id);
	}
	
	e[t][u] = top;
}

void build(int t, int u, int id) {
	top = 0;
	dfs(t, u, id);
	head[id] = u;
}

bool desc(int t, int u, int v) {
	if (rep[t][u] != rep[t][v]) return 0;
	
	int lo = b[t][u], hi = e[t][u], ps = b[t][v];
	return (ps >= lo && ps < hi);
}

int main() {
	while (sc(n) == 1) {
		cl(p[0], -1);
		cl(p[1], -1);
		
		rp(j, 2) rp(i, n) {
			adj[j][i].clear();
		}
		
		rp(i, n) {
			int pp, tp;
			sc2(pp, tp); pp--;
			if (tp == -1) continue;
			
			p[tp][i] = pp;
			adj[tp][pp].pb(i);
		}
		
		in = 0;
		rp(i, n) {
			if (p[0][i] == -1) build(0, i, in++);
			if (p[1][i] == -1) build(1, i, in++);
		}
		
		/*rp(i, n) {
			db(p[0][i] _ p[1][i]);
		}*/
		
		int q; sc(q);
		while (q--) {
			int t, u, v;
			sc3(t, u, v);
			u--; v--;
			
			if (t == 1) {
				if (u == v) puts("NO");
				else puts(desc(0, u, v)? "YES": "NO");
			} else {
				if (p[1][v] == -1) puts("NO");
				else {
					int idu = rep[0][u];
					int hu = head[idu];
					
					int idv = rep[1][v];
					int hv = head[idv];
					
					if (v != hu && desc(1, hu, v)) puts("YES");
					else if (hv != v && desc(0, hv, u)) puts("YES");
					else puts("NO");
				}
			}
		}
		//return 0;
	}
	return 0;
}