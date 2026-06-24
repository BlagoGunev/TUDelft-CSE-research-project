#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int x[4], y[4];
	for(int i = 0; i < 3; i++)
		scanf("%d%d", &x[i], &y[i]);
	printf("3\n");
	for(int i = 0; i < 3; i++)
	{
		int nx = x[i], ny = y[i];
		int tx = x[(i+1) % 3] - x[(i+2) % 3];
		int ty = y[(i+1) % 3] - y[(i+2) % 3];
		printf("%d %d\n", nx + tx, ny + ty);
	}
	return 0;
}