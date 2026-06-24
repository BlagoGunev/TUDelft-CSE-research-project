#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int t = 240 - k;
	int ans = (sqrt(25 + 40 * t) - 5) / 10;
	if (ans > n)
		ans = n;
	printf("%d\n", ans);
	return 0;
}