/*****************************
Filename: cf190929.cpp
Author: hbb
Create: 2019-09-29 21:12:41
 *****************************/
#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
const int inf = INT_MAX >> 1;
typedef long long int LL;

int n, m;
int G[maxn][maxn];
int r[maxn], c[maxn];

LL FastPow(LL x, LL y){
	LL res = 1;
	while(y){
		if(y & 1) res = (res * x) % mod;

		x = (x * x) % mod;

		y >>= 1;
	}
	return res;
}

int main(){
	while(scanf("%d %d", &n, &m) != EOF){
		for(int i = 1; i <= n; i++) scanf("%d", &r[i]);
		for(int i = 1; i <= m; i++) scanf("%d", &c[i]);
		memset(G, 0, sizeof(G));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= r[i]; j++)G[i][j] = 1;
			G[i][r[i] + 1] = 2;
		}
		int flag = 1;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= c[i]; j++){
				if(G[j][i] == 2){
					flag = 0;
					break;
				}
				else G[j][i] = 1;
			}
			if(flag == 0) break;
			if(G[c[i] + 1][i] == 1){
				flag = 0;
				break;
			}
			else G[c[i] + 1][i] = 2;
		}
		if(flag){
			int ans = 0;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){
					if(G[i][j] == 0) ans++;
				}
			}
			LL put = FastPow(2, ans);
			printf("%lld\n", put);
		}
		else printf("0\n");
	}
}