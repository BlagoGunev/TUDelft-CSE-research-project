#include<stdio.h>

#include<algorithm>

#include<string.h>

using namespace std;

typedef long long ll;

const int N = 100, M = 100000;

int k, a[N];

ll f[N][M];

inline ll dfs(int i, ll n){

	if (n == 0)

		return 0;

	if (i >= k)

		return n;

	if (n < M&&f[i][n]!=-1)

		return f[i][n];

	ll rt = dfs(i + 1, n) - dfs(i + 1, n / a[i]);

	if (n < M)

		f[i][n] = rt;

	return rt;

}

bool cmp(int a, int b){//剪枝的关键

	return a>b;

}

int main(){

	ll n;

	scanf("%I64d%d", &n, &k);

	for (int i = 0; i < k; i++)

		scanf("%d", &a[i]);

	sort(a, a + k, cmp);

	memset(f, -1, sizeof(f));

	printf("%I64d\n", dfs(0, n));

	return 0;

}