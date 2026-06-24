#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:16777216")
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define FOR(i,a,n) for(int i=(a);i<(n);i++)
#define REP(i,n) FOR(i, 0, n)
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define lint long long
#define PII pair <int,int>
#define PDD pair <double,double>
#define VI vector <int>
#define VII vector < PII >
#define X first
#define Y second
#define sz(a) (int)(a.size())
using namespace std;


const int MOD = 1000*1000*1000 + 9;
struct tver{
	int ne[4];
	bool fl;
	int pch, pr;
};
char s[110];
int n, k;
int l;
tver ver[110];
int cn;
int df[110][11][1010];
int ras[110];
int ds[110];
int dgo[110][5];
int dma[110];

int get(char c){
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	return 3;
}
int newv(){
	int nv = cn++;
	ver[nv].fl = 0;
	memset(ver[nv].ne, -1, sizeof(ver[nv].ne));
	return nv;
}
void add(int pos, int v){
	if (pos == l){
		ver[v].fl = 1;
		return;
	}
	int nn = get(s[pos]);
	if (ver[v].ne[nn] != -1){
		add(pos+1, ver[v].ne[nn]);
	} else {
		int nv = newv();
		ver[v].ne[nn] = nv;
		ras[nv] = pos+1;
		ver[nv].pch = nn;
		ver[nv].pr = v;
		add(pos+1, nv);
	}
}
int go(int u, int c);
int suf(int u){
	if (u == 0) return 0;
	if (ver[u].pr == 0) return 0;
	return ds[u] = go(suf(ver[u].pr), ver[u].pch);
}
int go(int u, int c){
	if (dgo[u][c] != -1) return dgo[u][c];
	if (ver[u].ne[c] != -1) return ver[u].ne[c];
	if (u == 0) return 0;
	return dgo[u][c] = go(suf(u), c);
}
int mar(int u){
	if (u == 0) return 0;
	if (dma[u] != -1) return dma[u];
	int res = 0;
	if (ver[u].fl) res = ras[u];
	else res = mar(suf(u));
	return dma[u] = res;
}
int f(int nv, int k, int len){
	if (mar(nv) >= k) k = 0;
	if (k >= 10) return 0;
	if (len == n){
		if (k == 0) return 1;
		return 0;
	}
	if (df[nv][k][len] != -1) return df[nv][k][len];
	int res = 0;
	REP(i, 4){
		int nev = go(nv, i);
		if (ras[nev] <= k) continue;
		res += f(nev, k+1, len+1);
		if (res >= MOD) res -= MOD;
	}
	return df[nv][k][len] = res;
}
void solve(){
	printf("%d\n", f(0, 0, 0));
}
int main(){
	//freopen("t.in", "r", stdin);
	memset(df, -1, sizeof(df));
	memset(dgo, -1, sizeof(dgo));
	memset(ds, -1, sizeof(ds));
	memset(dma, -1, sizeof(dma));
	scanf("%d%d", &n, &k);
	memset(ver[0].ne, -1, sizeof(ver[0].ne));
	cn = 1;
	REP(i, k){
		scanf("%s", s);
		l = strlen(s);
		add(0, 0);
	}
	solve();
	return 0;
}