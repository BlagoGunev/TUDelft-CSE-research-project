#include <cstdio>



const int size = 4005,mod = 1e9+7;

int dp[size][size];

int n;



int main(int argc, char const *argv[]){

	scanf("%d",&n);

	dp[0][0] = 1;

	for(int i = 1; i <= n; i++){

		dp[i][0] = dp[i-1][i-1]%mod;

		for(int j = 1; j <= i; j++){

			dp[i][j] = (dp[i-1][j-1]+dp[i][j-1])%mod;

		}

	}

	printf("%d\n",dp[n][n-1]);



	return 0;

}