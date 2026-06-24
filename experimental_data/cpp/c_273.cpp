#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 300005
using namespace std;

int n, m, x, y, E[N][5], g[N], d[N];

void Sat(int x){
	int cnt = 0;
	FOR(i,0,d[x]) if (g[x] == g[E[x][i]]) ++cnt;
	if (cnt >= 2){
		g[x] ^= 1;
		FOR(i,0,d[x]) if (g[x] == g[E[x][i]]) Sat(E[x][i]);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	FOR(i,0,m){
		scanf("%d%d", &x, &y), x--, y--;
		E[x][d[x]++] = y;
		E[y][d[y]++] = x;
	}
	
	FOR(i,0,n) Sat(i);
	FOR(i,0,n) printf("%d", g[i]);
	return 0;
}