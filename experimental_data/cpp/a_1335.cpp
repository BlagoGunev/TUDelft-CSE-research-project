#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		if(n >= 3)
		{
			if(n % 2 == 0)
			{
				printf("%d\n", (n/2)-1);
			}
			else
			{
				printf("%d\n", (n-1)/2);
			}
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}