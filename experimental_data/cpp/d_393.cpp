#include<bits/stdc++.h>

using namespace std;



#define scl(x) scanf("%lld",&x)

#define sc(x)  scanf("%d",&x)

#define ll long long

#define lop(i,n) for(int i=0;i<n;++i)

typedef pair<int,int> ii;

typedef pair<ll,ll> pll;



int mat[3][3];

ll dp[3][3][41];

int main(){

#ifndef ONLINE_JUDGE

	freopen("i.txt","r",stdin);

#endif

	lop(i,3)lop(j,3)sc(mat[i][j]);

	lop(n,41)

	lop(fr,3)lop(to,3){

		if(fr==to||!n)continue;

		int aux=3-fr-to;

		ll &ret=dp[fr][to][n];

		ret=dp[fr][aux][n-1]+mat[fr][to]+dp[aux][to][n-1];

		ret=min (ret , dp[fr][to][n-1]+mat[fr][aux]

				+dp[to][fr][n-1]+mat[aux][to]+dp[fr][to][n-1]);

	}

	int n;

	sc(n);

	printf("%lld\n",dp[0][2][n]);

}