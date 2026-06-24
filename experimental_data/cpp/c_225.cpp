#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;

int dp[1005][1005], cost[1005]; //to all '#'

int main(void){

    int i, j, sum;

    char matrix[1005][1005];

    scanf("%d %d %d %d", &n, &m, &x, &y);

    for(i = 0; i < n; i++) scanf("%s", matrix[i]);

    for(i = 0; i < m; i++){

        for(j = sum = 0; j < n; j++)

            if(matrix[j][i] == '#') sum++;

        cost[i + 1] = cost[i] + sum;

    }

    memset(dp, 127, sizeof(dp));

    dp[0][0] = 0;

    dp[1][0] = 0;

    for(i = 1; i <= m; i++){

        for(j = x; j <= y && i - j >= 0; j++){

            dp[0][i] = min(dp[1][i - j] + cost[i] - cost[i - j], dp[0][i]);

            dp[1][i] = min(dp[0][i - j] + n * j - (cost[i] - cost[i - j]), dp[1][i]);

        }

    }

    printf("%d\n", min(dp[0][m], dp[1][m]));

}