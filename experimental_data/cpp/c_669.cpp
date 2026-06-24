#include <bits/stdc++.h>
#define MAXN 101
#define rii(a,b) scanf("%d %d",&a,&b)
#define riii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define FOR(i,l,r) for(int i=l; i<r; i++)
#define FORR(i,l,r) for(int i=l; i>=r; i--)
using namespace std;

int t, a, b, n;
int R, C, Q, A[MAXN][MAXN], RM[MAXN][MAXN], CM[MAXN][MAXN];

int main() {
	riii(R,C,Q);
	FOR(i,0,Q) {
		rii(t,a); a--;
		if(t==1) {
			FOR(i,0,C) RM[a][i]++;
			n=RM[a][0]; b=CM[a][0];
			FOR(i,0,C-1) {
				RM[a][i]=RM[a][i+1];
				CM[a][i]=CM[a][i+1];
			}
			RM[a][C-1]=n; CM[a][C-1]=b;
		}
		if(t==2) {
			FOR(i,0,R) CM[i][a]++;
			n=RM[0][a]; b=CM[0][a];
			FOR(i,0,R-1) {
				RM[i][a]=RM[i+1][a];
				CM[i][a]=CM[i+1][a];
			}
			RM[R-1][a]=n; CM[R-1][a]=b;
		}
		if(t==3) {
			rii(b,n); b--;
			A[(a+CM[a][b])%R][(b+RM[a][b])%C]=n;
		}
	}
	FOR(i,0,R) FOR(j,0,C) printf("%d%c",A[i][j]," \n"[j==C-1]);
}