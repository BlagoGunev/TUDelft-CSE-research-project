#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{
	int N,tall;
	int Max, count;
	bool vis[100010] = { 0 };
	scanf("%d", &N);
	Max = N;
	for (int i = 0;i < N;i++)
	{
		scanf("%d", &tall);
		if (tall == Max)
		{
			printf("%d", Max);
			count = Max - 1;
			while (vis[count] == true)
				printf(" %d", count--);
			printf("\n");
			Max = count;
		}
		else if (tall < Max)
		{
			vis[tall] = true;
			printf("\n");
		}
	}
	return 0;
}