#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, num;
int a[1010];

int main()
{
	int i, mini;
	scanf("%d%d", &n, &m);

	for (i = 0; i < m; ++i) {
		scanf("%d", &num);
		a[num]++;
	}
	mini = 2000;
	for (i = 1; i <= n; ++i) {
		mini = min(mini, a[i]);
	}
	printf("%d\n", mini);
}