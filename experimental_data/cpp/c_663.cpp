#include <cstdio>

#include <cstring>

#include <algorithm>

#define INF (1 << 30)

#define maxn 201000

using namespace std;



int ansdota[maxn],ansdotb[maxn],ansa,ansb,st[maxn];

int fst[maxn],co[maxn],C[maxn],A[maxn],B[maxn],top;

int e,n,m,ans,x,y;



struct str { int v,nex,c; } edge[maxn << 1];



void make_edge(int a,int b,int c) {

	edge[++e].nex = fst[a]; fst[a] = e; edge[e].v = b; edge[e].c = c;

	edge[++e].nex = fst[b]; fst[b] = e; edge[e].v = a; edge[e].c = c;

}



bool paint(int u,int c) {

	co[u] = c; st[++top] = u;

	if (c == 1) x++; else y++;

	for (int i = fst[u]; i; i = edge[i].nex) {

		int v = edge[i].v;

		if (edge[i].c == 1) {

			if (!co[v]) { if (!paint(v,3 - co[u])) return false; }

			else if (co[v] == co[u]) return false;

		} else {

			if (!co[v]) { if (!paint(v,co[u])) return false; }

			else if (co[v] != co[u]) return false;

		}

	}

	return true;

}



void solve(int *ansdot, int &ans) {

	memset(fst,0,sizeof(fst));

	memset(co,0,sizeof(co));

	e = 0; ans = INF;

	for (int i = 1; i <= m; i++) {

		make_edge(A[i], B[i], C[i]);

	}

	int Ans = 0,t = 0;  

	for (int i = 1; i <= n; i++) {

		if (co[i]) continue;

		x = 0; y = 0; top = 0;

		if (!paint(i,1)) return;		

		Ans += min(x,y);

		if (x < y) {

			for (; top; top--) if (co[st[top]] == 1) ansdot[++t] = st[top];			

		} else

			for (; top; top--) if (co[st[top]] == 2) ansdot[++t] = st[top];

	}

	ans = min(ans,Ans);

}



int main() {

	scanf("%d %d",&n,&m);

	for (int i = 1; i <= m; i++) {

		int a,b; char c;

		scanf("%d %d %c",&a,&b,&c);

		A[i] = a; B[i] = b; C[i] = (c == 'B');

	}

	solve(ansdota,ansa);

	for (int i = 1; i <= m; i++) C[i] ^= 1;

	solve(ansdotb,ansb);

	if (min(ansa,ansb) == INF) printf("-1\n");

	else {

		printf("%d\n",min(ansa,ansb));

		if (ansa < ansb)

			for (int i = 1; i <= ansa; i++) printf("%d ",ansdota[i]);

		else

			for (int i = 1; i <= ansb; i++) printf("%d ",ansdotb[i]);

	}

	return 0;

}