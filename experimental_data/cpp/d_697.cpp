#include <bits/stdc++.h>



#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i++)

#define DOW(i,a,b) for (int i=(a),_b=(b);i>=_b;i--)

#define x first

#define y second

#define pb push_back

#define mp make_pair

#define maxn 100010



using namespace std;



typedef pair<int,int> PII;

typedef pair<int,PII> PP;

typedef long long LL;

typedef unsigned long long ULL;



struct Edge{

	int to, next;

}e[maxn<<1];



int head[maxn], cnt;

int sz[maxn], dep[maxn];



void ins(int u, int v){e[++cnt] = (Edge){v, head[u]}; head[u] = cnt;}



void insert(int u,int v){ins(u,v);ins(v,u);}





void dfs(int u, int fa){

	sz[u] = 1;

	for(int i = head[u]; i; i = e[i].next){

		int v = e[i].to;

		if(v == fa) continue;

		dep[v] = dep[u]+1;

		dfs(v, u);

		sz[u] += sz[v];

	}

}



int main(){

	//freopen("input.inp","r",stdin);

    //freopen("output.out","w",stdout);

	int n;

	scanf("%d",&n);

	FOR(i,2,n){

		int p;

		scanf("%d",&p);

		insert(i, p);

	}

	dfs(1,-1);

	FOR(i,1,n){

		int ans = n - sz[i] - dep[i];

		printf("%d", dep[i] + (ans >> 1) + 1);

		putchar('.');

		if (ans & 1) putchar('5');

		else putchar('0');

		putchar(' ');

	}

	puts("\n");

	return 0;

}