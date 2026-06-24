#include<cstdio>
#include<vector>
#include<algorithm>
#define db double
#define ll long long
#define N 300010
#define M 300000
using namespace std;
int n;
vector<int>e[110];
db f[N];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int p, w;
		scanf("%d%d", &p, &w);
		e[p].push_back(w);
	}
	for(int i = 1; i <= 100; i++)sort(e[i].begin(), e[i].end(), cmp);
	ll sum = 0;
	for(int i : e[100])sum += i;
	if(sum > M)
	{
		printf("%lld\n", sum);
		return 0;
	}
	f[sum] = 1;
	for(int i = 1; i < 100; i++)
	{
		int s = 100 / (100 - i);
		for(int j = 0; j < s && j < e[i].size(); j++)
		{
			for(int k = M - e[i][j]; k >= 0; k--)
				f[k + e[i][j]] = max(f[k + e[i][j]], f[k] * i * 0.01);
		}
	}
	db ans = 0;
	for(int i = 0; i <= M; i++)
		ans = max(ans, f[i] * i);
	printf("%.9lf\n", ans);
	return 0;
}