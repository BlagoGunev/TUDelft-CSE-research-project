#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	long long num[110];

	int i, j, n;
	long long sum = 0;
	scanf("%d", &n);
	for(i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &num[i]);
		sum += num[i];
		num[i]--;
	}

	for(i = 2 ; i <= n ; i++)
	{
		for(j = i ; j <= n ; j++)
		{
   			sum += num[j];
		}
	}
	printf("%lld\n", sum);
    return 0;
}