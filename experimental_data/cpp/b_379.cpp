#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int a[310];
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n-1;i++)
		{
			while(a[i])
			{
				printf("P");
				a[i]--;
				if(a[i]==0)
					break;
				printf("R");
				if(a[i+1])
				{
					a[i+1]--;
					printf("P");
				}
				printf("L");
			}
			printf("R");
		}
		while(a[n])
		{
			printf("P");
			a[n]--;
			if(a[n]==0)
				break;
			printf("L");
			printf("R");
		}		
		printf("\n");
	}
	return 0;
}