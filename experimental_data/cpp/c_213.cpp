#include <bitset>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <complex>
#include <cstring>
#include <map>
using namespace std;
int a[310][310];

int dp[620][310][310];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d", &(a[i][j]));
		}
	}
	if(n == 1){
		printf("%d\n", a[0][0]);
		return 0;
	}
	dp[0][0][0] = a[0][0];
	for(int i=1;i<=2*n-2;i++){
		
		for(int j=max(0, i - n + 1);j<=min(i, n - 1);j++){
			for(int k=j;k<=min(i, n-1);k++){
				if(j == k){
					dp[i][j][k] = a[j][i-j];
				} else {
					dp[i][j][k] = a[j][i-j] + a[k][i-k];
				}
				int q = -1000000000;
				if(j > 0){
					q = max(q, dp[i-1][j-1][k-1]);
				}
				if(k < i){
					q = max(q, dp[i-1][j][k]);
				}
				if(j > 0 && k < i){
					q = max(q, dp[i-1][j-1][k]);
				}
				if(k - j > 0){
					q = max(q, dp[i-1][j][k-1]);
				}
				dp[i][j][k] += q;
				//cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
			}
		}
	}
	printf("%d\n", dp[2*n-2][n-1][n-1]);
}