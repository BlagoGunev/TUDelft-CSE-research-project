#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n,k;
	while(~scanf("%d",&n))
	{
		if(n%2==0)
		{
			k = n/2;
			printf("%d\n",k);
			for(int i=1;i<=k;i++)
			{
				printf("2");
				if(i!=k)
				printf(" ");
			}
			printf("\n");
		}
		/*else if(n==3)
		{
			printf("1\n");
			printf("3\n");
		}*/
		else 
		{
			k = (n-3)/2 + 1;
			printf("%d\n",k--);
			for(int i=1;i<=k;i++)
			{
				printf("2");
				//if(i!=k)
				printf(" ");
			}
			printf("3\n");
		}
	}
	return 0;
}