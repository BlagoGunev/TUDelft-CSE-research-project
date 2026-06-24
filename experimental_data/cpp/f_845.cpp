#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define LL long long
using namespace std;
const int MAXN = 257;
const int p = 1000000007;
int n, m, x, y, ans;
char s[MAXN][MAXN];
int dp[2][(1 << 17) + 1][2];
inline int f(int x, int k){
	return (x >> (m - k)) & 1;
}
inline int c(int x, int k, int a){
	return f(x, k) == a ? x : x ^ (1 << (m - k));
}
inline int c(int x, int k, int a1, int a2){
	return c(c(x, k, a1), k + 1, a2);
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", s[i]);
	dp[1][0][0] = 1;
	x = 1, y = 0;
	if(n < m){
		swap(n, m);
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				swap(s[i][j], s[j][i]);
	}
	for(int i = 0; i < n; i++){
		x ^= 1, y ^= 1;
		for(int k = 0; k < (1 << (m + 1)); k++){
			dp[x][k][0] = f(k, 0) ? 0 : (dp[y][(k << 1) & ((1 << (m + 1)) - 1)][0] + dp[y][((k << 1) & ((1 << (m + 1)) - 1)) | 1][0]) % p;
			dp[x][k][1] = f(k, 0) ? 0 : (dp[y][(k << 1) & ((1 << (m + 1)) - 1)][1] + dp[y][((k << 1) & ((1 << (m + 1)) - 1)) | 1][1]) % p;
		}
		for(int j = 0; j < m; j++){
			x ^= 1, y ^= 1;
			if(s[i][j] == '.'){
				for(int k = 0; k < (1 << (m + 1)); k++){
					int p1 = f(k, j), p2 = f(k, j + 1);
					if(p1 && p2){
						dp[x][k][0] = (((dp[y][c(k, j, 1, 1)][0] * 2 % p + dp[y][c(k, j, 0, 1)][0]) % p + dp[y][c(k, j, 1, 0)][0]) % p + dp[y][c(k, j, 0, 0)][0]) % p;
						dp[x][k][1] = (((dp[y][c(k, j, 1, 1)][1] * 2 % p + dp[y][c(k, j, 0, 1)][1]) % p + dp[y][c(k, j, 1, 0)][1]) % p + dp[y][c(k, j, 0, 0)][1]) % p;
					}
					else if(p2){
						dp[x][k][0] = dp[y][c(k, j, 1, 0)][0];
						dp[x][k][1] = dp[y][c(k, j, 1, 0)][1];
					}
					else if(p1){
						dp[x][k][0] = dp[y][c(k, j, 0, 1)][0];
						dp[x][k][1] = dp[y][c(k, j, 0, 1)][1];
					}
					else{
						dp[x][k][0] = 0;
						dp[x][k][1] = dp[y][c(k, j, 0, 0)][0];
					}
				}
			}
			else{
				for(int k = 0; k < (1 << (m + 1)); k++){
					int p1 = f(k, j), p2 = f(k, j + 1);
					if(p1 && p2){
						dp[x][k][0] = 0;
						dp[x][k][1] = 0;
					}
					else if(p2){
						dp[x][k][0] = 0;
						dp[x][k][1] = 0;
					}
					else if(p1){
						dp[x][k][0] = 0;
						dp[x][k][1] = 0;
					}
					else{
						dp[x][k][0] = (((dp[y][c(k, j, 1, 1)][0] + dp[y][c(k, j, 0, 1)][0]) % p + dp[y][c(k, j, 1, 0)][0]) % p + dp[y][c(k, j, 0, 0)][0]) % p;
						dp[x][k][1] = (((dp[y][c(k, j, 1, 1)][1] + dp[y][c(k, j, 0, 1)][1]) % p + dp[y][c(k, j, 1, 0)][1]) % p + dp[y][c(k, j, 0, 0)][1]) % p;
					}
				}
			}
		}
	}
	for(int k = 0; k < (1 << (m + 1)); k++) ans = ((ans + dp[x][k][0]) % p + dp[x][k][1]) % p;
	cout << ans << endl;
	return 0;
}