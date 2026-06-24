#include<stdio.h>
#include<string.h>
#define MAXN 105
bool vis[MAXN];
int step,num;
int main() {
	int n, k;
	int runStep=1;
	scanf("%d%d", &n, &k);
	num = n;
	memset(vis, 0, sizeof(vis));
	for (int i = 1;i <= k;i++) {
		scanf("%d", &step);
		step %= num;
		while (step != 0) {
			runStep++;
			if (runStep > n)
				runStep = 1;
			if (!vis[runStep])
				step--;
		}
		vis[runStep] = true;
		if (i != 1)
			printf(" ");
		printf("%d", runStep);
		runStep++;
		if (runStep > n)
			runStep = 1;
		num--;
		while (vis[runStep]) {
			runStep++;
			if (runStep > n)
				runStep = 1;
		}
	}
	printf("\n");
	return 0;
}