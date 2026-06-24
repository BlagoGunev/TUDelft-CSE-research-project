#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#define REP(i,n) for (int i = 1; i <= (n); ++i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for (int i = (a); i >= (b); --i)
#define FEC(p,u) for (edge *p = head[u]; p; p = p->nxt)
using namespace std;
typedef long long LL;
void read(int &x){
	char ch = getchar(); while (ch < '0' || ch > '9') ch = getchar();
	for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x*10+ch-48;
}
int P(1000000007);

int n, m, a[110][110000], C[110000][110];
int main(){
	read(n), read(m);
	REP(i,n) read(a[0][i]);
	C[0][0] = 1;
	REP(i,100200){
		C[i][0] = 1;
		REP(j,102) C[i][j] = (C[i-1][j-1]+C[i-1][j])%P;
	}
	while (m--){
		int l, r, k;
		read(l), read(r), read(k);
		a[k+1][l] = (a[k+1][l]+1)%P;
		REP(i,k+1) a[i][r+1] = (a[i][r+1]-C[r-l+k+1-i][k+1-i]+P)%P;
	}
	ROF(i,101,0){
		int t(0);
		REP(j,n){
			t = (t+a[i+1][j])%P;
			a[i][j] = (a[i][j]+t)%P;
		}
	}
	REP(i,n-1) printf("%d ", a[0][i]); printf("%d\n", a[0][n]);
	return 0;
}