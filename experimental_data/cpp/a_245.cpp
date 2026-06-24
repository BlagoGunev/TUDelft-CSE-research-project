#include <bits/stdc++.h>

using namespace std;

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	long long int i = 0, n, x, y, t, sum1_x = 0, sum2_x = 0, sum1_y = 0, sum2_y = 0;
	scanf("%lld", &n);
	while (i < n) {
		scanf("%lld%lld%lld", &t, &x, &y);
		//printf("%d\n", i);
		if (t == 1) {
			sum1_x = sum1_x + x;
			sum1_y = sum1_y + y;
		} else {
			sum2_x = sum2_x + x;
			sum2_y = sum2_y + y;
		}
		i = i + 1;
	}
	
	if ((sum1_x + sum1_y) / 2 <= sum1_x) {
		printf("LIVE\n");
	} else {
		printf("DEAD\n");
	}

	if ((sum2_x + sum2_y) / 2 <= sum2_x) {
		printf("LIVE\n");
	} else {
		printf("DEAD\n");
	}
	
	return 0;
}