#include<cstdio>
#include<cstring>
#define rep(i,l,u) for (i=l; i<=u; i++)

using namespace std;

const int MAXN = 305;
int N,A[MAXN][MAXN],G[MAXN*2][MAXN],F[MAXN*2][MAXN][MAXN];

inline int max(int x,int y) { return x>y?x:y; }

int main()
{
	//freopen("in","r",stdin); freopen("out","w",stdout);

	int i,j,k;
	scanf("%d",&N);
	rep(i,1,N) rep(j,1,N) scanf("%d",&A[i][j]);
	rep(k,2,N+1)
	{
		int t = 0;
		rep(j,1,k-1)
			G[k-1][++t] = A[k-j][j];
	}
	rep(k,N+2,N*2)
	{
		int t = 0;
		rep(j,k-N,N)
			G[k-1][++t] = A[k-j][j];
	}
	F[1][1][1] = G[1][1];
	rep(k,2,N)
		rep(i,1,k) rep(j,i,k)
		{
			F[k][i][j] = -0x7FFFFFFF;
			if (i-1>0) F[k][i][j] = max(F[k][i][j],F[k-1][i-1][j-1]+G[k][i]+G[k][j]);
			if (i-1>0 && j<k) F[k][i][j] = max(F[k][i][j],F[k-1][i-1][j]+G[k][i]+G[k][j]);
			if (i<=j-1) F[k][i][j] = max(F[k][i][j],F[k-1][i][j-1]+G[k][i]+G[k][j]);
			if (j<k) F[k][i][j] = max(F[k][i][j],F[k-1][i][j]+G[k][i]+G[k][j]);
			if (i==j) F[k][i][j] -= G[k][i];
		}
	rep(k,N+1,N*2-1)
		rep(i,1,N*2-k) rep(j,i,N*2-k)
		{
			F[k][i][j] = -0x7FFFFFFF;
			F[k][i][j] = max(F[k][i][j],F[k-1][i][j]+G[k][i]+G[k][j]);
			F[k][i][j] = max(F[k][i][j],F[k-1][i][j+1]+G[k][i]+G[k][j]);
			if (i+1<=j) F[k][i][j] = max(F[k][i][j],F[k-1][i+1][j]+G[k][i]+G[k][j]);
			F[k][i][j] = max(F[k][i][j],F[k-1][i+1][j+1]+G[k][i]+G[k][j]);
			if (i==j) F[k][i][j] -= G[k][i];
		}
	printf("%d\n",F[N*2-1][1][1]);

	return 0;
}