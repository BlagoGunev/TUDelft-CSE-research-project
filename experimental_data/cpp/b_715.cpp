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
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector< vi > vii;

const ll oo = 0x3f3f3f3f3f3f3f3fll;

#define N 1009
#define M 20009

int an, adj[N], to[M], ant[M];
ll len[M];

void add(int u, int v, int w) {
	to[an] = v; len[an] = w;
	ant[an] = adj[u]; adj[u] = an++;
	swap(u, v);
	to[an] = v; len[an] = w;
	ant[an] = adj[u]; adj[u] = an++;
}

struct path {
	int u;
	ll d;
	path(int u, ll d):
		u(u), d(d) {}
	bool operator<(const path &p) const {
		return d > p.d;
	}
};

int n, m, s, t;
ll dist[N], dist2[N];

void dijkstra(int ii, int bg) {
	cl(dist, 0x3f);
	priority_queue<path> pilha;
	
	dist[bg] = 0;
	pilha.push(path(bg, 0));
	
	while (!pilha.empty()) {
		path aux = pilha.top(); pilha.pop();
		int u = aux.u;
		ll d = aux.d;
		
		if (d > dist[u]) continue;
		//db(u _ d);
		
		fre(it, u) {
			int v = to[it];
			ll dv = d + len[it];
			
			if (len[it] == 0) {
				if (ii == 0) continue;
				else dv++;
			}
			
			if (dist[v] > dv) {
				//from[d] = it;
				dist[v] = dv;
				pilha.push(path(v, dv));
			}
		}
	}
}

ll l;

bool dijkstra2(int bg) {
	cl(dist2, 0x3f);
	//cl(mark, 0);
	priority_queue<path> pilha;
	
	dist2[bg] = 0;
	pilha.push(path(bg, 0));
	
	while (!pilha.empty()) {
		path aux = pilha.top(); pilha.pop();
		int u = aux.u;
		ll d = aux.d;
		
		if (d > dist2[u]) continue;
		
		fre(it, u) {
			int v = to[it];
			
			if (len[it] == 0) {
				if (dist[v] == oo) {
					len[it] = len[it^1] = 1;
				} else {
					ll dd = dist[v] + dist2[u];
					len[it] = len[it^1] = max(1ll, l - dd);
				}
			}
			
			ll dv = d + len[it];
			
			if (dist2[v] > dv) {
				//from[d] = it;
				dist2[v] = dv;
				pilha.push(path(v, dv));
			}
		}
	}
	
	return 1;
}

int main() {
	while (sc2(n, m) == 2) {
		scanf("%lld", &l);
		sc2(s, t);
		
		an = 0;
		cl(adj, -1);
		
		rp(i, m) {
			int u, v, w;
			sc3(u, v, w);
			add(u, v, w);
		}
		
		dijkstra(0, s);
		if (dist[t] < l) {
			puts("NO");
			continue;
		}
		
		dijkstra(1, s);
		if (dist[t] > l) {
			puts("NO");
			continue;
		}
		
		//rp(i, n) db(i _ dist[i]);
		if (!dijkstra2(t)) {
			puts("NO");
			continue;
		}
		
		dijkstra(1, s);
		if (dist[t] != l) {
			puts("NO");
			continue;
		}
		
		puts("YES");
		rp(i, m) {
			int u = to[i+i+1];
			int v = to[i+i];
			ll w = len[i+i];
			
			printf("%d %d %lld\n", u, v, w);
		}
	}
	return 0;
}