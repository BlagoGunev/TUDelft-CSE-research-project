#include <bits/stdc++.h>

#define pb push_back

#define mp make_pair

#define INF 0x3f3f3f3f

#define VI vector<int>

#define pii pair<int,int>

#define matrix vector<VI>

#define LL long long

#define MOD 1000000007

#define ULL unsigned long long

#define uedge(g,a,b) g[a].pb(b), g[b].pb(a)

#define dedge(g,a,b) g[a].pb(b)

using namespace std;

int n, m;

class edge{

	public:

	int u, v, w, id;

	edge(){}

	edge(int a, int b, int c){

		u = a; v = b; w = c;

	}

	edge(int a, int b, int c, int d){

		u = a; v = b; w = c; id = d;

	}

	bool operator<(const edge& other) const{

		if(u != other.u) return u < other.u;

		if(v != other.v) return v < other.v;

		return w < other.w;

	}

};

int s, t;

edge E[30010];

edge M[30010];

vector<edge> g[1010];

bool v[1010];

int low[1010], in[1010];

int ind;

bool bridge[30010];

int reach;

int p[1010];

int find(int x){

	if(p[x] == x) return x;

	return p[x] = find(p[x]);

}

void join(int x, int y){

	p[find(x)] = find(y);

}

int P[1010];

int me;

int W[30010];

pii parent[1010];

int plen;

void bfs(){

	for(int i = 0; i <= n; i++){ v[i] = false; parent[i] = mp(-1,-1);}

	queue<int> q;

	q.push(s);

	v[s] = true;

	while(!q.empty()){

		int cur = q.front(); q.pop();

		if(cur == t) break;

		for(int i = 0; i < (int)g[cur].size(); i++){

			int next = g[cur][i].v;

			if(v[next]) continue;

			v[next] = true;

			parent[next] = mp(cur, g[cur][i].id);

			q.push(next);

		}

	}

	int cur = t;

	plen = 0;

	while(parent[cur].first != -1){

		int prev = parent[cur].first, e = parent[cur].second;

		P[plen++] = e;

		cur = prev;

	}

}

void dfs1(int cur, int prev, int forb){

	low[cur] = in[cur] = ind++;

	v[cur] = true;

	for(int i = 0; i < (int)g[cur].size(); i++){

		int next = g[cur][i].v;

		if(g[cur][i].id == prev) continue;

		if(g[cur][i].id == forb) continue;

		if(!v[next]){

			dfs1(next, g[cur][i].id, forb);

			low[cur] = min(low[cur], low[next]);

		}else low[cur] = min(low[cur], in[next]);

	}

	for(int i = 0; i < (int)g[cur].size(); i++){

		int next = g[cur][i].v;

		if(g[cur][i].id == prev) continue;

		if(g[cur][i].id == forb) continue;

		if(low[next] > in[cur]) bridge[g[cur][i].id] = true;

	}

}

void dfs2(int cur, int e, int forb, int& b){

	v[cur] = true;

	if(cur == t){

		if(e == -1){

			reach = -1;

		}else{

			reach = true;

			b = e;

		}

		return;

	}

	for(int i = 0; i < (int)g[cur].size(); i++){

		int next = g[cur][i].v;

		if(g[cur][i].id == forb) continue;

		if(v[next]) continue;

		if(!bridge[g[cur][i].id]) dfs2(next, e, forb, b);

		else{

			if(e == -1) dfs2(next, g[cur][i].id, forb, b);

			else{

				if(g[cur][i].w < W[e]) dfs2(next, g[cur][i].id, forb, b);

				else dfs2(next, e, forb, b);

			}

		}

	}

}

int main(){

	scanf("%d %d %d %d", &n, &m, &s, &t);

	for(int i = 1; i <= n; i++) p[i] = i;

	for(int i = 0; i < m; i++){

		int u, v, w;

		scanf("%d %d %d",&u, &v, &w);

		join(u,v);

		if(u > v) swap(u,v);

		E[i] = edge(u, v, w, i);

		W[i] = w;

	}

	int om = m;

	if(find(s) != find(t)){

		printf("0\n0\n");

		return 0;

	}

	sort(E, E + m);

	int idx = 0;

	for(int i = 0; i < m; i++){

		int cont = 0;

		int u = E[i].u, v = E[i].v;

		while(i < m){

			if(E[i].u == u && E[i].v == v){

				if(cont < 3){M[idx] = edge(u, v, E[i].w, E[i].id); idx++;}

				cont++; i++;

			}else break;

		}

		i--;

	}

	m = idx;

	for(int i = 0; i < m; i++){

		int u = M[i].u, v = M[i].v, w = M[i].w, id = M[i].id;

		g[u].pb(edge(u,v,w,id));

		g[v].pb(edge(v,u,w,id));

	}

	bfs();

	int c = 0;

	int cost = -1;

	int A, B;

	//for(int i = 0; i < plen; i++) printf("%d ", P[i]); printf("\n");

	for(int i = 0; i < plen; i++){

		for(int j= 0; j <= n; j++) v[j] = false;

		for(int j=0; j < m; j++) bridge[M[j].id] = false;

		ind = 0;

		dfs1(s,-1,P[i]);

		for(int j= 0; j <= n; j++) v[j] = false;

		reach = 0;

		int a = P[i], b;

		dfs2(s,-1,P[i],b);

		if(!reach){

			if(W[a] < cost || cost == -1) {

				c = 1;

				cost = W[a];

				A = a;

			}

		}else if(reach == 1){

			if(W[a] + W[b] < cost || cost == -1){

				c = 2;

				cost = W[a] + W[b];

				A = a; B = b;

			}

		}

	}

	if(c == 0) printf("-1\n");

	else if(c==1) printf("%d\n1\n%d\n", cost, A+1);

	else printf("%d\n2\n%d %d\n", cost, A+1, B+1);

	return 0;

}