#include <algorithm>
#include <cstdio>

using namespace std;

int n, mod, f[4000002], sum[4000002];
int main(){
	scanf("%d%d", &n, &mod);
	sum[n] = f[n] = 1;
	for (int i = n - 1;i >= 1;i --){
		f[i] = sum[i + 1];
		for (int j = 2;i * j <= n;j ++){
			f[i] = (f[i] + (sum[i * j] - sum[min(i * j + j, n + 1)] + mod) % mod) % mod;
		}
		sum[i] = (sum[i + 1] + f[i]) % mod;
	}
	printf("%d", f[1]);
}