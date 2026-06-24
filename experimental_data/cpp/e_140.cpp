#include<bits/stdc++.h> 

using namespace std;



typedef long long LL;

const int maxn = 1e6 + 10; 

int n, m, mod;

int a[maxn];

int d[5005][5005], f[2][5005];

LL Am[5005], fact[5005];  //排列，阶乘 

LL sum[maxn]; 



void init(int MM){

	for(int i = fact[0] = 1; i <= MM; i++) fact[i] = fact[i-1] * i % mod;

	for(int i = Am[0] = 1; i <= MM; i++) Am[i] = Am[i-1] * (m - i + 1) % mod;

	d[0][0] = 1;

	for(int i = 1; i <= MM; i++)

		for(int j = 1; j <= i; j++) d[i][j] = (d[i-1][j-1] + (LL)d[i-1][j]*(j - 1)) % mod;  //颜色顺序固定

}



int main(){

	cin >> n >> m >> mod;

	int MM = 0;

	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), MM = max(MM, a[i]);

	init(MM);

	int cur = sum[0] = 1;

	for(int i = 1; i <= n; i++){

		for(int j = 1; j <= min(a[i], m); j++){ 

			f[cur][j] = d[a[i]][j] * sum[i-1] % mod * Am[j] % mod;  //Am[j] == C(m,j)*fact[j]

			if(i > 1 && j <= a[i-1]) f[cur][j] -= (LL)f[cur^1][j] * d[a[i]][j] % mod * fact[j] % mod; //不用乘C(m，j) 

			if(f[cur][j] < 0) f[cur][j] += mod;                                                                 

			sum[i] = (sum[i] + f[cur][j]) % mod;                //因为f[cur^1][j]中乘过了  

		}

		cur ^= 1;

	}

	return 0*printf("%I64d\n", sum[n]);

}